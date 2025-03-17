#include <iostream> 
#include <string.h>
using namespace std;
// Функция для проверки, является ли символ гласным
bool isVowel(char c) {
   
    c = tolower(c);
  return (c == 'à' || c == 'å' || c == '¸' || c == 'è' ||
        c == 'î' || c == 'ó' || c == 'û' || c == 'ý' || c == 'þ' || c == 'ÿ');
}

// Функция для проверки, является ли слово симметричным
bool isSymmetric(const char* word) {
    int len = strlen(word); 
    for (int i = 0; i < len / 2; i++) { 
        if (word[i] != word[len - 1 - i]) { 
            return false;
        }
    }
    return true; 
}

// Функция для проверки, чередуются ли гласные и согласные в слове
bool iscoglco(const char* word) {
    for (int i = 0; word[i] != '\0'; i++) { 
        if (i > 0 && isVowel(word[i]) == isVowel(word[i - 1])) { 
            return false; 
        }
    }
    return true; 
}

// Функция для обработки строки и оставления только нужных слов
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
   // Пример ввода
    setlocale(LC_ALL, "Russian");
    const char* str = "àáà òóò ìàìà ðó÷êà. "; 
    cout << "Ñëîâà, êîòîðûå ñîîòâåòñòâóþò óñëîâèÿì:" << endl;
    processString(str); 
    return 0; 
}
