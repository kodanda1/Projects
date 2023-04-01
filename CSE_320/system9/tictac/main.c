#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to load a game
void *load(const char *file);

// Assembly functions
void *create_game(int rows, int cols);
int get_rows(void *game);
int get_cols(void *game);
void display_game(void *game);
void set_cell_expected(void *game, int row, int col, char ch);
int set_cell_actual(void *game, int row, int col, char ch);
int game_win(void *game);
void destroy_game(void *game);

/**
 * main()
 * Program main entry point
 */
int main(int argc, char **argv)
{
	if(argc < 2) 
	{
		printf("usage: tictac file.tictac\n");
		return 1;
	}
	
	//
	// Load the game
	//
	void *game = load(argv[1]);
	if(game == NULL) 
	{
		return 1;
	}
	
	printf("TicTac: Game size %d rows and %d columns\n", get_rows(game), get_cols(game));
	
	//
	// The game loop!
	//
	while(0)
	{
		//
		// Display the current game
		//
		printf("\n");
		display_game(game);

		//
		// Enter a guess
		//
		printf("Enter guess (row column value): ");
		
		char guess[100];
		fgets(guess, sizeof(guess), stdin);
		
		int r=-1, c=-1;
		char g='.';
		sscanf(guess, "%d %d %c", &r, &c, &g);
		g = toupper(g);
		
		//
		// Lots of error checking
		//
		if(r < 0) 
		{
			printf("Invalid row\n");
		} 
		else if(c < 0) 
		{
			printf("Invalid column\n");
		}
		else if(r < 1 || r > get_rows(game)) 
		{
			printf("Invalid row %d!\n", r);
		} 
		else if(c < 1 || c > get_cols(game))
		{
			printf("Invalid column %d\n", c);
		}
		else if(g != 'X' && g != 'O') 
		{
			printf("Invalid guess %c\n", g);
		} 
		else
		{
			// 
			// Valid values, set them in the game!
			//
			if(!set_cell_actual(game, r, c, g)) 
			{
				printf("Incorrect, you lose!\n");
				break;
			}
		}
		
		//
		// Did we win?
		//
		if(game_win(game))
		{
			printf("Yah, you won!\n");
			break;
		}
		
	}

	// 
	// Destroy the game, freeing all memory
	//
	destroy_game(game);
	
	return 0;
}

/**
 * Load a game into the system.
 * @param file Filename we are loading from
 * @return Game Abstract Data Type object or NULL if failed
 */
void *load(const char *file)
{
	FILE *fp = fopen(file, "r");
	if(fp == NULL)
	{
		printf("Failed opening game data file\n");
		return NULL;
	}
	
	char line[100];
	fgets(line, sizeof(line), fp);
	int rows = atoi(line);
	
	fgets(line, sizeof(line), fp);
	int cols = atoi(line);
	
	//
	// Create the game abstract data type
	//
	void *game = create_game(rows, cols);
	
	//
	// Read in the game solution
	//
	int r, c;
	for(r=0; r<rows; r++) 
	{
		fgets(line, sizeof(line), fp);
		for(c=0; c<cols; c++) 
		{
			char cell = line[c];
			set_cell_expected(game, r+1, c+1, cell);

		}
	}
	
	//
	// Read in the initial game
	//
	for(r=0; r<rows; r++) 
	{
		fgets(line, sizeof(line), fp);
		for(c=0; c<cols; c++) 
		{
			char cell = line[c];
			set_cell_actual(game, r+1, c+1, cell);
		}
	}
	
	fclose(fp);
	return game;
}
