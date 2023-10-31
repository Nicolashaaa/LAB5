#include <stdio.h>
#include <stdlib.h>
void printpointers(int a){
int *point=&a;
printf("Printed value via pointers: %d\n",*point);
}
void InsertionSort(int a[ ], int n) {
int i, j, value;
for(i = 1; i < n; i++) {
value = a[i];
for (j = i - 1; (j >= 0) && (value< a[j]); j--) {
a[j + 1] = a[j];
}
a[j+1] = value;
}
}

void swap(int *a,int*b){
int temp=*a;
*a=*b;
*b=temp;}

void easy1(int *array, int size, int *min, int *max){
 int i;

  if (size<=0){
    *min=0;
    *max=0;
  return;}
*min=*max=array[0];
  for(i=1; i<size; i++){
        if(array[i]>*max){*max=array[i];}
    }
    for(i=1; i<size; i++){
        if(array[i]<*min){*min=array[i];}
    }


}

void easy2(int *array, int size, int *sum){
int i;
   *sum=0;
  if (size<=0){return;}
  for(i=0; i<size; i++){
    if(array[i]<0){*sum=*sum+array[i];}
  }

}
void easy3(int *array, int size){
int i; int n=size;
   if (size<=0){return;}
   for(i=0; i<(size/2);i++)
      {
        swap(&array[i],&array[n-1]);
        n--;
      }

}
void easy4(int **array, int rows,int columns){
int** brok=(int **)malloc(columns*sizeof(int*));
int i,j;
for(i=0; i<columns;i++){
    brok[i]=(int*)malloc(rows*sizeof(int*));

}
for (i = 0; i < rows; i++) {
             for (j = 0; j < columns; j++) {
                    brok[j][i]=array[i][j];}}

             for (i = 0; i < columns; i++) {
             for (j = 0; j < rows; j++){
                printf("%5d",*(*(brok+i)+j));
             }printf("\n");}

             for (i = 0; i < columns; i++) {free(brok[i]);}
             free(brok);
}

void basetask(int **array, int rows,int columns){
int** brok=(int **)malloc(rows*sizeof(int*));
int* a=(int*)malloc(columns*sizeof(int*));
int i,j;
for(i=0; i<rows;i++){
    brok[i]=(int*)malloc(columns*sizeof(int*));

}
for (i = 0; i < rows; i++) {
             for (j = 0; j < columns; j++) {
                    brok[i][j]=array[i][j];}}
for (i = 0; i < rows; i++) {
             for (j = 0; j < columns; j++) {
                  *(a+j)=*(*(brok+i)+j);  }
                  InsertionSort(a,columns);
               for (j = 0; j < columns; j++) {
                  *(*(brok+i)+j)=*(a+j);}
                  }

for (i = 0; i < rows; i++) {
             for (j = 0; j < columns; j++) {
                    printf("%5d",*(*(brok+i)+j));}printf("\n");}
                    free(a);
                    for(i=0; i<rows;i++){free(brok[i]);}
                    free(brok);
}

int main(){
    int size,i,j,min,max,sum,rows,columns;
    int* d1;
int a=6;
printpointers(a);
int b=8;
printf("a=%d and b=%d\n",a,b);
printf("Swap a and b\n");
swap(&a,&b);
printf("a=%d and b=%d\n",a,b);
printf("Write the size of the array: ");
scanf("%d",&size);
 d1=(int*)malloc(size*sizeof(int*));
        for (i = 0; i < size; i++) {
            scanf("%d", &*(d1+i));
           /* *(d1+i) = rand()%61-30;*/
        }
    printf("The elements of the array are: ");
        for (i = 0; i < size; i++) {
            printf("%d ", *(d1+i));
        }
easy1(d1,size,&min,&max);
printf ("\nMinimum value: %d\n",min);
printf ("Maximum value: %d\n",max);
easy2(d1,size,&sum);
printf("Sum of all negative numbers: %d",sum);
easy3(d1,size);
 printf("\nThe elements of the reversed array: ");
        for (i = 0; i < size; i++) {
            printf("%d ", *(d1+i));
        }
printf("\nEnter amount of rows and columns: ");
scanf("%d %d",&rows,&columns);
int **d2;
d2=(int**)malloc(rows*sizeof(int*));

for(i=0; i<rows;i++){
    d2[i]=(int*)malloc(columns*sizeof(int*));
}
 for (i = 0; i < rows; i++) {
             for (j = 0; j < columns; j++) {
                    scanf("%d", &*(*(d2+i)+j));
               /* *(*(d2+i)+j) = rand()%61-30;*/

        }
        }
        printf("\n Generated array: \n");
        for (i = 0; i < rows; i++) {
             for (j = 0; j < columns; j++){
                printf("%5d",*(*(d2+i)+j));
             }
        printf("\n");
        }
        printf("\n");printf("\n");
        printf("\n Transposed array: \n");
easy4(d2,rows, columns);

printf("\n");printf("\n");

printf("\n Sorted ascendant by rows array: \n");
basetask(d2,rows,columns);
 for (i = 0; i < rows; i++) {free(d2[i]);
 }
free(d2);
free(d1);
return 0;
}

