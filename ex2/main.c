#include <stdio.h>

int main() {
    int a[] = {0, 1, 2};
    char b[] = "A B C";
    float c[] = {1.1, 1.2, 1.3};
    FILE *file;

    file = fopen("a.bin", "wb+");
    if (file == NULL) {
        printf("無法開啟檔案\n");
        return 1;
    }

    
    fwrite(a, sizeof(int), sizeof(a)/sizeof(int), file);
    fwrite(b, sizeof(char), sizeof(b), file);
    fwrite(c, sizeof(float), sizeof(c)/sizeof(float), file);

    
    fclose(file);

    file = fopen("a.bin", "rb");
    if (file == NULL) {
        printf("無法開啟檔案。\n");
        return 1;
    }

    
    int readInt[3];
    char readChar[4];
    float readFloat[3];


    fread(readInt, sizeof(int), 3, file);
    fread(readChar, sizeof(char), 5, file);
    fread(readFloat, sizeof(float), 3, file);
    fclose(file);

    
    for (int i = 0; i < 3; i++) {
        printf("%d ", readInt[i]);
    }
    printf("\n");

   
    printf("%s\n", readChar);

    
    for (int i = 0; i < 3; i++) {
        printf("%f ", readFloat[i]);
    }
    printf("\n");

    return 0;
}
