#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
    q0, q1, q2, q3, q4, q5, q6, q7, q8, q9 
} State;

State delta[256][256]; 

void initial_delta(const char *T) {
    int n = strlen(T);  
    int i, j;
    
   
    for (i = 0; i < n + 1; i++) {
        for (j = 0; j < 256; j++) {
            delta[i][j] = q0; 
        }
    }

   
    for (i = 0; i < n; i++) {
        delta[i][(unsigned char) T[i]] = i + 1;
    }


    delta[n][(unsigned char) T[n - 1]] = n;
}


int match(const char *S, const char *T) {
    int state = q0;
    int i, length = strlen(S);
    int n = strlen(T);


    for (i = 0; i < length; i++) {
        state = delta[state][(unsigned char) S[i]];
        
        
        if (state == n) 
            return i - n + 1; 
        
    }
    return -1; 
}

int main() {
    char st[1000], T[1000];
    printf("Nhap chuoi dau vao S: ");
    scanf("%s", st);
    printf("Nhap chuoi can tim T: ");
    scanf("%s", T);
    
    printf("Chuoi S da nhap: %s\n", st);
    printf("Chuoi T da nhap: %s\n", T);
    
    initial_delta(T);  
    
    int position = match(st, T);
    
    if (position != -1) {
        printf("Vi tri xuat hien cua chuoi '%s' trong chuoi '%s': %d\n", T, st, position);
    } else {
        printf("Khong co chuoi '%s' trong chuoi '%s'.\n", T, st);
    }
    
    return 0;
}

