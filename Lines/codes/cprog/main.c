#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"libr.h"

int main()
{
	double **P,**Q,**r1;
	int m=2,n=1;
	P=loadtxt("P.dat",m,n);
	Q=loadtxt("Q.dat",m,n);
	scalarmul(2,P);
	r1=linalg_sub(Q,P,2,1);
	scalarmul(-1,r1);
	print(r1,m,n);
	save(r1,m,n);
}
