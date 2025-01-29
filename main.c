#include<stdio.h>
#include<ncurses.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
    char name[40];
    char password[40];
    char email[40];
}user;

typedef struct{
	int color;
	char font;
}mainpixel;
mainpixel pixel[38][153];


int Login();


int Random_number(int a, int b){
    int randomnumber = rand();
    int c = b - a + 1;
    randomnumber %= c;
    printw("%d",randomnumber);
    return (randomnumber + a);
}

void update_screen(){
	clear();
	for(int j = 0; j < 38; j++){
		for(int i = 0; i < 153; i++){
			mvprintw(j, i, "%c", pixel[j][i].font);
		}
	}
}

int jadval(int ax, int bx, int ay, int by){
	for(int i = ax; i <= bx; i++){
		pixel[ay][i].font = '-';
		pixel[by][i].font = '-';
	}
	for(int i = ay + 1; i < by; i++){
		pixel[i][ax].font = '|';
		pixel[i][bx].font = '|';
	}
	for(int i = ax + 1; i < bx; i++){
		for(int j = ay + 1; j < by; j++){
			pixel[j][i].font = '.';
		}
	}
	update_screen();
}

void Table_show(int x1, int x2, int y1, int y2){
    int randomy1, randomx1, randomy2, randomx2;
    do{
        randomy1 = Random_number(y1, y2);
        randomy2 = Random_number(y1, y2);
        randomx1 = Random_number(x1, x2);
        randomx2 = Random_number(x1, x2);
        if(randomy2 < randomy1){
            int temp = randomy1;
            randomy1 = randomy2;
            randomy2 = temp;
        }
        if(randomx2 < randomx1){
            int temp = randomx1;
            randomx1 = randomx2;
            randomx2 = temp;
        }
        if(randomx2 - randomx1 < 5 || randomy2 - randomy1 < 5){
            continue;
        }
        printw("%d %d %d %d", randomx1, randomx2, randomy1, randomy2);
        jadval(randomx1, randomx2, randomy1, randomy2);
        break;        
    }while (true);
}



int Main_game(){
    srand(time(0));
    int tedad = Random_number(6, 10);
    if(tedad == 6){
        Table_show(2, 49, 2, 16);
        Table_show(51, 100, 2, 16);
        Table_show(102, 150, 2, 16);
        Table_show(2, 49, 18, 35);
        Table_show(51, 100, 18, 35);
        Table_show(102, 150, 18, 35);
    }
    else if(tedad == 7){
        Table_show(2, 49, 2, 16);
        Table_show(51, 100, 2, 16);
        Table_show(102, 150, 2, 16);
        Table_show(2, 36, 18, 35);
        Table_show(38, 74, 18, 35);
        Table_show(76, 112, 18, 35);
        Table_show(114, 150, 18, 35);
    }
    else if(tedad == 8){
        Table_show(2, 36, 2, 16);
        Table_show(38, 74, 2, 16);
        Table_show(76, 112, 2, 16);
        Table_show(114, 150, 2, 16);
        Table_show(2, 36, 18, 35);
        Table_show(38, 74, 18, 35);
        Table_show(76, 112, 18, 35);
        Table_show(114, 150, 18, 35);
    }
    else if(tedad == 9){
        Table_show(2, 28, 2, 16);
        Table_show(30, 58, 2, 16);
        Table_show(60, 88, 2, 16);
        Table_show(90, 118, 2, 16);
        Table_show(120, 150, 2, 16);
        Table_show(2, 36, 18, 35);
        Table_show(38, 74, 18, 35);
        Table_show(76, 112, 18, 35);
        Table_show(114, 150, 18, 35);
    }
    else if(tedad == 10){
        Table_show(2, 28, 2, 16);
        Table_show(30, 58, 2, 16);
        Table_show(60, 88, 2, 16);
        Table_show(90, 118, 2, 16);
        Table_show(120, 150, 2, 16);
        Table_show(2, 28, 18, 35);
        Table_show(30, 58, 18, 35);
        Table_show(60, 88, 18, 35);
        Table_show(90, 118, 18, 35);
        Table_show(120, 150, 18, 35);
    }
    getch();
    Login();
}




int Check_password(){
    
    /*/
    clear();
    FILE *fptr;
    user userinfo, temp; 
    clear();
    echo();
    attron(COLOR_PAIR(2));
    mvprintw(5, 54, "R O G U E    G A M E");
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(4));
    mvprintw(6, 58, "CHECKIG PASSWORD!!!");
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(1));
    mvprintw(10, 50, "Please enter your username:");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(3));
    mvprintw(32, 54, "Press R to return to the previous page");
    attroff(COLOR_PAIR(3));
    do{
        mvscanw(11, 50, "%s", userinfo.name);

    }while();
    mvprintw(32, 54, "                                                                  ");
    attron(COLOR_PAIR(4));
    mvprintw(32, 54, "Hello %s!!!", userinfo.name);
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(3));
    mvprintw(33, 54, "Press R to return to the previous page");
    attroff(COLOR_PAIR(3));
    do{
        p = 1;
        attron(COLOR_PAIR(1));
        mvprintw(13, 50, "please enter your password:");
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(3));
        mvscanw(14, 50, "%s", userinfo.password);
        attroff(COLOR_PAIR(3));
        if(strlen(userinfo.password) < 8){
            mvprintw(32, 54, "                                                                  ");
            mvprintw(33, 54, "                                                                  ");
            attron(COLOR_PAIR(2));
            mvprintw(32, 54, "WARNING!!! The password is too short.");
            attroff(COLOR_PAIR(2));
            mvprintw(14, 50, "                                                                  ");
        }
        else{
            p = 0;
        } 
    }while(p);
    do{
        int b = 0, k = 0, a = 0;
        for(int i = 0; i < strlen(userinfo.password); i++){
            if(userinfo.password[i] >= 'A' && userinfo.password[i] <= 'Z'){
                b++;
            }
            if(userinfo.password[i] >= 'a' && userinfo.password[i] <= 'z'){
                k++;
            }
            if(userinfo.password[i] >= '0' && userinfo.password[i] <= '9'){
                a++;
            }
        }
        if(b > 0 && k > 0 && a > 0){
            mvprintw(30, 54, "                                                                                  ");
            mvprintw(31, 54, "                                                                                  ");
            mvprintw(32, 54, "                                                                                  ");
            attron(COLOR_PAIR(4));
            mvprintw(32, 54, "Your password has been saved successfuly!");
            attroff(COLOR_PAIR(4));
            break;
        }
        if(b == 0){
            mvprintw(14, 50, "                                                                                  ");
            attron(COLOR_PAIR(2));
            mvprintw(30, 54, "INVALID PASSWORD!!! Your password must contain at least one uppercase character");
            attroff(COLOR_PAIR(2));
        }
        if(k == 0){
            mvprintw(14, 50, "                                                                                  ");
            attron(COLOR_PAIR(2));
            mvprintw(31, 54, "INVALID PASSWORD!!! Your password must contain at least one lowercase character");
            attroff(COLOR_PAIR(2));
        }
        if(a == 0){
            mvprintw(14, 50, "                                                                                  ");
            attron(COLOR_PAIR(2));
            mvprintw(32, 54, "INVALID PASSWORD!!! Your password must contain at least one number");
            attroff(COLOR_PAIR(2));
        }
        attron(COLOR_PAIR(3));
        mvscanw(14, 50, "%s", userinfo.password);
        attroff(COLOR_PAIR(3));
        mvprintw(30, 50, "                                                                                     ");
        mvprintw(31, 50, "                                                                                     ");
        mvprintw(32, 50, "                                                                                      ");
    }while(true);
    return ;
    */

}


int New_user(){
    FILE *fptr;
    user userinfo, temp; 
    clear();
    echo();
    attron(COLOR_PAIR(2));
    mvprintw(5, 54, "R O G U E    G A M E");
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(4));
    mvprintw(6, 58, "NEW USER!!!");
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(1));
    mvprintw(10, 50, "Please enter your username:");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(3));
    mvprintw(32, 54, "Press R to return to the previous page");
    attroff(COLOR_PAIR(3));
    int p;
    do{
        p = 1;
        fptr = (fopen("useesinfo.dat","rb+"));
        mvprintw(11, 50, "                                                                  ");
        attron(COLOR_PAIR(3));
        mvscanw(11,50, "%s", userinfo.name);
        fread(&temp, sizeof(user), 1, fptr);
        while(!feof(fptr) && p){
            if(!strcmp(temp.name, userinfo.name)){
            attron(COLOR_PAIR(2));
            mvprintw(32, 54, "WARNING!!! The username you enterd is already taken!");
            attroff(COLOR_PAIR(2));
            p=0;
            break;
            } 
            else{ 
               fread(&temp, sizeof(user), 1, fptr);
            }
        }
    }while(!p);
    mvprintw(32, 54, "                                                                  ");
    attron(COLOR_PAIR(4));
    mvprintw(32, 54, "Hello %s!!!", userinfo.name);
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(3));
    mvprintw(33, 54, "Press R to return to the previous page");
    attroff(COLOR_PAIR(3));
    do{
        p = 1;
        attron(COLOR_PAIR(1));
        mvprintw(13, 50, "please enter your password:");
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(3));
        mvscanw(14, 50, "%s", userinfo.password);
        attroff(COLOR_PAIR(3));
        if(strlen(userinfo.password) < 8){
            mvprintw(32, 54, "                                                                  ");
            mvprintw(33, 54, "                                                                  ");
            attron(COLOR_PAIR(2));
            mvprintw(32, 54, "WARNING!!! The password is too short.");
            attroff(COLOR_PAIR(2));
            mvprintw(14, 50, "                                                                  ");
        }
        else{
            p = 0;
        } 
    }while(p);
    do{
        int b = 0, k = 0, a = 0;
        for(int i = 0; i < strlen(userinfo.password); i++){
            if(userinfo.password[i] >= 'A' && userinfo.password[i] <= 'Z'){
                b++;
            }
            if(userinfo.password[i] >= 'a' && userinfo.password[i] <= 'z'){
                k++;
            }
            if(userinfo.password[i] >= '0' && userinfo.password[i] <= '9'){
                a++;
            }
        }
        if(b > 0 && k > 0 && a > 0){
            mvprintw(30, 54, "                                                                                  ");
            mvprintw(31, 54, "                                                                                  ");
            mvprintw(32, 54, "                                                                                  ");
            attron(COLOR_PAIR(4));
            mvprintw(32, 54, "Your password has been saved successfuly!");
            attroff(COLOR_PAIR(4));
            break;
        }
        if(b == 0){
            mvprintw(14, 50, "                                                                                  ");
            attron(COLOR_PAIR(2));
            mvprintw(30, 54, "INVALID PASSWORD!!! Your password must contain at least one uppercase character");
            attroff(COLOR_PAIR(2));
        }
        if(k == 0){
            mvprintw(14, 50, "                                                                                  ");
            attron(COLOR_PAIR(2));
            mvprintw(31, 54, "INVALID PASSWORD!!! Your password must contain at least one lowercase character");
            attroff(COLOR_PAIR(2));
        }
        if(a == 0){
            mvprintw(14, 50, "                                                                                  ");
            attron(COLOR_PAIR(2));
            mvprintw(32, 54, "INVALID PASSWORD!!! Your password must contain at least one number");
            attroff(COLOR_PAIR(2));
        }
        attron(COLOR_PAIR(3));
        mvscanw(14, 50, "%s", userinfo.password);
        attroff(COLOR_PAIR(3));
        mvprintw(30, 50, "                                                                                     ");
        mvprintw(31, 50, "                                                                                     ");
        mvprintw(32, 50, "                                                                                      ");
    }while(true);
    attron(COLOR_PAIR(1));
    mvprintw(16, 50, "Please enter your email:");
    attroff(COLOR_PAIR(1));
    do{
        int a = 0, d = 0, m;
        attron(COLOR_PAIR(3));
        mvscanw(17, 50, "%s", userinfo.email);
        attroff(COLOR_PAIR(3));
        mvprintw(17, 50, "                                                                                     ");
        mvprintw(30, 50, "                                                                                     ");
        mvprintw(31, 50, "                                                                                     ");
        mvprintw(32, 50, "                                                                                     ");
        if(userinfo.email[strlen(userinfo.email) - 4] != '.'){
            attron(COLOR_PAIR(2));
            mvprintw(32, 50, "WARNING!!! Invalid email!");
            attroff(COLOR_PAIR(2));
            continue;
        }
        for(int i = 0; i < strlen(userinfo.email); i++){
            if(userinfo.email[i] == '@'){
                a++;
                m = i;
            }
            if(userinfo.email[i] == '.'){
                d++;
            }
        }
        if(a != 1 || d != 1){
            attron(COLOR_PAIR(2));
            mvprintw(32, 50, "WARNING!!! Invalid email!");
            attroff(COLOR_PAIR(2));
            continue;
        }
        
        if(m < 3 || userinfo.email[m + 1] == '.'){
            attron(COLOR_PAIR(2));
            mvprintw(32, 50, "WARNING!!! Invalid email!");
            attroff(COLOR_PAIR(2));
            continue;
        }
        else{
            attron(COLOR_PAIR(4));
            mvprintw(31, 54, "Congratulations! Your registeration was succesfully completed!");
            mvprintw(32, 54, "Press any key to get back to the previous page");
            attroff(COLOR_PAIR(4));
            break;
        }
    }while(true);
    fclose(fptr);
    fptr = (fopen("useesinfo.dat","ab+"));
    fwrite(&userinfo, sizeof(userinfo), 1, fptr);
    fclose(fptr);
    getch();
    return 1;
}


int Login(){
    clear();
    attron(COLOR_PAIR(2));
    mvprintw(5, 54, "R O G U E    G A M E");
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(4));
    mvprintw(6, 58, "LOGIN MENUE!!!");
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(1));
    mvprintw(11, 60, "New game\n");
    mvprintw(13, 60, "Play as a guest\n");
    mvprintw(15, 60, "Last game\n");
    mvprintw(17, 60, "Scoreboard\n");
    mvprintw(19, 60, "Options\n");
    mvprintw(21, 60, "Return to the pervious page");
    mvprintw(23, 60, "Exit\n");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(3));
    mvprintw(32, 54, "Use the up and down keys to move.");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(4));
    mvprintw(11, 56, "**");
    noecho();
    char c = getch();
    int number = 0;
    while(c != 10){
        if(c == 65){
            mvprintw(11 + 2 * number, 56, "  ");
            number = ((number + 6) % 7);
            mvprintw(11 + 2 * number, 56, "**");
        }
        else if(c == 66){
            mvprintw(11 + 2 * number, 56, "  ");
            number = (number + 1) % 7;
            mvprintw(11 + 2 * number, 56, "**");
        }
        c = getch();
    }
    number++;
    attroff(COLOR_PAIR(4));
    if(number == 1){
        Check_password();
    }
    else if(number == 2){
        Main_game();
    }
    else if(number == 3){

    }
    else if(number == 4){

    }
    else if(number == 5){

    }
    else if(number == 6){
        return 6;
    }
    else if(number == 7){
        return 7;
    }
    clear();
}

int main(){
    FILE *fptr;
    fptr = (fopen("useesinfo.dat","rb+"));
    if (fptr == NULL){
        fptr = (fopen("useesinfo.dat","wb"));
    }
    while(true){
        initscr();
        clear();
        start_color();
        init_color(COLOR_BLACK, 100, 100, 100);
        init_pair(1, COLOR_YELLOW, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);
        init_pair(3, COLOR_WHITE, COLOR_BLACK);
        init_pair(4, COLOR_CYAN, COLOR_BLACK);
        bkgd(COLOR_PAIR(1));
        attron(A_BOLD);
        attron(COLOR_PAIR(2));
        mvprintw(5, 54, "R O G U E    G A M E");
        attroff(COLOR_PAIR(2));
        attron(COLOR_PAIR(4));
        mvprintw(6, 59, "MAIN MENUE");
        attroff(COLOR_PAIR(4));
        attron(COLOR_PAIR(1));
        mvprintw(17, 60, "New User\n");
        mvprintw(19, 60, "Login\n");
        mvprintw(21, 60, "Exit\n");
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(3));
        mvprintw(32, 54, "Use the up and down keys to move.");
        attroff(COLOR_PAIR(3));
        attron(COLOR_PAIR(4));
        mvprintw(17, 56, "**");
        noecho();
        char c = getch();
        int number = 0;
        while(c != 10){
            if(c == 65){
                mvprintw(17 + 2 * number, 56, "  ");
                number = ((number + 2) % 3);
                mvprintw(17 + 2 * number, 56, "**");
            }
            else if(c == 66){
                mvprintw(17 + 2 * number, 56, "  ");
                number = (number + 1) % 3;
                mvprintw(17 + 2 * number, 56, "**");
            }
            c = getch();
        }
        number++;
        attroff(COLOR_PAIR(4));
        if(number == 1){
            if (New_user() == 1){
                Login();
            }
        }
        else if(number == 2){
            int a = Login();
            if(a == 7){
                refresh();
                endwin();
                return 0;
            }
            if(a == 6){
                clear();
                continue;
            }
        }
        else if(number == 3){
            refresh();
            endwin();
            return 0;
        }
        getch();
        refresh();
        endwin();
    }
    return 0;
}
