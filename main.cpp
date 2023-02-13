#include <string>
#include <iostream>
#include <algorithm> // for shuffle method
#include <stdio.h>
#include <ctime>

using namespace std;

struct Deck
{
    string card[12];
};

// to use for iteration to give each deck's individual card value
string giveCardValue(int index)
{
    string value;
    if (index == 0)
    {
        return value = "as";
    }
    if (index == 10)
    {
        return value = "j";
    }
    if (index == 11)
    {
        return value = "q";
    }
    if (index == 12)
    {
        return value = "k";
    }
    else
    {
        return value = to_string(index + 1);
    }

    return value;
}

void poker(int players, int cardsPerPlayer, string deck[])
{
    for (int index = 0; index < 52; index++)
    {
        cout << deck[index] << " es la posicion: " << index << endl;
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
                deckPosition = j++;
            }
        }
        else
        {

            for (int j = deckPosition; j < cardsPerPlayer * i; j++)
            {
                cout << deck[j] << endl;
                deckPosition = j++;
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
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < 13; j++)
            {
                diamonds.card[j] = giveCardValue(j);
            }
        }

        if (i == 1)
        {
            for (int j = 0; j < 13; j++)
            {
                hearts.card[j] = giveCardValue(j);
            }
        }

        if (i == 2)
        {
            for (int j = 0; j < 13; j++)
            {
                clubs.card[j] = giveCardValue(j);
            }
        }

        if (i == 3)
        {
            for (int j = 0; j < 13; j++)
            {
                spades.card[j] = giveCardValue(j);
            }
        }
    }

    for (int i = 0; i < 13; i++)
    {
        cout << "\ndiamonds: " << diamonds.card[i] << "\n";
        cout << "\nhearts: " << hearts.card[i] << "\n";
        cout << "\nclubs: " << clubs.card[i] << "\n";
        cout << "\nspades: " << spades.card[i] << "\n";
    }

    // cout << diamonds.card[1];

    srand(time(0));
    int randomNumber = rand() % 100;
    random_shuffle(&diamonds.card[0], &diamonds.card[13]);
    random_shuffle(&spades.card[0], &spades.card[13]);
    random_shuffle(&clubs.card[0], &clubs.card[13]);
    random_shuffle(&hearts.card[0], &hearts.card[13]);

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

    // cout << "Ingrese Cantidad de jugadores: " << endl;
    // int playerQuantity;
    // cin >> playerQuantity;
    // cout << "\nIngrese Cantidad de Cartas a dar a cada jugador: " << endl;
    // int cardsPerPlayer;
    // cin >> cardsPerPlayer;

    // poker(playerQuantity, cardsPerPlayer, mainDeck);

    return 0;
}