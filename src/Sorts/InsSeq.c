
void ins_seq ( int[] t, int size) {
int i,j,k,tmp;
for ({ j=0; i=1;}; i< size; ++i) {
while ( t[i] > t[j] && j<= i) ++j;
tmp= t[i];
for (k=i; k>j; --k) t[k] = t[k-1];
t[j] = tmp;
}
}
