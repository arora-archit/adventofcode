#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char **matrix = NULL;
    char buffer[1024];
    int rows = 0;
    while (fgets(buffer,sizeof(buffer),stdin)) {
        buffer[strcspn(buffer,"\n")] = '\0';
        matrix = realloc(matrix, sizeof(char*) * (rows + 1));
        if (!matrix) {
            perror("Failed to allocate memory");
            return 1;
        }
        matrix[rows] = malloc(strlen(buffer) + 1);
        if (!matrix[rows]) {
            perror("Failed to allocate memory");
            return 1;
        }
        strcpy(matrix[rows],buffer);
        rows++;
    }
    int result = 0;
    int directions[8][2] = {
          {-1, -1}, {-1, 0}, {-1, 1},
          { 0, -1},          { 0, 1},
          { 1, -1}, { 1, 0}, { 1, 1}
    };
    // Part 1
    for (int i=0;i<rows;i++){
        for (int j=0;j<strlen(matrix[i]);j++){
            if (matrix[i][j]=='@'){
                int count=0;
                for (int d=0;d<8;d++){
                    int ni=i+directions[d][0];
                    int nj=j+directions[d][1];
                    if (ni>=0 && ni<rows && nj>=0 && nj<strlen(matrix[ni]) && matrix[ni][nj]=='@'){
                        count++;
                    }
                }
                if (count < 4) {
                    result++;
                    matrix[i][j] = 'X';
                }
            }
        }
    }
    // Part 2

    int changed = 1;
    while (changed){
        changed = 0;
        for (int i=0;i<rows;i++){
            for (int j=0;j<strlen(matrix[i]);j++){
                if (matrix[i][j]=='@'){
                    int count=0;
                    for (int d=0;d<8;d++){
                        int ni=i+directions[d][0];
                        int nj=j+directions[d][1];
                        if (ni>=0 && ni<rows && nj>=0 && nj<strlen(matrix[ni]) && matrix[ni][nj]=='@'){
                            count++;
                        }
                    }
                    if (count < 4) {
                        result++;
                        matrix[i][j] = 'X';
                        changed = 1;
                    }
                }
            }
        }
    }


    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    printf("%d\n",result);
    return 0;
}