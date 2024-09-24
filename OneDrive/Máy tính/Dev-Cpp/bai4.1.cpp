#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random number between 1 and 6
int rollDice() {
    return rand() % 6 + 1;
}

// Function to check if the player wins or loses
bool checkWin(int sum, int choice) {
    if (sum < 10) {
        cout << "Xui";
        if (choice == 1) {
            cout << "Ban chinh xac!!" << endl;
            return true;
        } else {
            cout << "Ban sai" << endl;
        }
    } else {
        cout << "Tai";
        if (choice == 2) {
            cout << "Ban chinh xac!!" << endl;
            return true;
        } else {
            cout << "Ban sai" << endl;
        }
    }
    return false;
}

// Function to play a round of the game
void playRound() {
    int choice;

    // Display options for the player
    cout << "Nhap lua chon cua ban:\n";
    cout << "1 - Tai\n";
    cout << "2 - Xui\n";
    cin >> choice;

    // Roll three dice and calculate the sum
    int d1 = rollDice();
    int d2 = rollDice();
    int d3 = rollDice();
    int sum = d1 + d2 + d3;

    // Display the result and check if the player wins or loses
    cout << "Xuc sac thu nhat: " << d1 << endl;
    cout << "Xuc sac thu hai: " << d2 << endl;
    cout << "Xuc sac thu ba: " << d3 << endl;
    cout << "Tong diem: " << sum << endl;

    bool isWin = checkWin(sum, choice);

    if (isWin) {
        cout << "Ban da thang!" << endl;
    } else {
        cout << "Ban da thua!" << endl;
    }
}

// Function to handle the money transaction
void handleMoney(int &money) {
    int choice;

    // Display options for the player
    cout << "Nhap so tien ban muon cuoc:\n";
    cout << "1 - 1,000d\n";
    cout << "2 - 50,000d\n";
    cout << "3 - 500,000d\n";
    cout << "4 - 5,000,000d\n";
    cout << "5 - All in\n";
    cin >> choice;

    int amount;
    switch (choice) {
        case 1:
            amount = 1000;
            break;
        case 2:
            amount = 50000;
            break;
        case 3:
            amount = 500000;
            break;
        case 4:
            amount = 5000000;
            break;
        case 5:
            amount = money;
            break;
        default:
            cout << "Lua chon khong hop le.\n";
            return;
    }

    // Check if the player has enough money
    if (amount > money) {
        cout << "So tien khong du.\n";
        return;
    }

    // Deduct the amount from the player's money
    amount -= money;

    // Play a round of the game
    playRound();

   if (checkWin) {
int winnings = amount * 2;
cout << "Ban da thang " << winnings << "d!\n";
money += winnings;
}
else {
cout << "Ban da thua " << amount << "d!\n";
}
}

int main() {
// Seed the random number generator
srand(time(NULL));


// Initialize the player's money to 10,000d
int money = 10000;

// Loop to play multiple rounds of the game
while (true) {
    // Check if the player has run out of money
    if (money <= 0) {
        cout << "Ban da het tien!\n";
        break;
    }

    // Handle the money transaction and play a round of the game
    handleMoney(money);

    // Display the player's remaining money
    cout << "So tien con lai cua ban: " << money << "d\n";

    // Ask the player if they want to continue playing
    char answer;
    cout << "Ban co muon choi tiep khong? (y/n): ";
    cin >> answer;
    if (answer != 'y' && answer != 'Y') {
        break;
    }
}

// Display the player's final score
cout << "So tien cuoi cung cua ban: " << money << "d\n";

return 0;
}

