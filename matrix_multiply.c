#include <stdio.h>



// void put_in_place(int rows, int cols, )
int main(void)
{
	int m,n,p,i,j,k,sum;
	
	//getting all dimension values from user
	printf("For A, how many rows?\n");
	scanf("%d", &m);
	printf("How many columns?\n");
	scanf("%d", &n);
	printf("For B, how many columns?\n");
	scanf("%d", &p);
	
	//printing the values that scanf got from user 
	printf("%d%d%d\n", m, n, p);
	
	double A[m][n], B[n][p], C[m][p];
    
    printf("Enter all values in row order, starting with Matrix A\n");

				//Putting values in A
    for(i=0; i<m; i++)
    	for(j=0; j<n; j++)
	scanf("%lf", &A[i][j]);
	
	
    				//printing all values of A
    for(i=0; i<m; i++)
    	for(j=0; j<n; j++)
			printf("%lf\n", A[i][j]);
				
			printf("Please enter values for B in row order\n");	
				//Putting values in B

    for(i=0; i<n; i++)
    	for(j=0; j<p; j++)
			scanf("%lf", &B[i][j]);
			
				//printing all values of B
	for(i=0; i<n; i++)
    	for(j=0; j<p; j++)
			printf("%lf\n", B[i][j]);
				
//matrix multiplication
	 for(i=0; i<m; i++)
	 	for(j=0; j<p; j++)
	 	{
	 	 	sum=0;
	 	 	for(k=0; k<n; k++)
	 	 		sum+=A[i][k]*B[k][j];
	 	 	
	 	 	C[i][j]=sum;
	 	 }

  for(i=0; i<m; i++)
    {
    	printf("\n");
    	
    	for(j=0; j<p; j++)
    		printf("%lf ", C[i][j]);
    }

    	printf("\n");
}

