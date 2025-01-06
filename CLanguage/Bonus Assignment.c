#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 8

char* rook_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user);
char* bishop_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user);
char* queen_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user);
char* pawn_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user);
char* knight_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user);
char* king_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user);

//TODO:
//char* pawn_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user);
//char* knight_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user);
//char* king_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user);


void print_board(char board[SIZE][SIZE]){
    printf("   ");
    for(int i = 0; i < SIZE; i++)
       printf("%d ", i);
    printf("\n");

    for(int i = 0; i < SIZE; i++){
       printf("%d  ", i);
       for(int j = 0; j < SIZE; j++)
         printf("%c ", board[i][j]);
       printf("\n");
    }
    return;
}

int get_position(int *r, int *c){
        int success = scanf("%d %d", r, c);
        if(success == 2) return 1;
        success = scanf("%d,%d", r, c);
        if(success == 2) return 1;
        success = scanf("%d-%d", r, c);
        if(success == 2) return 1;
        success = scanf("(%d,%d)", r, c);
        if(success == 2) return 1;
        int ch; //Clear the input      
        while ((ch = getchar()) != '\n' && ch != EOF);
        return 0;
}

int main() {
    char board[SIZE][SIZE] = { 
        "RNBQKBNR",
        "PPPPPPPP",
        "........",
        "........",
        "........",
        "........",
        "pppppppp",
        "rnbqkbnr"
    };

    print_board(board);

    bool user = true;
    char *moved_piece;
    int r, c, new_r, new_c;

    //We skip any kind of check for game end or winning conditions, so we have an endless loop
    while(1){ 
        printf("User %d: Please choose a piece (provide r and c):\n", user ? 1 : 2); 
        while(1){
            if(get_position(&r, &c))
               break;
            printf("Error. Could not read input, try again.\n");
        } 
        printf("User %d: Please provide destination (provide new_r and new_c):\n", user ? 1 : 2); 
        while(1){
            if(get_position(&new_r, &new_c))   
               break;
            printf("Error. Could not read input, try again.\n");
        }

        int success = 0;

        //try all moves until one succeeds
        moved_piece = rook_move(board, r, c, new_r, new_c, user);
        if(moved_piece) {
           printf("Rook moved successfully!\n");
           success = 1;
        }
        moved_piece = bishop_move(board, r, c, new_r, new_c, user);
        if(moved_piece) {
           printf("Bishop moved successfully!\n");
           success = 1;
        }
        moved_piece = queen_move(board, r, c, new_r, new_c, user);
        if(moved_piece) {
           printf("Queen moved successfully!\n");
           success = 1;
        }
        //Uncomment to test other moves
        //moved_piece = pawn_move(board, r, c, new_r, new_c, user);
        //if(moved_piece) {
        //   printf("Pawn moved successfully!\n");
        //   success = 1;
        //}
        //moved_piece = knight_move(board, r, c, new_r, new_c, user);
        //if(moved_piece) {
        //   printf("Knight moved successfully!\n");
        //   success = 1;
        //}
        //moved_piece = king_move(board, r, c, new_r, new_c, user);
        //if(moved_piece) {
        //   printf("King moved successfully!\n");
        //   success = 1;
        //}

        if(success) {
          print_board(board);
          user = !user; //change turn
        } else{
           printf("Error. Could not make move, invalid position or piece. Please try again.\n\n");
        }
    }

    return 0;
}

char* rook_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user) {
    //Validate the piece is a rook
    char piece = board[r][c];
    if ((user && piece != 'r') || (!user && piece != 'R'))
        return NULL;

    //Validate the move is in a straight line
    if (r != new_r && c != new_c)
        return NULL;

    //Validate we moved
    if(r == new_r && c == new_c)
        return NULL;


    //check all positions aside from start/end
    //Validate no pieces are in the path
    if(r == new_r && c > new_c){
        for(int i = new_c+1; i < c; i++)
          if(board[r][i] != '.')
             return NULL;
    } else if(r == new_r && c < new_c){
        for(int i = c+1; i < new_c; i++)
          if(board[r][i] != '.')
             return NULL;
    }

    if(c == new_c && r > new_r){
        for(int i = new_r+1; i < r; i++)
          if(board[i][c] != '.')
            return NULL;
    } else if(c == new_c && r < new_r){
        for(int i = r+1; i < new_r; i++)
          if(board[i][c] != '.')
            return NULL;
    }

    //Check the destination
    char dest_piece = board[new_r][new_c];
    if(user && (dest_piece >= 'a' && dest_piece <= 'z'))
       return NULL;
    if(!user && (dest_piece >= 'A' && dest_piece <= 'Z'))
       return NULL;

    //Move the rook and capture if necessary
    board[new_r][new_c] = piece;
    board[r][c] = '.';

    return &board[new_r][new_c];
}

char* bishop_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user) {
    //Validate the piece is a bishop
    char piece = board[r][c];
    if ((user && piece != 'b') || (!user && piece != 'B'))
        return NULL;

    //Validate the move is diagonal
    if (abs(new_r - r) != abs(new_c - c))
        return NULL;

    //Validate we moved
    if(r == new_r && c == new_c)
        return NULL;

    //Check if a piece is in the way diagonally (4 directions)
    if (new_r > r && new_c > c) { // moving down-right
        for (int i = r + 1, j = c + 1; i < new_r && j < new_c; i++, j++) 
            if (board[i][j] != '.') 
                return NULL;
    } else if (new_r > r && new_c < c) { // moving down-left
        for (int i = r + 1, j = c - 1; i < new_r && j > new_c; i++, j--) 
            if (board[i][j] != '.') 
                return NULL;
    } else if (new_r < r && new_c > c) { // moving up-right
        for (int i = r - 1, j = c + 1; i > new_r && j < new_c; i--, j++) {
            if (board[i][j] != '.') 
                return NULL;
            printf("%c\n", board[i][j]);
            }
    } else if (new_r < r && new_c < c) {// moving up-left
        for (int i = r - 1, j = c - 1; i > new_r && j > new_c; i--, j--) 
            if (board[i][j] != '.') 
                return NULL;
    }

    //Check the destination
    char dest_piece = board[new_r][new_c];
    if(user && (dest_piece >= 'a' && dest_piece <= 'z'))
       return NULL;
    if(!user && (dest_piece >= 'A' && dest_piece <= 'Z'))
       return NULL;

    //Move the rook and capture if necessary
    board[new_r][new_c] = piece;
    board[r][c] = '.';

    return &board[new_r][new_c];
}

char* queen_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user) {
    char piece = board[r][c];
    char queen_piece = user ? 'q' : 'Q';
    char rook_piece = user ? 'r' : 'R';
    char bishop_piece = user ? 'b' : 'B';

    if (piece != queen_piece)
        return NULL;

    //Check rook move for queen
    board[r][c] = rook_piece;
    char* moved_piece = rook_move(board, r, c, new_r, new_c, user);
    if (moved_piece != NULL) { //Success
        *moved_piece = queen_piece;
        return moved_piece;
    }

    Check bishop move for queen
    board[r][c] = bishop_piece;
    moved_piece = bishop_move(board, r, c, new_r, new_c, user);
    if (moved_piece != NULL) { //Success
        *moved_piece = queen_piece;
        return moved_piece;
    }

    //Revert changes and return NULL on failure
    board[r][c] = queen_piece;
    return NULL;
}

char* pawn_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user) {
    char piece = board[r][c];
    char pawn_piece = user ? 'p' : 'P';

    //Validate the piece is a pawn
    if (piece != pawn_piece)
        return NULL;

    //Validate the move is forward
    if (user && new_r <= r)
        return NULL;
    if (!user && new_r >= r)
        return NULL;

    //Validate the move is one step forward unless it is the first move and the pawn is moving two steps straight forward
    if (abs(new_r - r) > 1)
        if (r == 2 && user && c == new_c || r == 7 && !user && c == new_c)
        else
            return NULL;

    //Validate a diagonal move to take an opposing player's piece
    if (abs(new_c - c) == 1 && abs(new_r - r) == 1) {
    
        //Check the destination
        char dest_piece = board[new_r][new_c];
        if(dest_piece == '.')
           return NULL; //Cannot move diagonally without capturing
        if(user && (dest_piece >= 'a' && dest_piece <= 'z'))
           return NULL;
        if(!user && (dest_piece >= 'A' && dest_piece <= 'Z'))
           return NULL;
    }

    //Move the pawn and capture if necessary
    board[new_r][new_c] = piece;
    board[r][c] = '.';

    return &board[new_r][new_c];
}
    char *knight_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user) {
        char piece = board[r][c];
        char knight_piece = user ? 'n : 'N';


    //Validate the piece is a knight
    if (piece != knight_piece)
        return NULL;

    //Validate the move is changing both row and column
    if (user && new_r == r || new_c == c)
        return NULL;
    if (!user && new_r == r || new_c == c)
        return NULL;

    //Validate the move is L-shaped (shift 2 rows + 1 column, or 1 column + 2 rows)
    if (abs(new_r - r) + abs(new_c - c) != 3)
        return NULL;

    //Check the destination
    char dest_piece = board[new_r][new_c];
    if(user && (dest_piece >= 'a' && dest_piece <= 'z'))
       return NULL;
    if(!user && (dest_piece >= 'A' && dest_piece <= 'Z'))
       return NULL;

    //Move the knight and capture if necessary
    board[new_r][new_c] = piece;
    board[r][c] = '.';

    return &board[new_r][new_c];
    
    }

    char *king_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user) {
        char piece = board[r][c];
        char king_piece = user ? 'k' : 'K';
        char queen_piece = user ? 'q' : 'Q';

    if (piece != queen_piece)
        return NULL;

    //Check rook move for queen
    board[r][c] = rook_piece;
    char* moved_piece = rook_move(board, r, c, new_r, new_c, user);
    if (moved_piece != NULL) { //Success
        *moved_piece = queen_piece;
        return moved_piece;
    }

    Check bishop move for queen
    board[r][c] = bishop_piece;
    moved_piece = bishop_move(board, r, c, new_r, new_c, user);
    if (moved_piece != NULL) { //Success
        *moved_piece = queen_piece;
        return moved_piece;
    }

    //Revert changes and return NULL on failure
    board[r][c] = queen_piece;
    return NULL;
}
    