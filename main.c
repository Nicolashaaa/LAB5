#include <stdio.h>
#include <stdlib.h>
void DisplayMenu(){
printf("\n1. Dynamic memory allocation for two-dimensional arrays\n");
printf("2. Entering array elements from the keyboard\n");
printf("3. Filling the array with random values\n");
printf("4. Sorting table elements (according to variants)\n");
printf("5. Displaying table elements on screen\n");
printf("6. Releasing the memory allocated for the table\n");
printf("0. Exiting the program\n");
}



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

void basetask(int **brok, int rows,int columns){
int* a=(int*)malloc(columns*sizeof(int*));
int i,j;

for (i = 0; i < rows; i++) {
             for (j = 0; j < columns; j++) {
                  *(a+j)=*(*(brok+i)+j);  }
                  InsertionSort(a,columns);
               for (j = 0; j < columns; j++) {
                  *(*(brok+i)+j)=*(a+j);}
                  }free(a);

/*for (i = 0; i < rows; i++) {
             for (j = 0; j < columns; j++) {
                    printf("%5d",*(*(brok+i)+j));}printf("\n");}
                    free(a);
                    for(i=0; i<rows;i++){free(brok[i]);}
                    free(brok);*/
}

int main(){
    int size,i,j,min,max,sum,rows,columns,n,m,choice;
    int* d1;
int a=-13;
printpointers(a);
int b=21;
printf("a=%d and b=%d\n",a,b);
printf("Swap a and b\n");
swap(&a,&b);
printf("a=%d and b=%d\n",a,b);
printf("Write the size of the array: ");
scanf("%d",&size);
 d1=(int*)malloc(size*sizeof(int*));
        for (i = 0; i < size; i++) {
            /*scanf("%d", &*(d1+i));*/
            *(d1+i) = rand()%61-30;
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
int **bsk;
d2=(int**)malloc(rows*sizeof(int*));

for(i=0; i<rows;i++){
    d2[i]=(int*)malloc(columns*sizeof(int*));
}
 for (i = 0; i < rows; i++) {
             for (j = 0; j < columns; j++) {
                *(*(d2+i)+j) = rand()%61-30;

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

while (choice!=0){
        DisplayMenu();
        printf("Pick an option to choose: ");
        scanf("%d",&choice);
switch(choice){
case 1:
    printf("\nEnter amount of rows and columns: ");
scanf("%d %d",&n,&m);
bsk=(int**)malloc(n*sizeof(int*));
for(i=0; i<n;i++){
    bsk[i]=(int*)malloc(m*sizeof(int*));
}
    break;
case 2:

    for (i = 0; i < n; i++) {
             for (j = 0; j < m; j++) {
                    scanf("%d", &*(*(bsk+i)+j));}}
    break;
case 3:

     for (i = 0; i < n; i++) {
             for (j = 0; j < m; j++) {
                *(*(bsk+i)+j) = rand()%61-30;}}


    break;
case 4:

    basetask(bsk,n,m);
    break;
case 5:

    for (i = 0; i < n; i++) {
             for (j = 0; j < m; j++) {
                    printf("%5d",*(*(bsk+i)+j));}printf("\n");}
    break;
case 6:

    for(i=0; i<n;i++){free(bsk[i]);}
                    free(bsk);
    break;
case 0:
    break;

}}
basetask(d2,rows,columns);
 for (i = 0; i < rows; i++) {free(d2[i]);
 }
free(d2);
free(d1);
return 0;
}

