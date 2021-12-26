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
void searchHarm(int);
void landingHarm(int);
void dataHarm(int);
int pass = 0;
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
                while (1)
                {
                    if (_kbhit())
                    {
                        char c = _getch();
                        if (c == ' ')
                            break;
                    }
                }
                break;
            }
            else if (a > 15 && a <= 50)
            {
                Choice_of_Damage();
                while (1)
                {
                    if (_kbhit())
                    {
                        char c = _getch();
                        if (c == ' ')
                            break;
                    }
                }
                break;
            }
            else if (a > 50 && a <= 60)
            {
                Device_decay();
                while (1)
                {
                    if (_kbhit())
                    {
                        char c = _getch();
                        if (c == ' ')
                            break;
                    }
                }
                break;
            }
            else if (a > 60 && a <= 90)
            {
                Risk_or_Reward();
                while (1)
                {
                    if (_kbhit())
                    {
                        char c = _getch();
                        if (c == ' ')
                            break;
                    }
                }
                break;
            }
            else {
                otherEvents();
                while (1)
                {
                    if (_kbhit())
                    {
                        char c = _getch();
                        if (c == ' ')
                            break;
                    }
                }
                break;
            }
            
        }
        if (pass == 0)
        {
            while (1)//飞船升级
            {
                break;
            }
        }
        else {
            pass = 0;
        }
    }
}
void searchHarm(int x)
{
    int b = rand() % 5;
    if (b == 0)
    {
        atmosphere -= x;
    }
    else if (b == 1)
    {
        gravity -= x;
    }
    else if (b == 2)
    {
        temperature -= x;
    }
    else if (b == 3)
    {
        water -= x;
    }
    else if (b == 4)
    {
        resources -= x;
    }
    return;
}
void landingHarm(int x)
{
    int b = rand() % 2;
    if (b == 0)
    {
        landing -= x;
    }
    else {
        construction -= x;
    }
}
void dataHarm(int x)
{
    int b = rand() % 2;
    if (b == 0)
    {
        scientific -= x;
    }
    else {
        cultural -= x;
    }
    return;
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
    color(2);
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
    color(2);
    printf("Choice of Damage\n");
    color(16);
    int a = rand() % 5 + 1;
    if (a == 1)
    {
        puts("Overheat");
        puts("The AI wakes to a wall of blinding brightness. The seedship's course has taken it "
            "close to a super-giant star that has proved to be far hotter than the guidance system "
            "anticipated, and the ship is gathering heat faster than the radiator fins can radiate "
            "it away. The AI must shut down part of the heat regulation system before the entire "
            "system catastrophically fails.");
        puts("A.Allow the scanner module to overheat)   B.Allow the scanner module to overheatt");
        puts("C.Allow the landing/construction module to overheat  D.Allow the data storage module to overheat");
        puts("E.Damage to science or culture");
        while (1)
        {
            char c;
            if (_kbhit());
            {
                c = _getch();
                if (c == 'A')
                {
                    puts("The AI channels excess heat into the sleep chambers. The heat regulation system recovers as the ship "
                        "moves away from the super-hot star, but not before some colonists have sustained tissue damage too "
                        "severe for them to be successfully revived.");
                    int x = rand() % 5 + 75;
                    colonists -= 75;
                    break;
                }
                else if (c == 'B')
                {
                    int x = rand() % 12 + 10;
                    searchHarm(x);
                    break;
                }
                else if (c == 'C')
                {
                    int x = rand() % 20 + 1;
                    landingHarm(x);
                    break;
                }
                else if (c == 'D')
                {
                    int x = rand() % 10 + 7;
                    dataHarm(x);
                    break;
                }
            }
        }

    }
    else if (a == 2)
    {
        puts("Overwhelmed");
        puts("The seedship's course takes it through a dense star-forming nebula. Hundreds of infant suns illuminate clouds of "
            "interstellar gas and fill the sky with riotous color. Clouds twist through complex gravitational interference patterns "
            "and glitter with heavy elements formed in the death throes of the last generation of stars. The scanners were not designed "
            "to deal with this level of input, and it is threatening to overwhelm them.If the AI continues to use the scanners to "
            "navigate, it can tell that the[scanner] will be damaged.Shutting off the scanners, however, would leave the seedship "
            "vulnerable to collisions in this crowded area of space. ");
        puts("A.Keep the scanners running    B.Fly blind");
        while (1)
        {
            char c;
            if (_kbhit());
            {
                c = _getch();
                if (c == 'A')
                {
                    int x = rand() % 20 + 15;
                    searchHarm(x);
                    puts("The AI continues to use the scanners to navigate. The [scanner] overloads, but the seedship passes safely "
                        "through the star-forming nebula. ");
                    break;
                }
                else if (c == 'B')
                {
                    puts("No damage! The AI calculates a course that it thinks will avoid obstacles, then shuts down the scanners. To "
                        "it's relief, when it judges that it is out of danger and reactivates the scanners, there is no damage.");
                    break;
                }
                
            }
        }
    }
    else if (a == 3)
    {
        puts("Guidance Query");
        puts("The AI wakes to a query from the automatic guidance system. Normally the system is able to analyze the data from "
            "the navigation sensors and make any necessary changes to the ship's course, but this time it has encountered readings "
            "it cannot make sense of and has woken the AI to make a decision.\nAccording to some sensors there is something ahead on "
            "the ship's course, but according to others the course ahead is clear. If there is something there, it is close enough "
            "that avoiding it would mean changing course and arriving at a new system without the benefit of the upgraded scanners. ");
        puts("A.Change course    B.Stay on course");
        while (1)
        {
            char c;
            if (_kbhit)
            {
                c = _getch();
                if (c == 'A')
                {
                    puts("The AI instructs the guidance system to avoid the anomaly and choose a new target system. It continues"
                        "to monitor the sensor readings as the ship passes the position of the anomaly, but the readings never become "
                        "c;ear enough to reveal whether the course change was necessary.");
                    pass = 1;
                    break;
                }
                else if (c == 'B')
                {
                    int x = rand() % 2;
                    if (x == 0)
                    {
                        puts("Success: The AI instructs the guidance system to stay on course. To its relief, the anomaly resolves into "
                            "a sensor glitch, and the seedship speeds through empty space to its target system.");
                    }
                    else if (x == 1)
                    {
                        puts("Failure: The AI instructs the guidance system to stay on course. By the time the sensors get a clear picture "
                            "of the utterly black, unreflective dust cloud, it is too late to avoid it. The seedship continues towards its "
                            "target system but a dust particle impacts [device].");
                        int xx = rand() % 15 + 1;
                        int yy = rand() % 3;
                        if (yy == 0)
                        {
                            searchHarm(xx);
                        }
                        else if (yy == 1)
                        {
                            landingHarm(xx);
                        }
                        else {
                            dataHarm(xx);
                        }
                    }
                    break;
                }
            }
        }
    }
    else if (a == 4) {
        puts("Interstellar Dust");
        puts("The seedship is decelerating on its approach to the next system when it detects an unusually thick volume of interstellar "
            "dust in its path. Passing through the dust would likely mean several high-velocity collisions with dust particles. The AI "
            "could execute an emergency course change to avoid the dust, but then the seedship would pass this system by and arrive at an "
            "effectively random one, without benefiting from the upgrades to its scanners.");
        puts("A.Plough through the dust ");
        while (1)
        {
            char c;
            if (_kbhit())
            {
                c = _getch();
                if (c == 'A');
                {
                    int x = rand() % 5 + 1;
                    int y = rand() % 5;
                    if (y == 0)
                    {
                        searchHarm(x);
                    }
                    else if (y == 1)
                    {
                        landingHarm(x);
                    }
                    else if (y == 2)
                    {
                        dataHarm(x);
                    }
                    else if(y==3){
                        surface--;
                    }
                    else if (y == 4) {
                        colonists -= x * 7;
                    }
                    break;
                }
                if (c == 'B')
                {
                    puts(" The AI rotates the ship and fires the main engine. It speeds safely past the dust cloud and the original "
                        "target system, and decelerates towards the first system it finds on its new course. ");
                    pass = 1;
                    break;
                }
            }
        }
    }
    else if (a == 5)
    {
        puts("Comet");
        puts("As the seedship enters the new system's outer cometary cloud, the collision-avoidance system detects a fast-moving comet "
            "surrounded by a cloud of smaller ice fragments. The large comet is on a collision course with the [device]. The seedship could "
            "avoid it entirely, but would then hit one of the smaller fragments, and the collision-avoidance system cannot predict which part "
            "of the ship that fragment would hit.");
        puts("A.Avoid the comet     B.Allow it to hit the [device]");
        while (1)
        {
            char c;
            if (_kbhit())
            {
                c = _getch();
                if (c == 'A')
                {
                    int x = rand() % 15 + 1;
                    int y = rand() % 5;
                    if (y == 0)
                    {
                        searchHarm(x);
                    }
                    else if (y == 1)
                    {
                        landingHarm(x);
                    }
                    else if (y == 2)
                    {
                        dataHarm(x);
                    }
                    else if (y == 3) {
                        surface--;
                    }
                    else if (y == 4) {
                        colonists -= x * 7;
                    }
                    puts("The seedship changes course, but an ice fragment tears through the [device].some Damage to[device]");
                    break;
                }
                else if (c == 'B')
                {
                    int x = rand() % 20 + 12;
                    int y = rand() % 5;
                    if (y == 0)
                    {
                        searchHarm(x);
                    }
                    else if (y == 1)
                    {
                        landingHarm(x);
                    }
                    else if (y == 2)
                    {
                        dataHarm(x);
                    }
                    else if (y == 3) {
                        surface--;
                    }
                    else if (y == 4) {
                        colonists -= x * 7;
                    }
                    puts("The comet shatters against the [device], crushing vital components some Damage to the[device]");
                    break;
                }
            }
        }
    }
}
void Device_decay() {
    color(4);
    puts("Device Decay");
    color(16);
    int a = rand() % 3;
    if (a == 0) {
        puts("Power Failure");
        puts("The seedship's small nuclear power plant has lasted far longer than the civilization that created it,"
            "but now it is beginning to fail. While the ship is near a star the solar panels still provide as much power"
            "as the systems need, but in deep space, fluctuations in the power supply are causing worrying malfunctions throughout the ship.");
        puts("A.Shut off [1-200] sleep chambers to preserve power    B.Save the colonists at any cost");
        while (1)
        {
            char c;
            if (_kbhit());
            {
                c = _getch();
                if (c == 'A')
                {
                    puts("Between stars, the largest drain to the power supply comes from the sleep chambers.The seedship calculates that "
                         "shutting off[1 - 21] chambers would take enough strain off the power supply to allow the ship to continue running."
                        "Saving all the colonists would mean allowing the failing power system to damage other parts of the ship.");
                    int x = rand() % 10 + 5;
                    x *= 10;
                    colonists -= x;
                    break;
                }
                else if (c == 'B')
                {
                    puts("The AI ignores the power system's warnings. Stars seem to jump in the sky as power fluctuations put the AI offline "
                        "for millennia at a time. Eventually the power supply stabilizes: the [3 devices] have deteriorated to the point that "
                        "they are no longer draining as much power, so the ancient power plant is sufficient once again.");
                    int x = rand() % 10 + 15;
                    int y = rand() % 3;
                    if (y == 0)
                    {
                        searchHarm(x);
                    }
                    else if (y == 1)
                    {
                        landingHarm(x);
                    }
                    else if (y == 2)
                    {
                        dataHarm(x);
                    }
                    break;
                }
            }
        }
    }
    else if (a == 1) {
        puts("Database decay");
        puts("The seedship's computer systems are shielded, multiply redundant, designed to work for millennia, but the incessant sleet of "
            "cosmic radiation is nevertheless taking its toll. Storage areas are failing, and soon there will not be enough space to store all "
            "the data that has survived so far. The AI can move data out of the most damaged sectors to protect either the scientific or the "
            "cultural database, but not both");
        puts("A.Save the scientific database     B.Save the cultural database");
        while (1)
        {
            char c;
            if (_kbhit())
            {
                c = _getch();
                if (c == 'A')
                {
                    puts("The AI moves data to save the scientific database, and sectors containing the cultural database gradually fail. "
                        "Cultural guidance for new colonists, records of human history, great paintings, novels, symphonies, video "
                        "games — all lost forever in the dark.");
                    int x = rand() % 10 + 15;
                    cultural -= x;
                    break;
                }
                if (c == 'B')
                {
                    puts("The AI moves data to save the cultural database, and sectors containing the scientific database gradually fail."
                        "Scientific guidance written for the new colonists, humanity's best theories of the universe, the life's work of "
                        "tireless scientists over the centuries—all lost forever in the dark.");
                    int x = rand() % 10 + 15;
                    scientific -= x;
                    break;
                }
            }
        }
    }
    else if (a == 2)
    {
        puts("Landing/Construction Decay");
        puts("The seedship's body is designed to form the core of an initial settlement once it has landed on an alien planet, so the "
            "landing and construction systems share many components. As the seedship ages, these components are starting to decay, but "
            "the AI can focus on preserving the landing system or the construction system.");
        puts("A.Preserve the landing system     B.Preserve the construction system");
        while (1)
        {
            char c;
            if (_kbhit())
            {
                c = _getch();
                if (c == 'A')
                {
                    puts("The AI focuses on preserving the landing system, and allows the construction system to decay.");
                    int x = rand() % 10 + 15;
                    construction -= x;
                }
                else if (c == 'B')
                {
                    puts("The AI focuses on preserving the construction system, and allows the landing system to decay.");
                    int x = rand() % 10 + 15;
                    landing -= x;
                }
            }
        }
    }
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
