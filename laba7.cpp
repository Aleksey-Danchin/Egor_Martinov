#include <iostream>
#include <string>

using namespace std;

struct fio {
    char* name;
    char* surname;
};

struct date {
    int day;
    char* month;
    int year;
};

struct deposid {
    int number;
    fio person;
    date created;
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
    client.person.name = new char[20];
    cin >> client.person.name;

    cout << "Enter surname: ";
    client.person.surname = new char[20];
    cin >> client.person.surname;

    cout << "Enter year: ";
    cin >> client.created.year;

    cout << "Enter month: ";
    client.created.month = new char[20];
    cin >> client.created.month;

    cout << "Enter day: ";
    cin >> client.created.day;

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
    cout << "Number\t\tName\t\tSurname\t\tScore\t\tYear\t\tMonth\t\tDay" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < number; i++) {
        cout << clients[i].number << "\t\t";
        cout << clients[i].person.name << "\t\t";
        cout << clients[i].person.surname <<  "\t\t";
        cout << clients[i].score << "\t\t";
        cout << clients[i].created.year <<  "\t\t";
        cout << clients[i].created.month <<  "\t\t";
        cout << clients[i].created.day <<  "\t\t";
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
        if (mystrcmp(clients[i].person.name, name) == 0 && mystrcmp(clients[i].person.surname, surname) == 0) {
            counter += 1;
        }
    }

    int index = 0;
    deposid* client_scores = new deposid[index];

    for (int i = 0; i < clients_number; i++) {
        if (mystrcmp(clients[i].person.name, name) == 0 && mystrcmp(clients[i].person.surname, surname) == 0) {
            client_scores[index] = clients[i];
            index += 1;
        }
    }

    print_clients(client_scores, counter);
}

char monthes[12][4][20] = {
    { "January",  "january",  "Январь",  "январь" },
    { "February",  "february",  "Февраль",  "февраль" },
    { "March",  "march",  "Март",  "март" },
    { "April",  "april",  "Апрель",  "фпрель" },
    { "May",  "may",  "Май",  "май" },
    { "June",  "june",  "Июнь",  "июнь" },
    { "July",  "july",  "Июль",  "июль" },
    { "August",  "august",  "Август",  "август" }
};

long int date_to_int (int year, char* month, int day) {
    int month_number = -1;

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 4; j++) {
            if (mystrcmp(month, monthes[i][j]) == 0) {
                month_number = i;
                break;
            }
        }

        if (month_number != -1) {
            break;
        }
    }

    month_number = 0;
    return day + month_number * 31 + year * 365;
}

void print_latest (int year, char* month, int day) {
    int moment = date_to_int(year, month, day);
    int counter = 0;

    for (int i = 0; i < clients_number; i++) {
        int created_momemnt = date_to_int(clients[i].created.year, clients[i].created.month, clients[i].created.day);

        if (created_momemnt > moment) {
            counter += 1;
        }
    }

    int index = 0;
    deposid* client_scores = new deposid[index];

    for (int i = 0; i < clients_number; i++) {
        int created_momemnt = date_to_int(clients[i].created.year, clients[i].created.month, clients[i].created.day);

        if (created_momemnt > moment) {
            client_scores[index] = clients[i];
            index += 1;
        }
    }

    print_clients(client_scores, counter);
}

int main () {
    FILE* file;
    file = fopen("laba7.txt", "r");

    if (file == NULL) {
        cout << "File not open. Detected first launch." << endl;
        cout << "Enter n: ";
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            add_client();
        }
    } else {
        cout << "File readed." << endl;

        int number;
        char* name = new char[20];
        char* surname = new char[20];
        int year;
        char* month = new char[20];
        int day;
        float score;

        while (fscanf(
            file,
            "%d %s %s %d %s %d %f\n",
            &number,
            name,
            surname,
            &year,
            month,
            &day,
            &score
        ) != EOF) {
            deposid client;
            client.number = number;
            client.person.name = name;
            client.person.surname = surname;
            client.created.year = year;
            client.created.month = month;
            client.created.day = day;
            client.score = score;

            deposid* next_clients = new deposid[clients_number + 1];
            for (int i = 0; i < clients_number; i++) {
                next_clients[i] = clients[i];
            }
            next_clients[clients_number] = client;
            clients_number += 1;
            delete clients;
            clients = next_clients;

            name = new char[20];
            surname = new char[20];
            month = new char[20];
        };

        fclose(file);

        cout << "Data restored." << endl;
    }

    int code = 0;
    while (code != 6) {
        cout << endl << endl;
        cout << "Add client            1" << endl;
        cout << "Show clients table    2" << endl;
        cout << "Show biggest scores   3" << endl;
        cout << "Show client scores    4" << endl;
        cout << "Show latest scores    5" << endl;
        cout << "Exit                  6" << endl;
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

        else if (code == 5) {
            int year;
            char* month = new char[20];
            int day;

            cout << "Enter year: ";
            cin >> year;

            cout << "Enter month: ";
            cin >> month;

            cout << "Enter day: ";
            cin >> day;

            print_latest(year, month, day);
        }

        else if (code != 6) {
            cout << "Command not found.";
        }
    }

    remove("laba7.txt");
    file = fopen("laba7.txt", "w");
    if (file == NULL) {
        cout << "Can't write file." << endl;
    } else {
        for (int i = 0; i < clients_number; i++) {
            fprintf(
                file,
                "%d %s %s %d %s %d %f\n",
                clients[i].number,
                clients[i].person.name,
                clients[i].person.surname,
                clients[i].created.year,
                clients[i].created.month,
                clients[i].created.day,
                clients[i].score
            );
        }

        fclose(file);
        cout << "Data saved." << endl;
    }
}
