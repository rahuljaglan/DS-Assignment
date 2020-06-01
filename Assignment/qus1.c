                                                                       /*   By RAHUL JAGLAN   */
#include<stdio.h>

/*for selection sort*/
void ssort(int* a, int n)       
{
    for(int i=0;i<n;i++)
    {
        int p=i;
        int m=a[i];

        for(int j=i+1;j<n;j++)
        {
            if(a[j]<m)
            {
                m=a[j];
                p=j;                
            }
        }

        int t=a[i];                 
        a[i]=a[p];
        a[p]=t;
    }
}

int partition (int *a, int l, int h) 
{ 
    int pivot = a[h];   
    int i = (l - 1);   
  
    for (int j = l; j <= h- 1; j++) 
    { 
                                    
        if (a[j] < pivot) 
        { 
            i++;                   
            int t=a[i];
            a[i]=a[j];
            a[j]=a[i];   
        }   
    } 
    int t=a[i+1];
    a[i + 1]=a[h];
    a[h]=t;

    return (i + 1); 

} 
  
/*function that implements QuickSort 
 a[] --> Array to be sorted, 
  l  --> Starting index, 
  h  --> Ending index */

void qsort(int* a, int l, int h) 
{ 
    if (l < h) 
    { 

        int pi = partition(a, l, h);     
        
        qsort(a, l, pi - 1); 
        qsort(a, pi + 1, h); 
    } 
} 
 /*for insertion sort*/
void isort(int *a,int n)
{
    int i,j,t;

    for(i=0;i<n;i++)
    {
        t=a[i];
	    j=i-1;

	    while(j>=0 && a[j]>t) 
        {
            a[j+1]=a[j];
            j--;
        }
	    a[j+1]=t;
    }
}

/*to merge the two sorted arrays*/
void merge(int*a , int l, int m, int r)     
{ 

    int i, j, k; 

    int n1 = m - l + 1; 
    int n2 =  r - m; 
   
    int L[n1], R[n2]; 
   
    for (i = 0; i < n1; i++) 
        L[i] = a[l + i]; 

    for (j = 0; j < n2; j++) 
        R[j] = a[m + 1+ j]; 
  
           

    i = 0;

    j = 0;
    
    k = l;                 
    
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            a[k++] = L[i++];  
        } 
        else
        { 
            a[k++] = R[j++];    
        } 
    }  
    while (i < n1) 
    { 
        a[k++] = L[i++]; 

    }  
    while (j < n2) 
    { 
        a[k++] = R[j++];   
    } 
} 

/*for merge sort*/
void msort(int *a, int l, int r)        
{ 
    if (l < r) 
    {        
        int m = l+(r-l)/2; 
  
        msort(a, l, m); 
        msort(a, m+1, r); 
  
        merge(a, l, m, r); 
    } 
}

void printarr(int* a,int n)    
{
    printf("\n The sorted array is: ");

    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}

void main()
{
    
    printf("\n enter the size of the integer array");
    int n;
                           
    scanf("%d",&n);
   
    printf("\n enter the elements of the array");
    int a[n]; 
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    
    printf("\n Initially the array is: ");

    for(int i=0;i<n;i++)                
    printf("%d ",a[i]);
    
    int wish;                   
    
    printf("\n enter \n 1: quick sort\n 2:selection sort \n 3:merge sort\n 4:insertion sort \n-1:exit");
    scanf("%d",&wish);
    
    while(wish!=-1)
    {
        switch(wish)
        {
            case 1: {                  //quick sort
                        qsort(a,0,n);
                        printarr(a,n);              
                        break;
                    }   
            case 2:{                  //selection sort
                ssort(a,n);                         
                printarr(a,n);
                break;
            }
            case 3:{                  //merge sort
                msort(a,0,n-1);                     
                printarr(a,n);
                break;
            }
            case 4:{                 //insertion sort
                isort(a,n);                         
                printarr(a,n);
                break;                
            }
            default: printf("\n Invalid Choice");
        }
        
        printf("\n enter \n 1: quick sort\n 2:bubble sort \n 3:merge sort\n 4:insertion sort \n-1:exit");
        scanf("%d",&wish);

    }

}