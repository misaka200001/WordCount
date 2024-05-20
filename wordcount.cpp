#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_characters(FILE *file) {
    int count = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        count++;
    }

    return count;
}

int count_words(FILE *file) {
    int count = 0;
    char buffer[1000];

    while (fscanf(file, "%s", buffer) == 1) {
        count++;
    }

    return count;
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *parameter = argv[1];
    char *file_name;

    if (argc == 2) {
        file_name = "input.txt"; // 默认文件名为 input.txt
    } else {
        file_name = argv[2];
    }

    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int count;
    if (strcmp(parameter, "-c") == 0) {
        count = count_characters(file);
        printf("字符数：%d\n", count);
    } else if (strcmp(parameter, "-w") == 0) {
        count = count_words(file);
        printf("单词数：%d\n", count);
    } else {
        printf("Invalid parameter. Please use '-c' or '-w'.\n");
        return 1;
    }

    fclose(file);
    return 0;
}
