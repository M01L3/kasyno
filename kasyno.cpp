﻿#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

// Struktura karty
struct Card {
    string suit; // pik, kier, karo, trefl
    string value; // "2", "10", "J", "A"
    int points; // wartość karty 2-11
};

// Wyświetlanie karty
void displayCard(const Card& card) {
    cout << "+-----------+\n"; 
    cout << "| " << card.value;
    for (size_t i = 0; i < 4 - card.value.length(); i++) cout << " ";
    cout << "      |\n"; 
    cout << "| " << card.suit;
    for (size_t i = 0; i < 8 - card.suit.length(); i++) cout << " ";
    cout << "  |\n"; 
    cout << "|           |\n"; 
    cout << "+-----------+\n";

}

//tworzenie talii
vector<Card> createDeck() {
    vector<Card> deck;
    string suits[] = { "pik", "karo", "kier", "trefl" };
    string values[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    int points[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
    
    for (const auto& suit : suits) {
        for (size_t i = 0; i < 13; i++) {
            deck.push_back({ suit, values[i], points[i] });
        }
    }
    return deck;
}
//losowanie karty 
Card drawCard(vector<Card>& deck, mt19937& rng) {
    uniform_int_distribution<size_t> dist(0, deck.size() - 1); // Zakres losowania
    size_t index = dist(rng); // Losowy indeks
    Card card = deck[index]; // Pobierz kartę
    deck.erase(deck.begin() + index); // Usuń kartę z talii
    return card;
}

int main() {
    mt19937 rng(time(0));

    int gra,gramy = 1;

    cout << "W co dzisiaj gramy?\n";
    cout << "1-BlackJack 2-slots\n";
    cout << "Wybieram: ";
    cin >> gra;

    while (gramy == 1) {
        if (gra == 1) {
            cout << "Witamy w BlackJack\n";
            vector<Card> deck = createDeck();
            Card card = drawCard(deck, rng);
            displayCard(card);
            cout << "Kolejna partia?\n";
            cout << "1-tak/0-nie";
            cin >> gramy;
        }
        else if (gra == 2) {
            cout << "Witamy na slots\n";
            cout << "Krecimy?\n";
            cout << "1-tak/0-nie";
            cin >> gramy;
        }
    }
}