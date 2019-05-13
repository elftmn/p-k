#include <stdio.h>
#include <x86intrin.h>

#define N (1<<13)
#define step 16

int main(void) {
  int *a, *b, *c;
  a = (int *)malloc(4LL*N*N);
  b = (int *)malloc(4LL*N*N);
  c = (int *)malloc(4LL*N*N);
  int i,j;
  long long int at0, at1,bt0, bt1, ct0, ct1;
  int n,k;
  for(n=16;n<=N;n<<=1){
      at0 = _rdtsc();

  for(k=0;k<16;k++)
    for(i=0;i<n;i++){
      for(j=0;j<n;j+=step){
          a[(long long int)i*n+j]=j;
      }
  }
  at1 = (_rdtsc() - at0)>>4;

  bt0 = _rdtsc();
  for(k=0;k<16;k++)
  for(i=0;i<n;i+=step){
      for(j=0;j<n;j++){
          b[(long long int)j*n+i]=i;
      }
  }
  bt1 = (_rdtsc() - bt0)>>4;

  ct0 = _rdtsc();
  for(k=0;k<16;k++)
  for(i=0;i<n;i++){
      for(j=0;j<n;j+=step){
          c[(((long long int)(rand()*step)%(n*n)))&0xfffffff0]=j;
      }
  }
  ct1 = (_rdtsc() - ct0)>>4;  

  printf("%lld, (%.2f), %lld (%.2f), %lld (%.2f);\n", at1, (double) at1/at1, bt1, (double) bt1/at1, ct1, (double) ct1/at1);
}

  return 0;
}
