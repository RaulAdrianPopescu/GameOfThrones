#include "GameOfThrones.h"

std::string TakeUserString() // Functia ne returneaza input-ul de la user
{
	std::string userInput;
	std::cout << "\nTe rog, introdu sirul de caractere: "; std::cin >> userInput;

	return userInput;
}

bool isProgramStillRunning() // Functia ce va fi testata la finalul fiecarei iteratii a while loop-ului in caz ca user-ul vrea sa testeze alt cuvant
{
	char input;
	std::cout << "Doresti sa reincerci alt cuvant? Y/N\n";
	std::cin >> input;

	if (std::toupper(input) == 'Y') // Transformam input-ul user-ului cu litera mare sa ne asiguram ca user-ul introduce versiunea corecta de Y sau N
		return true;
	else if (std::toupper(input) == 'N')
		return false;
	else
		std::cout << "Ai introdus o comanda invalida. Stingerea...\n";

	return false;
}

bool CheckPalindromeValidity(std::string& inputString)
{
	std::vector<char> letters; // Vectorul in care o sa punem toate literele din input-ul user-ului
	
	for (int i = 0; i < inputString.length(); i++) // Introducem literele din sirul de caractere in vector
		letters.push_back(inputString[i]);

	/***********************************************************************************************************
	* Comparam fiecare litera cu restul ce sunt in vector.
	* 
	*  1. De fiecare data cand o litera se repeta (si nu este pe aceeasi pozitie ca litera pe care o comparam)
	*     atunci, litera de la indexul 'i' si cea de la indexul 'j' vor fi inlocuite cu '\0'
	*  
	*  2. Daca litera de la indexul 'i' sau 'j' este deja '\0' atunci trecem la urmatoarea iteratie a lui 'j'.
	*     Daca i si j sunt egale, trecem la urmatoare iteratie a lui 'j'
	* 
	*  Exemplu: 
	*		i = 0, j = 1
	*       daca litere[i] == litere[j]
	*		atunci: litere[i] = '\0'
	*				litere[j] = '\0'
	***********************************************************************************************************/
	for (int i = 0; i < letters.size(); i++)
	{
		for (int j = 0; j < letters.size(); j++)
		{
			if (i == j || letters[i] == '\0' || letters[j] == '\0')
				continue;
			else if (letters[i] == letters[j]) 
			{ 
				letters[i] = '\0';
				letters[j] = '\0';
			}
		}
	}
	
	/*************************************************************************************************************************
	* Vom crea o variabila care sa ne numere de cate ori gasim o litera fara pereche.
	* O litera nu are pereche in momentul in care are o alta valoare inafara de '\0'.
	* 
	* Dupa care vom face urmatoarele comparatii:
	*	
	*	1. Daca avem un input cu un numar par de litere, iar oddCount este 0, inseamna ca input-ul nostru poate fi palindrom
	*   2. Daca avem un input cu un numar impar de litere, iar oddCount este 1, inseamna ca input-ul nostru poate fi palindrom
	*   3. In orice alta situatie, input-ul nu este palindrom
	* 
	* Exemplu: vector litere = {'a', 'a', 'a', 'b', 'b', 'b', 'b'}
	*		   va deveni: litere = {'\0' , '\0', 'a', '\0', '\0', '\0', '\0'}
	*          oddCount = 1, inseamnand ca "aaabbbb" este valid pentru a fi palindrom
	**************************************************************************************************************************/

	int oddCount = 0;

	for (int i = 0; i < letters.size(); i++)
	{
		if (letters[i] != '\0')
			oddCount++;
	}

	if (inputString.length() % 2 == 0 && oddCount == 0)
		return true;
	else if (inputString.length() % 2 != 0 && oddCount == 1)
		return true;
	else
		return false;
}


std::string CreatePalindrome(std::string inputString)
{
	/******************************************************************************************************************************
	* repeatingLetters - va fi compus din literele care au pereche
	* mid - va reprezenta litera fara pereche dintr-un cuvant de dimensiune impara, care va fi mijlocul palindromului ce il creem
	* palindrome - va fi compus din repeatingLetters + mid (daca este cazul) + repeatingLetters
	* 
	* Vom trece prin fiecare litera din sirul de caractere si vom incrementa o variabila "occurences" care ne contorizeaza
	* numarul de recurente a literei
	* 
	* 1. Daca litera apare de un numar par de ori si nu exista deja in repeatingLetters, atunci o vom adauga in repeatingLetter.
	* 2. Daca litera apare de un numar impar de ori (mai mare ca 1) si nu exista deja in repeatingLetters, va fi adaugat in
	*	 repeatingLetters SI in mid.
	* 3. Daca litera apare doar o SINGURA DATA in cuvantul nostru, atunci il vom adauga in mid.
	*******************************************************************************************************************************/

	std::string repeatingLetters, palindrome;
	std::string mid = " ";

	for (int i = 0; i < inputString.length(); i++)
	{
		int occurences = 0;
		for (int j = 0; j < inputString.length(); j++)
		{
			if (inputString[i] == inputString[j])
				occurences++;
		}

		if (occurences % 2 == 0 && repeatingLetters.find(inputString[i]) == std::string::npos)
		{
			for (int timesToRepeat = 0; timesToRepeat < occurences / 2; timesToRepeat++)
				repeatingLetters += inputString[i];
		}
		else if (occurences % 2 != 0 && occurences > 1 && repeatingLetters.find(inputString[i]) == std::string::npos)
		{
			for (int timesToRepeat = 0; timesToRepeat < occurences / 2; timesToRepeat++)
			{
				mid = inputString[i];
				repeatingLetters += inputString[i];
			}
		}
		else if (occurences == 1)
			mid = inputString[i];
	}

	/*****************************************************************************************************************************
	* Vom concatena palindrome in felul urmator:
	*
	* 1. Adaugam repeatingLetters, dupa care acesta va fi inversat.
	* 2a. In cazul in care mid are alta valoare inafara de " ", atunci
	*     mid va fi adaugat imediat dupa ce adaugam repeatingLetters la pasul 1.
	* 2b. In orice alta situatie, vom adauga repeatingLetters din nou, acesta fiind
	*     inversat la finalul pasului 1.
	* 3.  Returnam palindromul.
	* 
	* Exemplu: "aaabbbb" => repeatingLetters = abb; mid = a
	*          palindrome.append(repeating letters) => palindrome = "abb" (apoi inversam repeatingLetters care va deveni "bba")
	*          dupa care, palindrome += mid apoi += repeatingLetters
	*          la final, palindrome va arata astfel: palindrome = "abbabba"
	******************************************************************************************************************************/

	palindrome.append(repeatingLetters);
	std::reverse(repeatingLetters.begin(), repeatingLetters.end());

	if (mid != " ")
	{
		palindrome.append(mid);
		palindrome.append(repeatingLetters);
	}
	else
	{
		palindrome.append(repeatingLetters);
	}

	return palindrome;
}
