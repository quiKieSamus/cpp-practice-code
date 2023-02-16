#include <string>
#include <iostream>
#include <algorithm> // for shuffle method
#include <stdio.h>
#include <ctime>

using namespace std;

struct Deck
{
    string card[13];
};

// to use for iteration to give each deck's individual card value
string giveCardValue(int index)
{
    string value;
    if (index == 0)
    {
        value = "as";
        return value;
    }
    else if (index == 10)
    {
        return value = "j";
    }
    else if (index == 11)
    {
        return value = "q";
    }
    else if (index == 12)
    {
        return value = "k";
    }
    else
    {
        return value = to_string(index + 1);
    }
}

void poker(int players, int cardsPerPlayer, string deck[])
{
    // for (int index = 0; index < 52; index++)
    // {
    //     cout << deck[index] << " es la posicion: " << index << endl;
    // }

    if (cardsPerPlayer*players > 52)
    {
        int cardsNeeded = (cardsPerPlayer*players) - 52;
        cout << "Se necesitan " << cardsNeeded << " carta(s) para jugar apropiadamente" << endl;
        exit(0);   
    }
    

    int deckPosition = 0;
    for (int i = 1; i <= players; i++)
    {
        cout << "\nCartas jugador " << i << endl;
        if (i == 1)
        {
            for (int j = 0; j < cardsPerPlayer; j++)
            {
                cout << deck[deckPosition] << endl;
                deckPosition++;
            }
        }
        else
        {

            for (int j = deckPosition; j < cardsPerPlayer * i; j++)
            {
                cout << deck[j] << endl;
                deckPosition++;
            }
        }
    }
}

int main()
{
    // initialize strucs
    Deck diamonds;
    Deck hearts;
    Deck clubs;
    Deck spades;

    // specify type
    // diamonds.type = "diamonds";
    // hearts.type = "hearts";
    // clubs.type = "clubs";
    // spades.type = "spades";

    // fill each deck's type cards from as to k

    for (int j = 0; j < 13; j++)
    {
        string cardValue = giveCardValue(j);
        diamonds.card[j] = cardValue;
        hearts.card[j] = cardValue;
        clubs.card[j] = cardValue;
        spades.card[j] = cardValue;
        cout << diamonds.card[j] << " " << hearts.card[j] << " " << clubs.card[j] << " " << spades.card[j] << endl;
    }

    // cout << diamonds.card[1];

    srand(time(0));
    int randomNumber = rand() % 100;
    random_shuffle(&diamonds.card[0], &diamonds.card[13]);
    random_shuffle(&hearts.card[0], &hearts.card[13]);
    random_shuffle(&spades.card[0], &spades.card[13]);
    random_shuffle(&clubs.card[0], &clubs.card[13]);

    for (int i = 0; i < 13; i++)
    {
        cout << diamonds.card[i] << endl;
        cout << hearts.card[i] << endl;
        cout << spades.card[i] << endl;
        cout << clubs.card[i] << endl;
        cout << "\n"<< i << "\n\n";
    }

    // fill big deck with all cards
    int c = 0;
    string mainDeck[52];
    for (int i = 0; i < 13; i++)
    {
        mainDeck[i] = diamonds.card[c];
        c++;
    }

    c = 0;

    for (int i = 13; i < 26; i++)
    {
        mainDeck[i] = hearts.card[c];
        c++;
    }

    c = 0;

    for (int i = 26; i < 39; i++)
    {
        mainDeck[i] = spades.card[c];
        c++;
    }

    c = 0;

    for (int i = 39; i < 52; i++)
    {
        mainDeck[i] = clubs.card[c];
        c++;
    }

    for (int i = 0; i < 52; i++)
    {
        cout << i << ": " << mainDeck[i] << endl;
    }

    cout << "Ingrese Cantidad de jugadores: ";
    int playerQuantity;
    cin >> playerQuantity;
    cout << "\nIngrese Cantidad de Cartas a dar a cada jugador: ";
    int cardsPerPlayer;
    cin >> cardsPerPlayer;

    poker(playerQuantity, cardsPerPlayer, mainDeck);

    return 0;
}