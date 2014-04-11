#include <stdio.h>
#include <string.h>


char* strstrback(const char *,const char *,const char *);


//strstrの後方検索版。オフセットを指定してそこから_Strの先頭まで探します
//strstrの文法を参考にしました : http://www1.cts.ne.jp/~clab/hsample/Point/Point14.html
char *strstrback(const char *_Str,const char* offset, const char *_SubStr){

    int n;

    n = strlen(_SubStr);												      		/* 文字列_SubStrの長さを求める */
	
    for(;; offset-- ) {
        offset = strchrback(_Str, offset , _SubStr[0]);		/* _SubStrの先頭の１文字を後方検索で探す */
        if (offset == _Str)return (NULL);							  	/* _Strの先頭まで検索し終えていた場合NULLを返す */
        if(strncmp(offset, _SubStr, n) == 0){			  			/* 見つかったらn文字比較 */
			return (char *)offset;										         	/* 一致したらポインタを返す */
		}
		/* ここに来た場合一致していないのでポインタをデクリメントし次の一致文字列を探す*/
    }

}
