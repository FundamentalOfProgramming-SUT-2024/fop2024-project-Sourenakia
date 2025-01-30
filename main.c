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
	char font, location;
    int flag;
    int x, y;
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

void Masir(int yv1, int xv1, int yv2, int xv2){
    
    int x1, x2, y1, y2;



    if(pixel[yv1][xv1 + 1].flag == 0){
        x1 = xv1 + 1;
        y1 = yv1;
    }
    else if(pixel[yv1][xv1 - 1].flag == 0){
        x1 = xv1 - 1;
        y1 = yv1;
    }
    else if(pixel[yv1 - 1][xv1].flag == 0){
        x1 = xv1;
        y1 = yv1 - 1;
    }
    else if(pixel[yv1 + 1][xv1].flag == 0){
        x1 = xv1;
        y1 = yv1 + 1;
    }
    if(pixel[yv2][xv2 + 1].flag == 0){
        x2 = xv2 + 1;
        y2 = yv2;
    }
    else if(pixel[yv2][xv2 - 1].flag == 0){
        x2 = xv2 - 1;
        y2 = yv2;
    }
    else if(pixel[yv2 - 1][xv2].flag == 0){
        x2 = xv2;
        y2 = yv2 - 1;
    }
    else if(pixel[yv2 + 1][xv2].flag == 0){
        x2 = xv2;
        y2 = yv2 + 1;
    }
    if(x2 < x1){
        int temp = x1;
        x1 = x2;
        x2 = x1;
    }
    
    if(y1 > y2){
        for(int i = x1; i <= x2; i++){
            if(pixel[y2][i].flag == 0){
                pixel[y2][i].font = '#';
            }
        }
        for(int j = y1; j >= y2; j--){
            if(pixel[j][x1].flag == 0){
                pixel[j][x1].font = '#';
            }
        }    
    }
    else{
        for(int i = x1; i <= x2; i++){
            if(pixel[y1][i].flag == 0){
                pixel[y1][i].font = '#';
            }
        }
        for(int j = y2; j >= y1; j--){
            if(pixel[j][x2].flag == 0){
                pixel[j][x2].font = '#';
            }
        }
    }
    
    //check
}








void Masir_1(int yv1, int xv1, int yv2, int xv2){
    
    int x1, x2, y1, y2;



    if(pixel[yv1][xv1 + 1].flag == 0){
        x1 = xv1 + 1;
        y1 = yv1;
    }
    else if(pixel[yv1][xv1 - 1].flag == 0){
        x1 = xv1 - 1;
        y1 = yv1;
    }
    else if(pixel[yv1 - 1][xv1].flag == 0){
        x1 = xv1;
        y1 = yv1 - 1;
    }
    else if(pixel[yv1 + 1][xv1].flag == 0){
        x1 = xv1;
        y1 = yv1 + 1;
    }
    if(pixel[yv2][xv2 + 1].flag == 0){
        x2 = xv2 + 1;
        y2 = yv2;
    }
    else if(pixel[yv2][xv2 - 1].flag == 0){
        x2 = xv2 - 1;
        y2 = yv2;
    }
    else if(pixel[yv2 - 1][xv2].flag == 0){
        x2 = xv2;
        y2 = yv2 - 1;
    }
    else if(pixel[yv2 + 1][xv2].flag == 0){
        x2 = xv2;
        y2 = yv2 + 1;
    }
    
    if(x1 > x2){
        for(int i = x1; i >= x2; i--){
            if (pixel[y1][i].flag == 0){
                pixel[y1][i].font = '#';
            }
        }
        for(int j = y1; j <= y2; j++){
            if(pixel[j][x2].flag == 0){
                pixel[j][x2].font = '#';
            }
        }
    }
    else{
        for(int j = y2; j >= y1; j--){
            if(pixel[j][x1].flag == 0){
                pixel[j][x1].font = '#';
            }
        }
        for(int i = x1; i <= x2; i++){
            if(pixel[y2][i].flag == 0){
                pixel[y2][i].font = '#';
            }
        }
    }
    
    //check
}

int jadval(int ax, int bx, int ay, int by){
	for(int i = ax; i <= bx; i++){
		pixel[ay][i].font = '-';
		pixel[by][i].font = '-';
        pixel[ay][i].flag = 2;
		pixel[by][i].flag = 2;
	}
	for(int i = ay + 1; i < by; i++){
		pixel[i][ax].font = '|';
		pixel[i][bx].font = '|';
        pixel[i][ax].flag = 3;
        pixel[i][bx].flag = 3;
	}
	for(int i = ax + 1; i < bx; i++){
		for(int j = ay + 1; j < by; j++){
			pixel[j][i].font = '.';
            pixel[j][i].flag = 1;
		}
	}
    int p = 0, p1 = 0, p2 = 0, p3 = 0, p4 = 0;
    do{
        int px1 = Random_number(ax + 1, bx - 1);
        int px2 = Random_number(ax + 1, bx - 1);
        int py1 = Random_number(ay + 1, by - 1);
        int py2 = Random_number(ay + 1, by - 1);
        int random = rand() % 2;
        if((random == 1) && (p1 == 0)){
            p1 = 1;
            pixel[ay][px1].font = '+';
            pixel[ay][px1].flag = 5;
            pixel[ay][px1].location = 'U';
        }
        random = rand() % 2;
        if((random == 1) && (p2 == 0)){
            p2 = 1;
            pixel[by][px2].font = '+';
            pixel[by][px2].flag = 5;
            pixel[by][px2].location = 'D';
        }
        random = rand() % 2;
        if((random == 1) && (p3 == 0)){
            p3 = 1;
            pixel[py1][ax].font = '+';
            pixel[py1][ax].flag = 5;
            pixel[py1][ax].location = 'L';
        }
        random = rand() % 2;
        if((random == 1) && (p4 == 0)){
            p4 = 1;
            pixel[py2][bx].font = '+';
            pixel[py2][bx].flag = 5;
            pixel[py2][bx].location = 'R';
        }
        p = p1 + p2 + p3 + p4;
    } while (p != 3 && p != 4);
}

void Table_show(int x1, int x2, int y1, int y2){
    int randomy1, randomx1, randomy2, randomx2, p = 0;
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

int Rahroh_up(int a, int b, int c, int d, int e){
    int m1, n1, m2, n2, p1 = 0, p2 = 0;
    for(int j = a; j < b; j++){
        for(int i = c; i < d; i++){
            if(pixel[j][i].location == 'U'){
                m1 = j;
                n1 = i;
                p1++;
            }
        }
    }
    for(int j = a; j < b; j++){
        for(int i = d + 1; i < e; i++){
            if(pixel[j][i].location == 'L'){
                m2 = j;
                n2 = i;
                p2++;
            }
        }
    }
    if (p1 + p2 == 2){
        Masir(m1, n1, m2, n2);
    }
    else if(p1 == 1){
        for(int j = a; j < b; j++){
            for(int i = d + 1; i < e; i++){
                if(pixel[j][i].location == 'U'){
                    m2 = j;
                    n2 = i;
                    p2++;
                }
            }
        }
        Masir(m1, n1, m2, n2);
    }
}

int Rahoroh_right(int a, int b, int c, int d, int e){
    int m1, n1, m2, n2, p1 = 0, p2 = 0;
    for(int j = a; j < b; j++){
        for(int i = c; i < d; i++){
            if(pixel[j][i].location == 'R'){
                m1 = j;
                n1 = i;
                p1++;
            }
        }
    }
    for(int j = a; j < b; j++){
        for(int i = d + 1; i < e; i++){
            if(pixel[j][i].location == 'L'){
                m2 = j;
                n2 = i;
                p2++;
            }
        }
    }
    if (p1 + p2 == 2){
        Masir(m1, n1, m2, n2);
    }
    else if(p1 == 1){
        for(int j = a; j < b; j++){
            for(int i = d + 1; i < e; i++){
                if(pixel[j][i].location == 'U'){
                    m2 = j;
                    n2 = i;
                    p2++;
                }
            }
        }
        Masir(m1, n1, m2, n2);
    }
    else{
        Rahroh_up(a, b, c, d, e);
    }
}

int Rahroh_left(int a, int b, int c, int d, int e){
    int m1, n1, m2, n2, p1 = 0, p2 = 0;
    for(int j = a; j < b; j++){
        for(int i = c; i < d; i++){
            if(pixel[j][i].location == 'L'){
                m1 = j;
                n1 = i;
                p1++;
            }
        }
    }
    for(int j = b + 1; j < e; j++){
        for(int i = c; i < d; i++){
            if(pixel[j][i].location == 'U'){
                m2 = j;
                n2 = i;
                p2++;
        }
        }
    }
    if (p1 + p2 == 2){
        Masir_1(m1, n1, m2, n2);
    }
    else if(p1 == 1){
        for(int j = b + 1; j < e; j++){
            for(int i = c; i < d; i++){
                if(pixel[j][i].location == 'L'){
                    m2 = j;
                    n2 = i;
                    p2++;
                }
            }
        }
        Masir_1(m1, n1, m2, n2);
    }
}

int Rahroh_down(int a, int b, int c, int d, int e){
    int m1, n1, m2, n2, p1 = 0, p2 = 0;
    for(int j = a; j < b; j++){
        for(int i = c; i < d; i++){
            if(pixel[j][i].location == 'D'){
                m1 = j;
                n1 = i;
                p1++;
            }
        }
    }
    for(int j = b + 1; j < e; j++){
        for(int i = c; i < d; i++){
            if(pixel[j][i].location == 'U'){
                m2 = j;
                n2 = i;
                p2++;
        }
        }
    }
    if (p1 + p2 == 2){
        Masir_1(m1, n1, m2, n2);
    }
    else if(p1 == 1){
        for(int j = b + 1; j < e; j++){
            for(int i = c; i < d; i++){
                if(pixel[j][i].location == 'L'){
                    m2 = j;
                    n2 = i;
                    p2++;
                }
            }
        }
        Masir_1(m1, n1, m2, n2);
    }
    else{
        Rahroh_left(a, b, c, d, e);
    }
}

int Main_game(){
    srand(time(0));
    int tedad = Random_number(11, 15);
    tedad = 12;
    /*/
    if(tedad == 11){
        Table_show(4, 36, 4, 12);
        Table_show(38, 74, 4, 12);
        Table_show(76, 112, 4, 12);
        Table_show(114, 148, 4, 12);
        Table_show(4, 49, 14, 23);
        Table_show(51, 100, 14, 23);
        Table_show(102, 148, 14, 23);
        Table_show(4, 36, 25, 32);
        Table_show(38, 74, 25, 32);
        Table_show(76, 112, 25, 32);
        Table_show(114, 148, 25, 32);
        int m1, m2, n1, n2;
        for(int j = 4; j < 13; j++){
            for(int i = 4; i < 37; i++){
                if(pixel[j][i].flag == 5){
                    m1 = i;
                    n1 = j;
                }
            }
        }
        for(int j = 4; j < 13; j++){
            for(int i = 38; i < 75; i++){
                if(pixel[j][i].flag == 5){
                    m2 = i;
                    n2 = j;
                }
            }
        }
        Masir(n1, m1, n2, m2);
        //mvprintw(10, 50, "%d %d %d %d", n1, n2, m1, m2);
    }
    */
    if(tedad == 12){
        Table_show(4, 36, 4, 12);
        Table_show(38, 74, 4, 12);
        Table_show(76, 112, 4, 12);
        Table_show(114, 148, 4, 12);
        Table_show(4, 36, 14, 23);
        Table_show(38, 74, 14, 23);
        Table_show(76, 112, 14, 23);
        Table_show(114, 148, 14, 23);
        Table_show(4, 36, 25, 32);
        Table_show(38, 74, 25, 32);
        Table_show(76, 112, 25, 32);
        Table_show(114, 148, 25, 32);
        Rahoroh_right(4, 13, 4, 37, 75);
        Rahoroh_right(4, 13, 38, 75, 113);
        Rahoroh_right(4, 13, 76, 113, 148);
        Rahoroh_right(14, 24, 4, 37, 75);
        Rahoroh_right(14, 24, 38, 75, 113);
        Rahoroh_right(14, 24, 76, 113, 148);
        Rahoroh_right(25, 33, 4, 37, 75);
        Rahoroh_right(25, 33, 38, 75, 113);
        Rahoroh_right(25, 33, 76, 113, 148);
        Rahroh_down(4, 13, 4, 37, 24);
        Rahroh_down(14, 24, 4, 37, 33);
        Rahroh_down(4, 13, 38, 75, 24);
        Rahroh_down(14, 24, 38, 75, 33);
        Rahroh_down(4, 13, 76, 113, 24);
        Rahroh_down(14, 24, 76, 113, 33);
        Rahroh_down(4, 13, 114, 149, 24);
        Rahroh_down(14, 24, 114, 149, 33);
    }
    update_screen();
    getch();
    Login();
    
}



int Check_password(){
    /*
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
    int p;
    do{
        p = 1;
        fptr = (fopen("useesinfo.dat","rb+"));
        mvprintw(11, 50, "                                                                  ");
        attron(COLOR_PAIR(3));
        char string[40];
        mvscanw(11,50, "%s", string);
        fread(&temp, sizeof(user), 1, fptr);
        while(!feof(fptr) && p){
            if(!strcmp(string, userinfo.name)){
                attron(COLOR_PAIR(1));
                mvprintw(13, 50, "please enter your password:");
                attroff(COLOR_PAIR(1));
                mvscanw(14, 50, "%s", string);
                if(!(string, userinfo.password)){
                    mvprintw(31, 54, "Wellcome %s!", userinfo.name);
                    mvprintw(32, 54, "Press any key to get back to the previous page");
                    break;
                }
                break;
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
    return ;
    /*/

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
    for(int j = 0; j < 38; j++){
        for(int i = 0; i < 153; i++){
            pixel[j][i].flag = 0;
        }
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
