#include <iostream>
#include <string>
using namespace std;

string choiceText(string word) {
	bool correctWord = false;
	while (!correctWord)
	{
		int cpt = 0;
		cout << "Player 1 please choose a word for player 2 to guess :" << endl;
		cout << "The word shouldn't contains special characters." << endl;
		cin >> word;

		for (char c : word)
		{
			if ((int(c) < 65 || int(c) > 90) && (int(c) < 97 || int(c) > 122))
			{
				cout << c << " is a special character, please do not use it." << endl;
				cpt++;
			}
		}
		if (cpt == 0)
		{
			correctWord = true;
		}
	}
	return word;
}
string isRecherche(string hiddenWord, string word) {
	bool sortieBoucleJeu = false;
	int maxErr = 10;
	int cptErr = 0; // compte le nombre d'erreur.
	string propositons;
	char tryLetter;
	while (!sortieBoucleJeu)
	{
		int cpt = 0; // compteur verif si mot caché est trouvé
		bool letterFound = false;

		cout << hiddenWord << endl << endl;
		cout << "Player 2, please choose a letter :" << endl;
		cout << "The word does not contain special characters." << endl;
		if (cptErr > 0)
		{
			cout << "Errors : " << cptErr << ". " << maxErr - cptErr << " tries left." << endl;
			cout << "The word doesn't contain the letters : ";
			for (char c : propositons){cout << c;}
			cout << endl;
		}
		cin >> tryLetter;

		for (int i = 0; i < word.size(); i++){
			if (word[i] == tryLetter){
				hiddenWord[i] = tryLetter;
				letterFound = true;
			}
		}

		if (!letterFound){
			cptErr++;
			propositons += tryLetter;
		}
		//verif victory

		for (int i = 0; i < hiddenWord.size(); i++){
			if (hiddenWord[i] != '_'){cpt++;}
		}

		if (cptErr >= maxErr){
			sortieBoucleJeu = true;
			return "j1";
		}

		if (cpt == hiddenWord.size()){
			sortieBoucleJeu = true;
			return "j2";
		}
		system("CLS");
	}
}

int main() {
#pragma region value
string word;
string hiddenWord;
string victory;
#pragma endregion
	word = choiceText(word);
	system("CLS");

	for (char c : word){hiddenWord += '_';}
	victory = isRecherche(hiddenWord, word);
	system("CLS");

	if (victory =="j1"){
		cout << "The hidden word was : " << endl;
		cout << word << endl;
		cout << "Player 1 won" << endl;
	}
	else if (victory =="j2"){
		cout << "The hidden word was : " << endl;
		cout << word << endl;
		cout << "Player 2 won" << endl;
	}

	return 0;
}