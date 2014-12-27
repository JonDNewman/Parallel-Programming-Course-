#include "stdio.h"
#include "sys/types.h"
#include "sys/times.h"
#include "ulocks.h"
#include "sys/param.h"
#include <time.h>
#define N 800
int A[N][N], B[N][N], C[N][N];

int nprocs=8;
void slaveproc();
void populate_matrices();
int main(void)
{

int i, j;
for(i=0; i<N; i++)
 for(j=0; j<N; j++)
   A[i][j]=j;

for(i=0; i<N; i++)
 for(j=0; j<N; j++)
   B[i][j]=1;

 m_set_procs(nprocs);

 clock_t begin, end;
 begin=clock();
 m_fork(slaveproc);

 end=clock();
  printf("Time used: %f\n", (double)(end-begin)/CLOCKS_PER_SEC);
 m_kill_procs();


}

void slaveproc()
{
  int i, nproc, id, j;
  nproc = m_get_numprocs();
  id = m_get_myid();

  int step= N/nproc;

        for(i=id*step; i<(id+1)*step; i++)
          for(j=0; j<N; j++)
                C[i][j]=A[i][j]+B[i][j];

}


