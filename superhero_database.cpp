#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int NUM_HEROES = 10;

string names[NUM_HEROES] = {
    "Moon Girl", "Ragman", "El Muerto", "Bouncing Boy", "Orphan",
    "D-Man", "The Question", "Sentry", "Big Bertha", "Ambush Bug"
};
string powers[NUM_HEROES] = {
    "Super Intelligence", "Souls of the Damned Suit", "Mystical Strength", "Inflatable Body", "Master Martial Artist",
    "Super Strength", "Detective Genius", "Limitless Power", "Body Mass Manipulation", "Meta Awareness"
};
string weaknesses[NUM_HEROES] = {
    "Social Awkwardness", "Emotionally Draining", "Pride", "Sharp Objects", "Silence / Guilt",
    "Mental Instability", "Lack of Identity", "Mental Fragility", "Public Perception", "Randomness"
};

int attributes[NUM_HEROES][2] = {
    {2015, 0}, {1976, 1}, {2006, 0}, {1961, 1}, {1999, 1},
    {1985, 0}, {1967, 1}, {2000, 0}, {1989, 0}, {1982, 1}
};
string universeNames[] = {"Marvel", "DC", "Other"};

void searchByName();
void searchByPower();
void sortHeroes();
void displayHeroes(bool toUpper);
void displayHero(int i);
string toLowerCase(string str);
string toUpperCase(string str);

int main() {
    int choice;
    bool running = true;

    while (running) {
        cout << "\n--- Superhero Database ---\n";
        cout << "1. Search by Name\n";
        cout << "2. Search by Superpower\n";
        cout << "3. Sort Superheroes Alphabetically\n";
        cout << "4. Display All in UPPERCASE\n";
        cout << "5. Display All in lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: searchByName(); break;
            case 2: searchByPower(); break;
            case 3: sortHeroes(); break;
            case 4: displayHeroes(true); break;
            case 5: displayHeroes(false); break;
            case 6: running = false; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

void searchByName() {
    string input;
    cout << "Enter superhero name to search: ";
    getline(cin, input);
    input = toLowerCase(input);

    bool found = false;
    for (int i = 0; i < NUM_HEROES; ++i) {
        if (toLowerCase(names[i]).find(input) != string::npos) {
            displayHero(i);
            found = true;
        }
    }
    if (!found) cout << "No superhero found with that name.\n";
}

void searchByPower() {
    string input;
    cout << "Enter superpower to search: ";
    getline(cin, input);
    input = toLowerCase(input);

    bool found = false;
    for (int i = 0; i < NUM_HEROES; ++i) {
        if (toLowerCase(powers[i]).find(input) != string::npos) {
            displayHero(i);
            found = true;
        }
    }
    if (!found) cout << "No superheroes found with that power.\n";
}

void sortHeroes() {
    for (int i = 0; i < NUM_HEROES - 1; ++i) {
        for (int j = i + 1; j < NUM_HEROES; ++j) {
            if (names[i] > names[j]) {
                swap(names[i], names[j]);
                swap(powers[i], powers[j]);
                swap(weaknesses[i], weaknesses[j]);
                swap(attributes[i][0], attributes[j][0]); // Year
                swap(attributes[i][1], attributes[j][1]); // Universe
            }
        }
    }
    cout << "Superheroes sorted alphabetically.\n";
}

void displayHeroes(bool toUpper) {
    for (int i = 0; i < NUM_HEROES; ++i) {
        string name = toUpper ? toUpperCase(names[i]) : toLowerCase(names[i]);
        string power = toUpper ? toUpperCase(powers[i]) : toLowerCase(powers[i]);
        string weak = toUpper ? toUpperCase(weaknesses[i]) : toLowerCase(weaknesses[i]);
        string uni = toUpper ? toUpperCase(universeNames[attributes[i][1]]) : toLowerCase(universeNames[attributes[i][1]]);
        cout << "\nName: " << name << "\nPower: " << power << "\nWeakness: " << weak
             << "\nYear Introduced: " << attributes[i][0] << "\nUniverse: " << uni << "\n";
    }
}

void displayHero(int i) {
    cout << "\nName: " << names[i]
         << "\nPower: " << powers[i]
         << "\nWeakness: " << weaknesses[i]
         << "\nYear Introduced: " << attributes[i][0]
         << "\nUniverse: " << universeNames[attributes[i][1]] << "\n";
}

string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

string toUpperCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}