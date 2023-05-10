#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define outputHandle GetStdHandle(STD_OUTPUT_HANDLE)

#define BLACK 0
#define DARK_BLUE 1
#define DARK_GREEN 2
#define DARK_CYAN 3
#define DARK_RED 4
#define DARK_PURPLE 5
#define DARK_YELLOW 6
#define DARK_WHITE 7

#define GRAY 8
#define BLUE 9
#define GREEN 10
#define CYAN 11
#define RED 12
#define PURPLE 13
#define YELLOW 14
#define WHITE 15

void bingkai();
void kotak1();
void kotak_spaent();
void kotakMenu();
void logo();
void hapus();
void hapus1();
void hapus2();
void first();
void daftar();
void load();
void masuk();
void uspas();
void halamanAdmin();
void menuAdmin();
void menuKandidat();
void dataKandidat();
void addition();
void kandidatPenuh();
void carilahKandidatEdit();
void carilahKandidatHapus();
void carilahKandidatDetail();
void editKandidat();
void hapusKandidat();
void detailKandidat();
void status();
void hasilAdmin();
void hasilUser();
void halamanUser();
void menuUser();
void kandidatUser();
void detaliKandidatUser();
void votingUser();
void kotakStatus();
char* validasiHuruf(char huruf[],int x,int y);
int valHuruf(char huruf[]);


int text_color = FOREGROUND_INTENSITY;
int background_color = 0;

char login[100][2][100];
char kandidat[5][3][1000] = {{"WAHYU","DIMAS FIRMANSYAH","Ngoding, Makan, Tidur"},{"ANANDA PRATAMA INDRABUANA","M. AZRIEL PAZARUDIN","Mendingan Tidur Daripada Ngoding"}};
char misi[5][10][300] = {{"Sabar","Syukur","Sukses","Selamat","Dunia Akhirat"},{"Tidur","Makan","Tidur","Makan","DroupOut ( DO )"}};
char pemilih[100][4][50] = {{"01022111023","WAHYU","20","S1 AKUNTANSI"},{"02032111018","AHMAD FARHAN FAUZAN","20","S1 TEKNIK INFORMATIKA"},{"02042111001","ACHMAD FAUZI SUHANDI","20","D3 MANAJEMEN INFORMATIKA"},{"02042111002","AGUS RAHMAN HIDAYAT","20","D3 MANAJEMEN INFORMATIKA"},{"02042111003","AHMAD FISAL HIDAYAT","20","D3 MANAJEMEN INFORMATIKA"},{"02042111004","ALI HANAFIAH","20","D3 MANAJEMEN INFORMATIKA"},{"02042111005","ALIYA ROHAYA SIREGAR","20","D3 MANAJEMEN INFORMATIKA"},{"010221110011","AMELIA SIREGAR","20","S1 AKUNTANSI"},{"02042111006","ANANDA PRATAMA INDRA BUANA","20","D3 MANAJEMEN INFORMATIKA"},{"02042111007","ANDRIANSYAH","20","D3 MANAJEMEN INFORMATIKA"},{"02032111020","ANGGI PERMANA","20","S1 TEKNIK INFORMATIKA"}};
int tampLogin=0;
int tampKandidat=2;
int tampPemilih=42;
int tam_misi[5];
int prosesVote[5]={0,0,0,0,0};
bool tandaSudahVoting[100]={false};
int tandaPemilih;
char userAdmin[50] = "040303";
char passAdmin[50] = "ADMIN";
char user[100],pass[100];
char cariKandidat[10];
char nim[16],tampnim[16],namaLengkap[30],angkatan[5],prodi[50];
char ketum[100],keamanan[100],visiKandidat[100],misiKandidat[100];
char tampNama[100],tampNim[100],tampAkt[100],tampProdi[100];



void gotoxy(int x, int y)
{
    COORD position = {x, y};
    SetConsoleCursorPosition(outputHandle, position);
}

void color(int color)
{
    SetConsoleTextAttribute(outputHandle, color | (background_color << 4));
    text_color = color;
}

void background(int color)
{
    SetConsoleTextAttribute(outputHandle, text_color | (color << 4));
    background_color = color;
}

void bingkai()
{
    background(0);
    color(6);
    for (int x = 0; x <= 119; x++)
    {
        for (int y = 0; y <= 39; y++)
        {
            gotoxy(x, y);
            if (x == 0 || x == 1 || x == 118 || x == 119 || y == 0 || y == 39)
            {
                printf("%c", 219);
            }
            else
            {
                printf(" ");
            }
        }
    }
}

void logo()
{
    color(6);
    gotoxy(33, 10); printf("                  ##############################          ");
    gotoxy(33, 11); printf("                 ##                                       ");
    gotoxy(33, 12); printf("    ####        ##   ######   ######   ######             ");
    gotoxy(33, 13); printf("    #          ##    ##  ##     ##     ##                 ");
    gotoxy(33, 14); printf("    ####      ##     ##  ##     ##     ######             ");
    gotoxy(33, 15); printf("    #        ##      ##  ##     ##     ##                 ");
    gotoxy(33, 16); printf("    ####    ##       ######     ##     ######             ");
    gotoxy(33, 17); printf("           ##                                             ");
    gotoxy(33, 18); printf("##        ##         ######   ##  ##   ######             ");
    gotoxy(33, 19); printf(" ##      ##          ##  ##   ##  ##   ##  ###            ");
    gotoxy(33, 20); printf("  ##    ##           ######   ##  ##   ######             ");
    gotoxy(33, 21); printf("   ##  ##            ##       ##  ##   ##  ###            ");
    gotoxy(33, 22); printf("    ####             ##       ######   ######             ");
    gotoxy(33, 26); printf("       ~~~  PEMBERDAYAAN UMAT BERKELANJUTAN  ~~~          ");
    color(6);
    gotoxy(33, 29);
    printf("<=========== Tekan SPASI Untuk Melanjutkan ==============>");
    color(3);
    gotoxy(30,37); printf("C O P Y   R I G H T   B Y   W A H Y U   J E B R E D ' Z ");

    while (true)
    {
        char pilih_menu;
        gotoxy(60, 28);
        pilih_menu = getch();
        if (pilih_menu == 32)
        {
            gotoxy(60, 28);
            printf("   ");
            hapus();
            first();
        }
        else
        {
            color(4);
            gotoxy(50, 28);
            printf("   ");
            gotoxy(40, 28);
            printf("M A S U K A N   T I D A K   V A L I D   ! ! !");
            Sleep(700);
            gotoxy(40, 28);
            printf("                                              ");
            Sleep(700);
            gotoxy(40, 28);
            printf("M A S U K A N   T I D A K   V A L I D   ! ! !");
            Sleep(700);
            gotoxy(40, 28);
            printf("                                              ");
            Sleep(700);
            gotoxy(60, 28);
            printf("   ");
        }
    }
}

void first()
{
        color(6);
        gotoxy(20, 2);  printf("######   ######   ####   ####   ##   ##       ##  ##     ######   ##  ##   ######");
        gotoxy(20, 3);  printf("##  ##   ##       ## ## ## ##   ##   ##       ##  ##     ##  ##   ##  ##   ##   ##");
        gotoxy(20, 4);  printf("######   ######   ##  ###  ##   ##   ##       ##  ##     ######   ##  ##   ## ###");
        gotoxy(20, 5);  printf("##       ##       ##       ##   ##   ##       ##  ##     ##       ##  ##   ##   ##");
        gotoxy(20, 6);  printf("##       ######   ##       ##   ##   ######   ######     ##       ######   ######");

    color(11);
    gotoxy(15, 8);  printf("      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(15, 9);  printf("    %c%c                                                                             %c%c",219,219,219,219,219);					
    gotoxy(15, 10); printf("  %c%c                                                                                 %c%c",219,219,219,219,219);
    gotoxy(15, 11); printf("%c%c                                                                                     %c%c",219,219,219,219,219);
    gotoxy(15, 12); printf("%c%c                                                                                     %c%c",219,219,219,219,219);
    gotoxy(15, 13); printf("%c%c                                                                                     %c%c",219,219,219,219,219);
    gotoxy(15, 14); printf("  %c%c                                                                                 %c%c",219,219,219,219,219);
    gotoxy(15, 15); printf("    %c%c                                                                             %c%c",219,219,219,219,219);
    gotoxy(15, 16); printf("      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);

    gotoxy(15, 18); printf("      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(15, 19); printf("    %c%c                                                                             %c%c",219,219,219,219,219);					
    gotoxy(15, 20); printf("  %c%c                                                                                 %c%c",219,219,219,219,219);
    gotoxy(15, 21); printf("%c%c                                                                                     %c%c",219,219,219,219,219);
    gotoxy(15, 22); printf("%c%c                                                                                     %c%c",219,219,219,219,219);
    gotoxy(15, 23); printf("%c%c                                                                                     %c%c",219,219,219,219,219);
    gotoxy(15, 24); printf("  %c%c                                                                                 %c%c",219,219,219,219,219);
    gotoxy(15, 25); printf("    %c%c                                                                             %c%c",219,219,219,219,219);
    gotoxy(15, 26); printf("      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);

    color(6);
    gotoxy(23, 10); printf("  ####            ######   ##   ######   ###    ##      ##  ##   ######");
    gotoxy(23, 11); printf("    ##            ##       ##   ##       ####   ##      ##  ##   ##  ##");
    gotoxy(23, 12); printf("    ##            ######   ##   ##  ##   ##  ## ##      ##  ##   ######");
    gotoxy(23, 13); printf("    ##                ##   ##   ##   ##  ##   ####      ##  ##   ##    ");
    gotoxy(23, 14); printf(" ########  ##     ######   ##   #######  ##    ###      ######   ##    ");

    gotoxy(23, 20); printf(" ######           ######   ##   ######   ###    ##      ##   ###    ## ");
    gotoxy(23, 21); printf("     ##           ##       ##   ##       ####   ##      ##   ####   ## ");
    gotoxy(23, 22); printf(" ######           ######   ##   ##  ##   ##  ## ##      ##   ##  ## ## ");
    gotoxy(23, 23); printf(" ##                   ##   ##   ##   ##  ##   ####      ##   ##   #### ");
    gotoxy(23, 24); printf(" ######    ##     ######   ##   #######  ##    ###      ##   ##    ### ");

    gotoxy(23, 30);
    printf("<<<======== TEKAN 1 UNTUK SIGN UP ATAU TEKAN 2 UNTUK SIGN IN ========>>>");
    while (true)
    {
        char pilih;
        gotoxy(58, 29);
        pilih = getch();
        if (pilih == '1')
        {
            hapus();
            daftar();
        }
        else if (pilih == '2')
        {
            hapus();
            masuk();
        }
        else
        {
            color(4);
            gotoxy(58, 29);
            printf("   ");
            gotoxy(37, 31);
            printf("M A S U K A N   T I D A K   V A L I D   ! ! !");
            Sleep(700);
            gotoxy(37, 31);
            printf("                                             ");
            Sleep(700);
            gotoxy(37, 31);
            printf("M A S U K A N   T I D A K   V A L I D   ! ! !");
            Sleep(700);
            gotoxy(37, 31);
            printf("                                             ");
            Sleep(700);
        }
    }
}

void hapus()
{
    for (int a = 1; a <= 36; a++)
    {
        gotoxy(2, 0 + a);
        printf("                                                                                                                    ");
        Sleep(5);
    }
}

void hapus1()
{
    for (int i = 1; i <= 26; i++)
    {
        gotoxy(5,8+i);
        printf("                                                                                                              ");
        Sleep(5);
    }
}

void hapus2()
{
    for (int i = 1; i <= 6; i++)
    {
        gotoxy(5,1+i);
        printf("                                                                                                              ");
        Sleep(5);
    }
}

void daftar()
{
    gotoxy(32, 5); printf("######   ##   ######   ###    ##      ##  ##   ######");
    gotoxy(32, 6); printf("##       ##   ##       ####   ##      ##  ##   ##  ##");
    gotoxy(32, 7); printf("######   ##   ##  ##   ##  ## ##      ##  ##   ######");
    gotoxy(32, 8); printf("    ##   ##   ##   ##  ##   ####      ##  ##   ##    ");
    gotoxy(32, 9); printf("######   ##   #######  ##    ###      ######   ##    ");

    for (int x = 0; x <= 75; x++)
    {
        for (int y = 0; y <= 16; y++)
        {
            color(11);
            gotoxy(20 + x, 13);
            printf("%c", 219);
            gotoxy(20 + x, 17);
            printf("%c", 219);
            gotoxy(20 + x, 21);
            printf("%c", 219);
            gotoxy(20 + x, 25);
            printf("%c", 219);
            gotoxy(20 + x, 29);
            printf("%c", 219);
            gotoxy(20, 13 + y);
            printf("%c", 219);
            gotoxy(38, 13 + y);
            printf("%c", 219);
            gotoxy(96, 13 + y);
            printf("%c", 219);
        }
    }

        color(6);
        gotoxy(23, 15);
        printf("NIM ");
        gotoxy(23, 19);
        printf("NAMA LENGKAP ");
        gotoxy(23, 23);
        printf("ANGKATAN ");
        gotoxy(23, 27);
        printf("PROGRAM STUDI ");


            gotoxy(40, 15);
            printf("MAKSIMAL 11 KARAKTER");
            Sleep(500);
            gotoxy(40, 15);
            printf("                    ");
            Sleep(500);
            gotoxy(40, 15);
            printf("MAKSIMAL 11 KARAKTER");
            Sleep(500);
            gotoxy(40, 15);
            printf("                    ");

        int b = 0;
        while (b != 1)
        {
            int x = 0;
            gotoxy(40, 15);
            nim[x] = getch();
            while (nim[x] != 13)
            {
                if (nim[x] == 8 || nim[0] == ' ')
                {
                    x--;
                    if (x < 0)
                    {
                        x = 0;
                    }
                    gotoxy(40 + x, 15);
                    printf(" ");
                }
                else if (nim[x] >= '0' && nim[x] <= '9')
                {
                    printf("%c", nim[x]);
                    x++;
                }
                else
                {
                    printf("\b", nim[x]);
                }
    
                if (x > 11)
                {
                    x = 11;
                    gotoxy(51, 15);
                    printf(" ");
                }
                gotoxy(40 + x, 15);
                nim[x] = getch();
            }
            nim[x] = NULL;
            if (strlen(nim) <= 11)
            {
                bool y=true;
                bool x=false;
                strcpy(pemilih[tampPemilih][0], nim);
                while (y==true)
                {
                        for(int a=0;a<tampPemilih;a++)
                        {
                            if(strcmp(pemilih[a][0],pemilih[tampPemilih][0])==0)
                            {
                                x=true;
                                break;
                            }
                        }
                        if(x==true)
                        {
                            gotoxy(40, 15);
                            printf("                      ");
                            gotoxy(40, 15);
                            printf("N I M   T I D A K   B O L E H   S A M A   ! ! !");
                            Sleep(500);
                            gotoxy(40, 15);
                            printf("                                               ");
                            Sleep(500);
                            gotoxy(40, 15);
                            printf("N I M   T I D A K   B O L E H   S A M A   ! ! !");
                            Sleep(500);
                            gotoxy(40, 15);
                            printf("                                               ");
                            break;
                        } 
                        else 
                        {
                            strcpy(pemilih[tampPemilih][0],strcpy(tampnim,pemilih[tampPemilih][0]));
                            y=false;
                              b=1;
                        }
                }   
            }
        }
            gotoxy(40, 19);
            printf("MAKSIMAL 20 KARAKTER");
            Sleep(500);
            gotoxy(40, 19);
            printf("                    ");
            Sleep(500);
            gotoxy(40, 19);
            printf("MAKSIMAL 20 KARAKTER");
            Sleep(500);
            gotoxy(40, 19);
            printf("                    ");
        int a = 0;
        while (a != 1)
        {
            int x = 0;
            gotoxy(40, 19);
            namaLengkap[x] = getch();
            while (namaLengkap[x] != 13)
            {
                if (namaLengkap[x] == 8 || namaLengkap[0] == ' ')
                {
                    x--;
                    if (x < 0)
                    {
                        x = 0;
                    }
                    gotoxy(40 + x, 19);
                    printf(" ");
                }
                else if ((namaLengkap[x] >= 'a' && namaLengkap[x] <= 'z') || (namaLengkap[x] >= 'A' && namaLengkap[x] <= 'Z') || namaLengkap[x] == '-' || namaLengkap[x] == ' ')
                {
                    printf("%c", namaLengkap[x]);
                    x++;
                }
                else
                {
                    printf("\b", namaLengkap[x]);
                }
                if (x > 20)
                {
                    x = 20;
                    gotoxy(60, 19);
                    printf(" ");
                }
                gotoxy(40 + x, 19);
                namaLengkap[x] = getch();
            }
            namaLengkap[x] == NULL;
            // if (strlen(namaLengkap) <= 20)
            // {
                strupr(namaLengkap);
                strcpy(pemilih[tampPemilih][1], namaLengkap);
                a=1;
            //}
            // else
            // {
            //     gotoxy(40, 19);
            //     printf("I N P U T A N   N A M A   S A L A H   ! ! !");
            //     Sleep(500);
            //     gotoxy(40, 19);
            //     printf("                                           ");
            //     Sleep(500);
            //     gotoxy(40, 19);
            //     printf("I N P U T A N   N A M A   S A L A H   ! ! !");
            //     Sleep(500);
            //     gotoxy(40, 19);
            //     printf("                                           ");
            //     a+=2;
            // }
            
        }

            gotoxy(40, 23);
            printf("MAKSIMAL 2 KARAKTER");
            Sleep(500);
            gotoxy(40, 23);
            printf("                   ");
            Sleep(500);
            gotoxy(40, 23);
            printf("MAKSIMAL 2 KARAKTER");
            Sleep(500);
            gotoxy(40, 23);
            printf("                   ");
        int c = 0;
        bool g=false;
        while (c != 1)
        {
            int x = 0;
            gotoxy(40, 23);
            angkatan[x] = getch();
            while (angkatan[x] != 13)
            {
                if (angkatan[x] == 8 || angkatan[0] == ' ')
                {
                    x--;
                    if (x < 0)
                    {
                        x = 0;
                    }
                    gotoxy(40 + x, 23);
                    printf(" ");
                }
                else if (angkatan[x] >= '0' && angkatan[x] <= '9')
                {
                    printf("%c", angkatan[x]);
                    x++;
                }
                else
                {
                    printf("\b", angkatan[x]);
                }
    
                if (x > 2)
                {
                    x = 2;
                    gotoxy(42, 23);
                    printf(" ");
                }
                gotoxy(40 + x, 23);
                angkatan[x] = getch();
            }
            angkatan[x] = NULL;
            if (strlen(angkatan) <= 2 && (strcmp(angkatan,"17")==0 || strcmp(angkatan,"18")==0 || strcmp(angkatan,"19")==0 || strcmp(angkatan,"20")==0))
            {
                strcpy(pemilih[tampPemilih][2],angkatan);
                c=1;         
            }
            else 
            {
                gotoxy(40, 23);
                printf("ANGKATAN YANG DI INPUT TIDAK ADA !!!");
                Sleep(500);
                gotoxy(40, 23);
                printf("                                    ");
                Sleep(500);
                gotoxy(40, 23);
                printf("ANGKATAN YANG DI INPUT TIDAK ADA !!!");
                Sleep(500);
                gotoxy(40, 23);
                printf("                                     ");
                c+=2;
            }
        }
            gotoxy(40, 27);
            printf("MAKSIMAL 24 KARAKTER");
            Sleep(500);
            gotoxy(40, 27);
            printf("                    ");
            Sleep(500);
            gotoxy(40, 27);
            printf("MAKSIMAL 24 KARAKTER");
            Sleep(500);
            gotoxy(40, 27);
            printf("                    ");
        int d = 0;
        bool j=false;
        while (d != 1)
        {
            int x = 0;
            gotoxy(40, 27);
            prodi[x] = getch();
            while (prodi[x] != 13)
            {
                if (prodi[x] == 8 || prodi[0] == ' ')
                {
                    x--;
                    if (x < 0)
                    {
                        x = 0;
                    }
                    gotoxy(40 + x, 27);
                    printf(" ");
                }
                else if ((prodi[x] >= 'a' && prodi[x] <= 'z') || (prodi[x] >= 'A' && prodi[x] <= 'Z') || prodi[x] == '1' || prodi[x] == '3' || prodi[x] == ' ')
                {
                    printf("%c", prodi[x]);
                    x++;
                }
                else
                {
                    printf("\b", prodi[x]);
                }
                if (x > 24)
                {
                    x = 24;
                    gotoxy(64, 27);
                    printf(" ");
                }
                gotoxy(40 + x, 27);
                prodi[x] = getch();
            }
            prodi[x] = NULL;
            strupr(prodi);
            if (strlen(prodi) <= 24 && (strcmp(prodi,"S1 AKUNTANSI")==0 ||strcmp(prodi,"S1 TEKNIK INFORMATIKA")==0 || strcmp(prodi,"D3 MANAJEMEN INFORMATIKA")==0))
            {
                strcpy(pemilih[tampPemilih][3], prodi);
                d=1;
            }
            else 
            {
                gotoxy(40, 27);
                printf("PROGRAM STUDI YANG DI INPUT TIDAK ADA !!!");
                Sleep(500);
                gotoxy(40, 27);
                printf("                                         ");
                Sleep(500);
                gotoxy(40, 27);
                printf("PROGRAM STUDI YANG DI INPUT TIDAK ADA !!!");
                Sleep(500);
                gotoxy(40, 27);
                printf("                                         ");
                d+=3;
            }
        }
        tampPemilih++;
        load();
        hapus();
        first();
}

void masuk()
{
    char pil;
    color(6);
    gotoxy(32, 5);  printf("######   ##   ######   ###    ##      ##   ###    ##");
    gotoxy(32, 6);  printf("##       ##   ##       ####   ##      ##   ####   ##");
    gotoxy(32, 7);  printf("######   ##   ##  ##   ##  ## ##      ##   ##  ## ##");
    gotoxy(32, 8);  printf("    ##   ##   ##   ##  ##   ####      ##   ##   ####");
    gotoxy(32, 9);  printf("######   ##   #######  ##    ###      ##   ##    ###");

    color(11);
    gotoxy(28, 13); printf("      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(28, 14); printf("    %c%c                                                %c%c",219,219,219,219);
    gotoxy(28, 15); printf("  %c%c                                                    %c%c",219,219,219,219);
    gotoxy(28, 16); printf("    %c%c                                                %c%c",219,219,219,219);
    gotoxy(28, 17); printf("      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);

    gotoxy(28, 20); printf("      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(28, 21); printf("    %c%c                                                %c%c",219,219,219,219);
    gotoxy(28, 22); printf("  %c%c                                                    %c%c",219,219,219,219);
    gotoxy(28, 23); printf("    %c%c                                                %c%c",219,219,219,219);
    gotoxy(28, 24); printf("      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);

            color(6);
            gotoxy(36, 15); printf("USERNAME  :");
            gotoxy(36, 22); printf("PASSWORD  :");
        // gotoxy(40,27); printf("T I D A K   P U N Y A   A K U N   ? ? ?");
        uspas();
    //     kotak_spaent();
    // int x=0;
    // int p;
    // do
    // {
    //     kotak1(x,4);
    //     p=getch();
    //     switch(p){
    //         case 77:
    //         kotak1(x,11);
    //         x+=28;
    //         if(x>38){
    //             x=0;
    //         }
    //         break;
    //         case 75:
    //         kotak1(x,11);
    //         x-=28;
    //         if(x<0){
    //             x=28;
    //         }
    //         break;
    //         case 13:
    //         if (x==28 && p ==13)
    //         {
    //             hapus();
    //             daftar();
    //         }
    //         else if(x==63 && p == 13)
    //         {
    //             printf("Mask");
    //         }
    //     }
    // } while (p != 13);
}

void kotak_spaent()
{
     for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (i == 1 || i == 19 || j == 1 || j == 5)
            {
                // color(15);
                gotoxy(34 + i, j + 28);
                printf("%c", 219);
                color(6);
                gotoxy(41,31); printf("B U A T");
                // color(15);
                gotoxy(62 + i, j + 28);
                printf("%c", 219);
                color(6);
                gotoxy(67,31); printf("L A N J U T");
            }
        }
    }
}

void kotakMenu()
{
    for (int x = 0; x <= 20; x++)
    {
        for (int y = 0; y <= 4; y++)
        {
            color(4);
            gotoxy(7 + x, 2);
            printf("%c", 219);
            gotoxy(7 + x, 6);
            printf("%c", 219);
            gotoxy(7 , 2 + y);
            printf("%c", 219);
            gotoxy(27, 2 + y);
            printf("%c", 219);

            color(7);
            gotoxy(35 + x, 2);
            printf("%c", 219);
            gotoxy(35 + x, 6);
            printf("%c", 219);
            gotoxy(35 , 2 + y);
            printf("%c", 219);
            gotoxy(55, 2 + y);
            printf("%c", 219);

            color(4);
            gotoxy(63 + x, 2);
            printf("%c", 219);
            gotoxy(63 + x, 6);
            printf("%c", 219);
            gotoxy(63 , 2 + y);
            printf("%c", 219);
            gotoxy(83, 2 + y);
            printf("%c", 219);

            color(7);
            gotoxy(92 + x, 2);
            printf("%c", 219);
            gotoxy(92 + x, 6);
            printf("%c", 219);
            gotoxy(92 , 2 + y);
            printf("%c", 219);
            gotoxy(112, 2 + y);
            printf("%c", 219);
        }
    }
}

void kotak1(int x,int w)
{
    color(w);
    for (int i = 35; i <= 53; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (i == 35 || i == 53 || j == 1 || j == 5)
            {
                gotoxy(x + i, j + 28);
                printf("%c", 219);
            }
        }
    }
}

void uspas()
{
    
    int a = 0;
    while (a != 1)
    {
        gotoxy(48, 15); printf("           ");
        int x = 0;
        gotoxy(48, 15);
        user[x] = getch();
        while (user[x] != 13)
        {
            if (user[x] == 8 || user[0] == ' ' || (user[x] >= 'a' && user[x] <= 'z') || (user[x] >= 'A' && user[x] <= 'Z'))
            {
                x--;
                if (x < 0)
                {
                    x = 0;
                }
                gotoxy(48 + x, 15);
                printf(" ");
            }
            else if(user[x] >= '0' && user[x] <= '9')
            {
                printf("%c", user[x]);
                x++;
            }
            if (x > 11)
            {
                x = 11;
                gotoxy(59, 15);
                printf(" ");
            }
            gotoxy(48 + x, 15);
            user[x] = getch();
        }
        user[x] = NULL;

        
        
       for (int i = 0; i < 100; i++)
       {
            if ((strlen(user) <= 11) && (strcmp(user, userAdmin) == 0))
            {
                a = 1;
                i=100;
            }
            else if ((strlen(user) <= 11) && (strcmp(user,pemilih[i][0])==0))
            {
                tandaPemilih=i;
                a = 1;
                strcpy(tampNim,pemilih[i][0]);
                strcpy(tampNama,pemilih[i][1]);
                strcpy(tampAkt,pemilih[i][2]);
                strcpy(tampProdi,pemilih[i][3]);
                i=100;
            }
       }
    }

    int b = 0;
    while (b != 3)
    {
        int x = 0;
        gotoxy(48, 22);
        pass[x] = getch();
        while (pass[x] != 13)
        {
            if (pass[x] == 8 || pass[0] == ' ')
            {
                x--;
                if (x < 0)
                {
                    x = 0;
                }
                gotoxy(48 + x, 22);
                printf(" ");
            }
            else if((pass[x] >= 'a' && pass[x] <= 'z') || (pass[x] >= 'A' && pass[x] <= 'Z') || (pass[x] >= '0' && pass[x] <= '9'))
            {
                printf("*");
                x++;
            }
            else
            {
                printf("\b",pass[x]);
            }
            if (x > 5)
            {
                x = 5;
                gotoxy(53, 22);
                printf(" ");
            }
            gotoxy(48 + x, 22);
            pass[x] = getch();
        }
        pass[x] = NULL;
        strupr(pass);
        if (strlen(pass) <= 5)
        {
            for (int i = 0; i < 100; i++)
            {
                if (strcmp(user, userAdmin) == 0 && strcmp(pass,passAdmin)==0)
                    {
                        gotoxy(39, 32); printf("ANDA BERHASIL LOGIN SEBAGAI ADMIN !!!"); Sleep(750);
                        gotoxy(39, 32); printf("                                     "); Sleep(750);
                        gotoxy(39, 32); printf("ANDA BERHASIL LOGIN SEBAGAI ADMIN !!!"); Sleep(750);
                        gotoxy(39, 32); printf("                                     "); Sleep(750);
                        hapus();
                        halamanAdmin();
                    }
                    
                    else if (strcmp(user,pemilih[i][0])==0 && (strcmp(pass, "PUB17") == 0) || (strcmp(pass, "PUB18") == 0) || (strcmp(pass, "PUB19") == 0) || (strcmp(pass, "PUB20") == 0))
                    {
                        gotoxy(35, 32); printf("ANDA BERHASIL LOGIN SEBAGAI MAHASISWA PUB !!!"); Sleep(750);
                        gotoxy(35, 32); printf("                                             "); Sleep(750);
                        gotoxy(35, 32); printf("ANDA BERHASIL LOGIN SEBAGAI MAHASISWA PUB !!!"); Sleep(750);
                        gotoxy(35, 32); printf("                                             "); Sleep(750);
                        hapus();
                        halamanUser();
                    }
                    else
                    {
                        gotoxy(48, 20); printf("           ");
                        gotoxy(48, 27); printf("           ");
                        gotoxy(37, 32);
                        printf("                                 ");
                        Sleep(500);
                        gotoxy(37, 32);
                        printf("USERNAME ATAU PASSWORD SALAH !!! ");
                        Sleep(500);
                        gotoxy(37, 32);
                        printf("                                 ");
                        Sleep(500);
                        gotoxy(37, 32);
                        printf("USERNAME ATAU PASSWORD SALAH !!! ");
                        Sleep(500);
                        gotoxy(37, 32);
                        printf("                                 ");
                        Sleep(500);
                        i=100;
                        uspas();
                    }
            }
        }
        else
        {
            b++;
        }
    }
}

void load()
{
    gotoxy(53, 34);
    printf("LOADING");
    color(7);
    gotoxy(71, 34);
    printf("%%");
    for (int a = 1, b = 0; a <= 100; a++)
    {
        gotoxy(68, 34);
        printf("%i", a);
        gotoxy(10 + a, 32);
        printf("%c", 219);
        if (a % 7 == 0)
        {
            if (b <= 5)
            {
                gotoxy(61 + b, 34);
                printf(".");
                b++;
            }
            else
            {
                b = 0;
                gotoxy(61, 34);
                printf("      ");
            }
        }
        else
        {
            Sleep(100);
        }
    }
    gotoxy(53, 34);
    printf("                   ");
    Sleep(100);
    gotoxy(50, 34);
    printf("DATA ANDA SUDAH TERSIMPAN\a");
    Sleep(300);
    gotoxy(50, 34);
    printf("                           ");
    Sleep(300);
    gotoxy(50, 34);
    printf("DATA ANDA SUDAH TERSIMPAN\a");
    Sleep(300);
    gotoxy(50, 34);
    printf("                           ");
    Sleep(300);
}

void halamanAdmin()
{
    for (int x = 0; x <= 111; x++)
    {
        for (int y = 0; y <= 27; y++)
        {
            color(6);
            gotoxy(4 + x, 8);
            printf("%c", 219);
            gotoxy(4 + x, 35);
            printf("%c", 219);
            gotoxy(4 , 8 + y);
            printf("%c", 219);
            gotoxy(115,8 + y);
            printf("%c", 219);
        }
    }
    int a=1;
    for (int i = 1; i <= 22; i++)
    {
        if (a>15)
        {
            a=1;
        }
        color(a);
        gotoxy(5+i,13); printf(" ######   ######   ##       ######   ####   ####   ######   ######");
        gotoxy(5+i,14); printf(" ##       ##       ##       ##  ##   ## ## ## ##   ##  ##     ##  ");
        gotoxy(5+i,15); printf(" ######   ######   ##       ######   ##  ###  ##   ######     ##  ");
        gotoxy(5+i,16); printf("     ##   ##       ##       ##  ##   ##       ##   ##  ##     ##  ");
        gotoxy(5+i,17); printf(" ######   ######   ######   ##  ##   ##       ##   ##  ##     ##  ");
        // Sleep(100);

        color(a);
        gotoxy(49-i,25); printf("   ######     ######   ######   ######   ####    ##   ######     ");
        gotoxy(49-i,26); printf("   ##   ##    ##  ##     ##     ##  ##   ## ##   ##   ##         ");
        gotoxy(49-i,27); printf("   ##    ##   ######     ##     ######   ##  ##  ##   ##  ###    ");
        gotoxy(49-i,28); printf("   ##   ##    ##  ##     ##     ##  ##   ##   ## ##   ##    ##   ");
        gotoxy(49-i,29); printf("   ######     ##  ##     ##     ##  ##   ##    ####   ######     ");
        Sleep(100);
        a++;
    }
        color(4);
        gotoxy(27,19); printf("        ######   ######     ####   ####   ##   ####    ##        ");
        gotoxy(27,20); printf("        ##  ##   ##   ##    ## ## ## ##   ##   ## ##   ##        ");
        gotoxy(27,21); printf("        ######   ##    ##   ##  ###  ##   ##   ##  ##  ##        ");
        gotoxy(27,22); printf("        ##  ##   ##   ##    ##       ##   ##   ##   ## ##        ");
        gotoxy(27,23); printf("        ##  ##   ######     ##       ##   ##   ##    ####        ");
        // Sleep(1500);
        hapus1();
        menuAdmin();
}

void menuAdmin()
{
    char pilihan;
    kotakMenu();
    // for (int i = 1; i <= 19; i++)
    // {
    //     for (int j = 1; j <= 5; j++)
    //     {
    //         if (i == 1 || i == 19 || j == 1 || j == 5)
    //         {
    //             xy(i, j + 5);
    //             printf("%c", 219);
    //             xy(3,7); printf("Wahyu");
    //             xy(i + 30, j + 5);
    //             printf("%c", 219);
    //             xy(i + 60, j + 5);
    //             printf("%c", 219);
    //         }
    //     }
    // }
    color(6);
    gotoxy(8,4);  printf("1. K A N D I D A T");
    gotoxy(38,4); printf("2. S T A T U S");
    gotoxy(67,4); printf("3. H A S I L");
    gotoxy(95,4); printf("4. L O G O U T");

    gotoxy(23,10); printf("     ######   ######   ##       ##   ##  ##   ######   ######   ##         ");
    gotoxy(23,11); printf("     ##  ##   ##  ##   ##       ##   ## ##    ##  ##   ##       ##         ");
    gotoxy(23,12); printf("     ######   ######   ##       ##   ####     ######   ######   ##         ");
    gotoxy(23,13); printf("     ##  ##   ##       ##       ##   ## ##    ##  ##       ##   ##         ");
    gotoxy(23,14); printf("     ##  ##   ##       ######   ##   ##  ##   ##  ##   ######   ##         ");

    gotoxy(23,16); printf("######          ##       ##   ######   ######   ##   ####    ##   ######   ");
    gotoxy(23,17); printf("##               ##     ##    ##  ##     ##     ##   ## ##   ##   ##       ");
    gotoxy(23,18); printf("######   ####     ##   ##     ##  ##     ##     ##   ##  ##  ##   ##  ###  ");
    gotoxy(23,19); printf("##                 ## ##      ##  ##     ##     ##   ##   ## ##   ##    ## ");
    gotoxy(23,20); printf("######              ###       ######     ##     ##   ##    ####   #######  ");

    gotoxy(23,22); printf("                         ######   ##  ##   ######                          ");
    gotoxy(23,23); printf("                         ##  ##   ##  ##   ##   ##                         ");
    gotoxy(23,24); printf("                         ######   ##  ##   ## ###                          ");
    gotoxy(23,25); printf("                         ##       ##  ##   ##   ##                         ");
    gotoxy(23,26); printf("                         ##       ######   ######                          ");
    
    gotoxy(23,28); printf("                     ######   ######   ######   ######                     ");
    gotoxy(23,29); printf("                         ##   ##  ##       ##       ##                     ");
    gotoxy(23,30); printf("                     ######   ##  ##   ######   ######                     ");
    gotoxy(23,31); printf("                     ##       ##  ##   ##       ##                         ");
    gotoxy(23,32); printf("                     ######   ######   ######   ######                     ");
    Sleep(1500);
    hapus1();
    gotoxy(23,16); printf("       ####   ####   ######   ####    ##   ##  ##                          ");
    gotoxy(23,17); printf("       ## ## ## ##   ##       ## ##   ##   ##  ##                          ");
    gotoxy(23,18); printf("       ##  ###  ##   ######   ##  ##  ##   ##  ##                          ");
    gotoxy(23,19); printf("       ##       ##   ##       ##   ## ##   ##  ##                          ");
    gotoxy(23,20); printf("       ##       ##   ######   ##    ####   ######                          ");

    gotoxy(23,22); printf("                     ######   ######     ####   ####   ##   ####    ##    ");
    gotoxy(23,23); printf("                     ##  ##   ##   ##    ## ## ## ##   ##   ## ##   ##    ");
    gotoxy(23,24); printf("                     ######   ##    ##   ##  ###  ##   ##   ##  ##  ##    ");
    gotoxy(23,25); printf("                     ##  ##   ##   ##    ##       ##   ##   ##   ## ##    ");
    gotoxy(23,26); printf("                     ##  ##   ######     ##       ##   ##   ##    ####    ");

    gotoxy(30,37); printf("                                                        ");

    int x=0;
    do
    {
        gotoxy(4,37); printf("M A S U K A N   P I L I H A N   :  ");
        gotoxy(38,37);
        pilihan = getch();
        if (pilihan == '1')
        {
            hapus1();
            hapus2();
            menuKandidat();
        }
        else if (pilihan == '2')
        {
            hapus1();
            hapus2();
            status();
        }
        else if (pilihan == '3')
        {
            hapus1();
            hapus2();
            hasilAdmin();
        }
        else if (pilihan == '4')
        {
            gotoxy(4,37); printf("                                      ");
            hapus();
            color(11);
            gotoxy(30,37); printf("C O P Y   R I G H T   B Y   W A H Y U   J E B R E D ' Z ");
            first();
        }
        else
        {
            gotoxy(33,37); printf("                                   ");
            gotoxy(33,37); printf("I N P U T A N   S A L A H   ! ! !"); Sleep(500);
            gotoxy(33,37); printf("                                 "); Sleep(500);
            gotoxy(33,37); printf("I N P U T A N   S A L A H   ! ! !"); Sleep(500);
            gotoxy(33,37); printf("                                 "); Sleep(500);
            x++;
        }
    } while (x>0);
    
}

void menuKandidat()
{
    char pilihan;
    kotakMenu();
    dataKandidat();
    gotoxy(8,4);  printf("                  ");
    gotoxy(38,4); printf("              ");
    gotoxy(67,4); printf("            ");
    gotoxy(95,4); printf("              ");
    color(6);
    gotoxy(8,4);  printf("1. A D D I T I O N");
    gotoxy(40,4); printf("2. E D I T");
    gotoxy(67,4); printf("3. C L E A R");
    gotoxy(95,4); printf("4. D E T A I L");
    int x=0;
    gotoxy(4,37); printf("M A S U K A N   P I L I H A N   :  ");
    gotoxy(57,37); printf("T E K A N   B A C K S P A C E   U N T U K   K E M B A L I");
    do
    {
        gotoxy(4,37); printf("M A S U K A N   P I L I H A N   :  ");
        gotoxy(38,37);
        pilihan = getch();
        if (pilihan == '1')
        {
                gotoxy(4,37); printf("                                      ");
                gotoxy(57,37); printf("                                                         ");
                
            if (tampKandidat>4)
            {
                hapus1();
                hapus2();
                kandidatPenuh();
            }
            else
            {
                hapus1();
                hapus2();
                addition();
            }
        }
        else if (pilihan == '2')
        {
            gotoxy(4,37); printf("                                      ");
            gotoxy(57,37); printf("                                                         ");    
            hapus2();
            carilahKandidatEdit();
        }
        else if (pilihan == '3')
        {
            gotoxy(4,37); printf("                                      ");
            gotoxy(57,37); printf("                                                         ");    
            hapus2();
            carilahKandidatHapus();
        }
        else if (pilihan == '4')
        {
            gotoxy(4,37); printf("                                      ");
            gotoxy(57,37); printf("                                                         ");    
            hapus2();
            carilahKandidatDetail();
        }
        else if (pilihan == 8)
        {
            gotoxy(57,37); printf("                                                           ");
            hapus1();
            hapus2();
            menuAdmin();
        }
        else
        {
            gotoxy(33,37); printf("                                   ");
            gotoxy(33,37); printf("I N P U T A N   S A L A H   ! ! !"); Sleep(500);
            gotoxy(33,37); printf("                                 "); Sleep(500);
            gotoxy(33,37); printf("I N P U T A N   S A L A H   ! ! !"); Sleep(500);
            gotoxy(33,37); printf("                                 "); Sleep(500);
            x++;
        }
    } while (x>0);
    
}

void dataKandidat()
{
    color(11);
    gotoxy(8,12); printf("======================================================================================================");
    gotoxy(8,13); printf("||     ||                                                 ||                                        ||");
    gotoxy(8,14); printf("|| N O ||               K E T U A   U M U M               ||            K E A M A N A N             ||");
    gotoxy(8,15); printf("||     ||                                                 ||                                        ||");
    gotoxy(8,16); printf("======================================================================================================");
    for (int i = 1; i <= 11 ; i++)
    {
    gotoxy(8,16+i); printf("||     ||                                                 ||                                        ||");
    }
    gotoxy(8,28); printf("======================================================================================================");
    int j=0;
    for(int i=0;i<tampKandidat;i++){
   	char tamp[3][100];
        color(15);
      strcpy(tamp[0],strupr(kandidat[i][0]));
      strcpy(tamp[1],strupr(kandidat[i][1]));

   	  gotoxy(12,18+j);  printf("%d",i+1);
      gotoxy(23,18+j);  printf("%s",tamp[0]);
      gotoxy(75,18+j);  printf("%s",tamp[1]);
        j+=2;
   }
}

void addition()
{
    char jum_misi[10];

    gotoxy(23,2); printf("    ######   ######     ######     ##   ######   ##   ######   ####    ##     ");
    gotoxy(23,3); printf("    ##  ##   ##   ##    ##   ##    ##     ##     ##   ##  ##   ## ##   ##     ");
    gotoxy(23,4); printf("    ######   ##    ##   ##    ##   ##     ##     ##   ##  ##   ##  ##  ##     ");
    gotoxy(23,5); printf("    ##  ##   ##   ##    ##   ##    ##     ##     ##   ##  ##   ##   ## ##     ");
    gotoxy(23,6); printf("    ##  ##   ######     ######     ##     ##     ##   ######   ##    ####     ");

    gotoxy(35,10);printf("- T A M B A H   D A T A   K A N D I D A T -");

    for (int x = 0; x <= 100; x++)
    {
        for (int y = 0; y <= 20; y++)
        {
            color(11);
            gotoxy(10 + x, 13);
            printf("%c", 219);
            gotoxy(10 + x, 17);
            printf("%c", 219);
            gotoxy(10 + x, 21);
            printf("%c", 219);
            gotoxy(10 + x, 25);
            printf("%c", 219);
            gotoxy(10 + x, 33);
            printf("%c", 219);
            gotoxy(10, 13 + y);
            printf("%c", 219);
            gotoxy(30, 13 + y);
            printf("%c", 219);
            gotoxy(110, 13 + y);
            printf("%c", 219);
        }
    }

        color(6);
        gotoxy(15, 15);
        printf("KETUA UMUM");
        gotoxy(16, 19);
        printf("KEAMANAN");
        gotoxy(18, 23);
        printf("VISI");
        gotoxy(18, 27);
        printf("MISI");

            gotoxy(32, 15);
            printf("MAKSIMAL 20 KARAKTER");
            Sleep(500);
            gotoxy(32, 15);
            printf("                    ");
            Sleep(500);
            gotoxy(32, 15);
            printf("MAKSIMAL 20 KARAKTER");
            Sleep(500);
            gotoxy(32, 15);
            printf("                    ");


        int a = 0;
        while (a != 1)
        {
            int x = 0;
            gotoxy(32, 15);
            ketum[x] = getch();
            while (ketum[x] != 13)
            {
                if (ketum[x] == 8 || ketum[0] == ' ')
                {
                    x--;
                    if (x < 0)
                    {
                        x = 0;
                    }
                    gotoxy(32 + x, 15);
                    printf(" ");
                }
                else if ((ketum[x] >= 'a' && ketum[x] <= 'z') || (ketum[x] >= 'A' && ketum[x] <= 'Z') || ketum[x] == '-' || ketum[x] == ' ')
                {
                    printf("%c", ketum[x]);
                    x++;
                }
                else
                {
                    printf("\b", ketum[x]);
                }
                if (x > 20)
                {
                    x = 20;
                    gotoxy(52, 15);
                    printf(" ");
                }
                gotoxy(32 + x, 15);
                ketum[x] = getch();
            }
            ketum[x] == NULL;
            // if (strlen(ketum) <= 20)
            // {
                strupr(ketum);
                strcpy(kandidat[tampKandidat][0], ketum);
                a=1;
            //}
            // else
            // {
            //     gotoxy(32, 15);
            //     printf("I N P U T A N   N A M A   S A L A H   ! ! !");
            //     Sleep(500);
            //     gotoxy(32, 15);
            //     printf("                                           ");
            //     Sleep(500);
            //     gotoxy(32, 15);
            //     printf("I N P U T A N   N A M A   S A L A H   ! ! !");
            //     Sleep(500);
            //     gotoxy(32, 15);
            //     printf("                                           ");
            //     a+=2;
            // }
            
        }

            gotoxy(32, 19);
            printf("MAKSIMAL 20 KARAKTER");
            Sleep(500);
            gotoxy(32, 19);
            printf("                    ");
            Sleep(500);
            gotoxy(32, 19);
            printf("MAKSIMAL 20 KARAKTER");
            Sleep(500);
            gotoxy(32, 19);
            printf("                    ");

        int b = 0;
        while (b != 1)
        {
            int x = 0;
            gotoxy(32, 19);
            keamanan[x] = getch();
            while (keamanan[x] != 13)
            {
                if (keamanan[x] == 8 || keamanan[0] == ' ')
                {
                    x--;
                    if (x < 0)
                    {
                        x = 0;
                    }
                    gotoxy(32 + x, 19);
                    printf(" ");
                }
                else if ((keamanan[x] >= 'a' && keamanan[x] <= 'z') || (keamanan[x] >= 'A' && keamanan[x] <= 'Z') || keamanan[x] == '-' || keamanan[x] == ' ')
                {
                    printf("%c", keamanan[x]);
                    x++;
                }
                else
                {
                    printf("\b", keamanan[x]);
                }
                if (x > 20)
                {
                    x = 20;
                    gotoxy(52, 19);
                    printf(" ");
                }
                gotoxy(32 + x, 19);
                keamanan[x] = getch();
            }
            keamanan[x] == NULL;
           // if (strlen(keamanan) <= 20)
            //{
                strupr(keamanan);
                strcpy(kandidat[tampKandidat][1], keamanan);
                b=1;
            //}
            // else
            // {
            //     gotoxy(32, 19);
            //     printf("I N P U T A N   N A M A   S A L A H   ! ! !");
            //     Sleep(500);
            //     gotoxy(32, 19);
            //     printf("                                           ");
            //     Sleep(500);
            //     gotoxy(32, 19);
            //     printf("I N P U T A N   N A M A   S A L A H   ! ! !");
            //     Sleep(500);
            //     gotoxy(32, 19);
            //     printf("                                           ");
            //     b+=2;
            // }
            
        }

        
        gotoxy(32, 23);
        printf("MAKSIMAL 30 KARAKTER");
        Sleep(500);
        gotoxy(32, 23);
        printf("                    ");
        Sleep(500);
        gotoxy(32, 23);
        printf("MAKSIMAL 30 KARAKTER");
        Sleep(500);
        gotoxy(32, 23);
        printf("                    ");

    int c = 0;
    while (c != 1)
    {
        int x = 0;
        gotoxy(32, 23);
        visiKandidat[x] = getch();
        while (visiKandidat[x] != 13)
        {
            if (visiKandidat[x] == 8 || visiKandidat[0] == ' ')
            {
                x--;
                if (x < 0)
                {
                    x = 0;
                }
                gotoxy(32 + x, 23);
                printf(" ");
            }
            else if ((visiKandidat[x] >= 'a' && visiKandidat[x] <= 'z') || (visiKandidat[x] >= 'A' && visiKandidat[x] <= 'Z') || visiKandidat[x] == '-' || visiKandidat[x] == ' ')
            {
                printf("%c", visiKandidat[x]);
                x++;
            }
            else
            {
                printf("\b", visiKandidat[x]);
            }
            if (x > 30)
            {
                x = 30;
                gotoxy(62, 23);
                printf(" ");
            }
            gotoxy(32 + x, 23);
            visiKandidat[x] = getch();
        }
        visiKandidat[x] == NULL;
        // if (strlen(visiKandidat) <= 30)
        // {
            strupr(visiKandidat);
            strcpy(kandidat[tampKandidat][2], visiKandidat);
            c=1;
        //}
        // else
        // {
        //     gotoxy(32, 23);
        //     printf("I N P U T A N   N A M A   S A L A H   ! ! !");
        //     Sleep(500);
        //     gotoxy(32, 23);
        //     printf("                                           ");
        //     Sleep(500);
        //     gotoxy(32, 23);
        //     printf("I N P U T A N   N A M A   S A L A H   ! ! !");
        //     Sleep(500);
        //     gotoxy(32, 23);
        //     printf("                                           ");
        //     c+=2;
        // }
        
    }
    
    int d=0;
    while (d!=1)
    {
        int x=0;
        do
        {
            gotoxy(13,29); printf("Jumlah Misi");
            gotoxy(18,30); gets(jum_misi);
            tam_misi[tampKandidat]=atoi(jum_misi);
            if(tam_misi[tampKandidat]>2 && tam_misi[tampKandidat]<=5){
                gotoxy(12,30);
                printf("            ");
                gotoxy(18,30); printf("  ");
                for(int a=0,b=1;a<atoi(jum_misi);a++,b++){
                    gotoxy(32,26+b); printf("%d. ",a+1);gets(misi[tampKandidat][a]);
                }
                x=0;
                d=1;
            } 
            else
            {
                gotoxy(12,30);
                printf("Jumlah salah");
                gotoxy(12,30);
                printf("            ");
                x++;
            }
            
        } while (x!=0);
    }
    hapus2();
    tampKandidat++;
    hapus1();
    menuKandidat();
}

void kandidatPenuh()
{

    gotoxy(27,13); printf("##  ##   ######   ####    ##   ######     ##   ######     ######   ######");
    gotoxy(27,14); printf("## ##    ##  ##   ## ##   ##   ##   ##    ##   ##   ##    ##  ##     ##  ");
    gotoxy(27,15); printf("####     ######   ##  ##  ##   ##    ##   ##   ##    ##   ######     ##  ");
    gotoxy(27,16); printf("## ##    ##  ##   ##   ## ##   ##   ##    ##   ##   ##    ##  ##     ##  ");
    gotoxy(27,17); printf("##  ##   ##  ##   ##    ####   ######     ##   ######     ##  ##     ##  ");

    gotoxy(27,19); printf("                 ######   ######   ##       ######   ##  ##              ");
    gotoxy(27,20); printf("                   ##     ##       ##       ##  ##   ##  ##              ");
    gotoxy(27,21); printf("                   ##     ######   ##       ######   ######              ");
    gotoxy(27,22); printf("                   ##     ##       ##       ##  ##   ##  ##              ");
    gotoxy(27,23); printf("                   ##     ######   ######   ##  ##   ##  ##              ");

    gotoxy(27,25); printf("               ######   ######   ####    ##   ##  ##   ##  ##            ");
    gotoxy(27,26); printf("               ##  ##   ##       ## ##   ##   ##  ##   ##  ##            ");
    gotoxy(27,27); printf("               ######   ######   ##  ##  ##   ##  ##   ######            ");
    gotoxy(27,28); printf("               ##       ##       ##   ## ##   ##  ##   ##  ##            ");
    gotoxy(27,29); printf("               ##       ######   ##    ####   ######   ##  ##            ");
    getch();
    menuKandidat();
}

void editKandidat(char ubah[10])
{
    char jum_misi[10];
    gotoxy(37,10);printf("- E D I T   D A T A   K A N D I D A T -");

    int o;
    o=atoi(ubah);

    for (int x = 0; x <= 100; x++)
    {
        for (int y = 0; y <= 20; y++)
        {
            color(11);
            gotoxy(10 + x, 13);
            printf("%c", 219);
            gotoxy(10 + x, 17);
            printf("%c", 219);
            gotoxy(10 + x, 21);
            printf("%c", 219);
            gotoxy(10 + x, 25);
            printf("%c", 219);
            gotoxy(10 + x, 33);
            printf("%c", 219);
            gotoxy(10, 13 + y);
            printf("%c", 219);
            gotoxy(30, 13 + y);
            printf("%c", 219);
            gotoxy(110, 13 + y);
            printf("%c", 219);
        }
    }

        color(6);
        gotoxy(15, 15);
        printf("KETUA UMUM");
        gotoxy(16, 19);
        printf("KEAMANAN");
        gotoxy(18, 23);
        printf("VISI");
        gotoxy(18, 27);
        printf("MISI");

            gotoxy(32, 15);
            printf("MAKSIMAL 20 KARAKTER");
            Sleep(500);
            gotoxy(32, 15);
            printf("                    ");
            Sleep(500);
            gotoxy(32, 15);
            printf("MAKSIMAL 20 KARAKTER");
            Sleep(500);
            gotoxy(32, 15);
            printf("                    ");


        int a = 0;
        while (a != 1)
        {
            int x = 0;
            gotoxy(32, 15);
            ketum[x] = getch();
            while (ketum[x] != 13)
            {
                if (ketum[x] == 8 || ketum[0] == ' ')
                {
                    x--;
                    if (x < 0)
                    {
                        x = 0;
                    }
                    gotoxy(32 + x, 15);
                    printf(" ");
                }
                else if ((ketum[x] >= 'a' && ketum[x] <= 'z') || (ketum[x] >= 'A' && ketum[x] <= 'Z') || ketum[x] == '-' || ketum[x] == ' ')
                {
                    printf("%c", ketum[x]);
                    x++;
                }
                else
                {
                    printf("\b", ketum[x]);
                }
                if (x > 20)
                {
                    x = 20;
                    gotoxy(52, 15);
                    printf(" ");
                }
                gotoxy(32 + x, 15);
                ketum[x] = getch();
            }
            ketum[x] == NULL;
//            if (strlen(ketum) <= 20)
//            {
                strupr(ketum);
                strcpy(kandidat[o-1][0], ketum);
                a=1;
            // }
            // else
            // {
            //     gotoxy(32, 15);
            //     printf("I N P U T A N   N A M A   S A L A H   ! ! !");
            //     Sleep(500);
            //     gotoxy(32, 15);
            //     printf("                                           ");
            //     Sleep(500);
            //     gotoxy(32, 15);
            //     printf("I N P U T A N   N A M A   S A L A H   ! ! !");
            //     Sleep(500);
            //     gotoxy(32, 15);
            //     printf("                                           ");
            //     a+=2;
            // }
            
        }

            gotoxy(32, 19);
            printf("MAKSIMAL 20 KARAKTER");
            Sleep(500);
            gotoxy(32, 19);
            printf("                    ");
            Sleep(500);
            gotoxy(32, 19);
            printf("MAKSIMAL 20 KARAKTER");
            Sleep(500);
            gotoxy(32, 19);
            printf("                    ");

        int b = 0;
        while (b != 1)
        {
            int x = 0;
            gotoxy(32, 19);
            keamanan[x] = getch();
            while (keamanan[x] != 13)
            {
                if (keamanan[x] == 8 || keamanan[0] == ' ')
                {
                    x--;
                    if (x < 0)
                    {
                        x = 0;
                    }
                    gotoxy(32 + x, 19);
                    printf(" ");
                }
                else if ((keamanan[x] >= 'a' && keamanan[x] <= 'z') || (keamanan[x] >= 'A' && keamanan[x] <= 'Z') || keamanan[x] == '-' || keamanan[x] == ' ')
                {
                    printf("%c", keamanan[x]);
                    x++;
                }
                else
                {
                    printf("\b", keamanan[x]);
                }
                if (x > 20)
                {
                    x = 20;
                    gotoxy(52, 19);
                    printf(" ");
                }
                gotoxy(32 + x, 19);
                keamanan[x] = getch();
            }
            keamanan[x] == NULL;
            // if (strlen(keamanan) <= 20)
            // {
                strupr(keamanan);
                strcpy(kandidat[o-1][1], keamanan);
                b=1;
            // }
            // else
            // {
            //     gotoxy(32, 19);
            //     printf("I N P U T A N   N A M A   S A L A H   ! ! !");
            //     Sleep(500);
            //     gotoxy(32, 19);
            //     printf("                                           ");
            //     Sleep(500);
            //     gotoxy(32, 19);
            //     printf("I N P U T A N   N A M A   S A L A H   ! ! !");
            //     Sleep(500);
            //     gotoxy(32, 19);
            //     printf("                                           ");
            //     b+=2;
            // }
            
        }

        
        gotoxy(32, 23);
        printf("MAKSIMAL 30 KARAKTER");
        Sleep(500);
        gotoxy(32, 23);
        printf("                    ");
        Sleep(500);
        gotoxy(32, 23);
        printf("MAKSIMAL 30 KARAKTER");
        Sleep(500);
        gotoxy(32, 23);
        printf("                    ");

    int c = 0;
    while (c != 1)
    {
        int x = 0;
        gotoxy(32, 23);
        visiKandidat[x] = getch();
        while (visiKandidat[x] != 13)
        {
            if (visiKandidat[x] == 8 || visiKandidat[0] == ' ')
            {
                x--;
                if (x < 0)
                {
                    x = 0;
                }
                gotoxy(32 + x, 23);
                printf(" ");
            }
            else if ((visiKandidat[x] >= 'a' && visiKandidat[x] <= 'z') || (visiKandidat[x] >= 'A' && visiKandidat[x] <= 'Z') || visiKandidat[x] == '-' || visiKandidat[x] == ' ')
            {
                printf("%c", visiKandidat[x]);
                x++;
            }
            else
            {
                printf("\b", visiKandidat[x]);
            }
            if (x > 30)
            {
                x = 30;
                gotoxy(62, 23);
                printf(" ");
            }
            gotoxy(32 + x, 23);
            visiKandidat[x] = getch();
        }
        visiKandidat[x] == NULL;
        // if (strlen(visiKandidat) <= 30)
        // {
            strupr(visiKandidat);
            strcpy(kandidat[o-1][2], visiKandidat);
            c=1;
        // }
        // else
        // {
        //     gotoxy(32, 23);
        //     printf("I N P U T A N   N A M A   S A L A H   ! ! !");
        //     Sleep(500);
        //     gotoxy(32, 23);
        //     printf("                                           ");
        //     Sleep(500);
        //     gotoxy(32, 23);
        //     printf("I N P U T A N   N A M A   S A L A H   ! ! !");
        //     Sleep(500);
        //     gotoxy(32, 23);
        //     printf("                                           ");
        //     c+=2;
        // }
        
    }
    
    int d=0;
    while (d!=1)
    {
        int x=0;
        do
        {
            gotoxy(13,29); printf("Jumlah Misi");
            gotoxy(18,30); gets(jum_misi);
            tam_misi[o-1]=atoi(jum_misi);
            if(tam_misi[o-1]>2 && tam_misi[o-1]<=5){
                gotoxy(12,30);
                printf("            ");
                gotoxy(18,30); printf("  ");
                for(int a=0,b=1;a<atoi(jum_misi);a++,b++){
                    gotoxy(32,26+b); printf("%d. ",a+1);gets(misi[o-1][a]);
                }
                x=0;
                d=1;
            } 
            else
            {
                gotoxy(12,30);
                printf("Jumlah salah");
                gotoxy(12,30);
                printf("            ");
                x++;
            }
            
        } while (x!=0);
    }
    gotoxy(4,37);  printf("                                                                     ");
    hapus1();
    hapus2();
    menuKandidat();
}

void hapusKandidat(int i)
{
    char tampunganK[4][1000];

    for(int a=i;a<tampKandidat;a++){
        strcpy(tampunganK[0],kandidat[a][0]);
       strcpy(tampunganK[1],kandidat[a][1]);
       strcpy(tampunganK[2],kandidat[a][2]);
       strcpy(tampunganK[3],kandidat[a][3]);
 
       strcpy(kandidat[a][0],kandidat[a+1][0]);
       strcpy(kandidat[a][1],kandidat[a+1][1]);
       strcpy(kandidat[a][2],kandidat[a+1][2]);
       strcpy(kandidat[a][3],kandidat[a+1][3]);
 
       strcpy(kandidat[a+1][0],tampunganK[0]);
       strcpy(kandidat[a+1][1],tampunganK[1]);
       strcpy(kandidat[a+1][2],tampunganK[2]);
       strcpy(kandidat[a+1][3],tampunganK[3]);
    }
 
    kandidat[tampKandidat-1][0][0] = NULL;
    kandidat[tampKandidat-1][1][0] = NULL;
    kandidat[tampKandidat-1][2][0] = NULL;
    kandidat[tampKandidat-1][3][0] = NULL;
 
 
    tampKandidat--;
 
 
    char tampMisi[10][300];
 
    for(int b=i;b<tam_misi[i];b++){
        strcpy(tampMisi[0],misi[b][0]);
       strcpy(tampMisi[1],misi[b][1]);
       strcpy(tampMisi[2],misi[b][2]);
       strcpy(tampMisi[3],misi[b][3]);
 
       strcpy(misi[b][0],misi[b+1][0]);
       strcpy(misi[b][1],misi[b+1][1]);
       strcpy(misi[b][2],misi[b+1][2]);
       strcpy(misi[b][3],misi[b+1][3]);
 
       strcpy(misi[b+1][0],tampMisi[0]);
       strcpy(misi[b+1][1],tampMisi[1]);
       strcpy(misi[b+1][2],tampMisi[2]);
       strcpy(misi[b+1][3],tampMisi[3]);
    }
 
 
    misi[tam_misi[i]-1][0][0] = NULL;
    misi[tam_misi[i]-1][1][0] = NULL;
    misi[tam_misi[i]-1][2][0] = NULL;
    misi[tam_misi[i]-1][3][0] = NULL;
    misi[tam_misi[i]-1][4][0] = NULL;
    misi[tam_misi[i]-1][5][0] = NULL;
    misi[tam_misi[i]-1][6][0] = NULL;
    misi[tam_misi[i]-1][7][0] = NULL;
    misi[tam_misi[i]-1][8][0] = NULL;
    misi[tam_misi[i]-1][9][0] = NULL;
 
    tam_misi[i]--;
    gotoxy(4,37);  printf("                                             ");
    hapus2();
    menuKandidat();
}

void detailKandidat(char v[10])
{
    char pil;
    for (int x = 0; x <= 90; x++)
    {
        for (int y = 1; y <= 15; y++)
        {
            color(6);
            gotoxy(14 + x, 14);
            printf("%c", 219);
            gotoxy(14 + x, 29);
            printf("%c", 219);
            gotoxy(14 , 14 + y);
            printf("%c", 219);
            gotoxy(104,14 + y);
            printf("%c", 219);
        }
    }
    int t;
    t=atoi(v);
    color(11);
    gotoxy(30,11);printf("< = = =   P A S A N G A N   N O   U R U T   %d   = = = >",t);
    gotoxy(20,16); printf("K E T U A   U M U M   :   ");
    gotoxy(20,18); printf("K E A M A N A N       :   ");
    gotoxy(20,20); printf("V I S I               :   ");

    gotoxy(20,22); printf("M I S I               :   ");

    gotoxy(45,16);printf("%s",&kandidat[t-1][0]);
    gotoxy(45,18);printf("%s",&kandidat[t-1][1]);
    gotoxy(45,20);printf("%s",&kandidat[t-1][2]);

    for(int a=0,b=1;misi[t-1][a][0]!=NULL;a++,b++){
        gotoxy(45,21+b); printf("%d %s",a+1,misi[t-1][a]);
    }
    gotoxy(4,37);  printf("                                                 ");
    do
    {
        gotoxy(4,37);  printf("T E K A N   E N T E R   U N T U K   K E   H A L A M A N   U T A M A   ! ! !");
        pil = getch();
        if (pil == 13)
        {
            gotoxy(4,37);  printf("                                                                                 ");
            hapus2();
            hapus1();
            menuKandidat();
        }
        else
        {
            gotoxy(4,37);  printf("T E K A N   E N T E R   U N T U K   K E   H A L A M A N   U T A M A   ! ! !");
            gotoxy(4,37);  printf("                                                                                 ");
            gotoxy(4,37);  printf("I N P U T A N   T I D A K   V A L I D   ! ! !"); Sleep(1500);
            gotoxy(4,37);  printf("                                              ");
        }

    } while (pil!=13);
    
    
    
}

void carilahKandidatEdit()
{
    bool x;
    bool y;
    int h=0;

    gotoxy(23,2); printf("                      ######   ######     ##   ######                        ");
    gotoxy(23,3); printf("                      ##       ##   ##    ##     ##                          ");
    gotoxy(23,4); printf("                      ######   ##    ##   ##     ##                          ");
    gotoxy(23,5); printf("                      ##       ##   ##    ##     ##                          ");
    gotoxy(23,6); printf("                      ######   ######     ##     ##                          ");

    while (h!=1)
    {
            gotoxy(4,37); printf("                                   ");
            gotoxy(4,37);  printf("M A S U K A N   N O   P A S A N G A N   :  ");
            gotoxy(46,37); gets(cariKandidat);
            int c;
            c=atoi(cariKandidat);

            if(c>0 && c<=tampKandidat){
                x=true;
            } else {
                x=false;
            }

        if(x==true){
            hapus1();
            editKandidat(cariKandidat);
        }
        else
        {
                gotoxy(4,37);  printf("                                           ");
                gotoxy(33,37); printf("                                   ");
                gotoxy(13,37); printf("P A S A N G A N   T I D A K   D I T E M U K A N   ! ! !");
                gotoxy(13,37); printf("                                                       ");
                h+=2;
        }
    }
}

void carilahKandidatHapus()
{
    bool x;
    bool y;
    int h=0;

    gotoxy(23,2); printf("                  ######   ##       ######   ######   ######                 ");
    gotoxy(23,3); printf("                  ##       ##       ##       ##  ##   ##  ##                 ");
    gotoxy(23,4); printf("                  ##       ##       ######   ######   ######                 ");
    gotoxy(23,5); printf("                  ##       ##       ##       ##  ##   ##   ##                ");
    gotoxy(23,6); printf("                  ######   ######   ######   ##  ##   ##    ##               ");

    while (h!=1)
    {
            gotoxy(4,37); printf("                                   ");
            gotoxy(4,37);  printf("M A S U K A N   N O   P A S A N G A N   :  ");
            gotoxy(46,37); gets(cariKandidat);
            int c;
            c=atoi(cariKandidat);

            if(c>0 && c<=tampKandidat){
                x=true;
                c-=1;
            } else {
                x=false;
            }

        if(x==true){
            hapus1();
            hapusKandidat(c);
        }
        else
        {
                gotoxy(4,37);  printf("                                           ");
                gotoxy(33,37); printf("                                   ");
                gotoxy(13,37); printf("P A S A N G A N   T I D A K   D I T E M U K A N   ! ! !");
                gotoxy(13,37); printf("                                                       ");
                h+=2;
        }
    }
}

void carilahKandidatDetail()
{
    bool x;
    bool y;
    int h=0;

    gotoxy(23,2); printf("               ######     ######   ######   ######   ##   ##                 ");
    gotoxy(23,3); printf("               ##   ##    ##         ##     ##  ##   ##   ##                 ");
    gotoxy(23,4); printf("               ##    ##   ######     ##     ######   ##   ##                 ");
    gotoxy(23,5); printf("               ##   ##    ##         ##     ##  ##   ##   ##                 ");
    gotoxy(23,6); printf("               ######     ######     ##     ##  ##   ##   ######             ");
    while (h!=1)
    {
            gotoxy(4,37); printf("                                   ");
            gotoxy(4,37);  printf("M A S U K A N   N O   P A S A N G A N   :  ");
            gotoxy(46,37); gets(cariKandidat);
            int c;
            c=atoi(cariKandidat);

            if(c>0 && c<=tampKandidat){
                x=true;
            } else {
                x=false;
            }

        if(x==true){
            hapus1();
            detailKandidat(cariKandidat);
        }
        else
        {
                gotoxy(4,37);  printf("                                           ");
                gotoxy(33,37); printf("                                   ");
                gotoxy(13,37); printf("P A S A N G A N   T I D A K   D I T E M U K A N   ! ! !");
                gotoxy(13,37); printf("                                                       ");
                h+=2;
        }
    }
}

void status()
{
    gotoxy(4,37); printf("                                      ");
    gotoxy(4,37); printf("M A S U K A N   N I M   :  ");
    int a = 0;
    while (a != 1)
    {
        gotoxy(31, 37); printf("           ");
        int x = 0;
        gotoxy(31, 37);
        user[x] = getch();
        while (user[x] != 13)
        {
            if (user[x] == 8 || user[0] == ' ' || (user[x] >= 'a' && user[x] <= 'z') || (user[x] >= 'A' && user[x] <= 'Z'))
            {
                x--;
                if (x < 0)
                {
                    x = 0;
                }
                gotoxy(31 + x, 37);
                printf(" ");
            }
            else if(user[x] >= '0' && user[x] <= '9')
            {
                printf("%c", user[x]);
                x++;
            }
            if (x > 11)
            {
                x = 11;
                gotoxy(42, 37);
                printf(" ");
            }
            gotoxy(31 + x, 37);
            user[x] = getch();
        }
        user[x] = NULL;

        for (int i = 0; i < 42; i++)
        {
            if ((strlen(user) <= 11) && (strcmp(user,pemilih[i][0])==0))
            {
                a = 1;
                strcpy(tampNim,pemilih[i][0]);
                strcpy(tampNama,pemilih[i][1]);
                strcpy(tampAkt,pemilih[i][2]);
                strcpy(tampProdi,pemilih[i][3]);
                kotakStatus();
            }
            else
            {
                // gotoxy(31,37); printf("N I M   T I D A K   D I T E M U K A N   ! ! !"); Sleep(500);
                // gotoxy(31,37); printf("                                             "); Sleep(500);
                // gotoxy(31,37); printf("N I M   T I D A K   D I T E M U K A N   ! ! !"); Sleep(500);
                // gotoxy(31,37); printf("                                             "); Sleep(500);
                // i=tampPemilih;
                a+=2;
            }
            
        }
    }
}

void hasilAdmin()
{
    gotoxy(4,37); printf("                                      ");
    gotoxy(8,28); printf("======================================================================================================");
    color(11);
    gotoxy(8,12); printf("======================================================================================================");
    gotoxy(8,13); printf("||     ||                                   ||                               ||                     ||");
    gotoxy(8,14); printf("|| N O ||        K E T U A   U M U M        ||        K E A M A N A N        ||      S U A R A      ||");
    gotoxy(8,15); printf("||     ||                                   ||                               ||                     ||");
    gotoxy(8,16); printf("======================================================================================================");
    for (int i = 1; i <= 11 ; i++)
    {
        gotoxy(8,16+i); printf("||     ||                                   ||                               ||                     ||");
    }
    gotoxy(8,28); printf("======================================================================================================");
    int j=0;
    for(int i=0;i<tampKandidat;i++){
   	char tamp[3][100];
        color(15);
      strcpy(tamp[0],strupr(kandidat[i][0]));
      strcpy(tamp[1],strupr(kandidat[i][1]));

   	  gotoxy(12,18+j);  printf("%d",i+1);
      gotoxy(21,18+j);  printf("%s",tamp[0]);
      gotoxy(60,18+j);  printf("%s",tamp[1]);
      gotoxy(97,18+j);  printf("%d",prosesVote[i]);
        j+=2;
   }
   char pil;
   do
    {
        color(4);
        gotoxy(30,37); printf("T E K A N   B A C K S P A C E   U N T U K   K E M B A L I");
        gotoxy(50,38); pil = getch(); 
        if (pil == 8)
        {
            gotoxy(30,37); printf("                                                         ");
            hapus1();
            menuAdmin();
        }
        
    } while (pil!=8);
}

void hasilUser()
{
    gotoxy(4,37); printf("                                      ");
    gotoxy(8,28); printf("======================================================================================================");
    color(11);
    gotoxy(8,12); printf("======================================================================================================");
    gotoxy(8,13); printf("||     ||                                   ||                               ||                     ||");
    gotoxy(8,14); printf("|| N O ||        K E T U A   U M U M        ||        K E A M A N A N        ||      S U A R A      ||");
    gotoxy(8,15); printf("||     ||                                   ||                               ||                     ||");
    gotoxy(8,16); printf("======================================================================================================");
    for (int i = 1; i <= 11 ; i++)
    {
        gotoxy(8,16+i); printf("||     ||                                   ||                               ||                     ||");
    }
    gotoxy(8,28); printf("======================================================================================================");
    int j=0;
    for(int i=0;i<tampKandidat;i++){
   	char tamp[3][100];
        color(15);
      strcpy(tamp[0],strupr(kandidat[i][0]));
      strcpy(tamp[1],strupr(kandidat[i][1]));

   	  gotoxy(12,18+j);  printf("%d",i+1);
      gotoxy(21,18+j);  printf("%s",tamp[0]);
      gotoxy(60,18+j);  printf("%s",tamp[1]);
      gotoxy(97,18+j);  printf("%d",prosesVote[i]);
        j+=2;
   }
   char pil;
   do
    {
        color(4);
        gotoxy(30,37); printf("T E K A N   B A C K S P A C E   U N T U K   K E M B A L I");
        gotoxy(50,38); pil = getch(); 
        if (pil == 8)
        {
            gotoxy(30,37); printf("                                                         ");
            hapus1();
            menuAdmin();
        }
        
    } while (pil!=8);
}

void halamanUser()
{
    for (int x = 0; x <= 111; x++)
    {
        for (int y = 0; y <= 27; y++)
        {
            color(6);
            gotoxy(4 + x, 8);
            printf("%c", 219);
            gotoxy(4 + x, 35);
            printf("%c", 219);
            gotoxy(4 , 8 + y);
            printf("%c", 219);
            gotoxy(115,8 + y);
            printf("%c", 219);
        }
    }
    int a=1;
    color(3);
    for (int i = 1; i <= 22; i++)
    {
        if (a>15)
        {
            a=1;
        }
        color(a);
        gotoxy(5+i,13); printf(" ######   ######   ##       ######   ####   ####   ######   ######");
        gotoxy(5+i,14); printf(" ##       ##       ##       ##  ##   ## ## ## ##   ##  ##     ##  ");
        gotoxy(5+i,15); printf(" ######   ######   ##       ######   ##  ###  ##   ######     ##  ");
        gotoxy(5+i,16); printf("     ##   ##       ##       ##  ##   ##       ##   ##  ##     ##  ");
        gotoxy(5+i,17); printf(" ######   ######   ######   ##  ##   ##       ##   ##  ##     ##  ");
       // Sleep(100);

        color(a);
        gotoxy(49-i,25); printf("   ######     ######   ######   ######   ####    ##   ######     ");
        gotoxy(49-i,26); printf("   ##   ##    ##  ##     ##     ##  ##   ## ##   ##   ##         ");
        gotoxy(49-i,27); printf("   ##    ##   ######     ##     ######   ##  ##  ##   ##  ###    ");
        gotoxy(49-i,28); printf("   ##   ##    ##  ##     ##     ##  ##   ##   ## ##   ##    ##   ");
        gotoxy(49-i,29); printf("   ######     ##  ##     ##     ##  ##   ##    ####   ######     ");
       // Sleep(100);
        a++;
    }
        color(2);
        gotoxy(27,19); printf("              ##  ##   ######   ######   ######                  ");
        gotoxy(27,20); printf("              ##  ##   ##       ##       ##  ##                  ");
        gotoxy(27,21); printf("              ##  ##   ######   ######   #####                   ");
        gotoxy(27,22); printf("              ##  ##       ##   ##       ##  ##                  ");
        gotoxy(27,23); printf("              ######   ######   ######   ##   ##                 ");
        Sleep(1500);
        hapus1();
        menuUser();
}

void menuUser()
{
    kotakMenu();

    for (int x = 0; x <= 90; x++)
    {
        for (int y = 1; y <= 15; y++)
        {
            color(6);
            gotoxy(14 + x, 16);
            printf("%c", 219);
            gotoxy(14 + x, 31);
            printf("%c", 219);
            gotoxy(14 , 16 + y);
            printf("%c", 219);
            gotoxy(104,16 + y);
            printf("%c", 219);
        }
    }

    gotoxy(10,10); printf("######     ######   ######   ######      ######   ######   ####   ####   ##   ##       ##   ##  ##");
    gotoxy(10,11); printf("##   ##    ##  ##     ##     ##  ##      ##  ##   ##       ## ## ## ##   ##   ##       ##   ##  ##");
    gotoxy(10,12); printf("##    ##   ######     ##     ######      ######   ######   ##  ###  ##   ##   ##       ##   ######");
    gotoxy(10,13); printf("##   ##    ##  ##     ##     ##  ##      ##       ##       ##       ##   ##   ##       ##   ##  ##");
    gotoxy(10,14); printf("######     ##  ##     ##     ##  ##      ##       ######   ##       ##   ##   ######   ##   ##  ##");

    gotoxy(16,19); printf("	#####     ");
    gotoxy(16,20); printf("       #######    ");
    gotoxy(16,21); printf("       #######    ");
    gotoxy(16,22); printf("        #####     ");
    gotoxy(16,23); printf("     ###########  ");
    gotoxy(16,24); printf("    ############# ");
    gotoxy(16,25); printf("   ###############");
    gotoxy(16,26); printf("   ###############");
    gotoxy(16,37); printf("   ###############");

    gotoxy(40,20); printf("NAMA LENGKAP     : %s",tampNama);
    gotoxy(40,22); printf("NIM              : %s",tampNim);
    gotoxy(40,24); printf("ANGKATAN         : %s",tampAkt);
    gotoxy(40,26); printf("PROGRAM STUDI    : %s",tampProdi);

    char pilihan;
    color(6);
    gotoxy(8,4);  printf("1. K A N D I D A T");
    gotoxy(38,4); printf("2. V O T I N G");
    gotoxy(67,4); printf("3. H A S I L");
    gotoxy(95,4); printf("4. L O G O U T");
    gotoxy(30,37); printf("                                                        ");

    int x=0;
    do
    {
        gotoxy(4,37); printf("M A S U K A N   P I L I H A N   :  ");
        gotoxy(38,37);
        pilihan = getch();
        if (pilihan == '1')
        {
            hapus1();
            hapus2();
            kandidatUser();
        }
        else if (pilihan == '2')
        {
            gotoxy(4,37); printf("                                      ");
            hapus1();
            hapus2();
            votingUser();
        }
        else if (pilihan == '3')
        {
            hapus1();
            hapus2();
            hasilUser();
        }
        else if (pilihan == '4')
        {
            gotoxy(4,37); printf("                                      ");
            hapus();
            first();
        }
        else
        {
            gotoxy(33,37); printf("                                   ");
            gotoxy(33,37); printf("I N P U T A N   S A L A H   ! ! !"); Sleep(500);
            gotoxy(33,37); printf("                                 "); Sleep(500);
            gotoxy(33,37); printf("I N P U T A N   S A L A H   ! ! !"); Sleep(500);
            gotoxy(33,37); printf("                                 "); Sleep(500);
            x++;
        }
    } while (x>0);
}

void kandidatUser()
{
    dataKandidat();
     for (int x = 0; x <= 20; x++)
    {
        for (int y = 0; y <= 4; y++)
        {
            color(7);
            gotoxy(35 + x, 2);
            printf("%c", 219);
            gotoxy(35 + x, 6);
            printf("%c", 219);
            gotoxy(35 , 2 + y);
            printf("%c", 219);
            gotoxy(55, 2 + y);
            printf("%c", 219);

            color(4);
            gotoxy(63 + x, 2);
            printf("%c", 219);
            gotoxy(63 + x, 6);
            printf("%c", 219);
            gotoxy(63 , 2 + y);
            printf("%c", 219);
            gotoxy(83, 2 + y);
            printf("%c", 219);
        }
    }
    gotoxy(38,4); printf("1. D E T A I L");
    gotoxy(66,4); printf("0. K E M B A L I");

    char pilihan;
    gotoxy(4,37); printf("M A S U K A N   P I L I H A N   :  ");
    gotoxy(38,37);
    pilihan = getch();
    if (pilihan == '1')
    {
        gotoxy(4,37); printf("                                      ");
        hapus2();
        detaliKandidatUser();
    }
    else if (pilihan== '0')
    {
        gotoxy(4,37); printf("                                      ");
        hapus1();
        hapus2();
        menuUser();
    }
    
}

void detaliKandidatUser()
{
    int h=0;
    gotoxy(23,2); printf("               ######     ######   ######   ######   ##   ##                 ");
    gotoxy(23,3); printf("               ##   ##    ##         ##     ##  ##   ##   ##                 ");
    gotoxy(23,4); printf("               ##    ##   ######     ##     ######   ##   ##                 ");
    gotoxy(23,5); printf("               ##   ##    ##         ##     ##  ##   ##   ##                 ");
    gotoxy(23,6); printf("               ######     ######     ##     ##  ##   ##   ######             ");
    while (h!=1)
    {
        bool x;
            gotoxy(4,37); printf("                                   ");
            gotoxy(4,37);  printf("M A S U K A N   N O   P A S A N G A N   :  ");
            gotoxy(46,37); gets(cariKandidat);
            int c;
            c=atoi(cariKandidat);

            if(c>0 && c<=tampKandidat){
                x=true;
            } else {
                x=false;
            }

        if(x==true){
            hapus1();
            char pil;
            for (int x = 0; x <= 90; x++)
            {
                for (int y = 1; y <= 15; y++)
                {
                    color(6);
                    gotoxy(14 + x, 14);
                    printf("%c", 219);
                    gotoxy(14 + x, 29);
                    printf("%c", 219);
                    gotoxy(14 , 14 + y);
                    printf("%c", 219);
                    gotoxy(104,14 + y);
                    printf("%c", 219);
                }
            }
            color(11);
            gotoxy(30,11);printf("< = = =   P A S A N G A N   N O   U R U T   %d   = = = >",c);
            gotoxy(20,16); printf("K E T U A   U M U M   :   ");
            gotoxy(20,18); printf("K E A M A N A N       :   ");
            gotoxy(20,20); printf("V I S I               :   ");

            gotoxy(20,22); printf("M I S I               :   ");

            gotoxy(45,16);printf("%s",&kandidat[c-1][0]);
            gotoxy(45,18);printf("%s",&kandidat[c-1][1]);
            gotoxy(45,20);printf("%s",&kandidat[c-1][2]);

            for(int a=0,b=1;misi[c-1][a][0]!=NULL;a++,b++){
                gotoxy(45,21+b); printf("%d %s",a+1,misi[c-1][a]);
            }
            gotoxy(4,37);  printf("                                                 ");
            do
            {
                gotoxy(10,37);  printf("T E K A N   S P A S I   U N T U K   K E   H A L A M A N   S E B E L U M N Y A   ! ! !");
                pil = getch();
                if (pil == 32)
                {
                    gotoxy(10,37);  printf("                                                                                                       ");
                    hapus2();
                    hapus1();
                    kandidatUser();
                }
                else
                {
                    gotoxy(10,37);  printf("                                                                                                     ");
                    gotoxy(35,37);  printf("I N P U T A N   T I D A K   V A L I D   ! ! !"); Sleep(1500);
                    gotoxy(35,37);  printf("                                              ");
                }

            } while (pil!=32);
    
        }
        else
        {
                gotoxy(4,37);  printf("                                           ");
                gotoxy(33,37); printf("                                   ");
                gotoxy(13,37); printf("P A S A N G A N   T I D A K   D I T E M U K A N   ! ! !");
                gotoxy(13,37); printf("                                                       ");
                h+=2;
        }
    }
}

void votingUser()
{
    char vote[10];
    if(tandaSudahVoting[tandaPemilih]==false){

    gotoxy(23,2); printf("        ##       ##   ######   ######   ##   ####    ##   #######             ");
    gotoxy(23,3); printf("         ##     ##    ##  ##     ##     ##   ## ##   ##   ##                  ");
    gotoxy(23,4); printf("          ##   ##     ##  ##     ##     ##   ##  ##  ##   ##  ##              ");
    gotoxy(23,5); printf("           ## ##      ##  ##     ##     ##   ##   ## ##   ##   ##             ");
    gotoxy(23,6); printf("            ###       ######     ##     ##   ##    ####   #######             ");


        if(tampKandidat!=0){
            dataKandidat();
            }
         else{
            gotoxy(30,20); printf("T I D A K   A D A   K A N D I D A T   Y A N G   B I S A   D I P I L I H");
            gotoxy(30,22); printf("M I N I M A L   H A R U S   A D A   1   P A S A N G A N   K A N D I D A T");
            getch();
            menuUser();
        }
    } else {
        hapus1();
        hapus2();
        gotoxy(14,22);printf("-   1  A K U N   H A N Y A   B I S A   M E L A K U K A N   1   K A L I   V O T E   ! ! !   -"); Sleep(750);
        gotoxy(14,22);printf("                                                                                                  "); Sleep(750);
        gotoxy(14,22);printf("-   1  A K U N   H A N Y A   B I S A   M E L A K U K A N   1   K A L I   V O T E   ! ! !   -"); Sleep(750);
        gotoxy(14,22);printf("                                                                                                  "); Sleep(750);
        gotoxy(14,22);printf("-   1  A K U N   H A N Y A   B I S A   M E L A K U K A N   1   K A L I   V O T E   ! ! !   -");
        getch();
        gotoxy(14,22);printf("                                                                                                  ");
        menuUser();
    }

    int a=0;
    while (a!=1)
    {
        bool x;
        gotoxy(26,10);printf("-   P A S T I K A N   P I L I H A N   A N D A   B E N A R   ! ! !   -");
        gotoxy(9,30);printf("M A S U K A N   N O M O R   K A N D I D A T   :  ");

        gotoxy(57,30);gets(vote);

        int c;
        c=atoi(vote);
        // Mengecek Data Kandidat
            if(c>0 && c<=tampKandidat){
                x = true;
            } else {
                x = false;
            }
        c-=1;

        char yakin;
        if(x==true){
            int d=0;
            while (d!=1)
            {
                gotoxy(9,32);printf("A P A K A H   A N D A   Y A K I N   D E N G A N   P I L I H A N   A N D A   ( Y / T )   :  ");
                gotoxy(100,32); yakin = getche();
                if(yakin == 'Y' || yakin == 'y'){
                    prosesVote[c]++;
                    tandaSudahVoting[tandaPemilih]=true;
                    d=1;
                    a=1;
                    hapus1();
                    hapus2();
                    menuUser();
                } else if(yakin == 'T' || yakin == 't') {
                    hapus1();
                    hapus2();
                    menuUser();
                    d+=2;
                } else {
                    gotoxy(100,32); printf("  ");
                    d+=2;
                }
            }
        } else {
            gotoxy(57,30); printf("K A N D I D A T   T I D A K   A D A  "); Sleep(1500);
            gotoxy(57,30); printf("                                     ");
        }
    }
    
}

void kotakStatus()
{
    if (tandaSudahVoting[tandaPemilih]==true)
    {
        for (int x = 0; x <= 90; x++)
        {
            for (int y = 1; y <= 15; y++)
            {
                color(6);
                gotoxy(14 + x, 12);
                printf("%c", 219);
                gotoxy(14 + x, 27);
                printf("%c", 219);
                gotoxy(14 , 12 + y);
                printf("%c", 219);
                gotoxy(104,12 + y);
                printf("%c", 219);
            }
        }
        
        gotoxy(40,16); printf("NAMA LENGKAP     : %s",tampNama);
        gotoxy(40,18); printf("NIM              : %s",tampNim);
        gotoxy(40,20); printf("ANGKATAN         : %s",tampAkt);
        gotoxy(40,22); printf("PROGRAM STUDI    : %s",tampProdi);

        gotoxy(15,29); printf("######   ##  ##   ######     ######   ##  ##     ##       ##   ######   ######   ######");
        gotoxy(15,30); printf("##       ##  ##   ##   ##    ##  ##   ##  ##      ##     ##    ##  ##     ##     ##    ");
        gotoxy(15,31); printf("######   ##  ##   ##    ##   ######   ######       ##   ##     ##  ##     ##     ######");
        gotoxy(15,32); printf("    ##   ##  ##   ##   ##    ##  ##   ##  ##        ## ##      ##  ##     ##     ##    ");
        gotoxy(15,33); printf("######   ######   ######     ##  ##   ##  ##         ###       ######     ##     ######");
    }
    else if(tandaSudahVoting[tandaPemilih]==false)
    {
        for (int x = 0; x <= 90; x++)
        {
            for (int y = 1; y <= 15; y++)
            {
                color(6);
                gotoxy(14 + x, 12);
                printf("%c", 219);
                gotoxy(14 + x, 27);
                printf("%c", 219);
                gotoxy(14 , 12 + y);
                printf("%c", 219);
                gotoxy(104,12 + y);
                printf("%c", 219);
            }
        }
        
        gotoxy(40,16); printf("NAMA LENGKAP     : %s",tampNama);
        gotoxy(40,18); printf("NIM              : %s",tampNim);
        gotoxy(40,20); printf("ANGKATAN         : %s",tampAkt);
        gotoxy(40,22); printf("PROGRAM STUDI    : %s",tampProdi);

        gotoxy(14,29); printf("######    ######   ##       ##  ##   ####   ####     ##       ##   ######   ######   ######");
        gotoxy(14,30); printf("##   ##   ##       ##       ##  ##   ## ## ## ##      ##     ##    ##  ##     ##     ##    ");
        gotoxy(14,31); printf("## ###    ######   ##       ##  ##   ##  ###  ##       ##   ##     ##  ##     ##     ######");
        gotoxy(14,32); printf("##   ##   ##       ##       ##  ##   ##       ##        ## ##      ##  ##     ##     ##    ");
        gotoxy(14,33); printf("######    ######   ######   ######   ##       ##         ###       ######     ##     ######");
    }
    char pil;
    do
     {
        gotoxy(4,37); printf("                                      ");
         color(4);
         gotoxy(30,37); printf("T E K A N   B A C K S P A C E   U N T U K   K E M B A L I");
         gotoxy(50,38); pil = getch(); 
         if (pil == 8)
         {
             gotoxy(30,37); printf("                                                         ");
             hapus1();
             menuAdmin();
         }
         
     } while (pil!=8);
}

void main()
{
    bingkai();
    logo();
    getch();
}