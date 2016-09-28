void ins_seqChained ( int[] t, int size) {
	int i,j,k,tmp;
	for (i=1; i< size;{j=0; ++i;}) {
		while ( t[i] > t[j] && j<= i) ++j;
		tmp= t[i];
		for (k=i; k>j; --k) t[k] = t[k-1];
		t[j] = tmp;
	}	
}
