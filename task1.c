#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char data[100];
    char filename[] = "sample.txt";

    // 1. Create and Write to the file
    fp = fopen(filename, "w"); // 'w' creates file if it doesn't exist or overwrites if it does
    if (fp == NULL) {
        printf("Error creating file.\n");
        return 1;
    }
    printf("Enter data to write to the file:\n");
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    fclose(fp);
    printf("Data written to file successfully.\n");

    // 2. Append to the file
    fp = fopen(filename, "a"); // 'a' opens file for appending
    if (fp == NULL) {
        printf("Error opening file for appending.\n");
        return 1;
    }
    printf("Enter data to append to the file:\n");
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    fclose(fp);
    printf("Data appended to file successfully.\n");

    // 3. Read from the file
    fp = fopen(filename, "r"); // 'r' opens file for reading
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }
    printf("Reading contents of the file:\n");
    while (fgets(data, sizeof(data), fp) != NULL) {
        printf("%s", data);
    }
    fclose(fp);

    return 0;
}
