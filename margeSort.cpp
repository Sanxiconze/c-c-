#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

/*
*  __margeSort是分解 
*  __marge 是合并 
*  __insertionSort是一个针对优化用的插入排序函数，当子集元素足够少时，使用插入排序会减少递归次数，效率会有所提升，
*  margeSort是给用户的接口 
*/ 


void __insertionSort(int arr[],int l, int r){
	//插入排序，在数组的指定区间内进行插入排序 
	for (int i = l+1;i <=r ;i++){
		int e = arr[i];
		int j;
		for(j = i; j > l&& arr[j-1]>e ; j--){
				arr[j] =arr[j-1];
		}
		arr[j]=e;		
	}
}



void __marge(int arr[],int l,int mid,int r){
//定义临时数组存放数据， 
	int tmp[r-l+1];
	for(int i = l;i <=r;i++){
		tmp[i-l] = arr[i];
	}
//从中间开始 左右比较将小的放回原数组 
	int a=l,b=mid+1;
	for(int i = l;i <= r;i++){
//对应到元素个数不同的情况 
		if(a>mid){
			arr[i] =tmp[b-l];
			b++;
		}else if(b>r){
			arr[i]= tmp[a-l];
			a++;
		}
//从中间开始 左右比较将小的放回原数组 
		else if (tmp[a-l] <tmp[b-l]){ //可以将 <换成 >号 
			arr[i] = tmp[a-l];
			a++;
		}else{
			arr[i] = tmp[b-l];
			b++;
		}
	}
}


void __margeSort(int arr[],int l, int r){
//0 或 1 个元素说明已经分到最小了，直接return 
	//if (l >= r) return;
	if(r-l<=5) //区间内只有五个元素后就 进行插入排序，减少递归次数 
	{
		__insertionSort(arr,l, r); 
		 return;
	 }
//寻找中间量，进行再次划分，  也可写为mid= (l+r+1) /2 这样奇数个元素时，右边会比左边多一个， 下面代码是左比又多 
	int mid = (l + r) / 2;
//再次划分 
	__margeSort(arr,l,mid);
	__margeSort(arr,mid+1,r);
//合并排序 
	if (arr[mid]>arr[mid+1])//填上此行会增加一次if判断，但对于有序的两个分集减少了再次排序的 操作，效率会增加一些 
		__marge(arr,l,mid,r);
}

//调用内部函数递归进行归并排序 
void margeSort(int arr[], int n){
	__margeSort(arr,0,n-1); //n为数量，从0开始 
}


int main(){
	int arr[] = {9,8,7,6,5,4,3,2,1,0,99,88,77,66,55,44,33,22,11,10};
	//生成一个数组， 长度 20 ； 
	margeSort(arr,20);
	
	for(int i = 0;i<20;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
