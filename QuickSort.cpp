
#include<bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void insertSort(int arr[], int l,int r){
//采用插入排序来对快排底层优化 
	for (int i = l+1;i<=r;i++){
		int e = arr[i];
		int j;
		for(j = i;j>l && arr[j-1]>e;j--){
			arr[j]=arr[j-1];
		}
		arr[j] = e;
	}
}

int __partition(int arr[],int l,int r){
	//这里采用 i , j两个坐标移动，将=e的元素分到左右两个结合中，减少递归次数。
	//(nlogn) 
	int e = arr[l];
	int i = l+1;
	int j = r;
	while(true){
		while(arr[i]<e)i++;
		while(arr[j]>e)j--;
		if(i>=j)break;
		
		swap(arr[i],arr[j]);
		i++;
		j--;
	}
	swap(arr[l],arr[j]);
	
	return j;
}
void __quickSort(int arr[], int l,int r){
	if (r-l<5){	//当子集合元素足够少时 采用插入排序来提升效率 
		insertSort(arr,l,r);
		return;
	}
	//if(l>=r)return;
	int p = __partition(arr,l,r);
	__quickSort(arr,l,p);
	__quickSort(arr,p+1,r);
}

void quickSort(int arr[], int n){
	__quickSort(arr,0,n-1);
}

int main(int argc, char *argv[]) {
	int arr[] = {9,8,7,6,5,4,3,2,1,0,99,88,77,66,55,44,33,22,11,10};
	//生成一个数组， 长度 20 ； 
	//margeSort(arr,20);
	quickSort(arr,20);
	
	for(int i = 0;i<20;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
