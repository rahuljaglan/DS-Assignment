                                                                            /*    By RAHUL JAGLAN    */

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void merge(char arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l+1; 
    int n2 =  r - m; 
  
    char L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
   
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            k++;
            i++;
            // printf("\n%s",arr);
        } 
        else
        { 
            arr[k] = R[j];
            k++;
            j++; 
            //  printf("\n%s",arr);
        }          
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i];
        k++;
        i++; 
        //  printf("\n%s",arr);
    } 

    while (j < n2) 
    { 
        arr[k] = R[j];
        k++;
        j++; 
        // printf("\n%s",arr);         
    } 
} 
  
void mergeSort(char arr[], int l, int r) 
{ 
    if (l < r) 
    {
        int m = (r+l)/2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
    return;
}

void main()
{
    printf("\n(2). sorting strings using mergesort\n");

    char s1[]="Polynomial";
    int n=10;
    
    printf("\n(a) Initially string is : \"");
    for(int i=0;i<n;i++)
    printf("%c",s1[i]);
    printf("\"");
    
    mergeSort(s1,0,n-1);         //merge sort

    printf("\n    Sorted string is : \"");
    for(int i=0;i<n;i++)
    printf("%c",s1[i]);
    printf("\"");

    char s2[]="Test case";
    int n2=9;

    printf("\n(b) Initially string is : \"");
    for(int i=0;i<n2;i++)
    printf("%c",s2[i]);
    printf("\"");
    
    mergeSort(s2,0,n2-1);

    printf("\n    Sorted string is : \"");
    for(int i=0;i<n2;i++)
    printf("%c",s2[i]);
    printf("\"");

    
}