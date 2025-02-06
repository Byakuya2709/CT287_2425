#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
    q0, q1, q2, q3, q4
} State;

State delta[5][256]; // B?ng chuy?n tr?ng thái

// Hàm kh?i t?o b?ng chuy?n tr?ng thái delta
void initialize_delta() {
    int i;
    for (i = 0; i < 5; i++) {
    	int j;
        for (j = 0; j < 256; j++) {
            delta[i][j] = q0; // M?c d?nh chuy?n v? tr?ng thái q0
        }
    }

    // Các quy t?c chuy?n tr?ng thái d?a trên b?ng ??
    delta[q0]['a'] = q1;
    delta[q0]['b'] = q0;
    delta[q0]['c'] = q0;
    delta[q0]['d'] = q0;

    delta[q1]['a'] = q0;
    delta[q1]['b'] = q2;
    delta[q1]['c'] = q0;
    delta[q1]['d'] = q0;

    delta[q2]['a'] = q0;
    delta[q2]['b'] = q0;
    delta[q2]['c'] = q3;
    delta[q2]['d'] = q0;

    delta[q3]['a'] = q0;
    delta[q3]['b'] = q0;
    delta[q3]['c'] = q0;
    delta[q3]['d'] = q4;

    delta[q4]['a'] = q4;
    delta[q4]['b'] = q4;
    delta[q4]['c'] = q4;
    delta[q4]['d'] = q4;
}


int match(const char *S) {
    State state = q0;
    int i;
    for (i = 0; i < strlen(S); i++) {
        state = delta[state][S[i]];
        if (state == q4) { 
            return i - 3; 
        }
    }
    return -1;
}

int main() {
    char st[1000];
    printf("Nhap chuoi dau vao: ");
    scanf("%s", st);
    
    printf("Chuoi da nhap: %s\n", st);
    
    initialize_delta(); 
    
    int position = match(st);
    
    if (position != -1) {
        printf("Vi tri xuat hien cua 'abcd' trong chuoi %s: %d\n",st, position);
    } else {
        printf("Khong co 'abcd' trong chuoi.\n");
    }
    
    return 0;
}

