#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printAbcpyramid(n);
    printnumpyramid(n);
    return 0;
}


void printAbcpyramid(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        char ch = 'A';
        for (int j = 0; j <= i; j++) {
            printf("%c ", ch+j);
            //ch++;
        }
        for (int j = i-1; j >= 0; j--) {
            printf("%c ", ch+j);
        }
        
        printf("\n");
    }
}

void printnumpyramid(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        int ch = 1;
        for (int j = 0; j <= i; j++) {
            printf("%d", ch+j);
            //ch++;
        }
        for (int j = i-1; j >= 0; j--) {
            printf("%d", ch+j);
        }
        
        printf("\n");
    }
}
