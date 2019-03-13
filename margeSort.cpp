#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

/*
*  __margeSort�Ƿֽ� 
*  __marge �Ǻϲ� 
*  margeSort�Ǹ��û��Ľӿ� 
*/ 
void __marge(int arr[],int l,int mid,int r){
//������ʱ���������ݣ� 
	int tmp[r-l+1];
	for(int i = l;i <=r;i++){
		tmp[i-l] = arr[i];
	}
//���м俪ʼ ���ұȽϽ�С�ķŻ�ԭ���� 
	int a=l,b=mid+1;
	for(int i = l;i <= r;i++){
//��Ӧ��Ԫ�ظ�����ͬ����� 
		if(a>mid){
			arr[i] =tmp[b-l];
			b++;
		}else if(b>r){
			arr[i]= tmp[a-l];
			a++;
		}
//���м俪ʼ ���ұȽϽ�С�ķŻ�ԭ���� 
		else if (tmp[a-l] <tmp[b-l]){ //���Խ� <���� >�� 
			arr[i] = tmp[a-l];
			a++;
		}else{
			arr[i] = tmp[b-l];
			b++;
		}
	}
}


void __margeSort(int arr[],int l, int r){
//0 �� 1 ��Ԫ��˵���Ѿ��ֵ���С�ˣ�ֱ��return 
	if (l >= r) return;
//Ѱ���м����������ٴλ��֣�  Ҳ��дΪmid= (l+r+1) /2 ����������Ԫ��ʱ���ұ߻����߶�һ���� �������������ֶ� 
	int mid = (l + r) / 2;
//�ٴλ��� 
	__margeSort(arr,l,mid);
	__margeSort(arr,mid+1,r);
//�ϲ����� 
	__marge(arr,l,mid,r);
}

//�����ڲ������ݹ���й鲢���� 
void margeSort(int arr[], int n){
	__margeSort(arr,0,n-1); //nΪ��������0��ʼ 
}


int main(){
	int arr[] = {9,8,7,6,5,4,3,2,1,0,99,88,77,66,55,44,33,22,11,10};
	//����һ�����飬 ���� 20 �� 
	margeSort(arr,20);
	
	for(int i = 0;i<20;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}

