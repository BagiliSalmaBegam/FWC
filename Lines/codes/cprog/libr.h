double **loadtxt(char *str,int m,int n); 
void print(double **p, int m,int n); 
double **linalg_sub(double **a, double **b, int m, int n); 
void scalarmul(int num,double **a);
double **createMat(int m,int n); 


double **loadtxt(char *str,int m,int n) 
{ 
FILE *fp; 
double **a; 
int i,j; 
 
 
a = createMat(m,n); 
fp = fopen(str, "r"); 
 
 for(i=0;i<m;i++) 
 { 
  for(j=0;j<n;j++) 
  { 
   fscanf(fp,"%lf",&a[i][j]); 
  } 
 } 
//End function for reading matrix from file 
 
fclose(fp); 
 return a; 
 
}

void print(double **p, int m,int n) 
{ 
 int i,j; 
 
 for(i=0;i<m;i++) 
 { 
  for(j=0;j<n;j++) 
  printf("%lf ",p[i][j]); 
 printf("\n"); 
 } 
}

double **linalg_sub(double **a, double **b, int m, int n) 
{ 
int i, j; 
double **c; 
c = createMat(m,n); 
 
 for(i=0;i<m;i++) 
 { 
  for(j=0;j<n;j++) 
  { 
c[i][j]= a[i][j]-b[i][j]; 
//printf("%d",c[i][j]);
  } 
 } 
return c; 
 
}

void scalarmul(int num,double **a)
{
	int temp;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<1;j++)
		{
			temp=a[i][j];
			a[i][j]=num*temp;
		}
	}
	
}

double **createMat(int m,int n) 
{ 
 int i; 
 double **a; 
  
 //Allocate memory to the pointer 
a = (double **)malloc(m * sizeof( *a)); 
    for (i=0; i<m; i++) 
         a[i] = (double *)malloc(n * sizeof( *a[i])); 
 
 return a;
}

void save(double **a, int rows, int cols) { 
	FILE *fp;
	fp = fopen("result.dat", "w"); 
	int i, j;  
	for (i = 0; i < rows; i++) {
    	    for (j = 0; j < cols; j++) {
      		fprintf(fp, "%lf", a[i][j]);      
    }    
	fprintf(fp, "\n");
	}
    fclose(fp);
}
