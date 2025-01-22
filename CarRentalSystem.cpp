#include <iostream>
#include <string>
using namespace std;

//-----Structure store car details-----//
struct Car {
    string company;
    string model;
    string color;
    string max_speed;
    int price;
};

//------Structure to store lease information-----//
struct LeaseInfo {
    string name;
    string nationalID;
    int rentalDays;
    double payment;
    double totalCost;
};

//-----Array of car details-----//
Car cars[9] = {
    {"Suzuki", "Mehran", "Silver", "80 Km/h", 4000},
    {"Volkswagen", "2020", "Black", "200 Km/h", 5000},
    {"BMW", "I8", "Black", "300 Km/h", 7000},
    {"Audi", "Etron GT", "Gun metallic", "250 Km/h", 6000},
    {"KIA", "Sportage", "White", "320 Km/h", 5000},
    {"Tesla", "X-Series", "Silver", "400 Km/h", 8000},
    {"Mercedes", "G-Wagon", "Black", "200 Km/h", 7000},
    {"Honda", "Civic", "Grey", "250 Km/h", 3000},
    {"Toyota", "Grande", "White", "280 Km/h", 2000}
};

//-----Function for user login-----//
void login() {
    string username, password;
    cout << "----------------------------------------------\n";
    cout << "Login to Sun Shine Car Rental System\n";
    cout << "----------------------------------------------\n";
    
    while (true) {
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

        if (username == "admin" && password == "1234") {
            cout << "\nAccess Granted! Welcome " << username << " to the Sun Shine Car Rental System.\n";
            break;
        } else {
            cout << "\nInvalid credentials. Please try again.\n";
        }
    }
}

//-----Function to display the menu-----//
void displayMenu() {
    cout << "----------------------------------------------\n";
    cout << "Available Cars:\n";
    for (int i = 0; i < 9; i++) {
        cout << i + 1 << ". " << cars[i].company << "\n";
    }
    cout << "----------------------------------------------\n";
}

//-----Function to show car details-----//
void showCarDetails(int choice) {
    Car selectedCar = cars[choice - 1];
    cout << "----------------------------------------------\n";
    cout << "Car Details:\n";
    cout << "Company      : " << selectedCar.company << "\n";
    cout << "Model        : " << selectedCar.model << "\n";
    cout << "Color        : " << selectedCar.color << "\n";
    cout << "Max Speed    : " << selectedCar.max_speed << "\n";
    cout << "Daily Price  : " << selectedCar.price << "\n";
    cout << "----------------------------------------------\n";
}

//----Function to process car rental----//
void rentCar(int choice) {
    LeaseInfo lease;
    Car selectedCar = cars[choice - 1];

    cout << "Enter your name: ";
    cin.ignore(); //-----ignore karna leftover newline character ko
    getline(cin, lease.name);  //-----getline 1 built in func ha jo Allow karta ha input spaces ka sath;

    cout << "Enter your National ID: ";
    getline(cin, lease.nationalID); 

    cout << "Enter number of rental days: ";
    cin >> lease.rentalDays;

    lease.totalCost = selectedCar.price * lease.rentalDays;
    cout << "Total cost for " << lease.rentalDays << " days: " << lease.totalCost << "\n";

    cout << "Enter payment amount: ";
    cin >> lease.payment;

    if (lease.payment >= lease.totalCost) {
        cout << "Payment successful! Enjoy your " << selectedCar.company << ".\n";
    } else {
        cout << "Insufficient payment. You need " << lease.totalCost - lease.payment << " more.\n";
    }
}

// Main function
int main() {
    login();

    while (true) {
        displayMenu();

        int choice;
        cout << "Select a car by entering the number (1-9): ";
        cin >> choice;

        if (choice >= 1 && choice <= 9) {
            showCarDetails(choice);

            string confirm;
            cout << "Do you want to rent this car? (yes/no): ";
            cin >> confirm;

            if (confirm == "yes") {
                rentCar(choice);
            }
        } else {
            cout << "Invalid choice. Please try again.\n";
        }

        string continueRenting;
        cout << "Do you want to rent another car? (yes/no): ";
        cin >> continueRenting;
        if (continueRenting == "no") {
            break;
        }
    }

    cout << "\nThank you for using the Sun Shine Car Rental System. Goodbye!\n";
    return 0;
}

