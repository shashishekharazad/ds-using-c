#include<stdio.h>
void mergesort(int arr[10], int first, int last);
void merge(int arr[10], int first, int mid, int last);

void main(){
	int arr[10];
	int i, n;
	printf("Enter size of array: ");
	scanf("%d", &n);
	
	printf("\nEnter array elements: ");
	for(i =0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	mergesort(arr, 0, n-1);
	
	printf("\nSorted element: ");
	for(i =0; i < n; i++){
		printf("%d ", arr[i]);
	}
	
}

void mergesort(int arr[10], int first, int last){
	int mid;
	if(first<last){
		mid = (first+last)/2;
		mergesort(arr, first, mid);
		mergesort(arr, mid+1, last);
		
		merge(arr, first, mid, last);
	}
}

void merge(int arr[10], int first, int mid, int last){
	int a[10];
	int i, j, k;
	
	i = first;
	j = mid+1;
	k = first;
	
	while(i <= mid && j <= last){
		if(arr[i] <= arr[j]){
			a[k++] = arr[i++];
		}
		else{
			a[k++] = arr[j++];
		}
	}
	
	if(i > mid){
		while(j <= last){
			a[k++] = arr[j++];
		}
	}
	else{
		while(i <= mid){
			a[k++] = arr[i++];
		}
	}
	
	for(i = first; i <= last; i++){
		arr[i] = a[i];
	}
}
