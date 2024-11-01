#include <stdio.h>

int binarySearch(int arr[], int target) {
    int left = 0, right = 10;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return mid; 
        } else if (arr[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }

    return -1; 
}

int main() {
    int size, target, array[11],  position, i,ex;
	
	
    printf("Enter the 11 sorted array elements:\n");
    for ( i = 0; i < 11; i++) {
        scanf("%d", &array[i]);
    }
    while(1){
    printf("Enter the value to search for: ");
    scanf("%d", &target);

    position = binarySearch(array, target);

    if (position != -1)
	 {
        printf("Element %d found at position %d in the array.\n", target, position);
     }
	 else
	  {
        printf("Element %d not found in the array.\n", target);
    }
	printf("To exit enter 1:");
	scanf("%d",&ex);
	if(ex==1){
	break;
	}
}
    return 0;
}

