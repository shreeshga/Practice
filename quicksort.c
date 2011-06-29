#include <stdio.h>
#define SIZE 10


void quicksort(int a[],int s,int e) {
	int key,l=s,k=e;
	key = a[(l + k) /2];
	while(l <=  k) {	
		while(a[l] < key ) l++;
		while(a[k] > key) k--;
		if( l <= k) {
			int temp = a[k];
			a[k] = a[l];
			a[l] = temp;
			l++,k--;
		}
	}
	if(s < k)
		quicksort(a,s,k);
	if(l < e)
		quicksort(a,l,e);	

}

main () {
	int array[SIZE]= {5,3,3,5,2,2,8,9,6,5};;
	//for(int i=0;i<SIZE;i++)
///		scanf("%d",&array[i]);

	quicksort(array,0,SIZE-1);
	
	for(int i=0;i<SIZE;i++)
		printf("%d,",array[i]);
	printf("\n");	
}
