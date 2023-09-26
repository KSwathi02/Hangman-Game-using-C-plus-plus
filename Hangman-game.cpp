
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


int processGuess(char* word, const char* targetWord, char guess);

const char* wordBank[] = {"computer", "president", "trojan", "program",
    "coffee", "library", "football", "popcorn",
    "science", "engineer"};

const int numWords = 10;

int main()
{
    srand(time(0));
    char guess;
    bool wordGuessed = false;
    int numTurns = 10;
    
   
    const char* targetWord = wordBank[rand() % numWords];
    
  
    char word[80];  
    
    for(int i = 0; i < strlen(targetWord); i++){
        *(word + i) = '*';
    }
    *(word + strlen(targetWord)) = '\0';
    
    
    while (numTurns !=0 && wordGuessed == false) {
        cout << "Current word: " << word << endl;
        cout << numTurns << " remain...Enter a letter to guess" << endl;
        cout << "> ";
        cin >> guess;
        
        int gameResult = processGuess(word, targetWord, guess);
        
        if (gameResult == 0) {
            numTurns--;
        }
        
        if (strcmp(targetWord, word) == 0) {
            wordGuessed = true;
        }
        
    }
    
   
    if (wordGuessed) {
        cout << "The word was: " << targetWord << ". You win!" << endl;
    }else{
        cout << "Too many turns... You lose!" << endl;
    }
    
    
    return 0;
}


int processGuess(char* word, const char* targetWord, char guess)
{
    int counter = 0;
    for(int i = 0; i < strlen(word); i++){
        if (guess == *(targetWord + i) ){
            *(word + i) = guess;
            counter++;
        }
    }
    return counter;
    
}

