#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
 
 
 
#define strncpynull( ... ) strncpynull_( __VA_ARGS__ ,1 )
int strncpynull_(char*,char*,size_t, ... );
 
 
 
//strncpyっぽい機能+最後に'\0'を付け足す関数
//flagが0だった場合、_Destの'\0'を検知しなくなる。省略すると1
int strncpynull_(char* _Dest,char* _Source,size_t Count, ... ){
	va_list list;
	
	if(_Dest == NULL || _Source == NULL || Count == 0)return -1;
 
	va_start( list , Count );
 
	if(va_arg(list,char) == 1){
		while(Count--){
			if(*_Dest=='\0' || *_Source=='\0')break;
			*_Dest++ = *_Source++;
		}
		if( !(*_Dest=='\0' || *_Source=='\0') )*_Dest = '\0';
	}else{
		while(Count--){
			*_Dest++ = *_Source++;
		}
		*_Dest = '\0';
	}
	
	va_end(list);
	return 0;
}
