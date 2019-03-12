
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<Windows.h>
#include<assert.h>

enum State{
	NORMAL,//普通状态
	FOUND_SLASH,//找到斜杠
	C_COMMENT,//C注释
	CPP_COMMENT,//C++注释
	FOUND_ASTERISK//找到*
};
void CommentConvert(FILE *pIn, FILE *pOut)
{
	enum State state = NORMAL;
	char ch, nextCH;
	while (1){
		ch = fgetc(pIn);
		if (ch == EOF)
			break;
		switch (state){
		case NORMAL:
			if (ch == '/')
				state = FOUND_SLASH;
			else
			{
				state = NORMAL;
				fputc(ch, pOut);
			}
			break;
		case FOUND_SLASH:
			if (ch == '*')
			{
				fprintf(pOut, "//");
				state = C_COMMENT;
			}
			else if (ch == '/')
			{
				fprintf(pOut, "//");
				state = CPP_COMMENT;
			}
			else
			{
				fprintf(pOut,"/");
				fputc(ch, pOut);
				state = NORMAL;
			}
			break;
		case C_COMMENT:
			if (ch == '*')
				state = FOUND_ASTERISK;
			else{
				fputc(ch, pOut);
				if (ch == '\n') {
					fprintf(pOut, "//");
				}
			}
			break;
		case CPP_COMMENT:
			if (ch = '\n')
			{
				fputc(ch, pOut);
				state = NORMAL;
			}
			else
			{
				fputc(ch, pOut);
				state = CPP_COMMENT;
			}
			break;
		case FOUND_ASTERISK:
			if (ch == '/')
			{
				nextCH = fgetc(pIn);
				if (nextCH != '\n'){
					fputc('\n', pOut);
				}
				state = NORMAL;
				ungetc(nextCH, pIn);
			}
			else if (ch == '*')
			{
				fputc('*', pOut);
				state = FOUND_ASTERISK;
			}
			else
			{
				fputc('*', pOut);
				fputc(ch, pOut);
				state = C_COMMENT;
			}
			break;
		}
	}
}

int main()
{
	const char *INPUT = "input.c";
	const char *OUTPUT = "output.c";
	FILE *pIn = fopen(INPUT, "r");
	assert(pIn);
	FILE *pOut = fopen(OUTPUT, "w");
	assert(pOut);

	CommentConvert(pIn, pOut);

	fclose(pOut);	// 后打开的先关
	fclose(pIn);

	return 0;

}