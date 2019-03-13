#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

void insertSort(int arr[],int n){
	for(int i=1;i<n;i++){
		int e = arr[i];
		int j;
//		for(j = i ;j>0;j--){
//			if (arr[j-1]>e){
//				arr[j]=arr[j-1];
//			}else{
//				break;
//			}
//		}
//两种写法都可以 
		for(j = i;j>0&&arr[j-1]>e;j--){
			arr[j]=arr[j-1];
		}
		arr[j]=e;
	}
}


int main(){
	int arr[] = {9,8,7,6,5,4,3,2,1,0,99,88,77,66,55,44,33,22,11,10};
	//生成一个数组， 长度 20 ； 
	//margeSort(arr,20);
	insertSort(arr,20);
	
	for(int i = 0;i<20;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}

