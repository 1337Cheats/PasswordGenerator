#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* generate_password(int length, const char* output_file) {
    printf("Password Generator written in C\nArguments -l or --length - specifies the length of the password. -o or --output - specifies the file the password is written to.\n");
    
    const char* characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    int num_characters = strlen(characters);
    
    char* password = malloc((length + 1) * sizeof(char));
    srand(time(NULL));
    
    for (int i = 0; i < length; i++) {
        password[i] = characters[rand() % num_characters];
    }
    password[length] = '\0';
    
    if (output_file) {
        FILE* file = fopen(output_file, "w");
        if (file) {
            fprintf(file, "%s\n", password);
            fclose(file);
        }
    }
    
    return password;
}

int main(int argc, char* argv[]) {
    int length = 12;
    const char* output_file = NULL;
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--length") == 0) {
            if (i + 1 < argc) {
                length = atoi(argv[i + 1]);
            }
        } else if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--output") == 0) {
            if (i + 1 < argc) {
                output_file = argv[i + 1];
            }
        }
    }
    
    char* password = generate_password(length, output_file);
    printf("%s\n", password);
    free(password);
    
    return 0;
}
