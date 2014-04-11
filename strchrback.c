#include <stdio.h>
#include <string.h>


char* strchrback(const char *,const char *,int);


//strchrの後方検索版。オフセットを指定してそこから_Strの先頭まで探します
char* strchrback(const char *_Str,const char *offset ,int _C){
	
	while(_Str != offset){
		if(*offset == _C){
			return (char*)offset;
		}else{
			offset--;
		}
	}

	return NULL;
}
