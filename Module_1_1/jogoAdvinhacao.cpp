#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

#define GAME_EASY_DIFFICULT     9
#define GAME_MEDIUM_DIFFICULT   6
#define GAME_HARD_DIFFICULT     3

int selectGameDifficulty (){
    
    char userInput;
    int Attempt_Limit;

    cout << "#  Please select the game level:  #" << endl;
    cout << "#  (E)asy, (M)edium, (H)ard:      #" << endl;
    cin >> userInput;
    
    switch(userInput){
        case 'E':
            Attempt_Limit = GAME_EASY_DIFFICULT;
            break;
        
        case 'M':
            Attempt_Limit = GAME_MEDIUM_DIFFICULT;
            break;

        case 'H':
            Attempt_Limit = GAME_HARD_DIFFICULT;
            break;

        default:
            cout << "# Please type the correct         #" << endl;
            cout << "# character for game level        #" << endl;
            cout << "#    (E)asy, (M)edium, (H)ard     #" << endl;
            Attempt_Limit = 0;
    }
    return Attempt_Limit;
}

float damageCalculator (int guess, int SECRET_NUMBER, int DIVISION_FACTOR, float DAMAGE_LIMIT){

    float damage = (float)(abs(guess-SECRET_NUMBER)/DIVISION_FACTOR);
    if(DAMAGE_LIMIT<damage) damage=DAMAGE_LIMIT;
    return damage;
}

char* printPoints (float points, int digits){

    char *printInfo = (char *)malloc(sizeof(char)*(digits+1));
    int rest, integerPart;
    int Mult = pow(10, digits-1);

    printInfo[digits] = '\0';
    for(int i = 0; i<digits; i++){
        printInfo[i] = (int)(points/Mult)+48;
        points = (int)((int)points % Mult);
        Mult = Mult /10;
    }
    return printInfo;
}

int main (void){

    // Game constants
    const int DIGITS_SHOW_SCORE = 4;
    const float INITIAL_SCORE = 1000;
    const int DIVISION_FACTOR = 2;
    srand(time(NULL));
    const int SECRET_NUMBER = rand()%100;
    
    float points = INITIAL_SCORE;
    int Attempt_Limit;
    float damageLimit;
    int guess = 0;
    bool stop = false;
    int gameLevel = 0;

    cout << "###################################" << endl;
    cout << "#           The Guess Game        #" << endl;
    cout << "# Created by: Callebe S. Barbosa  #" << endl;
    cout << "###################################" << endl;    

    Attempt_Limit = selectGameDifficulty ();
    Attempt_Limit>0 ? damageLimit =  (INITIAL_SCORE/Attempt_Limit) : damageLimit = 1 ;
    

    for(int i=0; i<Attempt_Limit && !stop; i++){
        
        cout << "What is your guess?" << endl;
        cin >> guess;
        
        if(guess == SECRET_NUMBER){
            cout << "###################################" << endl;
            cout << "#     Congratulation you got!     #" << endl;
            cout << "###################################" << endl;
            stop = true;
        }
        else{
            points -= damageCalculator (guess, SECRET_NUMBER, DIVISION_FACTOR, damageLimit);
            cout << "-> Damage :" << damageCalculator (guess, SECRET_NUMBER, DIVISION_FACTOR, damageLimit) << endl;
            cout.precision(2);
            cout << fixed;
            if(guess < SECRET_NUMBER){
                cout << ">> Your guess was lower than the Secret Number!" << endl;
            }
            else{
                cout << ">> Your guess was greater than the Secret Number!" << endl;
            }
        }
    }
    if(stop){
        cout << endl;
        cout << endl;
        cout << "###################################" << endl;
        cout << "#             YOU WIN!!           #" << endl;
        cout << "#                                 #" << endl;
        cout << "# You made : "<< printPoints(points, DIGITS_SHOW_SCORE) <<" points          #" << endl;
        cout << "###################################" << endl;
    }
    else{
        cout << endl;
        cout << "You fail! Best luck in the next time :)" << endl;
        cout << endl;
        cout << endl;
        cout << "###################################" << endl;
        cout << "#             GAME OVER!!         #" << endl;
        cout << "# You made : 000 points           #" << endl;
        cout << "###################################" << endl;
    }
    return 0;
}