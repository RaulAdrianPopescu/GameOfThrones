# GameOfThrones
Small project in which we take a random string of characters, verify if it could be a palindrome and then arrange it into one.


///////////////////////////////////////////////////////////// DESCRIPTION (RO) \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

Dothraki plănuiesc să usurpe tronul Regelui Robert. 
Regele Robert aude de această conspirație de la un raven și plănuiește să încuie singura ușă prin care inamicul poate să 
pătrundă în regat lui.
Dar această ușă are nevoie de o cheie care este reprezentată de către anagrama unui palindrom. 
începe să caute în cutia lui de șiruri de caractere, verificând pe fiecare în parte dacă poate fi rearanjat într-un palindrom.

Cerinta:
  Pentru un șir de caractere, să se tipărească pe ecran cuvântul DA sau NU dacă acest șir poate fi rearanjat astfel 
încât să fie un palindrom.

Constrangeri:
  Pot fi folosite doar caractere din alfabetul latin cu litere mici.
 
  Input:
   Sirul de caractere.

Exemplu:
  Input:
      aaabbbb
  Output:
      DA
      Sirul poate fi permutat astfel: bbaaabb


/////////////// SOLUTION BREAKDOWN \\\\\\\\\\\\

GameOfThrones.cpp:

TakeUserString():                       Functia ne returneaza input-ul de la user
isProgramStillRunning():                Functia ce va fi testata la finalul fiecarei iteratii a while loop-ului in caz ca user-ul vrea sa testeze alt cuvant

CheckPalindromeValidity(inputString):

                        A.Comparam fiecare litera cu restul ce sunt in vector (vector de tip char ce va fi compus din toate literele ce formeaza inputString) astfel:

                        A1. De fiecare data cand o litera se repeta (si nu este pe aceeasi pozitie ca litera pe care o comparam)
                           atunci, litera de la indexul 'i' si cea de la indexul 'j' vor fi inlocuite cu '\0'.
                        A2. Daca litera de la indexul 'i' sau 'j' este deja '\0' atunci trecem la urmatoarea iteratie a lui 'j'. 
                           Daca i si j sunt egale, trecem la urmatoare iteratie a lui 'j'.
                           Exemplu: 
	                            	i = 0, j = 1
	                              daca litere[i] == litere[j]
	                              atunci: litere[i] = '\0'
                                        litere[j] = '\0'
                                        
                        B.Vom crea o variabila care sa ne numere de cate ori gasim o litera fara pereche.
                          O litera nu are pereche in momentul in care are o alta valoare inafara de '\0'.
                          
                          Dupa care vom face urmatoarele comparatii:
                          
                        B1. Daca avem un input cu un numar par de litere, iar oddCount este 0, inseamna ca input-ul nostru poate fi palindrom.
                        B2. Daca avem un input cu un numar impar de litere, iar oddCount este 1, inseamna ca input-ul nostru poate fi palindrom.
                        B3. In orice alta situatie, input-ul nu este palindrom.
                        
CreatePalindrome(inputString):

                        A. Vom crea urmatoarele variabile:
                            repeatingLetters - va fi compus din literele care au pereche
                            mid - va reprezenta litera fara pereche dintr-un cuvant de dimensiune impara, care va fi mijlocul palindromului ce il creem
                            palindrome - va fi compus din repeatingLetters + mid (daca este cazul) + repeatingLetters
                            
                        B. Vom trece prin fiecare litera din sirul de caractere si vom incrementa o variabila "occurences" care ne contorizeaza numarul de recurente a literei.
                           Dupa care:
                        
                        B1. Daca litera apare de un numar par de ori si nu exista deja in repeatingLetters, atunci o vom adauga in repeatingLetter.
                        B2. Daca litera apare de un numar impar de ori (mai mare ca 1) si nu exista deja in repeatingLetters, va fi adaugat in repeatingLetters SI in mid.
                        B3. Daca litera apare doar o SINGURA DATA in cuvantul nostru, atunci il vom adauga in mid.
                        
                        C. Vom concatena palindrome astfel:
                        
                        C1. Adaugam repeatingLetters, dupa care acesta va fi inversat.
                        C2a. In cazul in care mid are alta valoare inafara de " ", atunci mid va fi adaugat imediat dupa ce adaugam repeatingLetters la pasul 1.
                        C2b. In orice alta situatie, vom adauga repeatingLetters din nou, acesta fiind inversat la finalul pasului 1.
                        C3.  Returnam palindromul.
                        
                        Exemplu:
                              "aaabbbb" => repeatingLetters = abb; mid = a
                              palindrome.append(repeating letters) => palindrome = "abb" (apoi inversam repeatingLetters care va deveni "bba")
                              dupa care, palindrome += mid apoi += repeatingLetters
                              la final, palindrome va arata astfel: palindrome = "abbabba"
