#include<stdio.h>

void print_help() {
    printf("\n🚀  Usage: unbanwd <banned word>\n    For help: unbanwd help\n\n✏️  e.g. 1: unbanwd ligma\n✏️  e.g. 2: unbanwd balls\n\n👋  Bye!\n");
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


int main(int argc, char **argv) {
    //first deal with argument errors
    if (argc != 2) {
        printf("\n⚠️   Too few/many arguments.\n");
        print_help();
        return(1);
    } else if (cmpstr(argv[1], "help") == 0) {
        print_help();
        return(0);
    }

    char **alt_lower = {};
    char **alt_upper = {};
    unsigned short index;

    //do the stuff
    for (int z = 0; z < lenstr(argv[1]); z++) {
        //make sure letter is ascii [no buffer overflow protection for utf-8]
        if (argv[1][z] > 255) {
            printf();
            return(1);
        }
        
        //do the stuff stuff
        if ((argv[1][z] >= 65)&&(argv[1][z] <= 90)) { //lower case
            printf("%s", alt_upper[argv[1][z]%65]);
        } else if ((argv[1][z] >= 97)&&(argv[1][z] <= 122)) { //upper case
            printf("%s", alt_upper[argv[1][z]%97]);
        } else {
            printf("%s", argv[1][z]);
        }
    }

    //test
    printf("%d\n%c\n", lenstr(argv[1]), 0x0455);
    return(0);
}
