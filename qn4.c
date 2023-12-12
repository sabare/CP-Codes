#include <stdio.h>
#include <math.h>

int main(void) {

  FILE *file;
  file = fopen("numbers.txt", "w");
  
  int A[10]={0,0,0,0,0,0,0,0,0,0};
  for(int j=0;j<10;j++){
      printf(A[j]);
      
    }
  srand(time(0));
  for(int i=0;i<3650;i++){
    for(int j=0;j<10;j++){
      A[j]+=rand()%5-2;
      
    }

    //printf(file, "day=%d ",i);
    //fprintf(file, "day=%d ",i);
    fprintf(file, "[");
  for(int j=0;j<10;j++){
    printf(" %d, ",A[j]);
    fprintf(file, "%d, ", A[j]);
  }

  printf("]\n ");
  fprintf(file, "],\n ");

  }
  return 0;
}