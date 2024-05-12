#include <stdio.h>
#include <stdlib.h>

void Merge(float a[], int p, int r);
void Insertion(float a[], int n);
void Print_Sorted_Array(float a[], int n);

void Insertion(float a[], int n)  
{   
    int i, j;
    for (j = 1; j < n; j++) 
    {
        float key = a[j];
        int i = j - 1;
        while (i >= 0 && a[i] > key) 
        {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }
    Print_Sorted_Array(a, n);
}


void merge_sort(float a[], int p, int q, int r) 
{
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    float L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = a[p + i];
    for (j = 0; j < n2; j++)
        R[j] = a[q + 1 + j];
        
    i = 0;
    j = 0;
    
    for (k = p; k <= r; k++)
    {
        if (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                a[k] = L[i];
                i = i + 1;
            }
            else
            {
                a[k] = R[j];
                j = j + 1;
            } 
        }
        else if (i < n1)
        {
            a[k] = L[i];
            i++;
        }
        else if (j < n2)
        {
            a[k] = R[j];
            j++;
        }
    }      	 
}   
   	    
void Merge(float a[], int p, int r) 
{
    if (p < r) 
    {
        int q = (p + r) / 2;

        Merge(a, p, q);
        Merge(a, q + 1, r);

        merge_sort(a, p, q, r);
    }
}

void Print_Sorted_Array(float a[], int n)
{
    printf("Sorted Array in Ascending order: ");
    for (int i = 0; i < n; i++) 
        printf("%.2f ", a[i]);
        
    printf("\n");
}

int main() 
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    float a[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%f", &a[i]);
        
    int choice = 0;  
    while (choice != 3)   
    {
        printf("\nChoose from the menu : \n1. Insertion Sort\n2. Merge Sort\n3. Exit.\n");
        printf("Enter Your Choice - ");
        scanf("%d", &choice);  
        switch(choice)  
        {  
            case 1:  
                Insertion(a, n);      
                break;  
            case 2:  
                Merge(a, 0, n-1);
                Print_Sorted_Array(a, n);         
                break;  
            case 3:
                printf("\nProgram Ended.\n");
                exit(0);
                break;  
            default:  
                printf("Please Enter Valid Choice!\n");  
        }
    }
}