/*******************************************************************************************************************************
* Dothraki plănuiesc să usurpe tronul Regelui Robert. 
* Regele Robert aude de această conspirație de la un raven și plănuiește să încuie singura ușă prin care inamicul poate să 
* pătrundă în regat lui.
* Dar această ușă are nevoie de o cheie care este reprezentată de către anagrama unui palindrom. 
* începe să caute în cutia lui de șiruri de caractere, verificând pe fiecare în parte dacă poate fi rearanjat într-un palindrom.
* 
* Cerinta:
*   Pentru un șir de caractere, să se tipărească pe ecran cuvântul DA sau NU dacă acest șir poate fi rearanjat astfel 
* încât să fie un palindrom.
* 
* Constrangeri:
*   Pot fi folosite doar caractere din alfabetul latin cu litere mici.
* 
* Input:
*   Sirul de caractere.
* 
* Exemplu:
*   Input:
*       aaabbbb
*   Output:
*       DA
*       Sirul poate fi permutat astfel: bbaaabb
********************************************************************************************************************************/

#include "GameOfThrones.h"

int main()
{
    do 
    {
        std::string userInput = TakeUserString();

        if (CheckPalindromeValidity(userInput))
        {
            std::cout << "\nDA\n" << "Sirul poate fi permutat astfel: ";
            std::cout << CreatePalindrome(userInput) << '\n';
            std::cout << std::endl;
        }
        else
            std::cout << "\nNU\n\n";
    } 
    while (isProgramStillRunning()); // Vom intreba user-ul daca doreste sa incerce alt cuvant

    return 0;
}
