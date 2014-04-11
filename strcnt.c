#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
 
 
int strcnt(char*,const char*);
 
 
//文字配列内に指定した文字列がいくつ存在するかを返す関数
int strcnt(char *str,const char *substr){
 
	char *p;
	int  len,i=0;
	
	len = strlen(substr);
 
	for(;;){
		if( (p = strstr(str,substr)) != NULL ){		//検索先文字列から指定文字がHITしたら
			i++;
			str = p+len;
		}else{
			break;
		}
	}
	
	return i;
}
