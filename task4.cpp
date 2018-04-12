#include <iostream>

using namespace std;

int main()
{
	string answer1, answer2, reply;
	answer1 = "A joey";
	answer2 = "a joey";

	cout << "What is a baby kangaroo called? \n\n\n";
	getline(cin, reply);
	if ((reply == answer1) || (reply == answer2)) {
		cout << "That's the right answer, congrats";
	} else {
		cout << "\n\n That's the wrong answer, try again!.\n\n"
		cout << "What is a baby kangaroo called? \n\n";
	getline(cin , reply);
	if ((reply == answer1) || (reply == answer2))
		count << "That's the right answer";
	} else {
		count << "Game Over,try harder next time";
	}
	return 0;
}