#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> 
#include <fcntl.h>
#include <termios.h>

#define ROWS 16
#define COLS 40
#define MAX_FALLING 50

// Global Game Variables
char grid[ROWS][COLS];
int balls_remaining = 50;
int balls_caught = 0;
int balls_dropped = 0;

// Bucket variables
int bucket_pos = 15;
int bucket_dir = 1; // 1 = right, -1 = left
int bucket_width = 5;

// Falling ball arrays
int ball_x[MAX_FALLING];
int ball_y[MAX_FALLING];
bool ball_active[MAX_FALLING];

// System functions to manage macOS Terminal input modes
void set_terminal_mode(bool raw) {
    if (raw) {
        // Disable line-buffering and key echoing so keypresses are instant and hidden
        system("stty -icanon -echo");
    } else {
        // Restore default Mac terminal settings on game over
        system("stty icanon echo");
    }
}

// Non-blocking key check for macOS
int check_keypress() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        return ch;
    }
    return 0;
}

void init_game() {
    for (int i = 0; i < MAX_FALLING; i++) {
        ball_active[i] = false;
    }
}

void spawn_ball() {
    if (balls_remaining > 0) {
        for (int i = 0; i < MAX_FALLING; i++) {
            if (!ball_active[i]) {
                ball_x[i] = COLS / 2; // Drops right from the center
                ball_y[i] = 1;        // Starts right below dispenser
                ball_active[i] = true;
                balls_remaining--;
                balls_dropped++;
                break;
            }
        }
    }
}

void update_physics() {
    // 1. Clear grid canvas
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = ' ';
        }
    }

    // 2. Draw static dispenser at top center
    grid[0][(COLS/2)-1] = '|';
    grid[0][COLS/2]     = 'V';
    grid[0][(COLS/2)+1] = '|';

    // 3. Move and bounce the bucket near the bottom
    bucket_pos += bucket_dir;
    if (bucket_pos <= 1 || bucket_pos >= COLS - bucket_width - 1) {
        bucket_dir *= -1; 
    }

    // Draw bucket structure visually: \___/
    grid[ROWS - 3][bucket_pos] = '\\';
    for (int w = 1; w < bucket_width - 1; w++) {
        grid[ROWS - 3][bucket_pos + w] = '_';
    }
    grid[ROWS - 3][bucket_pos + bucket_width - 1] = '/';

    // 4. Update and draw falling balls
    for (int i = 0; i < MAX_FALLING; i++) {
        if (ball_active[i]) {
            ball_y[i]++; // Ball falls 1 row per cycle

            // Collision Check: Reached bucket line
            if (ball_y[i] == ROWS - 3) {
                if (ball_x[i] >= bucket_pos && ball_x[i] < bucket_pos + bucket_width) {
                    balls_caught++; 
                }
                ball_active[i] = false; 
            } 
            // Missed and hit floor
            else if (ball_y[i] >= ROWS - 1) {
                ball_active[i] = false;
            } 
            // Still falling
            else {
                grid[ball_y[i]][ball_x[i]] = 'o';
            }
        }
    }
}

void render_frame() {
    // Clear screen escape sequence for macOS Terminal
    printf("\e[1;1H\e[2J");
    
    printf("==========================================\n");
    printf("         QUIK DROP ARCADE (macOS)         \n");
    printf("==========================================\n");
    printf(" BALLS LEFT: %-3d | CAUGHT: %-2d / 50 \n", balls_remaining, balls_caught);
    printf("==========================================\n");

    // Print the grid
    for (int i = 0; i < ROWS; i++) {
        printf("|"); 
        for (int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j]);
        }
        printf("|\n"); 
    }
    
    // Floor
    printf("|");
    for(int j=0; j<COLS; j++) printf("_");
    printf("|\n");

    printf("\n>> PRESS [SPACEBAR] TO DROP A BALL! <<\n");
    printf(">> PRESS [Q] TO QUIT EARLY         <<\n");
}

int main() {
    init_game();
    set_terminal_mode(true); // Turn on instant keyboard capture

    while (true) {
        int key = check_keypress();
        if (key == ' ') { 
            spawn_ball(); 
        }
        if (key == 'q' || key == 'Q') { 
            break; 
        }

        update_physics();
        render_frame();

        // Check if any balls are still moving
        bool active_balls_exist = false;
        for (int i = 0; i < MAX_FALLING; i++) {
            if (ball_active[i]) active_balls_exist = true;
        }

        // End game when stock is empty and no balls are in the air
        if (balls_remaining == 0 && !active_balls_exist) {
            break; 
        }

        usleep(65 * 1000); // 65 millisecond frame delays
    }

    set_terminal_mode(false); // Clean up and reset terminal back to normal

    // Game Over Banner
    printf("\e[1;1H\e[2J");
    printf("==========================================\n");
    printf("                GAME OVER                 \n");
    printf("==========================================\n");
    printf(" Total Balls Dropped: %d\n", balls_dropped);
    printf(" Total Balls Caught : %d\n\n", balls_caught);

    if (balls_caught == 50) {
        printf(" *** JACKPOT WINNER! PERFECT 50/50! ***\n");
    } else {
        printf(" You missed %d balls. Better luck next time!\n", 50 - balls_caught);
    }
    printf("==========================================\n");

    return 0;
}
