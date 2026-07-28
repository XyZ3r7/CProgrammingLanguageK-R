#include <stdio.h>
int binsearch(int x, int a[], int n);

int main() {

}

int binsearch(int x, int a[], int n) {
    int low, high, mid;
    low = 0;
	high = n - 1;
	mid =(low + high) / 2;
	while (low <= high && x != a[mid]){
		if(x < a[mid])
			high = mid - 1;
		else
		 	low = mid + 1;
		mid = (low + high)/2;
	}
	if(a[mid] == x){
		return mid;
	}else{
		return -1;
	}
}
