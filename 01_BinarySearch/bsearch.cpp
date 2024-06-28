#include <stdio.h>
#include <iostream>
#include <vector>

int rand_array[13] = {1,2,3,5,8,9,10,20,30,103,204,1002,39992};
std::vector<int> rand_vect = {1,2,3,5,8,9,10,20,30,103,204,1002,39992};

int binary_search(int target, int arr[], int arr_size){
  int low = 0;
  int high = arr_size-1;
  int mid = arr_size / 2;

  while (low<=high){
    mid = (low + high) / 2;

    if(arr[mid]==target){
      return mid;
    } else if (target < arr[mid]){
      high = mid-1;
    } else {
      low = mid+1;
    }
  }
  return -1;
}

int binary_search(int target, std::vector<int> arr){
  int low = 0;
  int high = arr.size();
  int mid;

  while (low<=high){
    mid = (low+high)/2;
    if (arr[mid]==target){
      return mid;
    }
    else if (arr[mid]>target){
      high = mid-1;
    } else {
      low = mid+1;
    }
  }
  return -1;
}

int recursive_binary_search(int target, int arr[], int low, int high){
  if (low<=high) {
    int mid = (low + high)/2;
    if (arr[mid]==target){
      return mid;
    } else if (target < arr[mid]){
      return recursive_binary_search(target, arr, low, mid-1);
    } else {
      return recursive_binary_search(target, arr, mid+1, high);
    }
  } else {
    return -1;
  }
}

int recursive_binary_search(int target, std::vector<int> arr, int low, int high){
  int mid = (low + high)/2;

  if (low>high){
    return -1;
  } else {
    if (arr[mid]==target){
      return mid;
    } else if (arr[mid]>target){
      return recursive_binary_search(target, arr, low, mid-1);
    } else {
      return recursive_binary_search(target, arr, mid+1, high);
    }
  }
}

int main(){
  int target;
  std::cout << "What would you like to find?: ";
  std::cin >> target;
  //int size = sizeof(rand_array)/sizeof(rand_array[0]);
  //int index = recursive_binary_search(target, rand_array, 0, size);
  //int index = binary_search(target, rand_vect);
  int index = recursive_binary_search(target, rand_vect, 0, rand_vect.size());
  if(index==-1){
    printf("The target was not found in the array.\n");
  } else {
    printf("The target %d was found at index %d.\n", target, index);
  }
  return 0;
}
