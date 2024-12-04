#include <stdio.h>

int fibonacci(int n){
    int soma = 0;
    if(n == 0){ return 0; }
    if(n == 1){ return 1; }
    return soma += fibonacci(n-1);
}

//ex 5:
// ? brain has melted

int main(){

    return 0;
}