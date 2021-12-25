#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<conio.h>
void color(short x)	//自定义函根据参数改变颜色 
{
    if (x >= 0 && x <= 15)//参数在0-15的范围颜色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
    else
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void NoEffect();
void Choice_of_Damage();
void Device_decay();
void Risk_or_Reward();
void otherEvents();
void planetDraw();
void setcolor(int);
int judgeCon(int);
int judge(int);
void planetSerch();
void searchDraw();
void surfaceSearch();
int atmosphere = 100;
int gravity = 100;
int temperature = 100;
int water = 100;
int resources = 100;
int colonists = 1000;
int landing = 100;
int construction = 100;
int scientific = 100;
int cultural = 100;
int surface = 10;
int atmosphere_level = 1;
int gravity_level = 1;
int temperature_level = 1;
int water_level = 1;
int resources_level = 1;
int planet_atmosphere = 0;
int planet_gravity = 0;
int planet_temperature = 0;
int planet_water = 0;
int planet_resources = 0;
int is_search_atm = 0;
int is_search_gra = 0;
int is_search_tem = 0;
int is_search_wat = 0;
int is_search_res = 0;
const char* atm1[3] = {"!Corrosive","!Non-existent","!Radioactive"};
const char* atm2 = "-Thin atmosphere";
const char* atm3 = "+Breathable";
const char* gra1[2] = {"!Very low","!Very high"};
const char* gra2[2] = { "-Low","-High" };
const char* gra3 = "+Suitable";
const char* tem1[2] = { "!Very hot","!Very cold" };
const char* tem2[2] = {"-Hot", "-Cold"};
const char* tem3 = "+Suitable";
const char* wat1[3] = {"！Corrosion","！Acidic","!Not drinkable"};
const char* wat2[2] = {"-Drink after processing","-A bit"};
const char* wat3 = "+Abundant water";
const char* res1[2] = {"!No resources","!Harmful resources" };
const char* res2 = "-Less resources";
const char* res3 = "+Abundant resources";
int main()
{
    puts("In 4856 AD, the earth civilization was facing a huge catastrophe, and human" 
        "beings exhausted all global resources to create a giant interstellar spacecraft\n");
    while (1)
    {
        if (_kbhit())
        {
            char c = _getch();
            if (c == ' ')
                break;
        }
    }
    puts("Your human task is to bring mankind to discover new planets and create colonie"
        "s to allow human civilization to continue.During the interstellar flight, you "
        "may be faced with various events. Please make a reasonable choice to reduce the "
        "damage of the spacecraft and reduce the casualties. Lead mankind to a new home!");
    while (1)
    {
        if (_kbhit())
        {
            char c = _getch();
            if (c == ' ')
            break;
        }
    }
    color(15);
    puts("\nStart your journey now!");
    color(16);
    while (1)
    {
        if (_kbhit())
        {
            char c = _getch();
            if (c == ' ')
            break;
        }
    }
    while (1)
    {
        planetDraw();
        puts("M(Move on)     P(Probe surface)     C(Found Colony)\n");
        //开始使用飞船自带探测器探测星球；
        planetSerch();
        searchDraw();
        puts("\n");
       
        while (1)
        {
            if (_kbhit())
            {
                char c = _getch();
                if (c == 'M')
                {
                    puts("进入事件");
                    break; //离开当前循环，进入事件
                }
                else if (c == 'P') //发射探针
                {
                    if (surface == 0)
                    {
                        color(4);
                        puts("The number of probes is already insufficient!");
                        color(16);
                        continue;
                    }
                    else {
                        surface--;

                        planetDraw();
                        puts("M(Move on)     P(Probe surface)     C(Found Colony)\n");
                        searchDraw();
                        surfaceSearch();
                    }
                }
                else if (c == 'C')//进入殖民进程
                {

                }
            }
        }
        while (1) //开始事件
        {
            color(4);
            puts("Events!\n");
            color(16);
            while (1)
            {
                if (_kbhit())
                {
                    char c = _getch();
                    if (c == ' ')
                        break;
                }
            }
            int a = rand() % 100 + 1;
            if (a <=15) {
                NoEffect();
                break;
            }
            else if (a > 15 && a <= 50)
            {
                Choice_of_Damage();
                break;
            }
            else if (a > 50 && a <= 60)
            {
                Device_decay();
                break;
            }
            else if (a > 60 && a <= 90)
            {
                Risk_or_Reward();
                break;
            }
            else {
                otherEvents();
                break;
            }
            
        }
        while (1)//飞船升级
        {
            break;
        }
    }
}
void surfaceSearch()
{

}
void planetSerch() {
    //大气搜索
    int cc = 100 - atmosphere;
    int aa = rand() % 100 + 1;
    if (aa > cc)
    {
        if (atmosphere_level == 1)
        {
            int x = rand() % 10 + 1;
            if (x > 4)
            {
                planet_atmosphere = 1;
            }
            else if (x > 1 && x <= 4) {
                planet_atmosphere = 2;
            }
            else {
                planet_atmosphere = 3;
            }
        }
        else if (atmosphere_level == 2)
        {
            int x = rand() % 10 + 1;
            if (x > 3)
            {
                planet_atmosphere = 2;
            }
            else {
                planet_atmosphere = 3;
            }
        }
        else if (atmosphere_level == 3)
        {
            int x = rand() % 10 + 1;
            if (x > 3)
            {
                planet_atmosphere = 3;
            }
            else {
                planet_atmosphere = 2;
            }
        }
        is_search_atm = 1;
    }
    //引力调查
    cc = 100 - gravity;
    aa = rand() % 100 + 1;
    if (aa > cc)
    {
        if (gravity_level == 1)
        {
            int x = rand() % 10 + 1;
            if (x > 4)
            {
                planet_gravity = 1;
            }
            else if (x > 1 && x <= 4) {
                planet_gravity = 2;
            }
            else {
                planet_gravity = 3;
            }
        }
        else if (gravity_level == 2)
        {
            int x = rand() % 10 + 1;
            if (x > 3)
            {
                planet_gravity = 2;
            }
            else {
                planet_gravity = 3;
            }
        }
        else if (gravity_level == 3)
        {
            int x = rand() % 10 + 1;
            if (x > 3)
            {
                planet_gravity = 3;
            }
            else {
                planet_gravity = 2;
            }
        }
        is_search_gra = 1;
    }
    //温度调查
    cc = 100 - temperature;
    aa = rand() % 100 + 1;
    if (aa > cc)
    {
        if (temperature_level == 1)
        {
            int x = rand() % 10 + 1;
            if (x > 4)
            {
                planet_temperature = 1;
            }
            else if (x > 1 && x <= 4) {
                planet_temperature = 2;
            }
            else {
                planet_temperature = 3;
            }
        }
        else if (temperature_level == 2)
        {
            int x = rand() % 10 + 1;
            if (x > 3)
            {
                planet_temperature = 2;
            }
            else {
                planet_temperature = 3;
            }
        }
        else if (temperature_level == 3)
        {
            int x = rand() % 10 + 1;
            if (x > 3)
            {
                planet_temperature = 3;
            }
            else {
                planet_temperature = 2;
            }
        }
        is_search_tem = 1;
    }
    //水调查
    cc = 100 - water;
    aa = rand() % 100 + 1;
    if (aa > cc)
    {
        if (water_level == 1)
        {
            int x = rand() % 10 + 1;
            if (x > 4)
            {
                planet_water = 1;
            }
            else if (x > 1 && x <= 4) {
                planet_water = 2;
            }
            else {
                planet_water = 3;
            }
        }
        else if (water_level == 2)
        {
            int x = rand() % 10 + 1;
            if (x > 3)
            {
                planet_water = 2;
            }
            else {
                planet_water = 3;
            }
        }
        else if (water_level == 3)
        {
            int x = rand() % 10 + 1;
            if (x > 3)
            {
                planet_water = 3;
            }
            else {
                planet_water = 2;
            }
        }
        is_search_wat = 1;
    }
  
    //资源调查
    cc = 100 - resources;
    aa = rand() % 100 + 1;
    if (aa > cc)
    {
        if (resources_level == 1)
        {
            int x = rand() % 10 + 1;
            if (x > 4)
            {
                planet_resources = 1;
            }
            else if (x > 1 && x <= 4) {
                planet_resources = 2;
            }
            else {
                planet_resources = 3;
            }
        }
        else if (resources_level == 2)
        {
            int x = rand() % 10 + 1;
            if (x > 3)
            {
                planet_resources = 2;
            }
            else {
                planet_resources = 3;
            }
        }
        else if (resources_level == 3)
        {
            int x = rand() % 10 + 1;
            if (x > 3)
            {
                planet_resources = 3;
            }
            else {
                planet_resources = 2;
            }
        }
        is_search_res = 1;
    }
    
}
void searchDraw()
{
    //星球大气
    printf("%-20s", "Atmosphere");
    if (planet_atmosphere == 1)
    {
        int a = rand() % 3 + 1;
      //  color(4);
        printf("%-25s", atm1[a]);
       // color(16);
    }
    else if (planet_atmosphere == 2)
    {
      //  color(6);
        printf("%-25s", atm2);
       // color(16);
    }
    else if (planet_atmosphere == 3)
    {
      //  color(2);
        printf("%-25s", atm3);
      //  color(16);
    }
    else {
        printf("%-25s", "Can not search");
    }
    //星球重力
    printf("%-20s", "Gravity");
    if (planet_gravity == 1)
    {
        int a = rand() % 2 + 1;
     //   color(4);
        printf("%-25s\n", gra1[a]);
     //   color(16);
    }
    else if (planet_gravity == 2)
    {
       // color(6);
        int a = rand() % 2 + 1;
        printf("%-25s\n",gra2[a]);
      //  color(16);
    }
    else if (planet_gravity == 3)
    {
      //  color(2);
        printf("%-25s\n", gra3);
      //  color(16);
    }
    else {
        printf("%-25s", "Can not search");
    }
    //星球温度
    printf("%-20s", "Temperature");
    if (planet_temperature == 1)
    {
      //  color(4);
        int a = rand() % 2 + 1;
        printf("%-25s", tem1[a]);
       // color(16);
    }
    else if (planet_temperature == 2)
    {
       // color(6);
        int a = rand() % 2 + 1;
        printf("%-25s", tem2[a]);
      //  color(16);
    }
    else if (planet_temperature == 3)
    {
      //  color(2);
        printf("%-25s", tem3);
       // color(16);
    }
    else {
        printf("%-25s", "Can not search");
    }
    //星球水资源
    printf("%-20s", "water");
    if (planet_water == 1)
    {
       // color(4);
        int a = rand() % 3 + 1;
        printf("%-25s\n", wat1[a]);
       // color(16);
    }
    else if (planet_water == 2)
    {
       // color(6);
        int a = rand() % 2 + 1;
        printf("%-25s\n", wat2[a]);
      //  color(16);
    }
    else if (planet_water == 3)
    {
      //  color(2);
        printf("%-25s\n", wat3);
      //  color(16);
    }
    else {
        printf("%-25s", "Can not search");
    }
    //星球资源
    printf("%-20s", "Resources");
    if (planet_resources == 1)
    {
       // color(4);
        int a = rand() % 2 + 1;
        printf("%-25s", res1[a]);
      //  color(16);
    }
    else if (planet_resources == 2)
    {
      //  color(6);
        printf("%-25s", res2);
       // color(16);
    }
    else if (planet_resources == 3)
    {
       // color(2);
        printf("%-25s", res3);
      //  color(16);
    }
    else {
        printf("%-25s", "Can not search");
    }
}
void NoEffect() {
    color(6);
    printf("No Effect:");
    color(16);
    int a = rand() % 4 + 1;
    if (a == 1)
    {
        puts("False Alarm");
        puts("Deep in space, the AI wakes suddenly to an alert from the medical "
            "monitoring program. It anxiously checks the colonists, but finds that "
            "there is no problem, and the alert was a glitch. Nevertheless, the AI "
            "spends some time watching its sleeping charges, reassuring itself that "
            "they are all alive, before it joins them again in sleep.\nPress space to continue......");
        while (1)
        {
            if (_kbhit())
            {
                char c = _getch();
                if (c == ' ')
                    break;
            }
        }
    }
    else if (a == 2)
    {
        puts("Hibernating");
        puts("The next star chosen by the guidance system is on the other side of a "
            "great void, with no stars for dozens of light years. The AI hibernates "
            "for the millennia-long journey through utter emptiness.\nPress space to continue......");
        while (1)
        {
            if (_kbhit())
            {
                char c = _getch();
                if (c == ' ')
                    break;
            }
        }
    }
    else if (a == 3)
    {
        puts("Hibernating 2");
        puts("For centuries the seedship drifts towards its next destination, very nearly inert, "
            "the AI hibernating and only the simple collision avoidance and damage monitoring systems "
            "ticking over.\nPress space to continue......");
        while (1)
        {
            if (_kbhit())
            {
                char c = _getch();
                if (c == ' ')
                    break;
            }
        }
    }
    else if (a == 4)
    {
        puts("Star Cluster");
        puts("The seedship's course takes it through a dense star cluster, and while the AI sleeps "
            "the guidance system weaves a complex course through the stars' overlapping gravitational "
            "fields.\nPress space to continue......");
        while (1)
        {
            if (_kbhit())
            {
                char c = _getch();
                if (c == ' ')
                    break;
            }
        }
    }
}
void Choice_of_Damage() {

}
void Device_decay() {

}
void Risk_or_Reward() {

}
void otherEvents() {

}
void planetDraw()
{
    system("cls");
    printf("|-------------------------------------------------------------------|\n");
    printf("|Construction:                      ");
    setcolor(judgeCon(colonists));
    printf("%-4d", colonists);
    color(16);
    printf("                            |\n");
    puts("|Scanners:                          Systems:                        |");

    printf("|Atmosphere(%d):            ", atmosphere_level);
    setcolor(judge(atmosphere));
    printf("%-3d%%", atmosphere);
    color(16);
    printf("     Landing:               ");
    setcolor(judge(landing));
    printf("%-3d%%", landing);
    color(16);
    puts("     |");

    printf("|Gravity(%d):               ", gravity_level);
    setcolor(judge(gravity));
    printf("%-3d%%", gravity);
    color(16);
    printf("     Construction:          ");
    setcolor(judge(construction));
    printf("%-3d%%", landing);
    color(16);
    puts("     |");

    printf("|Temperature(%d):           ", temperature_level);
    setcolor(judge(temperature));
    printf("%-3d%%", temperature);
    color(16);
    printf("                                     |\n");

    printf("|Water(%d):                 ", water_level);
    setcolor(judge(water));
    printf("%-3d%%", water);
    color(16);
    puts("     Databass                        |");

    printf("|Resources(%d):             ", resources_level);
    setcolor(judge(resources));
    printf("%-3d%%", resources);
    color(16);
    printf("     Scientific:            ");
    setcolor(judge(scientific));
    printf("%-3d%%", scientific);
    color(16);
    puts("     |");

    printf("|Surface:                  ");
    printf("%-3d", surface);
    printf("      Cultural:              ");
    setcolor(judge(cultural));
    printf("%-3d%%", cultural);
    color(16);
    puts("     |");
    puts("|-------------------------------------------------------------------|\n");
}
void setcolor(int a)
{
    if (a == 0) {
        color(2);
    }
    else if (a == 1) {
        color(6);
    }
    else if (a == 2) {
        color(4);
    }
}
int judgeCon(int a)
{
    if (a == 1000) //绿色
        return 0;
    if (a >= 100 && a < 1000) //黄色
        return 1;
    if (a < 100)
        return 2;
}
int judge(int a)
{
    if (a == 100) //绿色
        return 0;
    if (a >= 10 && a < 100) //黄色
        return 1;
    if (a < 100)
        return 2;
}
