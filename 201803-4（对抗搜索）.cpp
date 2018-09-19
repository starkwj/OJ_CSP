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
 * 伪代码
 * function minimax(node, depth) // 指定当前节点和搜索深度  
   // 如果能得到确定的结果或者深度为零，使用评估函数返回局面得分  
   if node is a terminal node or depth = 0  
       return the heuristic value of node  
   // 如果轮到对手走棋，是极小节点，选择一个得分最小的走法  
   if the adversary is to play at node  
       let α := +∞  
       foreach child of node  
           α := min(α, minimax(child, depth-1))  
   // 如果轮到我们走棋，是极大节点，选择一个得分最大的走法  
   else {we are to play at node}  
       let α := -∞  
       foreach child of node  
           α := max(α, minimax(child, depth-1))  
   return α;
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

// α-β剪枝算法
/**
 * 伪代码
 * function alphabeta(node, depth, α, β, Player)           
    if  depth = 0 or node is a terminal node  
        return the heuristic value of node  
    if  Player = MaxPlayer // 极大节点  
        for each child of node // 极小节点  
            α := max(α, alphabeta(child, depth-1, α, β, not(Player) ))     
            if β ≤ α // 该极大节点的值>=α>=β，该极大节点后面的搜索到的值肯定会大于β，因此不会被其上层的极小节点所选用了。对于根节点，β为正无穷  
                break                             (* Beta cut-off *)  
        return α  
    else // 极小节点  
        for each child of node // 极大节点  
            β := min(β, alphabeta(child, depth-1, α, β, not(Player) )) // 极小节点  
            if β ≤ α // 该极大节点的值<=β<=α，该极小节点后面的搜索到的值肯定会小于α，因此不会被其上层的极大节点所选用了。对于根节点，α为负无穷  
                break                             (* Alpha cut-off *)  
        return β   
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
