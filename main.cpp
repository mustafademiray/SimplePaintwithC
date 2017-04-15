#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <bitmap_image.hpp>

bool daire = false;
bool dortgen = false;
bool ucgen = false;
bool kalem = false;
bool dogru = false;
bool silgi = false;
int a,b,i,j;

bitmap_image image(600,600);

void dizilim()
{
    int i,j;
    bar(600,600,0,0);

    setbkcolor(3);
    setcolor(15);
    outtextxy(80,15,"Kalem");

    //setbkcolor(3);
    //setcolor(15);
    outtextxy(5,15,"Dogru Ciz");

    setbkcolor(3);
    //setcolor(15);
    outtextxy(130,15,"Daire Ciz" );

    setbkcolor(3);
    //setcolor(15);
    outtextxy(200,15,"Dortgen");

    setbkcolor(3);
    setcolor(15);
    outtextxy(260,15,"Silgi");

    setbkcolor(3);
    setcolor(15);
    outtextxy(300,15,"Ucgen");

    setbkcolor(3);
    setcolor(15);
    outtextxy(350,15,"Temizle");

    setbkcolor(0);
    setcolor(15);
    outtextxy(410,15,"Cikis");

    setbkcolor(0);
    setcolor(15);
    outtextxy(280,37,"Kaydet");

    setbkcolor(0);
    setcolor(15);
    outtextxy(339,37," Ac ");


    //kirmizi
    for(i=35;i<=55;i++)
    {
        for(j=5;j<=25;j++)
        {
            putpixel(j,i,4);
        }
    }

    //yesil
    for(i=35;i<=55;i++)
    {
        for(j=35;j<=55;j++)
        {
            putpixel(j,i,2);
        }
    }

    //mavi
    for(i=35;i<=55;i++)
    {
        for(j=65;j<=85;j++)
        {
            putpixel(j,i,1);
        }
    }

    //cyan
    for(i=35;i<=55;i++)
    {
        for(j=95;j<=115;j++)
        {
            putpixel(j,i,3);
        }
    }

    //kahve
    for(i=35;i<=55;i++)
    {
        for(j=125;j<=145;j++)
        {
            putpixel(j,i,6);
        }
    }

     //acik mavi
    for(i=35;i<=55;i++)
    {
        for(j=155;j<=175;j++)
        {
            putpixel(j,i,9);
        }
    }

    //acik kirmizi
    for(i=35;i<=55;i++)
    {
        for(j=185;j<=205;j++)
        {
            putpixel(j,i,12);
        }
    }

    //sari
    for(i=35;i<=55;i++)
    {
        for(j=215;j<=235;j++)
        {
            putpixel(j,i,14);
        }
    }

     //siyah
    for(i=35;i<=55;i++)
    {
        for(j=245;j<=265;j++)
        {
            putpixel(j,i,0);
        }
    }

    for(i=60;i<=62;i++)
    {
        for(j=0;j<=600;j++)
        {
            putpixel(j,i,BLACK);
        }
    }

}

void resim_kaydet()
{
    int i,j;
    int a;
    for(i=0;i<600;i++){
        for(j=62;j<600;j++){
            if(getpixel(i,j)==WHITE)
            {
                image.set_pixel(i,j,255,255,255);
            }
            else if(getpixel(i,j)==YELLOW){
                image.set_pixel(i,j,255,255,0);
            }
            else if(getpixel(i,j)==RED)
            {
                image.set_pixel(i,j,255,0,0);
            }
            else if(getpixel(i,j)==BLUE)
            {
                image.set_pixel(i,j,0,0,255);
            }
            else if(getpixel(i,j)==GREEN)
            {
                image.set_pixel(i,j,0,255,0);
            }
            else if(getpixel(i,j)==BLACK)
            {
                image.set_pixel(i,j,0,0,0);
            }
            else if(getpixel(i,j)==LIGHTRED)
            {
                image.set_pixel(i,j,255,204,203);
            }
            else if(getpixel(i,j)==CYAN)
            {
                image.set_pixel(i,j,0,204,255);
            }
            else if(getpixel(i,j)==BROWN)
            {
                image.set_pixel(i,j,121,82,39);
            }
            else if(getpixel(i,j)==LIGHTBLUE)
            {
                image.set_pixel(i,j,173,216,230);
            }
        }
    }
    image.save_image("resim.bmp");

    FILE *dosya;
    dosya = fopen("cikti.txt","w+");
    for(i=0;i<600;i++){
        for(j=62;j<600;j++){
            fprintf(dosya,"%d\n",getpixel(i,j));
        }
    }
    fclose(dosya);
}

void resim_ac()
{
    FILE *cikti=fopen("cikti.txt","r+");
    int pixel,x=0,y=0;
    while(!feof(cikti)){
        fscanf(cikti,"%d",&pixel);
        putpixel(x,y+62,pixel);
        y++;
        if(y==538) // 62+538 = 600'e kadar gitsin diye.
        {
            x++;
            y=0;
        }

    }
    fclose(cikti);
}

void sol_tik()
{
    while(1){
    int x,y;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        printf("mouse'a %d ve %d'de tiklandi\n",mousex(),mousey());
        x=mousex();
        y=mousey();
        clearmouseclick(WM_LBUTTONDOWN);
        if(x>5 && x <25 && y>35 && y<55){
            printf("kirmizi tiklandi\n");
            setcolor(RED);
        }
        else if(x>35 && x<55 && y>35 && y<55){
            setcolor(GREEN);
            printf("yesil tiklandi\n");
        }
        else if(x>65 && x<85 && y>35 && y<55){
            printf("mavi tiklandi\n");
            setcolor(BLUE);
        }
        else if(x>95 && x<115 && y>35 && y<55){
            printf("cyan tiklandi\n");
            setcolor(CYAN);
        }
        else if(x>125 && x<145 && y>35 && y<55){
            printf("kahverengi tiklandi\n");
            setcolor(BROWN);
        }
        else if(x>155 && x<175 && y>35 && y<55){
            printf("acik mavi tiklandi\n");
            setcolor(LIGHTBLUE);
        }
        else if(x>185 && x<205 && y>35 && y<55){
            printf("light red tiklandi\n");
            setcolor(LIGHTRED);
        }
        else if(x>215 && x<235 && y>35 && y<55){
            printf("sari tiklandi\n");
            setcolor(YELLOW);
        }
        else if(x>245 && x<265 && y>35 && y<55){
            printf("siyah tiklandi\n");
            setcolor(BLACK);
        }
        else if(x>130 && x<190 && y>15 && y<30){
            int d,e;
            daire = true;
            printf("daireye tiklandi\n");
            kalem = false;
            dortgen = false;
            ucgen = false;
            silgi = false;
            dogru = false;
            delay(1000);
            getmouseclick(WM_LBUTTONDOWN, x, y);
            a=x,b=y;
            delay(1000);
            getmouseclick(WM_LBUTTONUP, d, e);
            int yaricap,uzunluk;
            uzunluk = (a-d)*(a-d)+(b-e)*(b-e);
            yaricap=((sqrt(uzunluk))/2);
            circle(d,e,yaricap);
        }
        else if(x>5 && x<65 && y>15 && y<30){
            printf("dogru ciz tiklandi\n");
            dogru = true;
            dortgen = false;
            daire = false;
            kalem = false;
            ucgen = false;
            silgi = false;
            delay(1500);
            getmouseclick(WM_LBUTTONDOWN, x, y);
            a=x,b=y;
            getmouseclick(WM_LBUTTONUP, x, y);
            line(a,b,x,y);

        }
        else if(x>80 && x<120 && y>15 && y<30){
            printf("kalem tiklandi\n");
            kalem = true;
            dortgen = false;
            daire = false;
            ucgen = false;
            silgi = false;
            dogru = false;
        }
        else if(kalem == true){
            getmouseclick(WM_LBUTTONDOWN,x,y);
            bool tikKontrol=true;
            do
            {
                if(y>60){
                    getmouseclick(WM_MOUSEMOVE,x,y);
                    circle(x,y,1);
                }
                tikKontrol=(ismouseclick(WM_LBUTTONDOWN));
            }
                while(!tikKontrol);
                kalem = false;
        }
        else if(x>200 && x<250 && y>15 && y<30){
            printf("dortgen tiklandi\n");
            dogru = false;
            dortgen = true;
            daire = false;
            kalem = false;
            ucgen = false;
            silgi = false;
            delay(1000);
            getmouseclick(WM_LBUTTONDOWN,x,y);
            a=x;
            b=y;
            delay(1000);
            getmouseclick(WM_LBUTTONDOWN,x,y);
            rectangle(a,b,x,y);
        }
        else if(x>260 && x<290 && y>15 && y<30){
            printf("silgi tiklandi \n");
            kalem = false;
            dogru = false;
            dortgen = false;
            daire = false;
            ucgen = false;
            silgi = true;
        }
        else if(silgi == true){
            while(!ismouseclick(WM_LBUTTONDOWN)){}
            getmouseclick(WM_LBUTTONDOWN,x,y);
            bool tikKontrolSilgi=true;
            do
            {   setcolor(WHITE);
                getmouseclick(WM_MOUSEMOVE,x,y);
                circle(x,y,3);
                //delay(0);
                tikKontrolSilgi=(ismouseclick(WM_LBUTTONDOWN));
            }
                while(!tikKontrolSilgi);
                silgi = false;
        }
        else if(x>300 && x<340 && y>15 && y<30){
            printf("ucgen tiklandi\n");
            dogru = false;
            dortgen = false;
            daire = false;
            kalem = false;
            ucgen = true;
            silgi = false;
            delay(1500);
            getmouseclick(WM_LBUTTONDOWN, x, y);
            a=x,b=y;
            getmouseclick(WM_LBUTTONUP, x, y);
            line(a,b,x,y);
            int q,w,e,r;
            q=a;
            w=b;
            e=x;
            r=y;
            delay(750);
            getmouseclick(WM_LBUTTONDOWN,x,y);
            line(x,y,q,w);
            line(x,y,e,r);
        }
        else if(x>350 && x<400 && y>15 && y<30){
            clearviewport();
            dizilim();
            dortgen = false;
            daire = false;
            ucgen = false;
            kalem = false;
            dogru = false;
            setcolor(BLACK);
            printf("temizle tiklandi\n");
        }
        else if(x>280 && x<325 && y>37 && y<53)
        {
            resim_kaydet();
            printf("resim kaydet tiklandi..\n");
        }
        else if(x>340 && x<362 && y>37 && y<53)
        {
            resim_ac();
            printf("resim ac tiklandi..\n");
        }
        else if(x>410 && x<440 && y>15 && y<30){
            printf("cikis tiklandi\n");
            exit(1);
        }
        else{
            while(!ismouseclick(WM_LBUTTONDOWN)){}
                getmouseclick(WM_LBUTTONDOWN,x,y);
                bool tikKontrol=true;
                if(y>60 && x<600){
                    do
                    {
                        getmouseclick(WM_MOUSEMOVE,x,y);
                        circle(x,y,1);
                        tikKontrol=(ismouseclick(WM_LBUTTONDOWN));
                    }
                    while(!tikKontrol);
                }
                else{
                    kalem = false;
                }
            }
        }
    }
}

int main()
{
    initwindow(600,600,"Pro_Lab_I",500,15);
    dizilim();
    while(1)
    sol_tik();
    getch();
    return 0;
}
