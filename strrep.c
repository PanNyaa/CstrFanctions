#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
 
 
 
int strrep(char*,char*,char*);
 
 
 
//文字列から特定文字列を検索し指定の特定文字列に置き換える、ような関数。
//文字列が入った配列の大きさを指定して、置換結果がそれ以上になったらエラーを返します。
//置換後の文字数が同じもしくは少ない場合のみの対応です。
//大きくしてしまうと2次元以上にしていたときなどに、他の配列に食い込んでしまうので、
//元のサイズよりも大きくなったときはエラーを返します。(-1　か　必要なサイズ？)
int strrep(char *str,char *search,char *replace){
 
	char *p;
	int len,len_s,len_r,r_cnt;
 
	len = strlen(str);						//検索先文字列の長さを得る
	len_s = strlen(search);	  		//指定された検索する文字列の長さを得る
	len_r = strlen(replace);			//指定された置換する文字列の長さを得る
	r_cnt = strcnt(str,search);		//指定された検索する文字列の数を得る
 
	if(len_s < len_r){
		return -1;	//検索文字列よりも置換文字列のほうが多かった場合、結果配列が大きくなってしまうのでエラーを返す
	}
	if(len_s == 0){
		return -1;	//検索文字列が0文字だった場合、置換処理をする必要がないのでエラーを返す
	}
 
	for(;;){
		if( (p = strstr(str,search)) != NULL ){		//検索先文字列から指定文字がHITしたら
		
			strncpy(p,replace,len_r);	//置換文字数分だけ置換
			strncpynull(p+len_r,p+len_s,strlen(p+len_s),0);
 
		}
		if(--r_cnt <= 0)
			break;			//検索文字列の回数分だけ、繰り返す
	}
	return 0;
}
