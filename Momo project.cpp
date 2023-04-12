#include <iostream>

using namespace std;

void renderMenu(){
    cout << "1. Resetting/changing pin" << endl;
    cout << "2. Checking balance" << endl;
    cout << "3. Sending money" << endl;
    cout << "4. exit" << endl;
}

void outputBalance(double balance){
    cout << endl;
    cout << "Your balance is: GHC" << balance << endl;
    cout << endl;
}

bool checkAuthorization(string pin){
        bool isValidUser = false;
        string enteredPin;
        cout << "Enter Your Pin: " << endl;
        cin >> enteredPin;
        if(enteredPin != pin) {
            cout << "Incorrect pin" << endl;
        }
        else{
            isValidUser = true;
        }
        return isValidUser;
}

int tryPins(string pin){
    int tries = 0;
    bool isValidUser = false;
    while(!isValidUser){
        if(tries >= 3) break;
        isValidUser = checkAuthorization(pin);
        if(!isValidUser) tries+= 1;
    }
    return tries;
}

bool checkBalance(string pin, double balance){
    int tries = 0;
    bool isValidUser = false;
    while(!isValidUser){
        if(tries >= 3) break;
        isValidUser = checkAuthorization(pin);
        if(!isValidUser) tries+= 1;
    }
    if(tries >= 3){
        cout << "Wrong pin entered 3 times " << endl;
        return false;
    }
    if(isValidUser) 
        outputBalance(balance);

    return true;
}

string changePin(string pin){
    string newPin;
   cout << "Enter new pin: ";
   cin >> newPin;
    return newPin;
}

double sendMoney(double currentAmount){
    double balance;
    double amountToSend;
    string receipientName;
    cout << "Enter name of receipient: ";
    cin >> receipientName;
    cout << "\nEnter amount to be sent: ";
    cin >> amountToSend;
    if(amountToSend > currentAmount){
        cout << "Amount entered is greater than your account balance!!" << endl;
        return 0;
    }
    balance = currentAmount - amountToSend;
    return balance;
}

int main() 
{
    string pin = "0000";    
    double balance = 1000;
    int pinMenuId = '1';
    int balanceMenuId = '2';
    int sendMenuId = '3';
    int exitMenuId = '4';

    while(true){
        renderMenu();
        char input;
        cin >> input;
        if(input == pinMenuId){
            int tries = tryPins(pin); 
            if(tries >= 3){
                cout << "Wrong pin entered 3 times " << endl;
                break;
            }
            pin = changePin(pin);
        }
        else if(input == balanceMenuId){
            bool bChecked = checkBalance(pin, balance);
            if(!bChecked) break;
        } else if(input == sendMenuId){
            int tries = tryPins(pin); 
            if(tries >= 3){
                cout << "Wrong pin entered 3 times " << endl;
                break;
            }
            balance = sendMoney(balance);
        }
        else if(input == exitMenuId){
            break;
        }
    }
}
