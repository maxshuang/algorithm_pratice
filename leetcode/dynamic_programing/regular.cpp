//给定一个字符串和模式串，判断是否匹配
//.：匹配任意1个字符
//*: 匹配0个或者任意多个前面的字符

#include <string.h>
#include <stdio.h>

bool is_match(const char* str, const char* pat)
{
	if(!(*pat))
		return !(*str);
	
	bool first_match = str && (('.'==*pat) || (*str == *pat));
	
	//*匹配0个前面的字符或者多个前面的字符
	if(strlen(pat) >=2 && '*' == pat[1]){
		return is_match(str, pat+2) || (first_match && is_match(str+1, pat));
	}

	//匹配下一个字符
	return first_match && is_match(str+1, pat+1);
}

int main()
{
	const char* str = "aaaabcdfgaa";
	const char* pat = "c*a..abcc*dfg..c*";
	
	printf("is_match:%d\n", is_match(str, pat));
	return 0;
}
