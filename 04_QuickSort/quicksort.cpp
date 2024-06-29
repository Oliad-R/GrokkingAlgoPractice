#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> rand_vect = {1,5,3,9,7,13,23,19};

void printVect(vector<int> arr){
  for (int i: arr){
    cout << i << endl;
  }
  cout << "----------------" << endl;
}

vector<int> subVect(vector<int>& arr, int start, int end){
  if (start < 0 || end <= start || end >= arr.size()){
    cout << "Invalid start or end index." << endl;
    return {};
  }

  int vec_size = end - start + 1;
  vector<int> sub_vect(vec_size);

  copy(arr.begin() + start, arr.begin() + end + 1, sub_vect.begin());
  
  return sub_vect;
}

vector<int> addVect(vector<vector<int>> a){
  vector<int> concat;
  for (vector<int> vec: a){
    for (int i: vec){
      concat.push_back(i);
    }
  }

  return concat;
}

vector<int> quickSort(vector<int> arr){
  vector<int> lower, upper;

  if (arr.size() < 2){
    return arr;
  } else {
    int pivot = arr[0];
    for (int i: arr){
      //cout << i << endl;
      if (i == pivot) {
        continue;
      } else if (i < pivot){
        lower.push_back(i);
      } else {
        upper.push_back(i);
      }
    }

    return addVect({quickSort(lower), {pivot}, quickSort(upper)});
  }
}


int main(){
  cout << "This is the unsorted array:" << endl;
  printVect(rand_vect);

  //cout << "This is a subarray from index 0-3" << endl;

  //printVect(subVect(rand_vect,0,3)); 

  cout << "This is the sorted vector:" << endl;

  printVect(quickSort(rand_vect));
  return 0;
}
