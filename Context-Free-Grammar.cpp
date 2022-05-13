#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <string.h>
using namespace std;

string S(); //Wczesna deklaracje funkcji S
string A(); //Wczesna deklaracje funkcji A
string B(); //Wczesna deklaracje funkcji B

//Ustawiam alfabet (a,b)->(a=0,b=1)-system binarny
string binarna(string ciag) //Zamienia ciag na system dwojkowy
{
    string napis = "";
    int pom = 0;
    int index;
    for (int i = 0; i < ciag.length(); i++)
    {
        if (ciag[i] == 'b')
        {
            index = i;
            break;
        }
    }
    for (int j = index; j < ciag.length(); j++)
    {
        if (ciag[j] == 'a') napis += '0';
        else napis += '1';
    }
    return napis;
}

void sortowanie_string(string t[], int n) //Na poczatku sortuje bubblesortem po dlugosiach lancuchow
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].length() > t[j].length()) swap(t[j], t[i]);
            else if (t[i].length() == t[j].length())
            {
                string binarna_i = binarna(t[i]);
                string binarna_i1 = binarna(t[j]);
                if (binarna_i1.length() < binarna_i.length()) swap(t[i], t[j]);
                else if (binarna_i1.length() == binarna_i.length())
                {
                    if (binarna_i1 < binarna_i)
                    {
                        swap(t[i], t[j]);
                    }
                }
            }
        }
    }
}

int main()
{
    srand(time(NULL)); //Do liczb losowych przy funkcjach S(),A(),B()
    int n;
    cout << "Program wypisuje na ekranie n posortowanych kanonicznie roznych lancuchow" << endl;
    cout << "z jezyka opisanego za pomoca gramatyki bezkontekstowej:" << endl;
    cout << "S->aB|bA  A->a|AS|bA   B->b|bS|aBB" << endl << endl;
    cout << "Prosze podac ile roznych lancuchow z podanej gramatyki bezkontekstowej ma wypisac program:";
    cin >> n;
    string napisy[100];
    bool pom = true;

    for (int i = 0; i < n; i++)
    {

        if (pom)
        {
            string napis = "";
            napisy[i] = S().c_str();
            pom = false;
        }

        else
        {

        SKOK:
            string napis = "";
            napisy[i] = S().c_str();
            if (napisy[i].length() > 45) goto SKOK;
            for (int j = 0; j < i; j++)
            {
                if (napisy[j] == napisy[i]) goto SKOK;
            }

        }
    }

    //Sortuje po dlugosci lancuchow
    sortowanie_string(napisy, n);
    //Wypisuje lancuchy

    for (int i = 0; i < n; i++)
    {
        cout << napisy[i] << endl;
    }
    
    return 0;
}

string S()
{
    int liczba = rand() % 2;
    if (liczba == 0) return "a" + B();
    else return "b" + A();
}

string A()
{
    int liczba = rand() % 3;
    if (liczba == 0) return "a";
    else if (liczba == 1) return A() + S();
    else return "b" + A();
}

string B()
{
    int liczba = rand() % 3;
    if (liczba == 0) return "b";
    else if (liczba == 1) return "b" + S();
    else return "a" + B() + B();
}
