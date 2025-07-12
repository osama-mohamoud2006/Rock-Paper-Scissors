#include<iostream>
#include <ctime>
#include<cstdlib>
#include <stdlib.h> // for clear screen
#include <windows.h> //for sound 
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

struct stcount_wins_and_losses {
	int user_wins = 0;
	int computer_wins = 0;
	int draws = 0;
	/*bool user_win = false;
	bool computer_win = false;*/

};
enum enScreen_color { black = 1, red = 2, yellow = 3, green = 4, red_on_black = 5, purple = 6, gameover = 7 };
enum enprobabilties_of_game {
	computer_won = 1, user_won = 2, draw = 3
};
enum  enprobabilties_of_choice {
	stone = 1, paper = 2, scissor = 3
};
void playm3lab() {
	PlaySound(TEXT("lml-b-wl.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void playMario2GameOver() {
	
	
	
	PlaySound(TEXT("smb2_game_over.wav"), NULL, SND_FILENAME | SND_ASYNC);
	

}

void animateText(const string& text, int delay = 20) {
	for (char c : text) {
		cout << c << flush;
		Sleep(delay);
	}
}
void screen_color(enScreen_color color) {
	if (color == enScreen_color::black)system("color 0F");
	if (color == enScreen_color::green)  system("color 2F");
	if (color == enScreen_color::yellow)  system("color 6F");
	if (color == enScreen_color::red)  system("color 4F");
	if (color == enScreen_color::red_on_black)  system("color 0C");
	if (color == enScreen_color::purple) system("color 0D");
	if (color == enScreen_color::gameover)  system("color 40");


}
int random(int from, int to) {
	return rand() % (to - from + 1) + from;
}
int input_from_to(int from, string text, int to) {
	int round = 0;
	do {
		cout << text;
		cin >> round;
		if (round < from || round>to) { // if user inputed number is not in range	
			cout << "\n\nplease enter correct range!\n";
			cout << '\a';
			screen_color(red_on_black);
			round = 0;
		}
		else  screen_color(black);
	} while (round < from || round>to);
	return round;
}
int user_choice() {
	// function to get user choice between 1 and 3
	return 	input_from_to(1, "", 3);
}
void print_text_after_each_round(int round_count, int& choice) {
	cout << "\nRound" << "[" << round_count << "]" << " begins :)\n\n";

	cout << "Your choice is:" << " [1]:Stone " << ", [2]:Paper " << ",[3]:scissor: ";
	choice = user_choice();
	cout << endl;
	cout << "__________Round" << "[" << round_count << "]" << "_________" << endl;
}




enprobabilties_of_game computer_vs_user(int choice_from_user, stcount_wins_and_losses& count) {
	cout << '\n';

	choice_from_user = enprobabilties_of_choice(choice_from_user);

	//[1] :Stone " << ", [2] : Paper " << ", [3] : scissor : "
	int computer_choice = random(1, 3);


	//stone vs paper && stone vs scissor 
	if (computer_choice == enprobabilties_of_choice::stone && choice_from_user == enprobabilties_of_choice::paper) {


		cout << "player choice: " << "paper" << endl;
		cout << "computer choice: " << "stone" << endl;
		cout << "\nuser won this round!\n" << endl;
		screen_color(green);
		count.user_wins++;
		return user_won;




	}

	else if (computer_choice == enprobabilties_of_choice::stone && choice_from_user == enprobabilties_of_choice::scissor) {
		cout << "player choice: " << "scissor" << endl;
		cout << "computer choice: " << "stone" << endl;
		cout << "\nComputer won this round!\n";
		screen_color(red);
		cout << '\a';
		count.computer_wins++;
		return computer_won;
	}

	else if (computer_choice == enprobabilties_of_choice::stone && choice_from_user == enprobabilties_of_choice::stone) {

		cout << "player choice: " << "stone" << endl;
		cout << "computer choice: " << "stone" << endl;
		cout << "\nComputer and you  won this round!\n";
		screen_color(yellow);
		count.draws++;
		return draw;
	}


	//if paper vs stone && paper vs scissor
	else if (computer_choice == enprobabilties_of_choice::paper && choice_from_user == enprobabilties_of_choice::scissor) {


		cout << "player choice: " << "scissor" << endl;
		cout << "computer choice: " << "paper" << endl;
		cout << "\nuser won this round!\n";
		screen_color(green);
		count.user_wins++;
		return user_won;



	}

	else if (computer_choice == enprobabilties_of_choice::paper && choice_from_user == enprobabilties_of_choice::stone) {
		cout << "player choice: " << "stone" << endl;
		cout << "computer choice: " << "paper" << endl;
		cout << "\ncomputer won this round!\n";
		screen_color(red);
		cout << '\a';
		count.computer_wins++;
		return computer_won;
	}



	else if (computer_choice == enprobabilties_of_choice::paper && choice_from_user == enprobabilties_of_choice::paper) {
		cout << "player choice: " << "paper" << endl;
		cout << "computer choice: " << "paper" << endl;
		cout << "\nComputer and you won this round!\n";
		screen_color(yellow);
		count.draws++;

		return draw;
	}



	// if scissor vs paper && scissoer vs stone
	else if (computer_choice == enprobabilties_of_choice::scissor && choice_from_user == enprobabilties_of_choice::paper) {


		cout << "player choice: " << "paper" << endl;
		cout << "computer choice: " << "scissor" << endl;
		cout << "\nComputer won this round!\n";
		screen_color(red);
		cout << '\a';
		count.computer_wins++;
		return computer_won;


	}


	else if (computer_choice == enprobabilties_of_choice::scissor && choice_from_user == enprobabilties_of_choice::stone) {
		cout << "player choice: " << "stone" << endl;
		cout << "computer choice: " << "scissor" << endl;
		cout << "\nuser won this round!\n";
		screen_color(green);
		count.user_wins++;
		return user_won;
	}


	else if (computer_choice == enprobabilties_of_choice::scissor && choice_from_user == enprobabilties_of_choice::scissor) {
		cout << "player choice: " << "scissor" << endl;
		cout << "computer choice: " << "scissor" << endl;
		cout << "\ncomputer and you  won this round!\n";
		screen_color(yellow);
		count.draws++;
		return draw;
	}





}



void the_number_of_rounds_by_user(int& choice, int& time, stcount_wins_and_losses& count) {
	cout << "enter the number of rounds you want: ";

	cin >> time;


	for (int t = 1; t <= time; t++) {
		print_text_after_each_round(t, choice);
		computer_vs_user(choice, count);
		cout << "____________________________________________________" << endl << endl;

	}





}

void game_summary(stcount_wins_and_losses& count, int time) {
	system("color 0C");

	playMario2GameOver(); 
	cout << "\n\t+==============================+\n";
	cout << "\t|       ";
	animateText("G  A  M  E   O  V  E  R", 150);
	cout << "       |\n";
	cout << "\t+==============================+\n";

	Sleep(300);
	cout << "\n\t+------------------------------+\n";
	cout << "\t|      *  ";
	animateText("R  E  S  U  L  T  S", 100);
	cout << "  *       |\n";
	cout << "\t+------------------------------+\n\n";

	Sleep(300);
	cout << "---------------------------------------------------\n";
	cout << "the game rounds: "; Sleep(200); cout << time << endl;
	cout << "player won times: "; Sleep(200); cout << count.user_wins << endl;
	cout << "computer won times: "; Sleep(200); cout << count.computer_wins << endl;
	cout << "draw times: "; Sleep(200); cout << count.draws << endl;

	Sleep(300);
	cout << "\n";
	if (count.computer_wins > count.user_wins)
		animateText("final winner is: computer\n", 50);
	else if (count.computer_wins < count.user_wins)
		animateText("final winner is: player\n", 50);
	else
		animateText("No winner!\n", 50);
}

void start_game(int& choice, int& time, stcount_wins_and_losses& count) {

	the_number_of_rounds_by_user(choice, time, count);

	char need = ' ';
	do {
		game_summary(count, time);
		cout << "\n\n-------------------------------------------------------\n";
		cout << "\ndo you need another round? y/n ";
		cin >> need;
		if (need == 'y' || need == 'Y') {
			count.user_wins = 0;
			count.computer_wins = 0;
			count.draws = 0;
			playm3lab();
				
			
			system("CLS");//clear the whole screen
			screen_color(black);

			the_number_of_rounds_by_user(choice, time, count);
		}

	} while (need == 'y' || need == 'Y');
	cout << '\n';
	cout << "\n\n-------------------------------------------------------\n";
	cout << "see you later! " << endl << endl;





}

int main() {
	srand((unsigned)time(NULL)); // Seed for random number generation
	stcount_wins_and_losses count;
	int choice = 0;
	int time = 0;

	screen_color(black);
	start_game(choice, time, count);



}
