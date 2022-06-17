#include<stdio.h>

void print_help() {
    printf("\n🚀  Usage: unbanwd <banned word>\n    For help: unbanwd --help\n\n✏️  e.g. 1: unbanwd ligma\n✏️  e.g. 2: unbanwd balls\n\n👋  Bye!\n");
}

//i write my own string length function 💪
unsigned int lenstr(char *str) {
    int size = 0;
    while (str[size] != '\0') size++;
    return(size);
}

//i write my own string compare function 💪
unsigned short cmpstr(char *str1, char *str2) {
    unsigned int str1len = lenstr(str1);
    if (str1len != lenstr(str2)) return(1);
    for (int z = 0; z < str1len; z++) {
        if (str1[z] != str2[z]) return(1);
    }
    return(0);
}

//i write my own string compare function 💪
void cpstr(char *dst, char *src) {
    unsigned int z = 0;
    while ((dst[z] != '\0')&&(src[z] != '\0')) {
        dst[z] = src[z];
        printf("\ncopied %c\n", src[z]);
        z++;
    }
    printf("\ndone cpstr for %s\n\n", src);
}

int main(int argc, char **argv) {
    //first deal with argument errors
    if (argc != 2) {
        printf("\n⚠️   Too few/many arguments.\n");
        print_help();
        return(1);
    } else if (cmpstr(argv[1], "--help") == 0) {
        print_help();
        return(0);
    }

    char alt_lower[26][4] = {"а", "b", "c", "d", "e", "f", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", };
    char alt_upper[26][4] = {"A", "B", "C", "D", "E", "F", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", };
    unsigned short index;
    //char final_letter[4] = {0, 0, 0, 0};
    unsigned int letters_done = 0;

    //do the stuff
    for (int z = 0; z < lenstr(argv[1]); z++) {
        index = argv[1][z];

        //make sure letter is ascii [no buffer overflow protection for utf-8]
        if (index > 255) {
            printf("\n⚠️   Non-ASCII character found. Quit.\n👋  Bye!\n");
            return(1);
        }
        
        //do the stuff stuff
        if ((index >= 65)&&(index <= 90)) { //upper case
            printf("%s", alt_upper[index % 65]);
            letters_done++;
        } else if ((index >= 97)&&(index <= 122)) { //lower case
            printf("%s", alt_lower[index % 97]);
            letters_done++;
        } else {
            printf("%c", index);
        }
    }
    printf("\n");//end line after unbanned word

    if (letters_done == 0) {
        printf("\n⚠️   Could not modify.\n👋  Bye!\n");
    }
    return(0);
}
