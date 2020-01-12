#include <stdio.h>
#include <algorithm>

void update(int *a,int *b) {
    // Complete this function   
     int temp = std::abs(*a - *b);
    *a = *a + *b;
    *b = temp;
   
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
