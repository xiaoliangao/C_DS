#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define MAX_SIZE 255

typedef struct {
    char str[MAX_SIZE];
    int len;
} SString;
//ƒ£ Ω¥Æ∆•≈‰À„∑®
int Index(SString S, SString T)
{
    int i = 0, j = 0;
    while (i < S.len && j < T.len) {
        if (S.str[i] == T.str[j]) {
            i++;
            j++;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == T.len) {
        return i - j;
    }
    else {
        return -1;
    }
}
    


int main()
{
    SString S, T;
    printf("Enter the string S: ");
    fgets(S.str, MAX_SIZE, stdin);
    S.len = strlen(S.str) - 1;
    printf("Enter the string T: ");
    fgets(T.str, MAX_SIZE, stdin);
    T.len = strlen(T.str) - 1;
    int index = Index(S, T);
    if (index == -1) {
        printf("No match found.\n");
    }
    else {
        printf("Match found at index %d.\n", index);
    }
    return 0;
}