#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;
// consider creating a player object eventually
//next to work on is exit detection and enemy detection.


/*pathing
make it use a vector
have it follow appropriate pathing methods, and stop searchign when it

void pathing(vector< vector<maze> > &cave, int playerLoc[], int exitLoc[],const int enemyLoc[], bool &leave, bool &pass, char &desc)
int enem1 = enemyLoc[0];
int enem2 = enemyLoc[1];
vector <int> moves;
for(int x = 0;enemyLoc[0] == playerLoc[0] && enemyLoc[1] == playerLoc[1]; x++)
{
    int choice;
	bool valid = false;
	do{
		choice = (rand() % 5);
		do{
			if (enemyLoc[0] > playerLoc[0] && cave[enemyLoc[0] - 1][enemyLoc[1]].walls == false)
			{
			     //cout << "\nChoice 1 selected. part 1";
				choice = 1;
				valid = true;
			}
			else if (enemyLoc[0] < playerLoc[0] && cave[enemyLoc[0] + 1][enemyLoc[1]].walls == false)
			{
			    // cout << "\nChoice 2 selected. part 1";
				choice = 2;
				valid = true;
			}
			else if (enemyLoc[1] > playerLoc[1] && cave[enemyLoc[0]][enemyLoc[1] - 1].walls == false)
			{
			     //cout << "\nChoice 3 selected. part 1";
				choice = 3;
				valid = true;
			}
			else if (enemyLoc[1] < playerLoc[1] && cave[enemyLoc[0]][enemyLoc[1] + 1].walls == false)
			{
			    // cout << "\nChoice 4 selected. part 1";
				choice = 4;
				valid = true;
			}
			else if (valid == false){
				choice = ((rand() % 4) + 1);
				if ( choice == 1 && valid == false && cave[enemyLoc[0] - 1][enemyLoc[1]].walls == false)
				{
					//cout << "\nChoice 1 selected. part 2";
					choice = 1;
					valid = true;
				}
				else if (choice == 2 && valid == false && cave[enemyLoc[0] + 1][enemyLoc[1]].walls == false)
				{
				//	cout << "\nChoice 2 selected. part 2";
					choice = 2;
					valid = true;
				}
				else if (choice == 3 && valid == false && cave[enemyLoc[0]][enemyLoc[1] - 1].walls == false)
				{
				//	cout << "\nChoice 3 selected. part 2";
					choice = 3;
					valid = true;
				}
				else if (choice == 4 && valid == false && cave[enemyLoc[0]][enemyLoc[1] + 1].walls == false)
				{
				//	cout << "\nChoice 4 selected. part 2";
					choice = 4;
					valid = true;
				}
			}

				else { valid = false; cout << "\nIt Broke Alex"; }


		} while (valid == false);
		pass = false;
		switch(choice)
		{
		//consider going back to a switch statement.
		  case 1: if (choice == 1 && cave[enemyLoc[0] - 1][enemyLoc[1]].walls == false)
		{
		//	 cout << "\nEnemy Moved North";
		//	cave[enemyLoc[0]][enemyLoc[1]].enem = false;
			enemyLoc[0]--;
			pass = true;
			//cave[enemyLoc[0]][enemyLoc[1]].enem = true;
		}
            else {choice ++;}
            break;
		case 2: if (cave[enemyLoc[0] + 1][enemyLoc[1]].walls == false)
		{
		//	 cout << "\nEnemy Moved South";
		//	cave[enemyLoc[0]][enemyLoc[1]].enem = false;
			enemyLoc[0]++;
			pass = true;
		//	cave[enemyLoc[0]][enemyLoc[1]].enem = true;
		}
            else {choice ++;}
            break;

		case 3: if (choice == 3 && cave[enemyLoc[0]][enemyLoc[1] - 1].walls == false)
		{
		//	 cout << "\nEnemy Moved West";
		//	cave[enemyLoc[0]][enemyLoc[1]].enem = false;
			enemyLoc[1]--;
			pass = true;
		//	cave[enemyLoc[0]][enemyLoc[1]].enem = true;
		}
		else {choice ++;}
            break;

		 case 4: if ( choice == 4 && cave[enemyLoc[0]][enemyLoc[1] + 1].walls == false)
		{
		//	 cout << "\nEnemy Moved East";
		//	cave[enemyLoc[0]][enemyLoc[1]].enem = false;
			enemyLoc[1]++;
			pass = true;
		//	cave[enemyLoc[0]][enemyLoc[1]].enem = true;
		}
		else {}
            break;
		 default :
        //     cout << "\nIt done broke,"; pass == true; valid = true; cout << endl << choice;
             break;
		}
	} while (pass == false);
    moves.push_back(x);

}


enemyLoc[0] = enem1;
enemyLoc[1] = enem2;
}

*/

int ROWS = 50;
int COLS = 50;
const int RENDDIST = 10;
const int SIZE = 2;
bool won = false;
bool leave = false;
bool pass = true;
int hardmode = 0;

struct pcharacter		//used for holding chacter info   // not yet implemented
{
    string name;
	int hp; // hit points
	int level; //level will determine stats and such
	int race; //Will hold race 1 - human 2 - dwarf 3 - elf 4 - gnome 5 - hobbit
	int age; // age, means nothing really
	int coins; //holds coins
	double invWeight; //Inventory weight
	int playerLoc[SIZE];
};

struct item	//used for making items **not implemented yet
{
	int type; //1 weapon 2 armor 3 food 4 potion 5 other
	double weight; //how much it weighs
	int bonus; //stat bonus
};

struct maze
{
	bool walls; //true if no wall false if wall
	bool player; //true if player is there, false if not
	bool exit; //true if exit, false if not
	int item; //0 nothing is there # means something
	int enem; //enemies 0 is nothing # is something
};
void welcome();
pcharacter getCharInfo(pcharacter player);
void viewCharCard(pcharacter player);
void getDims();
void hardMode();
void getDens(int &dense);
void makeMaze( vector< vector<maze> > &cave, const int);
void movN(const vector< vector<maze> > &cave, int arrayToMod[]);//These are move functions will be used eventually. // currently not in use
void movS(const vector< vector<maze> > &cave, int arrayToMod[]);
void movE(const vector< vector<maze> > &cave, int arrayToMod[]);
void movW(const vector< vector<maze> > &cave, int arrayToMod[]);
int menuDesc(int, int);
void dispMenu(const vector< vector<maze> > &cave, int playerLoc[]); //This method will display the menu of choices.
void correctMaze(vector< vector<maze> > &cave, int playerLoc[], int exitLoc[], int enemyLoc[]);
void awareness(vector< vector<maze> > &cave, int playerLoc[], int exitLoc[], int enemyLoc[]);
void dispMaze(vector< vector<maze> > &cave, int playerLoc[], int exitLoc[], int enemyLoc[]);
void playerMov(vector< vector<maze> > &cave, int playerLoc[], int exitLoc[], int enemyLoc[], bool &leave, bool &pass, char &desc, bool &won);
void enemyMov(vector< vector<maze> > &cave, int playerLoc[], int exitLoc[], int enemyLoc[], bool &leave, bool &pass, char &desc, bool &won);
void exiting(vector< vector<maze> > &cave, int playerLoc[], int exitLoc[],int enemyLoc[], bool &leave, bool &pass, char &desc);
void win(bool &won, bool &leave, bool &pass);
void struggle(vector< vector<maze> > &cave, int playerLoc[], int exitLoc[], int enemyLoc[], bool &leave, bool &pass, char &desc, bool &won);

int main()
{
    welcome();
    pcharacter player;
    player =  getCharInfo(player);
    getDims();
    vector< vector<maze> > cave(ROWS, vector<maze>(COLS));

	//maze cave[ROWS][COLS];	//The tops of places are tops[x] the bottoms are tops[x+1]
	//int sides[ROWS][COLS];	//west of places are sides[x] easts are sides[x+1]
	//int playerLoc[SIZE];		//[0] is rows [1] is cols
	int exitLoc[SIZE];			//[0] is rows [1] is cols
	int enemyLoc[SIZE];
	int density = 1;

	bool leave = false;
	bool pass = true;
	bool locDisp = false;


	char desc;
	hardMode();
	getDens(density);
	makeMaze(cave,density);
	correctMaze(cave, player.playerLoc, exitLoc,enemyLoc);

	do{
		if (hardmode<2)
		{
			dispMaze(cave, player.playerLoc, exitLoc, enemyLoc);
		}
		exiting(cave, player.playerLoc, exitLoc, enemyLoc, leave, pass, desc);
		awareness(cave, player.playerLoc, exitLoc, enemyLoc);
		playerMov(cave, player.playerLoc, exitLoc, enemyLoc, leave, pass, desc, won);
		enemyMov(cave, player.playerLoc, exitLoc, enemyLoc, leave, pass, desc, won);
	} while (won == false);

	return 0;
}
/*****************
*lets player define size of their personal corner of hell they will be in
***************************/
void welcome()
{
    cout << "Welcome! This game is a text / console based maze exploration game." << endl
        << "In which you the player, have decided to go into an old cave in search" << endl
        <<"of a buried treasure. The cave's features are yours to choose. But take" << endl
        << "care, for something else stalks you in the dark." << endl;
        }

pcharacter getCharInfo(pcharacter player)
{
    player.hp = 3;
    player.level = 1;
    cout << "\n\n\tWhat race would you like to play?: " << "\n1.Human (1)" << "\n2.Dwarf (2)" << "\n3.Elf(3)" << "\n4.Gnome (4)" << "\n5.Hobbit(5)" << endl;
    cout << "\nPlease enter a choice (must be 1,2,3,4 or 5): ";
    player.race = menuDesc(1,5);
    cout << "\n\tHow old is your character?";
    player.age = menuDesc(15,900);
    player.coins = 10;
    player.invWeight = 0.0;
    return player;
}

void getDims()
{
    int w;
    int l;
    do{
    cout << endl << "How wide do you want the maze to be ? (minimum of 15, max 500).";
    w = menuDesc(15,500);
    }while (w < 15 || w > 500);
    COLS = w;

    do{
    cout << endl << "How long do you want the maze to be ? (minimum of 15, max 500).";
    l = menuDesc(15,500);
    }while (l < 15 || l > 500);
    ROWS = l;
}


//******************
//*Decides if player wants to cry blood
//******************

void hardMode()
{
	char choice;
	cout << "\nHello, would you like to play in hardmode today?\nThere are no maps(Y/N): ";
	cin >> choice;
	if (choice == 'Y' || choice == 'y')
	{
		choice = 'n';
		hardmode++;
		cout << "\nHello, would you like to play in hardermode today?\nThere are no maps, and no location indicators (Y/N): ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y')
		{
            hardmode++;
        }
	}
	else { hardmode = false; }

}
//**********************
//Gets desity of maze
//*********************
void getDens(int &dense)
{
	do{
		cout << "\n\tWelcome! Please input an integer to represent how dense \n\tThe cave you are exploring is. \n\t1.Standard \n\t2.Dense(Not allways passable) \n\t3.Rarely Passable";
		cout << endl;
		dense = menuDesc(1,3);
	} while (dense != 1 && dense != 2 && dense != 3 && dense != 4 && dense != 5 && dense != 6);
}

//***************
//Makes the maze*
//***************

void makeMaze(vector< vector<maze> > &cave, const int DENSITY)
{
	unsigned seed = time(0);
	srand(seed);
	for (int c = 0; c < COLS; c++)
	{
		cave[0][c].walls = 3;
		for (int r = 0; r < ROWS; r++)
		{
			if (((rand()*(rand() % 20)) %(DENSITY+1)) > 0)
			{
				//cave[r][c].walls = ((rand()*(rand() % 20))%4);
				cave[r][c].walls = true;
			}
			else
			{ cave[r][c].walls = false; }
			cave[r][COLS].walls = 3;
		}
	}
}

//*******************************
//This one  corrects the maze   *
//And sets player locs          *
//*******************************

void correctMaze(vector< vector<maze> > &cave, int playerLoc[], int exitLoc[], int enemyLoc[])
{
	unsigned seed = time(0);
	srand(seed);

	playerLoc[0] = (rand() % (ROWS/3))+(ROWS/5);
	playerLoc[1] = (rand() % (COLS/3))+(COLS/5);
	exitLoc[0] = (rand() % (ROWS-6))+2;
	exitLoc[1] = (rand() % (COLS-6))+2;
	enemyLoc[0] = (playerLoc[0] +(rand() % (ROWS)) + 2)%(ROWS-4);
	enemyLoc[1] = (playerLoc[1] + (rand() % (COLS)) + 2)%(COLS-4);

	for (int c = 1; c < COLS - 1; c++)
	{
		for (int r = 1; r < ROWS - 1; r++)
		{
			if (cave[r][c].walls == true)
			{
				cave[r][c].walls = 1;
			}
			else
			{
				cave[r][c].walls = false;
			}

		}
	}

		for (int r = 0; r < ROWS - 1; r++)
		{
				cave[r][0].walls = true;
				cave[r][COLS-1].walls = true;
		}

    for (int c = 0; c < COLS - 1; c++)
		{
				cave[0][c].walls = true;
				cave[ROWS-1][c].walls = true;
		}




	cave[playerLoc[0]][playerLoc[1]].player = true;
	cave[playerLoc[0]][playerLoc[1]].walls = false;
	cave[playerLoc[0] + 1][playerLoc[1]].walls = false;
	cave[playerLoc[0]][playerLoc[1] + 1].walls = false;
	cave[playerLoc[0] + 1][playerLoc[1] + 1].walls = false;
	cave[playerLoc[0] - 1][playerLoc[1]].walls = false;
	cave[playerLoc[0]][playerLoc[1] - 1].walls = false;

	cave[exitLoc[0]][exitLoc[1]].exit = true;
	cave[exitLoc[0]][exitLoc[1]].walls = false;
	cave[exitLoc[0] + 1][exitLoc[1]].walls = false;
	cave[exitLoc[0]][exitLoc[1] + 1].walls = false;
	cave[exitLoc[0] + 1][exitLoc[1] + 1].walls = false;
	cave[exitLoc[0]][exitLoc[1]-1].walls = false;
	cave[exitLoc[0]-1][exitLoc[1]].walls = false;

	cave[exitLoc[0]][exitLoc[1]].exit = true;
	cave[exitLoc[0]][exitLoc[1]].walls = false;
	cave[exitLoc[0] + 1][exitLoc[1]].walls = false;
	cave[exitLoc[0]][exitLoc[1] + 1].walls = false;
	cave[exitLoc[0] + 1][exitLoc[1] + 1].walls = false;
	cave[exitLoc[0]][exitLoc[1] - 1].walls = false;
	cave[exitLoc[0] - 1][exitLoc[1]].walls = false;

}

//***********************
//Displays maze
//*********************

void dispMaze(vector< vector<maze> > &cave, int playerLoc[], int exitLoc[], int enemyLoc[])
{
    unsigned char symb;
	bool side;
	int farbound = (playerLoc[0] + RENDDIST);
	int lowbound = (playerLoc[1] + RENDDIST);
	if (hardmode < 1){


		cout << endl;
		for (int r = playerLoc[0] - RENDDIST; r < farbound; r++)
		{

			if (farbound > ROWS)
            {
				farbound = ROWS;
			}
            if (r < 0)
			{
				r = 0;
			}

			cout << "\n\t\t";
			for (int c = playerLoc[1] - RENDDIST; c < lowbound; c++)
			{
				if (farbound > COLS)
				{
					farbound = COLS;
				}
				if (c < 0)
				{
					c = 0;
				}

				side = cave[r][c].walls;

				if ((exitLoc[0] == c && exitLoc[1] == c) && (playerLoc[0] == r && playerLoc[1] == c))
				{
					symb = '&';
				}
				else if (exitLoc[0] == r && exitLoc[1] == c)
				{
					symb = 'E';

				}
				else if ((playerLoc[0] == r && playerLoc[1] == c))
				{
					symb = '@';
				}
				else if ((enemyLoc[0] == r && enemyLoc[1] == c))
				{
					symb = '%';
				}

				else
				{
					if (side == false)
					{
						symb = ' ';
					}
					else
					{
						symb = 219;
					}
				}
				cout << symb;
			}
		}
	cout << endl << endl << "\tWelcome to the Maze. You can seen the map. However remember it is old" << "\n\tNo-one has been here for years so the map may be innacurrate." << endl;
	cout << "\n\tYou are the @ and the exit is the E, something else % is in here" << endl;
}
	int exitoc1;
	int exitoc2;
	unsigned seed = time(0);
	srand(seed);
	if (hardmode < 2)
	{
		cout << "\nYou are at row: " << playerLoc[0] << " and at column: " << playerLoc[1] << endl;

		//ENMEY MOVEMENT AND SHIT

		if (exitLoc[0] > 5 && exitLoc[0] < ROWS)
		{
			exitoc1 = exitLoc[0] + (rand() % 5);
		}
		else { exitoc1 = exitLoc[0]; }

		if (exitLoc[1] > 5 && exitLoc[1] < COLS)
		{
			exitoc2 = exitLoc[1] + (rand() % 5);
		}
		else { exitoc2 = exitLoc[0]; }

		cout << "\nThe exit is roughly at row: " << exitLoc[0] + (rand() % 5) << " and at column: " << exitLoc[1] + (rand() % 5) << endl;
	}
}
//**********************************
//Controls Player movement
//**********************************

void playerMov(vector< vector<maze> > &cave, int playerLoc[], int exitLoc[], int enemyLoc[], bool &leave, bool &pass, char &desc, bool &won)
{
	int choice;
	do{
        do{
            dispMenu(cave,playerLoc);
            choice = menuDesc(1,5);
        }while (choice < 1 || choice > 5);
		pass = false;
		switch (choice)
		{
		case 1: if (cave[playerLoc[0]-1][playerLoc[1]].walls == false)
		{
			cout << "\nYou move up through the north passage";
			cave[playerLoc[0]][playerLoc[1]].player = false;
			playerLoc[0]--;
			pass = true;
			cave[playerLoc[0]][playerLoc[1]].player = true;
		}
				else { cout << "\nThat way is blocked"; pass = false; }
				break;
		case 2: if (cave[playerLoc[0] + 1][playerLoc[1]].walls == false)
		{
			cout << "\nYou move down through the south passage";
			cave[playerLoc[0]][playerLoc[1]].player = false;
			playerLoc[0]++;
			pass = true;
			cave[playerLoc[0]][playerLoc[1]].player = true;
		}
				else { cout << "\nThat way is blocked"; pass = false; }
				break;
		case 3: if (cave[playerLoc[0]][playerLoc[1]-1].walls == false)
		{
			cout << "\nYou move through the east passage";
			cave[playerLoc[0]][playerLoc[1]].player = false;
			playerLoc[1]--;
			pass = true;
			cave[playerLoc[0]][playerLoc[1]].player = true;
		}
				else { cout << "\nThat way is blocked"; pass = false; }
				break;

		case 4: if (cave[playerLoc[0]][playerLoc[1] + 1].walls == false)
		{
			cave[playerLoc[0]][playerLoc[1]].player = false;
			cout << "\nYou move through the west passage";
			playerLoc[1]++;
			pass = true;
			cave[playerLoc[0]][playerLoc[1]].player = true;
		}
				else { cout << "\nThat way is blocked"; pass = false; }
				break;

		case 5: cout << "\n Are you sure you want to exit? (Y/N)";
			//	char desc;
			cin >> desc;
			if (desc == 'Y' || desc == 'y')
			{
				leave = true;
				pass = true;
				won = true;
			}
			else { pass = false; }
			break;

		default: cout << "\nThat is not a correct input, please input a 1,2,3,4 or 5" << endl;
            pass = false;
			break;
		}
	} while (pass == false);
}

//******************
//Controls enemy movement
//*********************
void enemyMov(vector< vector<maze> > &cave, int playerLoc[], int exitLoc[],int enemyLoc[], bool &leave, bool &pass, char &desc, bool &won)
{
	int choice;
	bool valid = false;
	do{
		choice = (rand() % 5);
		do{
			if (enemyLoc[0] > playerLoc[0] && cave[enemyLoc[0] - 1][enemyLoc[1]].walls == false)
			{
			     //cout << "\nChoice 1 selected. part 1";
				choice = 1;
				valid = true;
			}
			else if (enemyLoc[0] < playerLoc[0] && cave[enemyLoc[0] + 1][enemyLoc[1]].walls == false)
			{
			    // cout << "\nChoice 2 selected. part 1";
				choice = 2;
				valid = true;
			}
			else if (enemyLoc[1] > playerLoc[1] && cave[enemyLoc[0]][enemyLoc[1] - 1].walls == false)
			{
			     //cout << "\nChoice 3 selected. part 1";
				choice = 3;
				valid = true;
			}
			else if (enemyLoc[1] < playerLoc[1] && cave[enemyLoc[0]][enemyLoc[1] + 1].walls == false)
			{
			    // cout << "\nChoice 4 selected. part 1";
				choice = 4;
				valid = true;
			}
			else if (valid == false){
				choice = ((rand() % 4) + 1);
				if ( choice == 1 && valid == false && cave[enemyLoc[0] - 1][enemyLoc[1]].walls == false)
				{
					//cout << "\nChoice 1 selected. part 2";
					choice = 1;
					valid = true;
				}
				else if (choice == 2 && valid == false && cave[enemyLoc[0] + 1][enemyLoc[1]].walls == false)
				{
				//	cout << "\nChoice 2 selected. part 2";
					choice = 2;
					valid = true;
				}
				else if (choice == 3 && valid == false && cave[enemyLoc[0]][enemyLoc[1] - 1].walls == false)
				{
				//	cout << "\nChoice 3 selected. part 2";
					choice = 3;
					valid = true;
				}
				else if (choice == 4 && valid == false && cave[enemyLoc[0]][enemyLoc[1] + 1].walls == false)
				{
				//	cout << "\nChoice 4 selected. part 2";
					choice = 4;
					valid = true;
				}
			}

				else { valid = false; cout << "\nIt Broke Alex"; }


		} while (valid == false);
		pass = false;
		switch(choice)
		{
		//consider going back to a switch statement.
		  case 1: if (choice == 1 && cave[enemyLoc[0] - 1][enemyLoc[1]].walls == false)
		{
			 cout << "\nEnemy Moved North";
			cave[enemyLoc[0]][enemyLoc[1]].enem = false;
			enemyLoc[0]--;
			pass = true;
			cave[enemyLoc[0]][enemyLoc[1]].enem = true;
		}
            else {choice ++;}
            break;
		case 2: if (cave[enemyLoc[0] + 1][enemyLoc[1]].walls == false)
		{
			 cout << "\nEnemy Moved South";
			cave[enemyLoc[0]][enemyLoc[1]].enem = false;
			enemyLoc[0]++;
			pass = true;
			cave[enemyLoc[0]][enemyLoc[1]].enem = true;
		}
            else {choice ++;}
            break;

		case 3: if (choice == 3 && cave[enemyLoc[0]][enemyLoc[1] - 1].walls == false)
		{
			 cout << "\nEnemy Moved West";
			cave[enemyLoc[0]][enemyLoc[1]].enem = false;
			enemyLoc[1]--;
			pass = true;
			cave[enemyLoc[0]][enemyLoc[1]].enem = true;
		}
		else {choice ++;}
            break;

		 case 4: if ( choice == 4 && cave[enemyLoc[0]][enemyLoc[1] + 1].walls == false)
		{
			 cout << "\nEnemy Moved East";
			cave[enemyLoc[0]][enemyLoc[1]].enem = false;
			enemyLoc[1]++;
			pass = true;
			cave[enemyLoc[0]][enemyLoc[1]].enem = true;
		}
		else {}
            break;
		 default :
             cout << "\nIt done broke,"; pass == true; valid = true; cout << endl << choice;
             break;
		}
	} while (pass == false);

	return;
}

//*********************
//*Displays info about where the player is
//************************

void awareness(vector< vector<maze> > &cave, int playerLoc[], int exitLoc[], int enemyLoc[])
{
	if (abs(enemyLoc[0] - playerLoc[0]) <= 10 && enemyLoc[0] <= playerLoc[0])
	{
		if (abs(enemyLoc[1] - playerLoc[1]) <= 10)
		{
			if (abs(enemyLoc[0] - playerLoc[0]) <= 5 && enemyLoc[0] <= playerLoc[0])
			{
				if (abs(enemyLoc[1] - playerLoc[1]) <= 5)
				{
					cout << "\nYou hear close noises to the North.";
				}
			}
			else { cout << "\nYou hear noises to the North."; }
		}

	}
	else if (abs(enemyLoc[0] - playerLoc[0]) <= 10 && enemyLoc[0] >= playerLoc[0])
	{
		if (abs(enemyLoc[1] - playerLoc[1]) <= 10)
		{
			if (abs(enemyLoc[0] - playerLoc[0]) <= 5 && enemyLoc[0] >= playerLoc[0])
			{
				if (abs(enemyLoc[1] - playerLoc[1]) <= 5)
				{
					cout << "\nYou hear close noises to the South.";
				}
			}
			else { cout << "\nYou hear noises to the South."; }
		}

	}


	if (abs(enemyLoc[1] - playerLoc[1]) <= 10 && enemyLoc[1] <= playerLoc[1])
	{
		if (abs(enemyLoc[0] - playerLoc[0]) <= 10)
		{
			if (abs(enemyLoc[1] - playerLoc[1]) <= 5 && enemyLoc[1] <= playerLoc[1])
			{
				if (abs(enemyLoc[0] - playerLoc[0]) <= 5)
				{
					cout << "\nYou hear close noises to the East.";
				}
			}
			else { cout << "\nYou hear noises to the East."; }
		}

	}
	else if (abs(enemyLoc[1] - playerLoc[1]) <= 10 && enemyLoc[1] >= playerLoc[1])
	{
		if (abs(enemyLoc[0] - playerLoc[0]) <= 10)
		{
			if (abs(enemyLoc[1] - playerLoc[1]) <= 5 && enemyLoc[1] >= playerLoc[1])
			{
				if (abs(enemyLoc[0] - playerLoc[0]) <= 5)
				{
					cout << "\nYou hear close noises to the West.";
				}
			}
			else { cout << "\nYou hear noises to the West."; }
		}

	}

}
//****************
//Determins if they won
//***************
void exiting(vector< vector<maze> > &cave, int playerLoc[], int exitLoc[], int enemyLoc[], bool &leave, bool &pass, char &desc)
{
 bool dontmatter = false;
	if (playerLoc[0] == exitLoc[0] && playerLoc[1] == exitLoc[1]) /*&& cave[playerLoc[0]][playerLoc[1]].player == true && cave[exitLoc[0]][exitLoc[1]].exit == true*/
	{
		cout << "\nCongrats you have won!" << endl;
		leave = true;
		pass = true;
		win(won, leave, pass);
	}
	else if ((playerLoc[0] == enemyLoc[0]-1 || playerLoc[0] == enemyLoc[0]+1 || playerLoc[0] == enemyLoc[0])&&(playerLoc[1] == enemyLoc[1]-1 || playerLoc[1] == enemyLoc[1]+1 || playerLoc[1] == enemyLoc[1]))
	{
	    struggle(cave,playerLoc,exitLoc,enemyLoc,leave,pass,desc,dontmatter);
	}
	else
	{
		return;
	}
}

//*****************
//This part will display the win
//******************playerLoc[1] == enemyLoc[1]

void win(bool &won, bool &leave, bool &pass)
{
	char again;

	cout << "\n Would you like to play again?(Y/N)";
	cin >> again;

	if (toupper(again) == 'Y')
	{
		leave = false;
		pass = false;
		main();
	}
	else
	{
		won = true;
		exit(0);
	}

}


void struggle(vector< vector<maze> > &cave, int playerLoc[], int exitLoc[], int enemyLoc[], bool &leave, bool &pass, char &desc, bool &won)
{
	int proll; // player roll
	int eroll; // enemyroll
		proll = (rand() % 20) + 3;
		eroll = (rand() % 20);

		cout << "\n The creature is on you!\nYou struggle!" << endl;
		if (eroll > proll)
		{
			cout << "\nThe creature knocks you out and drags you away" << endl << endl;
			win(won,leave,pass);
		}
		else{
        cout << "\nYou escape the creature." << endl;
		return;
		}
}


void movN(const vector< vector<maze> > &cave, int arrayToMod[])
{
	if (cave[arrayToMod[0]][arrayToMod[1]].walls == true)
	{
		arrayToMod[0]--;
	}
	else {}
}

void movS(const vector< vector<maze> > &cave, int arrayToMod[])
{
	if (cave[arrayToMod[0]][arrayToMod[1]].walls == true)
	{
		arrayToMod[0]++;
	}
	else {}
}

void movW(const vector< vector<maze> > &cave, int arrayToMod[])
{
	if (cave[arrayToMod[0]][arrayToMod[1]].walls == true)
	{
		arrayToMod[1]--;
	}
	else {}
}

void movE(const vector< vector<maze> > &cave, int arrayToMod[])
{
	if (cave[arrayToMod[0]][arrayToMod[1]].walls == true)
	{
		arrayToMod[1]++;
	}
	else {}
}

void dispMenu(const vector< vector<maze> > &cave, int playerLoc[])
{
        cout << "\nThe passage to the North is: ";
		if (cave[playerLoc[0]-1][playerLoc[1]].walls == false){ cout << "OPEN"; }
		else { cout << "Blocked"; }
		cout << "\nThe passage to the South is: ";
		if (cave[playerLoc[0]+1][playerLoc[1]].walls == false){ cout << "OPEN"; }
		else { cout << "Blocked"; }
		cout << "\nThe passage to the West is: ";
		if (cave[playerLoc[0]][playerLoc[1]-1].walls == false){ cout << "OPEN"; }
		else { cout << "Blocked"; }
		cout << "\nThe passage to the East is: ";
		if (cave[playerLoc[0]][playerLoc[1] + 1].walls == false) { cout << "OPEN"; }
		else { cout << "Blocked"; }
		cout << "\n\n\tWhat could you like to do?: " << "\n1.Go North (1)" << "\n2.Go South(2)" << "\n3.Go West(3)" << "\n4.Go East(4)" << "\n5.Exit the Game(5)" << endl;
        cout << "\nPlease enter a choice (must be 1,2,3,4 or 5): ";
}

int menuDesc(int low, int high)
{

    int desc;
    while(!(cin >> desc))
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << endl << "That number is not valid, please enter a valid number." << endl;
    }
    if (desc < low )
    {
        cout << endl << "That number is too low, must be at least " << low << " please enter an appropriate value: ";
        while(desc < low)
        {
        cin.clear();
        cin.ignore(10000,'\n');
        cin >> desc;
        }
    }

      if (desc > high )
    {
        cout << endl << "That number is too high, must be no more than " << high << " please enter an appropriate value: ";
        while(desc > high)
        {
        cin.clear();
        cin.ignore(10000,'\n');
        cin >> desc;
        }
    }
    return desc;
}
int menuDesc(int choice);
