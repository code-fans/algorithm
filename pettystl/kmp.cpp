#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

namespace pettystl {

	int* getNext(char *str)
	{
		int len = strlen(str);
		int* next = (int*)calloc(len, sizeof(int));
		next[0] = -1;
		int i = 0, k = -1;
	
		while ( i < len-1) { 
	
			if (k==-1||str[i]==str[k]) {
				i++;
				k++;
				next[i] = (str[i] == str[k] ? next[k] : k);
			}
			else {
				k = next[k];
			}
		}
	
		return next;
	}
	
	int KMP(char* chang, char* duan)
	{
	
		int* next = getNext(duan);
		int c_len = strlen(chang);
		int d_len = strlen(duan);
		int i = 0, k = 0;
	
		while (i<c_len && k<d_len) {
	
			if (k == -1 || chang[i] == duan[k]) {
				i++;
				k++;
			}
			else {
				k = next[k];
			}
		}
	
		return k < d_len ? -1 : i - k;
	}
 
}
