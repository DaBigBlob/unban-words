#include<stdio.h>

void print_help() {
    printf("\n🚀  Usage: unbanwd <banned word>\n    For help: unbanwd help\n\n✏️  e.g. 1: unbanwd jingle\n✏️  e.g. 2: unbanwd bells\n\n👋  Bye!\n");
}

//i write my own string length function 💪
int lenstr(char *str) {
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
        printf("⚠️   Too few/many arguments.\n");
        print_help();
        return(1);
    } else if (cmpstr(argv[1], "help") == 0) {
        print_help();
        return(0);
    }

    //do the stuff
    for (int z = 0; z < lenstr(argv[1]); z++) {
        //
    }

    //test
    printf("%s\n%c\n", argv[1], 0x0455);
    return(0);
}
