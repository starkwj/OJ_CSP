#include <stdio.h>

char chess[3][3];

int isWin(char go) {
	int i;
	if (chess[1][1] == go ) {
		if (chess[0][0] == go && chess[2][2] == go)
			return 1;
		if (chess[0][2] == go && chess[2][0] == go)
			return 1;
	}
	
	for (i = 0; i < 3; i++) {
		if (chess[i][0] == go && chess[i][1] == go && chess[i][2] == go) {
			return 1;
		}
	}
	
	for (i = 0; i < 3; i++) {
		if (chess[0][i] == go && chess[1][i] == go && chess[2][i] == go) {
			return 1;
		}
	}
	
	return 0;
}

int getScore() {
	int i, j, cnt = 1;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (chess[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}


/**
 * α����
 * function minimax(node, depth) // ָ����ǰ�ڵ���������  
   // ����ܵõ�ȷ���Ľ���������Ϊ�㣬ʹ�������������ؾ���÷�  
   if node is a terminal node or depth = 0  
       return the heuristic value of node  
   // ����ֵ��������壬�Ǽ�С�ڵ㣬ѡ��һ���÷���С���߷�  
   if the adversary is to play at node  
       let �� := +��  
       foreach child of node  
           �� := min(��, minimax(child, depth-1))  
   // ����ֵ��������壬�Ǽ���ڵ㣬ѡ��һ���÷������߷�  
   else {we are to play at node}  
       let �� := -��  
       foreach child of node  
           �� := max(��, minimax(child, depth-1))  
   return ��;
 */
int dfs(char go)
{
    // no place to put chess
    if (getScore() == 1) {
        return 0;
    }

    int i, j, score;
	if (go == 1) {
        score = -9;
    } else {
        score = 9;
    }
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (chess[i][j] == 0) {
				chess[i][j] = go;

	            if (isWin(go)) {
					int w = getScore();
					chess[i][j] = 0;
	                if (go == 1) {
	                    return score > w ? score : w;
	                } else {
	                    return score < -w ? score : -w;
	                }
	            }
	            // go on
	            int temp = dfs(3 - go);
	            // for 1(x), get max score of win or minimum score of lose
	            if (go == 1) {
	                score = score > temp ? score : temp;
	            } else {
	                score = score < temp ? score : temp;
	            }
	            chess[i][j] = 0;
            	// backtrack
        	}
		}
	}
    return score;

}

// ��-�¼�֦�㷨
/**
 * α����
 * function alphabeta(node, depth, ��, ��, Player)           
    if  depth = 0 or node is a terminal node  
        return the heuristic value of node  
    if  Player = MaxPlayer // ����ڵ�  
        for each child of node // ��С�ڵ�  
            �� := max(��, alphabeta(child, depth-1, ��, ��, not(Player) ))     
            if �� �� �� // �ü���ڵ��ֵ>=��>=�£��ü���ڵ�������������ֵ�϶�����ڦ£���˲��ᱻ���ϲ�ļ�С�ڵ���ѡ���ˡ����ڸ��ڵ㣬��Ϊ������  
                break                             (* Beta cut-off *)  
        return ��  
    else // ��С�ڵ�  
        for each child of node // ����ڵ�  
            �� := min(��, alphabeta(child, depth-1, ��, ��, not(Player) )) // ��С�ڵ�  
            if �� �� �� // �ü���ڵ��ֵ<=��<=�����ü�С�ڵ�������������ֵ�϶���С�ڦ�����˲��ᱻ���ϲ�ļ���ڵ���ѡ���ˡ����ڸ��ڵ㣬��Ϊ������  
                break                             (* Alpha cut-off *)  
        return ��   
(* Initial call *)  
alphabeta(origin, depth, -infinity, +infinity, MaxPlayer)  
 */
int alphabeta(int alpha, int beta, char go)
{
	if (getScore() == 1) {
		return 0;
	}
	
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (chess[i][j] == 0) {
				chess[i][j] = go;

	            if (isWin(go)) {
					int w = getScore();
					chess[i][j] = 0;
	                if (go == 1) {
	                    return alpha > w ? alpha : w;
	                } else {
	                    return beta < -w ? beta : -w;
	                }
	            }
	            // go on
	            int temp = alphabeta(alpha, beta, 3 - go);
	            // minimax
	            if (go == 1) {
	                alpha = alpha > temp ? alpha : temp;
	                if (beta <= alpha) {
	                	chess[i][j] = 0;
	                	return alpha;
					}
	                
	            } else {
	                beta = beta < temp ? beta : temp;
	                if (beta <= alpha) {
	                	chess[i][j] = 0;
	                	return beta;
					}
	            }
	            chess[i][j] = 0;
            	// backtrack
        	}
		}
	}
	if (go == 1) {
		return alpha;
	} else {
		return beta;
	}
}


int main()
{
	int i, j, n;
	scanf("%d", &n);
	while (n--)
	{
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				scanf("%d", &chess[i][j]);
			}
		}
	
	    if (isWin(1)) {
	        printf("%d\n", getScore());
	    }
	    else if (isWin(2)) {
	        printf("%d\n", -1 * getScore());
	    }
	    else {
	        printf("%d\n", alphabeta(-9, 9, 1));
	    }	
	}
	
	return 0;
	
}
