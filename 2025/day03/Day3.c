#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char line[1024];
    long long total = 0;
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;

        int n = strlen(line);
        int k = 12;
        char result[20];
        int pos = 0;

        int start = 0;

        while (k > 0) {
            int max_digit = -1;
            int max_index = -1;

            int END = n - k;

            for (int i = start; i <= END; i++) {
                int d = line[i] - '0';
                if (d > max_digit) {
                    max_digit = d;
                    max_index = i;
                }
            }

            result[pos++] = line[max_index];
            start = max_index + 1;
            k--;
        }

        result[pos] = '\0';
        total = total + strtoll(result,NULL,10);
    }
    printf("%lld",total);
}

