#include <stdio.h>
#define SIZE 7


int getIndex(int in[],int post[],int s,int e) {
	int l =e;
	while(l > 0) {
		for(int i=s;i<=e;i++)
			if(in[i] == post[l]) return i;
		printf("[NotFound: %d %d %d]\n",s,e,post[l]);
		l--;
	}
	return -1;
}

void getPre(int in[],int post[],int s,int e) {
	int index = -1;
	if(s == e) {
		printf("%d\n",in[s]);
		return;
	}
	else if(s > e) return;
        index = getIndex(in,post,s,e);
	printf("Root -> %d\n",in[index]);
	getPre(in,post,s,index-1);
	getPre(in,post,index+1,e);
}

main() {
	int inorder[SIZE]={1,2,4,6,7,8,9};
	int postorder[SIZE]={1,2,6,7,9,8,4};
	getPre(inorder,postorder,0,SIZE-1);
	
}


