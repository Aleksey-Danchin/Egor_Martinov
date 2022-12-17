#include <iostream>
#include <stdio.h>

using namespace std;

int linesNumber = 0;
char** lines = new char*[100];

void fun (char* line, char*& max, char*& min) {
    int maxLength = -1;
    int maxIndex = 0;

    int minLength = 1000;
    int minIndex = 0;

    int length = 0;
    while (line[length] != '\0') {
        length++;
    }

    int startIndex = 0;
    for (int endIndex = 0; endIndex < length; endIndex++) {
        if (line[endIndex] == ' ' || line[endIndex] == '\n') {
            int length = endIndex - startIndex;

            if (maxLength < length) {
                maxLength = length;
                maxIndex = startIndex;
            }

            if (minLength > length) {
                minLength = length;
                minIndex = startIndex;
            }

            startIndex = endIndex + 1;
        }
    }

    max = &line[maxIndex];
    min = &line[minIndex];
}

int main () {
    while (linesNumber < 100) {
        // Прочитали строчку вместе с пробелами
        char* buff = new char[100];
        fgets(buff, 100, stdin);

        // Определение количества элементов в строке
        int length = 0;
        while (buff[length] != '\0') {
            length++;
        }

        // Определяем инкедкс в котором находится слово end
        int endIndex = -1;
        for (int i = 0; i < length - 2; i++) {
            if (buff[i] == 'e' && buff[i + 1] == 'n' && buff[i + 2] == 'd') {
                endIndex = i;
                break;
            }
        }

        // Если нашлось слово end
        if (endIndex != -1) {
            // Обрезаем строчку включая слово end и добавляем в конце строки \0
            char* line = new char[endIndex + 3];
            for (int i = 0; i < endIndex + 3; i++) {
                line[i] = buff[i];
            }
            line[endIndex + 3] = '\0';

            // Добавляем обрезанную строчку в массив строк
            lines[linesNumber] = line;
            linesNumber++;
            break;
        }
        
        // или же запоминаем исходную строчку
        else {
            lines[linesNumber] = buff;
            linesNumber++;
        }
    }

    char* minLine;
    int minLength = 1000;

    char* maxLine;
    int maxLength = -1;

    char* max;
    char* min;

    for (int i = 0; i < linesNumber; i++) {
        fun(lines[i], max, min);

        // Определение количества элементов в строке
        int length = 0;
        while (*(max + length) != ' ' && *(max + length) != '\0') {
            length++;
        }

        if (length > maxLength) {
            maxLength = length;
            maxLine = lines[i];
        }

        length = 0;
        while (*(min + length) != ' ' && *(min + length) != '\0') {
            length++;
        }

        if (length < minLength) {
            minLength = length;
            minLine = lines[i];
        }
    }

    cout << maxLine;
    cout << maxLength << endl;

    cout << minLine;
    cout << minLength << endl;

}

