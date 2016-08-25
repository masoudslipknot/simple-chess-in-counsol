#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<ctime>
#include<math.h>
#include<string.h>

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorCoord;
	cursorCoord.X = x;
	cursorCoord.Y = y;
	SetConsoleCursorPosition(consoleHandle, cursorCoord);
}
void setTextColor(int textColor, int backColor = 0)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int colorAttribute = backColor << 4 | textColor;
	SetConsoleTextAttribute(consoleHandle, colorAttribute);
}
void sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}
void clrscr(){
	system("cls");
}

void printTheMap(char chessboard[10][20], int& whitesum, int &blacksum){

	int i, j;                                              //temp is used for piece and temp2 and temp3 are used for first position
	for (i = 0; i < 10; i++){
		if (i>0)
			printf("\n");
		for (j = 0; j < 20; j++)
		if (chessboard[i][j]<123 && chessboard[i][j]>96){
			setTextColor(0, 6);
			printf("%c", chessboard[i][j]);
		}
		else if (chessboard[i][j]<91 && chessboard[i][j]>64){
			setTextColor(7, 0);
			printf("%c", chessboard[i][j]);
		}
		else {
			setTextColor(7, 0);
			printf("%c", chessboard[i][j]);
		}
	}
	gotoxy(0, 8);
	printf("------------------");
	printf("\n");
	printf(" A B C D E F G H ");
	printf("\n\n\nMenu \n");
	printf("click the # of the action you want to do\n");
	printf("1-chess Roles\n");
	printf("2-offer draw\n");
	printf("3-How to play\n");
	printf("4-credit\n");
	printf("5-save game\n");
	printf("6-Load game\n");
	printf("7-new game\n");
	printf("8-best points\n");
	printf("9-Quit\n");
	printf("\n");
	setTextColor(3, 0);
	printf("produced by erfani company all right reserved 2014");
	gotoxy(55, 0);
	printf("white points");
	gotoxy(55, 2);
	printf("black points");
	gotoxy(53, 0);
	setTextColor(7, 0);
	printf("%d", whitesum);
	gotoxy(53, 2);
	printf("%d", blacksum);
	gotoxy(20, 0);
	setTextColor(7, 0);
	printf("black");
	gotoxy(20, 7);
	printf("white");
	gotoxy(7, 0);



}
void game(char chessboard[10][20], int&whitesum, int&blacksum){
	whitesum = 0;
	blacksum = 0;
	int i, j;
	char newboard[10][20] = { { '|', 'r', '|', 'n', '|', 'b', '|', 'q', '|', 'k', '|', 'b', '|', 'n', '|', 'r', '|', ' ', '8' }, { '|', 'p', '|', 'p', '|', 'p', '|', 'p', '|', 'p', '|', 'p', '|', 'p', '|', 'p', '|', ' ', '7' }, { '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', ' ', '6' }, { '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', ' ', '5' }, { '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', ' ', '4' }, { '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', ' ', '3' }, { '|', 'P', '|', 'P', '|', 'P', '|', 'P', '|', 'P', '|', 'P', '|', 'P', '|', 'P', '|', ' ', '2' }, { '|', 'R', '|', 'N', '|', 'B', '|', 'Q', '|', 'K', '|', 'B', '|', 'N', '|', 'R', '|', ' ', '1' }, };
	clrscr();
	for (i = 0; i < 10; i++)
	for (j = 0; j < 20; j++){
		chessboard[i][j] = newboard[i][j];
	}
	printTheMap(chessboard, whitesum, blacksum);

}
void knightmove(int &temp3, int &temp2, int& turn, char temp, int& x, int &y, char chessboard[][20])
{
	//temp is used for piece and temp2 and temp3 are used for first position
	if (temp == 'N'){
		if ((x == temp3 + 2 && y == temp2 - 2) || (x == temp3 - 2 && y == temp2 - 2) || (x == temp3 + 2 && y == temp2 + 2) || (x == temp3 - 2 && y == temp2 + 2) || (x == temp3 + 4 && y == temp2 - 1) || (x == temp3 + 4 && y == temp2 + 1) || (x == temp3 - 4 && y == temp2 - 1) || (x == temp3 - 4 && y == temp2 + 1)){
			chessboard[y][x] = temp;

		}
		else{
			gotoxy(26, 8);
			printf("wrong place try again kniaght moves like l");
			turn = 0;
		}

	}
	else if (temp == 'n'){
		if ((x == temp3 + 2 && y == temp2 - 2) || (x == temp3 - 2 && y == temp2 - 2) || (x == temp3 + 2 && y == temp2 + 2) || (x == temp3 - 2 && y == temp2 + 2) || (x == temp3 + 4 && y == temp2 - 1) || (x == temp3 + 4 && y == temp2 + 1) || (x == temp3 - 4 && y == temp2 - 1) || (x == temp3 - 4 && y == temp2 + 1)){
			chessboard[y][x] = temp;
		}
		else{
			gotoxy(26, 8);
			printf("wrong place try again kniaght moves like l");
			turn = -1;
		}
	}

}
void pawnmove(int& temp3, int &temp2, int& turn, char temp, int& x, int &y, char chessboard[][20])
{
	//temp is used for piece and temp2 and temp3 are used for first position
	if (temp == 'P'&&temp2 == 6){

		if ((x == temp3&& y == temp2 - 2 && chessboard[y][x] == '_'&&chessboard[temp2 - 1][temp3] == '_') || (x == temp3&& y == temp2 - 1 && chessboard[y][x] == '_') || (x == temp3 + 2 && y == temp2 - 1 && chessboard[y][x] != '_') || (x == temp3 - 2 && y == temp2 - 1 && chessboard[y][x] != '_')){
			chessboard[y][x] = temp;



		}
		else{
			turn = 0;
		}
	}

	else if (temp == 'p'&&temp2 == 1){


		if ((x == temp3&& y == temp2 + 2 && chessboard[y][x] == '_'&&chessboard[temp2 + 1][temp3] == '_') || (x == temp3&& y == temp2 + 1 && chessboard[y][x] == '_') || (x == temp3 + 2 && y == temp2 + 1 && chessboard[y][x] != '_') || (x == temp3 - 2 && y == temp2 + 1 && chessboard[y][x] != '_')){
			chessboard[y][x] = temp;
		}

		else{
			gotoxy(26, 8);
			printf("wrong place");
			turn = -1;
		}
	}


}
void pawn2move(int &temp3, int &temp2, int& turn, char temp, int& x, int& y, char chessboard[][20])
{
	//temp is used for piece and temp2 and temp3 are used for first position
	if (temp == 'P'&&temp2 != 6){


		if ((x == temp3&& y == temp2 - 1 && chessboard[y][x] == '_') || (x == temp3 - 2 && y == temp2 - 1 && chessboard[y][x] != '_') || (x == temp3 + 2 && y == temp2 - 1 && chessboard[y][x] != '_')){
			chessboard[y][x] = temp;
		}
		else{
			turn = 0;
		}

	}
	else if (temp == 'p'&&temp2 != 1){

		if ((x == temp3&& y == temp2 + 1 && chessboard[y][x] == '_') || (x == temp3 - 2 && y == temp2 + 1 && chessboard[y][x] != '_') || (x == temp3 + 2 && y == temp2 + 1 && chessboard[y][x] != '_')){
			chessboard[y][x] = temp;
		}
		else{
			turn = -1;
		}

	}
}
void Rockmove(int &temp3, int &temp2, int& turn, char temp, int &x, int &y, char chessboard[][20]){
	//temp is used for piece and temp2 and temp3 are used for first position
	int i = temp3, j = temp2;
	if (temp == 'R'){
		if (x == temp3 || y == temp2){
			if (x == temp3&&y != temp2){
				for (j = temp2; j > y; j--){
					if (chessboard[j][x] != '_'){
						turn = 0;
						break;
					}
				}
				if (turn != 0)
					chessboard[y][x] = temp;
			}
			if (x != temp3&&y == temp2){
				for (i = temp3; i < x; i = i + 2){
					if (chessboard[y][i] != '_'){
						turn = 0;
						break;
					}
				}
				if (turn != 0)
					chessboard[y][x] = temp;
			}
			if (x != temp3&&y == temp2){
				for (i = temp3; i>x; i = i - 2){
					if (chessboard[y][i] != '_'){
						turn = 0;
						break;
					}
				}
				if (turn != 0)
					chessboard[y][x] = temp;
				//else chessboard[y][x] = '_';

			}
			if (x == temp3&&y != temp2){
				for (j = temp2; j < y; j++){
					if (chessboard[j][x] != '_'){
						turn = 0;
						break;
					}
				}
				if (turn != 0)
					chessboard[y][x] = temp;
				//else chessboard[y][x] = '_';

			}
		}
		else turn = 0;
	}
	else if (temp == 'r'){
		if (x == temp3 || y == temp2){
			if (x == temp3&&y != temp2){
				for (j = temp2; j < y; j++){
					if (chessboard[j][x] != '_'){
						turn = -1;
						break;
					}
				}
				if (turn != -1)
					chessboard[y][x] = temp;
				//else chessboard[y][x] = '_';
			}
			if (x == temp3&&y != temp2){
				for (j = temp2; j > y; j--){
					if (chessboard[j][x] != '_'){
						turn = -1;
						break;
					}
				}
				if (turn != -1)
					chessboard[y][x] = temp;
				//else chessboard[y][x] = '_';
			}
			if (x != temp3&&y == temp2){
				for (i = temp3; i < x; i = i + 2){
					if (chessboard[y][i] != '_'){
						turn = -1;
						break;
					}
				}
				if (turn != -1)
					chessboard[y][x] = temp;
				;
			}
			if (x != temp3&&y == temp2){
				for (i = temp3; i > x; i = i - 2){
					if (chessboard[y][i] != '_'){
						turn = -1;
						break;
					}
					if (turn != -1)
						chessboard[y][x] = temp;
					//else chessboard[y][x] = '_';
				}
			}
		}
		else turn = -1;
	}
}
void whitebishobmove(int &temp3, int &temp2, int& turn, char temp, int &x, int &y, char chessboard[][20]){
	int i, j, sw = 1, wh = 1;                                          //temp is used for piece and temp2 and temp3 are used for first position
	if (temp == 'B'){
		if ((temp3 - x == 2 * (temp2 - y)) || (x - temp3 == 2 * (temp2 - y)) || (temp3 - x == 2 * (y - temp2)) || (x - temp3 == 2 * (y - temp2))){
			for (i = temp3, j = temp2; i > x&& j > y; i = i - 2, j--){
				if (chessboard[j][i] != '_'){
					turn = 0;
					sw = 0;
					break;
				}


			}
			if (turn != 0 && sw != 0)

				chessboard[y][x] = temp;





			for (i = temp3, j = temp2; i<x&& j>y; i = i + 2, j--){
				if (chessboard[j][i] != '_'){
					turn = 0;
					sw = 0;
					break;
				}
			}
			if (turn != 0 && sw != 0){

				chessboard[y][x] = temp;

			}





			for (i = temp3, j = temp2; i > x&& j < y; i = i - 2, j++){
				if (chessboard[j][i] != '_'){
					turn = 0;
					sw = 0;
					break;
				}
			}
			if (turn != 0 && sw != 0){

				chessboard[y][x] = temp;

			}



			for (i = temp3, j = temp2; i < x&& j < y; i = i + 2, j++){
				if (chessboard[j][i] != '_'){
					turn = 0;
					sw = 0;
					break;
				}

			}
			if (turn != 0 && sw != 0){

				chessboard[y][x] = temp;
			}


		}
		else turn = 0;
	}

	else if (temp == 'b'){
		if ((temp3 - x == 2 * (temp2 - y)) || (x - temp3 == 2 * (temp2 - y)) || (temp3 - x == 2 * (y - temp2)) || (x - temp3 == 2 * (y - temp2))){
			for (i = temp3, j = temp2; i > x&& j > y; i = i - 2, j--){
				if (chessboard[j][i] != '_'){
					turn = -1;
					wh = 0;
					break;
				}


			}
			if (turn != -1 && wh != 0)

				chessboard[y][x] = temp;

			else chessboard[y][x] = '_';



			for (i = temp3, j = temp2; i<x&& j>y; i = i + 2, j--){
				if (chessboard[j][i] != '_'){
					turn = -1;
					wh = 0;
					break;
				}
			}
			if (turn != -1 && wh != 0){

				chessboard[y][x] = temp;

			}
			else chessboard[y][x] = '_';




			for (i = temp3, j = temp2; i > x&& j < y; i = i - 2, j++){
				if (chessboard[j][i] != '_'){
					turn = -1;
					wh = 0;
					break;
				}
			}
			if (turn != -1 && wh != 0){

				chessboard[y][x] = temp;

			}
			else chessboard[y][x] = '_';


			for (i = temp3, j = temp2; i < x&& j < y; i = i + 2, j++){
				if (chessboard[j][i] != '_'){
					turn = -1;
					wh = 0;
					break;
				}

			}
			if (turn != -1 && wh != 0){

				chessboard[y][x] = temp;
			}

			else chessboard[y][x] = '_';
		}
		else turn = -1;
	}
}
void quienmove(int &temp3, int &temp2, int&turn, char temp, int&x, int&y, char chessboard[][20]){
	int i, j, k, t, sw = 1, wh = 1;                                                         //temp is used for piece and temp2 and temp3 are used for first position
	if (temp == 'Q'){
		if ((x == temp3) || (y == temp2) || (x - temp3 == 2 * (temp2 - y)) || (temp3 - x == 2 * (temp2 - y)) || (temp3 - x == 2 * (y - temp2)) || (x - temp3 == 2 * (y - temp2))){
			if (x == temp3 || y == temp2){
				if (x == temp3&&y != temp2){
					for (j = temp2; j > y; j--){
						if (chessboard[j][x] != '_'){
							turn = 0;
							break;
						}
					}
					if (turn != 0)
						chessboard[y][x] = temp;
				}
				if (x != temp3&&y == temp2){
					for (i = temp3; i < x; i = i + 2){
						if (chessboard[y][i] != '_'){
							turn = 0;
							break;
						}
					}
					if (turn != 0)
						chessboard[y][x] = temp;
				}
				if (x != temp3&&y == temp2){
					for (i = temp3; i>x; i = i - 2){
						if (chessboard[y][i] != '_'){
							turn = 0;
							break;
						}
					}
					if (turn != 0)
						chessboard[y][x] = temp;
					else chessboard[y][x] = '_';

				}
				if (x == temp3&&y != temp2){
					for (j = temp2; j < y; j++){
						if (chessboard[j][x] != '_'){
							turn = 0;
							break;
						}
					}
					if (turn != 0)
						chessboard[y][x] = temp;
					else chessboard[y][x] = '_';

				}
			}
			if ((x - temp3 == 2 * (temp2 - y)) || (temp3 - x == 2 * (temp2 - y)) || (temp3 - x == 2 * (y - temp2)) || (x - temp3 == 2 * (y - temp2))){
				for (k = temp3, t = temp2; k > x&& t > y; k = k - 2, t--){
					if (chessboard[t][k] != '_'){
						turn = 0;
						sw = 0;
						break;
					}


				}
				if (turn != 0 && sw != 0)

					chessboard[y][x] = temp;

				else chessboard[y][x] = '_';



				for (k = temp3, t = temp2; k<x&& t>y; k = k + 2, t--){
					if (chessboard[t][k] != '_'){
						turn = 0;
						sw = 0;
						break;
					}
				}
				if (turn != 0 && sw != 0){

					chessboard[y][x] = temp;

				}
				else chessboard[y][x] = '_';




				for (k = temp3, t = temp2; k > x&& t < y; k = k - 2, t++){
					if (chessboard[t][k] != '_'){
						turn = 0;
						sw = 0;
						break;
					}
				}
				if (turn != 0 && sw != 0){

					chessboard[y][x] = temp;

				}
				else chessboard[y][x] = '_';


				for (k = temp3, t = temp2; k < x&& t < y; k = k + 2, t++){
					if (chessboard[t][k] != '_'){
						turn = 0;
						sw = 0;
						break;
					}

				}
				if (turn != 0 && sw != 0){

					chessboard[y][x] = temp;
				}

				else chessboard[y][x] = '_';
			}
		}
		else turn = 0;
	}
	else if (temp == 'q'){
		if ((x == temp3) || (y == temp2) || (x - temp3 == 2 * (temp2 - y)) || (temp3 - x == 2 * (temp2 - y)) || (temp3 - x == 2 * (y - temp2)) || (x - temp3 == 2 * (y - temp2))){
			if (x == temp3 || y == temp2){
				if (x == temp3&&y != temp2){
					for (j = temp2; j > y; j--){
						if (chessboard[j][x] != '_'){
							turn = -1;
							break;
						}
					}
					if (turn != -1)
						chessboard[y][x] = temp;
				}
				else chessboard[y][x] = '_';
				if (x != temp3&&y == temp2){
					for (i = temp3; i < x; i = i + 2){
						if (chessboard[y][i] != '_'){
							turn = -1;
							break;
						}
					}
					if (turn != -1)
						chessboard[y][x] = temp;
				}
				if (x != temp3&&y == temp2){
					for (i = temp3; i>x; i = i - 2){
						if (chessboard[y][i] != '_'){
							turn = -1;
							break;
						}
					}
					if (turn != -1)
						chessboard[y][x] = temp;


				}
				else chessboard[y][x] = '_';
				if (x == temp3&&y != temp2){
					for (j = temp2; j < y; j++){
						if (chessboard[j][x] != '_'){
							turn = -1;
							break;
						}
					}
					if (turn != -1)
						chessboard[y][x] = temp;


				}
				else chessboard[y][x] = '_';
			}
			if ((x - temp3 == 2 * (temp2 - y)) || (temp3 - x == 2 * (temp2 - y)) || (temp3 - x == 2 * (y - temp2)) || (x - temp3 == 2 * (y - temp2))){
				for (k = temp3, t = temp2; k > x&& t > y; k = k - 2, t--){
					if (chessboard[t][k] != '_'){
						turn = -1;
						wh = 0;
						break;
					}


				}
				if (turn != -1 && wh != 0)

					chessboard[y][x] = temp;

				else chessboard[y][x] = '_';



				for (k = temp3, t = temp2; k<x&& t>y; k = k + 2, t--){
					if (chessboard[t][k] != '_'){
						turn = -1;
						wh = 0;
						break;
					}
				}
				if (turn != -1 && wh != 0){

					chessboard[y][x] = temp;

				}
				else chessboard[y][x] = '_';




				for (k = temp3, t = temp2; k > x&& t < y; k = k - 2, t++){
					if (chessboard[t][k] != '_'){
						turn = -1;
						wh = 0;
						break;
					}
				}
				if (turn != -1 && wh != 0){

					chessboard[y][x] = temp;

				}
				else chessboard[y][x] = '_';


				for (k = temp3, t = temp2; k < x&& t < y; k = k + 2, t++){
					if (chessboard[t][k] != '_'){
						turn = -1;
						wh = 0;
						break;
					}

				}
				if (turn != -1 && wh != 0){

					chessboard[y][x] = temp;
				}

				else chessboard[y][x] = '_';
			}

		}
		else turn = -1;
	}
}
void draw(){
	char ans = 0;
	gotoxy(20, 0);
	printf("Your opponent offerd draw\n");
	printf(" do you accsept draw press buttom? y/n\n");
	ans = getch();
	if (ans == 'y'){ printf("draw by agrement\n"); }
	else{
		printf(" play on\n");
	}
	printf("press 2 to return to main menu\n");



}
void kingmove(int temp3, int temp2, int&turn, char temp, int&x, int &y, char chessboard[][20]){
	if (temp == 'K'){
		if ((x == temp3&&y == temp2 - 1) || (x == temp3&&y == temp2 + 1) || (x == temp3 + 2 && y == temp2) || (x == temp3 - 2 && y == temp2) || (x == temp3 + 2 && y == temp2 - 1) || (x == temp3 - 2 && y == temp2 - 1) || (x == temp3 + 2 && y == temp2 + 1) || (x == temp3 - 2 && y == temp2 + 1))
			chessboard[y][x] = temp;
		else turn = 0;
	}
	else if (temp == 'k'){
		if ((x == temp3&&y == temp2 - 1) || (x == temp3&&y == temp2 + 1) || (x == temp3 + 2 && y == temp2) || (x == temp3 - 2 && y == temp2) || (x == temp3 + 2 && y == temp2 - 1) || (x == temp3 - 2 && y == temp2 - 1) || (x == temp3 + 2 && y == temp2 + 1) || (x == temp3 - 2 && y == temp2 + 1))
			chessboard[y][x] = temp;
		else turn = -1;
	}
}
void printcredit(){
	gotoxy(30, 0);
	printf("credit\n");
	gotoxy(0, 3);
	printf("project lead:Masoud erfani");
	gotoxy(0, 6);
	printf("programing lead:Masoud erfani\n");
	printf("thanks to all who have helped me along the way\n");
	printf("produced by erfani Remedy company\n");
	printf("press 4 to return to main menu");



}
void howtoplay(){
	gotoxy(30, 0);
	printf("(How to play)");
	gotoxy(0, 3);
	printf("\n");
	printf("         --->  is used for wright move\n    ");
	printf("    <---  is uesd for left move \n");
	printf("  |\n");
	printf("  |\n");
	printf("  \\/ is used for down move   \n");
	printf("\n");
	printf("  /\\ \n");
	printf("  |\n");
	printf("  |  is used for up move     \n");
	printf("\n");
	printf(" P is used in this game to pick up and put down pieces\n");
	printf("press 3 to return to main menu");



}
void role(){

	gotoxy(30, 0);
	printf("chess role");
	gotoxy(0, 3);
	printf("Every piese has it own role\n");
	printf("pawn role:at first it can go two or one step then only one step and it cant come back\n");
	printf("knight role:it goes like L\n");
	printf("bishob role:it gose throw diemeters\n");
	printf("rock role:it goes throw clomens\n");
	printf("quin role:it goes like bishob and rock\n");
	printf("king move:it goes only one step to rvery navigation\n");
	printf("in this chess if you put a piece then you have to play with it\n");
	printf("press 1 to return to main menu");
}
void savegame(char chessboard[10][20], int &whitesum, int &blacksum, int&turn){
	FILE *savegame;                                  //this funtinn gets array and points and turn and wrire them on file
	int i;
	gotoxy(28, 8);
	char savename[20];
	FILE *chess;
	
	printf("please enter your save game name");
	scanf("%s", &savename);
	
	
		chess = fopen("chess.dat", "a+b");
		if (!chess){
			printf("cant open the file its your problem");
			return;
		}
		gotoxy(28, 8);
		printf("%s", savename);
		fwrite(savename, 20 * sizeof(char), 1, chess);
		fclose(chess);
		savegame = fopen(savename, "w+b");
		fwrite(chessboard, 200 * sizeof(char), 1, savegame);
		fwrite(&whitesum, 1 * sizeof(int), 1, savegame);
		fwrite(&blacksum, 1 * sizeof(int), 1, savegame);
		fwrite(&turn, 1 * sizeof(int), 1, savegame);
		fclose(savegame);
	
}
void savegame2(char chessboard[10][20], int &whitesum, int &blacksum, int&turn){
	FILE *savegame;                                  //this funtinn gets array and points and turn and wrire them on file
	int i;
	gotoxy(28, 8);
	char savename[20];
	char save[20];
	FILE *chess;
	int sw = 0;
	if (sw == 0){
		printf("please enter your save game name");
		scanf("%s", &savename);
		scanf("%s", &save);
		sw = 1;

		chess = fopen("chess.dat", "a+b");
		if (!chess){
			printf("cant open the file its your problem");
			return;
		}
		gotoxy(28, 8);
		printf("%s", savename);
		fwrite(savename, 20 * sizeof(char), 1, chess);
		fclose(chess);
		savegame = fopen(savename, "w+b");
		fwrite(chessboard, 200 * sizeof(char), 1, savegame);
		fwrite(&whitesum, 1 * sizeof(int), 1, savegame);
		fwrite(&blacksum, 1 * sizeof(int), 1, savegame);
		fwrite(&turn, 1 * sizeof(int), 1, savegame);
		fclose(savegame);
	}
	else {
		printf("please enter your save game name");
		scanf("%s", &savename);
		savegame = fopen(savename, "w+b");
		fwrite(chessboard, 200 * sizeof(char), 1, savegame);
		fwrite(&whitesum, 1 * sizeof(int), 1, savegame);
		fwrite(&blacksum, 1 * sizeof(int), 1, savegame);
		fwrite(&turn, 1 * sizeof(int), 1, savegame);
		fclose(savegame);
	}
}
void loadgame(char chessboard[10][20], int&whitesum, int&blacksum, int&turn){
	const int numsave = 10;                           //this funtion gets array and points and turn but this time read them from file that you say
	int i = 0, j = 0;
	int chose = 0;
	FILE *savegame;
	FILE *chess;
	char savename[20];
	char savenames[numsave][20] = { 0 };
	char history[10];
	chess = fopen("chess.dat", "a+b");
	fread(&savenames[i], 20 * sizeof(char), 1, chess);
	while (!feof(chess)){
		fread(&savenames[i], 20 * sizeof(char), 1, chess);
		i++;
	}
	clrscr();
	for (j = 0; j < i; j++){
		printf("%d %s\n", j + 1, savenames[j]);
	}
	printf("please enter number of save you want");

	scanf("%d", &chose);

	savegame = fopen(savenames[chose - 1], "rb");

	fread(chessboard, 200 * sizeof(char), 1, savegame);
	fread(&whitesum, 1 * sizeof(int), 1, savegame);
	fread(&blacksum, 1 * sizeof(int), 1, savegame);
	fread(&turn, 1 * sizeof(int), 1, savegame);
	clrscr();
	printTheMap(chessboard, whitesum, blacksum);
	fclose(chess);
	fclose(savegame);
}
void bestpoints(int&whitesum,int&blacksum){
	printf("1-%d\n", whitesum);
	printf("2-%d\n", blacksum);
	if (whitesum > blacksum){
		gotoxy(0, 0);
		printf("1-%d\n", whitesum);
		printf("2-%d", blacksum);
	}
	else if (whitesum < blacksum){
		gotoxy(0, 0);
		printf("1-%d\n", blacksum);
		printf("2-%d", whitesum);

	}
}
void playingchess(){
	
	int totalltime = 0;
	int starttime = 0;
	int whitesum = 0;
	int blacksum = 0;
	char chessboard[10][20] = { { '|', 'r', '|', 'n', '|', 'b', '|', 'q', '|', 'k', '|', 'b', '|', 'n', '|', 'r', '|', ' ', '8' }, { '|', 'p', '|', 'p', '|', 'p', '|', 'p', '|', 'p', '|', 'p', '|', 'p', '|', 'p', '|', ' ', '7' }, { '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', ' ', '6' }, { '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', ' ', '5' }, { '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', ' ', '4' }, { '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', ' ', '3' }, { '|', 'P', '|', 'P', '|', 'P', '|', 'P', '|', 'P', '|', 'P', '|', 'P', '|', 'P', '|', ' ', '2' }, { '|', 'R', '|', 'N', '|', 'B', '|', 'Q', '|', 'K', '|', 'B', '|', 'N', '|', 'R', '|', ' ', '1' }, };
	printTheMap(chessboard, whitesum, blacksum);
	int x = 1, y = 0;
	int change = 0;
	char temp = 0, ch = 0;
	int turn = 5;
	int m = 16, n = 8;
	char checkmate = 0;
	int temp2 = 0;
	int temp3 = 0;
	int time;
	int since = 0;              //since and l are used for extera activity for menu
	int l = 0;


	while (checkmate != 'K'&&checkmate != 'k'&&ch != '9') {
		if (_kbhit()){
			gotoxy(x, y);
			ch = getch();
			if (ch == '4'){
				if (l == 0){ since = 1; l++; clrscr(); printcredit(); }
				else if (l != 0){ since--; l--; clrscr(); gotoxy(0, 0); printTheMap(chessboard, whitesum, blacksum); }

			}
			if (ch == '3'){
				if (l == 0){ since = 1; l++; clrscr(); howtoplay(); }
				else if (l != 0){ since = 0; l--; clrscr(); gotoxy(0, 0); printTheMap(chessboard, whitesum, blacksum); }
			}
			if (ch == '1'){
				if (l == 0)	{ since = 1; l++; clrscr(); role(); }
				else if (l != 0){ since = 0; l--; clrscr(); gotoxy(0, 0); printTheMap(chessboard, whitesum, blacksum); }
			}
			if (ch == '2'){
				if (l == 0)	{ since = 1; l++; clrscr(); draw(); }
				else if (l != 0){ since = 0; l--; clrscr(); gotoxy(0, 0); printTheMap(chessboard, whitesum, blacksum); }
			}
			if (ch == '5'){
				savegame(chessboard, whitesum, blacksum, turn);
			}
			if (ch == '6'){
				loadgame(chessboard, whitesum, blacksum, turn);
			}
			if (ch == '7'){
				game(chessboard, whitesum, blacksum);
			}
			if (ch == '8'){
				if (l == 0)	{ since = 1; l++; clrscr(); bestpoints(whitesum,blacksum); }
				else if (l != 0){ since = 0; l--; clrscr(); gotoxy(0, 0); printTheMap(chessboard, whitesum, blacksum); }
				
			}
			

			if (ch == -32)
				ch = getch();
			if (ch == 112 && change == 0){       //change is used for understanding the position of buttom p for picking up and puting down

				if (turn == 2 && chessboard[y][x] <= 'Z' && chessboard[y][x] >= 'A'){  //here we understand whose turn is
					continue;

				}

				else if (turn == 1 && chessboard[y][x] <= 'z' && chessboard[y][x] >= 'a'){
					continue;
				}

				if (chessboard[y][x] == '_'){
					continue;
				}
				if (chessboard[y][x] <= 'Z'&& chessboard[y][x] >= 'A'){                //in this part the one who will start will be chosen
					turn = 1;
				}
				else if (chessboard[y][x] <= 'z'&& chessboard[y][x] >= 'a'){
					turn = 2;
				}


				temp = chessboard[y][x];//here p is used to pick up pieses
				temp2 = y;
				temp3 = x;
				chessboard[y][x] = '_';
				change--;
				clrscr();
				printTheMap(chessboard, whitesum, blacksum);
			}
			else if (ch == 72 && since == 0){                 //here curoser moves across the chessboard
				y--;
				if (y < 0){
					y = n - 1;
				}
				else if (y >= n){
					y = 0;
				}
			}

			else if (ch == 77 && since == 0){
				x += 2;
				if (x < 0){
					x = m - 1;
				}
				else if (x >= m){
					x = 1;
				}


			}
			else if (ch == 75 && since == 0){
				x -= 2;
				if (x < 0){
					x = m - 1;
				}
				else if (x >= m){
					x = 0;
				}

			}
			else if (ch == 80 && since == 0){
				y++;

				if (y < 0){
					y = n - 1;
				}
				else if (y >= n){
					y = 0;
				}
			}

			if (ch == 112 && change < 0){     //here p is used to put pieses
				checkmate = chessboard[y][x];
				if (turn == 1 && chessboard[y][x] <= 'Z' && chessboard[y][x] >= 'A')    //here every can move its pieses
					continue;
				else if (turn == 2 && chessboard[y][x] <= 'z' && chessboard[y][x] >= 'a')
					continue;
				if ((x == temp3&&y == temp2)){

					continue;




				}

				knightmove(temp3, temp2, turn, temp, x, y, chessboard); //here we see every pieceses move
				quienmove(temp3, temp2, turn, temp, x, y, chessboard);
				pawnmove(temp3, temp2, turn, temp, x, y, chessboard);
				pawn2move(temp3, temp2, turn, temp, x, y, chessboard);
				Rockmove(temp3, temp2, turn, temp, x, y, chessboard);
				whitebishobmove(temp3, temp2, turn, temp, x, y, chessboard);

				kingmove(temp3, temp2, turn, temp, x, y, chessboard);

				switch (checkmate){
				case 'P': gotoxy(53, 1);
					blacksum = blacksum + 1;
					break;
				case 'p': gotoxy(53, 0);
					whitesum = whitesum + 1;
					break;
				case 'R':gotoxy(53, 1);
					blacksum = blacksum + 5;
					break;
				case 'r':gotoxy(53, 0);
					whitesum = whitesum + 5;
					break;
				case'Q':gotoxy(53, 1);
					blacksum = blacksum + 10;
					break;
				case'q': gotoxy(53, 0);
					whitesum = whitesum + 10;
					break;
				case'B':gotoxy(53, 1);
					blacksum = blacksum + 3;
					break;
				case'b':gotoxy(53, 0);
					whitesum = whitesum + 3;
					break;
				case'N':gotoxy(53, 1);
					blacksum = blacksum + 3;
					break;
				case 'n':gotoxy(53, 0);
					whitesum = whitesum + 3;
					break;
				case'K':gotoxy(53, 1);
					blacksum = blacksum + 100;
					break;
				case'k':gotoxy(53, 0);
					whitesum = whitesum + 100;
					break;
				}



				change++;
				clrscr();
				printTheMap(chessboard, whitesum, blacksum);
				switch (turn){
				case 1:gotoxy(24, 8);
					printf("black turn");
					gotoxy(0, 0);
					totalltime = starttime - time;
					starttime = (clock()) / 1000;

					turn = 2;
					break;
				case 2:gotoxy(24, 8);
					printf("white turn");
					gotoxy(7, 0);
					totalltime = starttime - time;
					starttime = (clock()) / 1000;
					turn = 1;
					break;
				case 0:;
					gotoxy(25, 8);
					printf("wrong place try again");
					change--;
					turn = 1;
					break;
				case -1:
					gotoxy(25, 8);
					printf("wrong place try again");
					change--;
					turn = 2;
					break;

				}



			}
		}

		time = (clock()) / 1000;
		if (time - starttime > 20 && turn == 1){
			turn = 2;
			totalltime = starttime - time;
			starttime = time;
			gotoxy(24, 8);
			printf("white turn");
		}
		else if (time - starttime > 20 && turn == 2){
			turn = 1;
			totalltime = starttime - time;
			starttime = time;
			gotoxy(24, 8);
			printf("black turn");
		}
		gotoxy(0, 23);
		printf("time: %d", time - starttime);
		gotoxy(x, y);



	}

	if (checkmate == 'k'){
		gotoxy(24, 8);
		printf("white wins");
	}
	else if (checkmate == 'K') {
		gotoxy(24, 8);
		printf("black wins");
	}
}





void main(){

	playingchess();


}






