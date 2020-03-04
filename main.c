#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>


void Title();
void Home();

char username[24];
char password[24];


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleTitle("Bataille Navale");
    Home();
    system("pause");
    return 0;
}

void Title(){
    printf("--------------\n");
    printf("Bataille Naval\n");
    printf("--------------\n");
}

void Home(){
    Title();
    printf("By Sébastien Moraz\n\n");

}