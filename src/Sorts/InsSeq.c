#include <stdlib.h>

void ins_seq (int t[], size_t size) {
	size_t i, j, k;
	int tmp;
	
	j = 0;
	for (i = 1; i < size; ++i) {
		while ( t[i] > t[j] && j <= i) 
			++j;
		
		tmp = t[i];
		
		for (k = i; k > j; --k)
			t[k] = t[k -1 ];
		
		t[j] = tmp;
		
		j = 0;
	}	
}
