//X= Horizontal
//Y= Vertical
//pop= mendorong ular
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <sys/timeb.h>
using namespace std;

struct segment{
    int x,y;
    struct segment *next, *prev;
    }*head,*tail,*current,*temp;

    int score_read()
    {
        FILE *rd;
        int high_score;
        rd=fopen("Highscore.txt","r");
        if(!rd){
            return 0;
        }
        else{
            while(!feof(rd)){
                fscanf(rd,"%d",&high_score);fflush(stdin);
            }
            fclose(rd);
        }
        return high_score;
    }
    int skor_write(int score)
    {
        FILE *wr;
        int skor;
        skor=score;
        wr=fopen("Highscore.txt","w");
        if(!wr){
            return 0;
        }
        else{
            fprintf(wr,"%d",skor);
        }
        fclose(wr);
    }
    void push (int x, int y)
    {
    current = (struct segment*)malloc(sizeof(struct segment));
    current->next = current->prev = NULL;
    current->x = x;
    current->y = y;
    if(head == NULL){
        head = tail = current;
        }
        else{
            current->next = head;
            head->prev = current;
            head=current;
        }
    }
    void pop()
    {
        if(head==tail){
            free(head);
            head = tail = NULL;
        }
    }
    void pop_all()
    {
        while(head!=NULL){
            pop();
        }
    }
    void gotoxy(int x, int y)
    {
        COORD pos;
        pos.X = x;
        pos.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    }
    void display()
    {
        temp=head;
        while(temp!=NULL){
            gotoxy(temp->x,temp->y);
            printf("o");
            temp=temp->next;
        }
    }
    //Variabel set game snake
    int snake_size=3;
    int snake_speed=200;
    int dir = VK_RIGHT;
    int game_width=56;
    int game_height=25;
    int food_x, food_y;

    int check(int x, int y)
    {
        temp=head;
        while (temp!=NULL){
            if(temp->x==x && temp->y == y){
                return 1;
            }
            temp =temp->next;
        }
        return 0;
    }
    void place_food()
    {
        int x,y;
        do{
            food_x =rand()%(game_width-1)+1;
            food_y =rand()%(game_height-1)+1;
        }
        while(check(food_x,food_y)==1);
    }
    void load()
    {
        int i;
        printf("\n\n\tsilahkan tungu");
        for(i=0;i<5;i++);
        //sleep(600);
        printf(".");
    }
    system("cls");
    for(i=0;i<5;i++)
    {
        printf("\n\n\t\t%d",5-i);
        sleep(1000);
        system("cls");
    }
    void header(){
    cout<<"||========================================||"<<endl;
    cout<<"||            PERMAINAN SNAKE             ||"<<endl;
    cout<<"||----------------------------------------||"<<endl;
    cout<<"||                                        ||"<<endl;
    cout<<"||         OLEH :                         ||"<<endl;
    cout<<"|| MOCHAMMAD RIZKY KURNIA FAJAR :215521016||"<<endl;
    cout<<"||                                        ||"<<endl;
    cout<<"||                                        ||"<<endl;
    cout<<"||----------------------------------------||"<<endl;
    cout<<"||               JURUSAN                  ||"<<endl;
    cout<<"||            ILMU KOMPUTER               ||"<<endl;
    cout<<"||========================================||"<<endl;
    cout<<"TEKAN ENTER UNTUK KE MENU"<<endl;
    system("PAUSE");
    system("cls");
    }
    int game_in(){
    int level = 1;
    int 1;
    int x,y;
    srand(time(NULL));
    int score=0;
    int high_score;
    high_score=skor_read();
    load();

    struct timeb last_timestamp;
    ftime(&last_timestamp);

    for(i=1;i<=snake_size;i++)
    {
        push(1,15);
    }
    place_food();

    while(1)
    {
        struct timeb current_timestamp;
        ftime(&current_timestamp);
        int interval = 1000 * (current_timestamp.time - last_timestamp.time + current_timestamp.millitm - last_time.millitm);

        if(interval > snake_speed)
        }
        {
            switch(dir) //INPUT KEYBOARD
            {
                case VK_LEFT:
                x = head->x - 1;
                y = head->y;
                break;

                case VK_RIGHT:
                x = head->x + 1;
                y = head->y;
                break;

                case VK_UP:
                x = head->x;
                y = head->y - 1;
                break;

                case VK_DOWN:
                x = head->x;
                y = head->y + 1;
                break;
            }
            if(x<1||x>=game_width||y<1||y>=game_height)
            {
                break;
            }
            if(check(x,y)==1)
            {
                break;
            }
            if(x==food_x && y==food_y)
            {
                score = score+100;
                place_food();

                if(score%300==0 && score!=0)
                {
                    snake_speed=snake_speed-10;
                    level=level=1;
                }
                else{
                    pop();
                }
            }
            push(x,y);
            system("cls");
            cout<<"########################################################\t\t   GAME SNAKE"<<endl;
            cout<<"#                                                      #\t\tLEVEL      :"<<level<<endl;
            cout<<"#                                                      #\t\tSCORE      :"<<score<<endl;
            cout<<"#                                                      #\t\tHIGH SCORE :"<<high_score<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"#                                                      #"<<endl;
            cout<<"########################################################"<<endl;

            display();
            gotoxy(food_x,food_y);
            cout<<"@";

            last_timestamp=current_timestamp;
        }//ULAR TETAP LURUS
        if(GetKeyState(VK_LEFT)<0)
        {
            if(dir!=VK_RIGHT)
            {
                dir=VK_LEFT;
            }
        }
        if(GetKeyState(VK_RIGHT)<0)
        {
            if(dir!=VK_LEFT)
            {
                dir=VK_RIGHT;
            }
        }
        if(GetKeyState(VK_UP)<0)
        {
            if(dir!=VK_DOWN)
            {
                dir=VK_UP;
            }
        }
        if(GetKeyState(VK_DOWN)<0)
        {
            if(dir!=VK_UP)
            {
                dir=VK_DOWN;
            }
        }
        if(GetKeyState(VK_ESCAPE)<0)
        {
            return 0;
        }
        system("cls");
        cout<<"GAME OVER"<<endl;
        cout<<"Your Score :"<<score<<endl;
        cout<<"High Score :"<<high_score<<endl;
        if(score>high_score)
        {
            cout<<"KAMU SUDAH MELEWATI SCORE TERTINGGI";
            skor_write(score);
        }
        else
        {
            cout<<"COBA LAGI :)";
        }
        pop_all();
        getch();
    }
    int main()
    {
        int menu;
        header();
        cout<<"1. MULAI"<<endl;
        cout<<"2. Exit"<<endl;
        cout<<"Pilihan :"endl;
        if (menu==1)
        {
            game_in();
            system("pause");
        }
        else id(menu==2)
        {
            cout<<"TERIMA KASIH";
        }
        return 0;
    }

