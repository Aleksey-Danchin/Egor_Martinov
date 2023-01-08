#include <iostream>
#include <string>

using namespace std;

struct deposid {
    int number;
    char* surname;
    char* name;
    double score;
};

int clients_number = 0;
deposid* clients = new deposid[0];

int mystrcmp(char* str1, char* str2 ) {
    while(*str1 && *str2 && *str1 == *str2 ) {
        str1++;
        str2++;
    }
    
    int d = *str1 - *str2;
    return d == 0 ? 0 : d > 0 ? 1 : -1;
}

void add_client () {
    deposid client;

    cout << "Enter number: ";
    cin >> client.number;

    cout << "Enter name: ";
    client.name = new char[20];
    cin >> client.name;

    cout << "Enter surname: ";
    client.surname = new char[20];
    cin >> client.surname;

    cout << "Enter score: ";
    cin >> client.score;

    deposid* next_clients = new deposid[clients_number + 1];
    for (int i = 0; i < clients_number; i++) {
        next_clients[i] = clients[i];
    }
    next_clients[clients_number] = client;

    delete clients;
    clients = next_clients;
    clients_number += 1;
}

void print_clients (deposid* clients, int number) {
    cout << "Number\t\tName\t\tSurname\t\tScore" << endl;
    cout << "-----------------------------------------------------" << endl;

    for (int i = 0; i < number; i++) {
        cout << clients[i].number << "\t\t";
        cout << clients[i].name << "\t\t";
        cout << clients[i].surname <<  "\t\t";
        cout << clients[i].score << "\t\t";
        cout << endl;
    }

}

void print_biggest (float limit) {
    int counter = 0;

    for (int i = 0; i < clients_number; i++) {
        if (clients[i].score > limit) {
            counter += 1;
        }
    }

    int index = 0;
    deposid* biggest_clients = new deposid[counter];

    for (int i = 0; i < clients_number; i++) {
        if (clients[i].score > limit) {
            biggest_clients[index] = clients[i];
            index += 1;
        }
    }

    print_clients(biggest_clients, counter);
}

void print_user (char* name, char* surname) {
    int counter = 0;

    for (int i = 0; i < clients_number; i++) {
        if (mystrcmp(clients[i].name, name) == 0 && mystrcmp(clients[i].surname, surname) == 0) {
            counter += 1;
        }
    }

    int index = 0;
    deposid* client_scores = new deposid[index];

    for (int i = 0; i < clients_number; i++) {
        if (mystrcmp(clients[i].name, name) == 0 && mystrcmp(clients[i].surname, surname) == 0) {
            client_scores[index] = clients[i];
            index += 1;
        }
    }

    print_clients(client_scores, counter);
}

int main () {
    cout << "Enter n: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        add_client();
    }

    print_clients(clients, clients_number);

    int code = 0;
    while (code != 5) {
        cout << endl << endl;
        cout << "Add client            1" << endl;
        cout << "Show clients table    2" << endl;
        cout << "Show biggest scores   3" << endl;
        cout << "Show client scores    4" << endl;
        cout << "Exit                  5" << endl;
        cout << "-----------------------" << endl;
        cout << "Enter command: ";
        cin >> code;

        if (code == 1) {
            add_client();
        }

        else if (code == 2) {
            print_clients(clients, clients_number);
        }

        else if (code == 3) {
            cout << "Enter score limit: ";
            float limit;
            cin >> limit;
            print_biggest(limit);
        }

        else if (code == 4) {
            char* name = new char[20];
            char* surname = new char[20];

            cout << "Enter name: ";
            cin >> name;

            cout << "Enter surname: ";
            cin >> surname;

            print_user(name, surname);
        }

        else if (code != 5) {
            cout << "Command not found.";
        }
    }
}

