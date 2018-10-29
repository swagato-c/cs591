#include <stdio.h>

int binserach(int* arr, int len, int k){
	int lo = 0, hi = len - 1;
	while (lo <= hi){
		int mid = lo + (hi - lo >> 1);
		if (arr[mid] < k)  lo = mid + 1;
		if (arr[mid] > k)  hi = mid - 1;
		if (arr[mid] == k) return mid + 1;
	}
	return -1;
}

int main(){
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int q = binserach(arr, (int)(sizeof(arr)/sizeof(arr[0])), 9);
	printf("%d\n", binserach(arr, (int)(sizeof(arr)/sizeof(arr[0])), 9));
	printf("%d\n", binserach(arr, (int)(sizeof(arr)/sizeof(arr[0])), 10));
	printf("%d\n", binserach(arr, (int)(sizeof(arr)/sizeof(arr[0])), 1));
	return 0;
}