#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int  __partition(int arr[],int l,int r){
	//从左到右 
	// v为 中间量 
	//  l          j         i
	// 最左    <v  v  >v    当前   
	//
	
	int v = arr[l];
	int j = l;
	for (int i = l+1;i<=r;i++){
		if(arr[i]<v){
			swap(arr[j+1],arr[i]);
			j++;
		}
	}
	swap(arr[l],arr[j]);
	return j;
}
void __quickSort(int arr[],int l,int r){
	if (l>=r)return;
	//p是中间量，进行递归排序 
	int p = __partition(arr,l,r);
	__quickSort(arr,l,p);
	__quickSort(arr,p+1,r);
	
}

void quickSort(int arr[],int n){
	__quickSort(arr,0,n-1);
} 

int main(int argc, char *argv[]) {
	int arr[]={9,8,7,6,5,4,3,2,1,0,11,22,33,44,55,66,77,88,99,10};
	
	quickSort(arr,20);
	for(int i = 0;i<20;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
