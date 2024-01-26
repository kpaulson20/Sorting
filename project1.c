#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int A[], int n);
void countSort(int A[], int n);
void printArray(int A[], int n);
void generateInFile(int n);

int main()
{
    /*1. Call generateInFile function to generate integer random numbers and store them in a text file*/
    generateInFile();

    /*2. Copy the numbers from the file to an array A1 and another array A2 (A1=A2). Use dynamic allocation to declare A1 and A2*/
    int numbers = 0;
    int temp;
    while (fscanf("A1.txt", "%d", &temp) == 1)
    {
        numbers++;
    }
    
    int* A1 = (int*)malloc(numbers * sizeof(int));
    int* A2 = (int*)malloc(numbers * sizeof(int));

    for (int i = 0; i < numbers; i++) 
    {
        A2[i] = A1[i];
    }
    /*3. Define two variables start1 and end1 of type clock_t.*/
    clock_t start1, end1;

    /*4. Keep the following code to measure the running time of the selection sort algorithm.*/

    start1 = clock();
    selectionSort(A, n);
    end1 = clock(); 
    time_spent1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    printf("Time taken by selectionSort algorithm is %f sec.\n",time_spent1);

    /*5. repeat steps 3. and 4. to measure the running time of the counting sort algorithm*/
    clock_t start2, end2;

    start2 = clock();
    countingSort(A, n);
    end2 = clock();
    time_spent2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    printf("Time taken by countingSort algorithm is %f sec.\n", time_spent2);
    return 0;

    /*Calling other functions*/
    selectionSort();
    countingSort();
    printArray();
} 

//selection sort function
void selectionSort(int A, int n) // n is the size of A
{
    //Implement selection sort algorithm here
    int i, j, lowest, temp;

    for (i = 0; i < n - 1; i++)
    {
        lowest = i;
        for (j = i+1; j < n - 1; j++)
        {
            if (A[j] < A[lowest])
            {
                lowest = j;
            }
        }
        temp = A[i];
        A[i] = A[lowest];
        A[lowest] = temp;
    }
}

//counting sort function
void countSort(int A[], int n) // n is the size of A
{
    int k, *B, *C;
    //Write a code to find the value of k (index) that is equal to the maximum value of A
    int max = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }

    B = (int*)malloc(n * sizeof(int)); //Dynamic allocation of two temporarily arrays B and C.
    C = (int*)malloc((k+1) * sizeof(int));

    //continue the implementation of the counting sort algorithm here.
    for (int i = 0; i <= max; i++)
    {
        C[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        C[A[i]]++;
    }
    for (int i = 0; i <= max; i++)
    {
        C[i] += C[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
    for (int i = 0; i < n; i++)
    {
        A[i] = B[i];
    }

    free(C);
    free(B);
}

//Function to print the content of an array
void printArray(int A[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

 //Function to generate n random integer numbers in the range 0 to RAND_MAX = 32767
 void generateInFile(int n)
 {
    int x;
    FILE *out;
    out = fopen("A1.txt", "r+");  
    fprintf(out, "%d\n", n);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        x = rand();
        fprintf(out, "%d ", x);
    }
    fclose(out);
 }
