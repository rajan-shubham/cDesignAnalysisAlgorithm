#include <stdio.h>
#include <stdlib.h>

void Bubble(float arr[], int n);
void Selection(float arr[], int n);
void Print_Sorted_Array(float arr[], int n);

void Bubble(float arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                float temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            } 
        }
        if (flag == 0)
            break;
    }
    Print_Sorted_Array(arr, n);    
}

void Selection(float arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min_index = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        if (i != min_index)
        {
            int temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp;
        }
    }
    Print_Sorted_Array(arr, n);
}

void Print_Sorted_Array(float arr[], int n)
{
    printf("Sorted array in Ascending order: ");
    for (int i = 0; i < n; i++) 
        printf("%.2f ", arr[i]);
        
    printf("\n");
}

int main() 
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    float arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);
        
    int choice = 0;  
    while (choice != 3)   
    {
        printf("\nChoose from the menu : \n1. Bubble Sort\n2. Selection Sort\n3. Exit.\n");
        printf("Enter Your Choice - ");
        scanf("%d", &choice);  
        switch(choice)  
        {  
            case 1:  
                Bubble(arr, n);      
                break;  
            case 2:  
                Selection(arr, n);         
                break;  
            case 3:
                printf("\nProgram Ended.\n");
            exit(0);
            break;  
            default:  
            printf("Please Enter Valid Choice...\n");  
        }
    }
}  