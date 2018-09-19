#include <stdio.h>
#include <string.h>

char * printem(char *p);
char * printlink(char *p);

int main()
{
	char buf[101];
	char *p;
	enum state {none, para, ul, em, link} first;
	first = none;
	
	while (fgets(buf, 101, stdin))
	{
		switch (buf[0]) {
			case '\n': {
				if (first == ul)
				{
					printf("</ul>\n");
				}
				else if (first == para)
				{
					printf("</p>\n");
				}
				first = none;
				break;
			}
			
			case '#': {
				int cnt = 0;
				for (p = &buf[0]; *p == '#'; p++)
				{
					cnt++;
				}
				printf("<h%d>", cnt);
				while (*p == ' ')
				{
					p++;
				}
				while (*p != '\n')
				{
					if (*p == '_')
					{
						p = printem(p);
					}
					else if (*p == '[')
					{
						p = printlink(p);
					}
					else
					{
						printf("%c", *p);
					}
					p++;
				}
				printf("</h%d>\n", cnt);
				break;
			}
			
			case '*': {
				if (first == none)
				{
					first = ul;
					printf("<ul>\n");
				}
				printf("<li>");
				p = &buf[1];
				while (*p == ' ')
				{
					p++;
				}
				while (*p != '\n')
				{
					if (*p == '_')
					{
						p = printem(p);
					}
					else if (*p == '[')
					{
						p = printlink(p);
					}
					else
					{
						printf("%c", *p);
					}
					p++;
				}
				printf("</li>\n");
				break;
			}
			
			default: {
				if (first == none)
				{
					first = para;
					printf("<p>");
				}
				else if (first == para)
				{
					printf("\n");
				}
				p = &buf[0];
				while (*p != '\n')
				{
					if (*p == '_')
					{
						p = printem(p);
					}
					else if (*p == '[')
					{
						p = printlink(p);
					}
					else
					{
						printf("%c", *p);
					}
					p++;
				}
				break;
			}
		}
	}
	
	if (first == ul)
	{
		printf("</ul>");
	}
	else if (first == para)
	{
		printf("</p>");
	}
	return 0;
}

char * printem(char *p)
{
	printf("<em>");
	p++;
	while (*p != '_')
	{
		if (*p == '[')
		{
			p = printlink(p);
		}
		else
		{
			printf("%c", *p);
		}
		p++;
	}
	printf("</em>");
	return p;
}

char * printlink(char *p)
{
	char *textbeg = ++p;
	while (*p != ']')
	{
		p++;
	}
	char *textend = p;
	p += 2;
	printf("<a href=\"");
	while (*p != ')')
	{
		if (*p == '_')
		{
			p = printem(p);
		}
		else
		{
			printf("%c", *p);
		}
		p++;
	}
	printf("\">");
	
	while (textbeg != textend)
	{
		if (*textbeg == '_')
		{
			textbeg = printem(textbeg);
		}
		else
		{
			printf("%c", *textbeg);
		}
		textbeg++;
	}
	printf("</a>");
	return p;
}
