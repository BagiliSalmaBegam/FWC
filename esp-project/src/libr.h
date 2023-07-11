double **linalg_sub(double **a, double **b, int m, int n);
void scalarmul(int num,double **a);
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


double **load_ser(AsyncWebServerRequest *request,const char* matrix1[2])
{
	double **a;
	int m=2,n=1;
	a = createMat(m,n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=request->getParam(matrix1[i])->value().toDouble();
		}
	}
	return a;
}

