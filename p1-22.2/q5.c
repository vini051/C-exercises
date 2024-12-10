#include <stdio.h>

int ack(int m, int n){
    if (m == 0)
        return n+1;
    if (m > 0 && n == 0)
        return ack(m-1, 1);
    if (m > 0 && n > 0)
        return ack(m-1, ack(m, n-1));
}

int main(void){
    printf("%d\n", ack(2,3));
    return 0;
}


// ack(2,3) = ack(1, ack(2,2))
//                   ack(2,2) = ack(1, ack(2,1))
//                                     ack(2,1) = ack(1, ack(2,0))
//                                                       ack(2,0) = ack(1,1)
//                                                                  ack(1,1) = ack(0, ack(1,0))
//                                                                                    ack(1,0) = ack(0,1)
//                                                                                               ack(0,1) = 2
//                                                                             ack(0, 2) = 3
//                                                ack(1, 3) = ack(0, ack(1,2))
//                                                                   ack(1,2) = ack(0, ack(1,1))
//                                                                                     ack(1,1) = ack(0, ack(1,0))
//                                                                                                       ack(1,0) = ack(0,1)
//                                                                                                                  ack(0,1) = 2
//                                                                                                ack(0,2) = 3
//                                                                              ack(0,3) = 4
//                                                            ack(0,4) = 5
//                              ack(1,5) = ack(0, ack(1,4))
//eu cansei