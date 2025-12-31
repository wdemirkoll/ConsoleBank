#include <iostream>
#include <string>

// Global Variables
std::string Name;

double CreditCard = 0; // Credit Card Balance
double BankCard = 0; // Bank Card Balance
double Cash = 0; // Cash

double DepositMoney; // Deposit To Money - Deposit Amount
double WithdrawMoney; // Withdraw To Money - Withdraw Amount

int Vote; // Selection-Vote

// Displays the main menu options
void MainMenu(){
    std::cout << "------------------" << std::endl;
    std::cout << "[1] - Check Cash Balance" << std::endl;
    std::cout << "[2] - Check Credit Card Balance" << std::endl;
    std::cout << "[3] - Check Bank Card Balance" << std::endl;
    std::cout << "[4] - Deposit Money To Card" << std::endl;
    std::cout << "[5] - Withdraw Money From Card" << std::endl;
    std::cout << "[6] - Exit" << std::endl;
    std::cout << "------------------" << std::endl;
}

// Gets user menu selection
void MainVote(){
    std::cout << "Vote:";
    std::cin >> Vote;
}

// Gets deposit amount from user
void DepositVote(){
    std::cout << "Enter amount:";
    std::cin >> DepositMoney;
}

// Gets withdraw amount from user
void WithdrawVote(){
    std::cout << "Enter amount:";
    std::cin >> WithdrawMoney;
}

int main(){
    std::cout << "Enter your name, ";
    getline(std::cin, Name);

    std::cout << "\nWelcome, " << Name << std::endl;
    std::cout << "I'm giving you $500 cash as a gift for testing my code :)\n\n";

    Cash += 500; // Gift

    while(true){
        MainMenu();
        MainVote();

        switch(Vote){
        case 1:
            std::cout << "Your cash balance: $" << Cash << std::endl;
            break;

        case 2:
            std::cout <<"Your credit card balance: $" << CreditCard << std::endl;
            break;

        case 3:
            std::cout << "Your bank card balance: $" << BankCard << std::endl;
            break;

        case 4:
            std::cout << "[1] - Deposit Money From Credit Card" << std::endl;
            std::cout << "[2] - Deposit Money From Bank Card" << std::endl;
            MainVote();
            DepositVote(); // Get deposit amount

             switch(Vote){
             case 1:
                // Check if user has enough cash
                if(DepositMoney > 0 && DepositMoney <= Cash){
                    Cash -= DepositMoney;
                    CreditCard += DepositMoney;

                    std::cout << "Success!" << std::endl;
                }
                else
                    std::cout << "Insufficient balance.." << std::endl;
                break;


             case 2:
                // Check if user has enough cash
                if(DepositMoney > 0 && DepositMoney <= Cash){
                    Cash -= DepositMoney;
                    BankCard += DepositMoney;

                    std::cout << "Success!" << std::endl;
                }
                else{
                    std::cout << "Insufficient balance.." << std::endl;
                }
                break;


             default:
                std::cout << "Invalid Selection!" << std::endl;
                break;
              }
            break;


        case 5:
            std::cout << "[1] - Withdraw Money From Credit Card" << std::endl;
            std::cout << "[2] - Withdraw Money From Bank Card" << std::endl;
            MainVote();

             switch(Vote){
             case 1:
                WithdrawVote();

                // Check if credit card has enough balance
                if(WithdrawMoney > 0 && WithdrawMoney <= CreditCard){
                    CreditCard -= WithdrawMoney;
                    Cash += WithdrawMoney;

                    std::cout << "Successful!" << std::endl;
                }
                else{
                    std::cout << "Insufficient balance.." << std::endl;
                }
                break;


             case 2:
                WithdrawVote();

                // Check if bank card has enough balance
                if(WithdrawMoney > 0 && WithdrawMoney <= BankCard){
                    BankCard -= WithdrawMoney;
                    Cash += WithdrawMoney;

                    std::cout << "Successful!" << std::endl;
                }
                else{
                    std::cout << "Insufficient balance.." << std::endl;
                }
                break;


             default:
                std::cout << "Invalid Selection!" << std::endl;
                break;
             }
            break;


        case 6:
            return 0; // Exit


        default:
            std::cout << "Invalid Selection!" << std::endl;
            break;
        }
     }

  return 0;
}
