#include <stdio.h>
#include <stdlib.h> 
#include <wchar.h>
#include <locale.h>
#include <fcntl.h>
#include <io.h>
#include <string.h>

#define MAX_LEN 50

int translator()
{
    FILE *file = _wfopen(L"slovar.txt", L"r, ccs=UTF-8");
    if (file == NULL) {
        wprintf(L"Ошибка: Не удалось открыть файл slovar.txt!\n");
        return 1;
    }

    wchar_t search_word[MAX_LEN];
    wchar_t file_word[MAX_LEN];
    wchar_t translation[MAX_LEN];
    
    while (1) {
        wprintf(L"Введите слово для перевода (или exit для возврата): ");
        if (wscanf(L"%49s", search_word) != 1) {
            break;
        }

        if (wcscmp(search_word, L"exit") == 0) {
            wprintf(L"Возврат в главное меню...\n");
            break;
        }

        int found = 0;

        rewind(file);

        while (fwscanf(file, L"%49s %49s", file_word, translation) == 2) {
            if (wcscmp(search_word, file_word) == 0) {
                wprintf(L"Перевод: %s\n\n", translation);
                found = 1;
                break; 
            }
        }

        if (!found) {
            wprintf(L"Слово '%s' не найдено в словаре.\n\n", search_word);
        }
    }

    fclose(file); 
    return 0;
}


int clear()
{
    system("cls");
    wprintf(L"+-----------------------+--------------------------------------------------+\n");
    wprintf(L"| Команда               | Описание                                         |\n");
    wprintf(L"+-----------------------+--------------------------------------------------+\n");
    wprintf(L"| translator            | Переводчик                                       |\n");
    wprintf(L"| clear                 | Очистить экран консоли                           |\n");
    wprintf(L"| exit                  | Закрывает программу                              |\n");
    wprintf(L"+-----------------------+--------------------------------------------------+\n");
    
    return 0;
}

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    
    wprintf(L"+-----------------------+--------------------------------------------------+\n");
    wprintf(L"| Команда               | Описание                                         |\n");
    wprintf(L"+-----------------------+--------------------------------------------------+\n");
    wprintf(L"| translator            | Переводчик                                       |\n");
    wprintf(L"| clear                 | Очистить экран консоли                           |\n");
    wprintf(L"| exit                  | Закрывает программу                              |\n");
    wprintf(L"+-----------------------+--------------------------------------------------+\n");
    
    wchar_t a[MAX_LEN]; 
    
    while(1)
    {
        wprintf(L"\n>>> "); 
        wscanf(L"%49s", a); 
        
        if(wcscmp(a, L"translator") == 0) 
        {
            translator();
        }
        else if(wcscmp(a, L"clear") == 0)
        {
            clear();
        }
        else if(wcscmp(a, L"exit") == 0)
        {
            break;
        }
        else
        {
            wprintf(L"Я вас не понял\n");
        }
    }
    return 0;
}
