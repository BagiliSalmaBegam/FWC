#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"  

int main() {
    Node *P, *Q, *R,*R1;
    int m = 2, n = 1;

    // Loading the matrices from .dat files
    P = loadtxt("P.dat");
    Q = loadtxt("Q.dat");
    scalarmul(2,P);
    R=linalg_sub(Q,P);
    scalarmul(-1,R);
    print(R);
    savef("result.dat",R,m,n);
}
