#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
 
 
#define va_len(DEST,LIST,LISTPTR,TYPE,ENDOFFLAG) do{char*p;DEST=0;va_start(LIST,LISTPTR);p=LISTPTR;while(p!=ENDOFFLAG){p=va_arg(LIST,TYPE);DEST++;}va_end(LIST);}while(0)
 
#define strstrs( ... ) strstrs_( __VA_ARGS__ ,NULL )
char* strstrs_(char*,char*, ... );
 
int ascmp_int(const void* a,const void* b){return (*(int*)a-*(int*)b);};
int descmp_int(const void* a,const void* b){return (*(int*)a-*(int*)b)*-1;};
 
 
 
char* strstrs_(char *_Str,char *_SubStr, ... ){
	//#define strstrs( ... ) strstrs_( __VA_ARGS__ ,NULL ) マクロにより、リストの終端はNULL固定
	//strstrの可変長引数版関数。strstrs(buf,"cat","dog","food"); みたいな感じに使う。
	//bufの先頭に一番近い文字列を優先する( buf="___dog_____________cat___" だった場合、dogのdのポインタを返す)
	//可変長引数の文法を参考にしました ( http://hitorilife.com/verargs.php )
	
	va_list list;
	char *p;
	int s_len,arg_len,i,*arr;
 
	arg_len = 0;
	s_len = strlen(_Str);
 
	
	va_len(arg_len,list,_SubStr,char*,NULL);		//NULLまで探索し可変部分の引数の数を得る
 
	arr = (int*)malloc( sizeof(int) * (arg_len+1) );	//可変引数の数だけ、_Str(サーチ元文字列先頭ポインタ)～p(指定文字列発見時ポインタ)間の距離を保存する配列を作成
	memset(arr,0,sizeof(int)*(arg_len+1));
 
	va_start( list , _SubStr );
 
	for( i=0 ; i < arg_len ; i++){
		if( (p = strstr( _Str , _SubStr )) != NULL ){
			for(;_Str != p;p--)arr[ i ]++;		//文字列が見つかったら、_Str~pのポインタ間距離を計算し保存
		}else{
			arr[ i ] = s_len;			//見つからなかったら、_Str~\0の距離(文字数分)を保存
		}
		_SubStr = va_arg( list , char* );		//文字列が見つかっても見つからなくても次のリストへ
	}
 
	qsort(arr,arg_len,sizeof(int),ascmp_int);		//昇順ソートで、_Strの先頭と一番距離が近かったポインタ距離を一番上へ
 
	if(arr[0] != s_len){
		p = _Str+arr[0];
	}else{
		p = NULL;
	}
 
	free(arr);
	va_end( list );	//見つからなかった場合はva_endしてからNULLを返す
	return p;
}
