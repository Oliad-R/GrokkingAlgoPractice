#include <stdio.h>
#include <iostream>

int factorial(int n){
  if (n==1){
    return 1;
  }
  else {
    return n*factorial(n-1);
  }
}

int main(){
  int i = -1;
  while (i <= 0){
    std::cout << "What factorial would you like?\n";
    std::cin >> i;
    if (i < 0){
      std::cout << "Invalid input.\n";
    }
  }

  printf("RESULT: %d\n", factorial(i));
  return 0;
}
