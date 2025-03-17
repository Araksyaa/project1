#include <iostream> 
#include <string.h>
using namespace std;

bool isVowel(char c) {
   
    c = tolower(c);
  return (c == 'а' || c == 'е' || c == 'ё' || c == 'и' ||
        c == 'о' || c == 'у' || c == 'ы' || c == 'э' || c == 'ю' || c == 'я');
}


bool isSymmetric(const char* word) {
    int len = strlen(word); 
    for (int i = 0; i < len / 2; i++) { 
        if (word[i] != word[len - 1 - i]) { 
            return false;
        }
    }
    return true; 
}


bool iscoglco(const char* word) {
    for (int i = 0; word[i] != '\0'; i++) { 
        if (i > 0 && isVowel(word[i]) == isVowel(word[i - 1])) { 
            return false; 
        }
    }
    return true; 
}


void processString(const char* input) {
    char word[100]; 
    int index = 0; 

   
    for (int i = 0; ; ++i) {
        if (input[i] == ' ' || input[i] == '.') { 
            if (index > 0) { 
                word[index] = '\0'; 
                if (isSymmetric(word) && iscoglco(word)) {
                    cout << word << endl; 
                }
                index = 0; 
            }
            if (input[i] == '.') break; 
        }
        else {
            word[index++] = input[i];
        }
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    const char* str = "аба тут мама ручка. "; 
    cout << "Слова, которые соответствуют условиям:" << endl;
    processString(str); 
    return 0; 
}