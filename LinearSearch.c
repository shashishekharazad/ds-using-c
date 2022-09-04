#include<stdio.h>
void main(){
	int arr[10];
	int i, n, k;
	printf("Enter size of array: ");
	scanf("%d", &n);
	
	printf("Enter array element: ");
	for(i =0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	
	printf("Enter a key to search: ");
	scanf("%d", &k);
	int flag = 0;
	for(i = 0; i < n; i++){
		if(k == arr[i]){
			flag = 1;
			break;
		}
		else{
			flag = 0;
		}
	}
	if(flag == 1)
		printf("Element found at %d position", i+1);
	else
		printf("Element not found!");
}
