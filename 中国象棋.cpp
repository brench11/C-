#include<graphics.h>
#define WIDTH 1800
#define HIGH 1080
int boardLine_x, boardLine_y;
void show();
void startup();
int reDis(int);//构建一个象棋的矩阵，根据矩阵中的位置返回在棋盘中的位置
int rePiece(int);
void showStar(int, int);
void searchPoint(int, int);
void updateWithInput();
void updateIstap();
void movePoint(int, int);
void cleanN1();
void remove(int, int);
int istap = 0;
int board[10][9]={
	2,2,2,2,2,2,2,2,2,
	0,0,0,0,0,0,0,0,0,
	0,2,0,0,0,0,0,0,0,
	2,0,2,0,2,0,2,0,2,
	0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,
	1,0,1,0,1,0,1,0,1,
	0,1,0,0,0,0,0,1,0,
	0,0,0,0,2,0,0,0,0,
	1,1,1,1,1,1,1,1,1
};
struct hongChe {
	int b_x, b_y;
	int m_x, m_y;
	int camp;
	int alife,inStack;
};
struct hongChe hongche[2];
struct hongMa {
	int b_x, b_y;
	int m_x, m_y; 
	int camp;
	int alife, inStack;
};
struct hongMa hongma[2];
struct hongXiang {
	int b_x, b_y;
	int m_x, m_y;
	int camp;
	int alife, inStack;
};
struct hongXiang hongxiang[2];
struct hongShi {
	int b_x, b_y;
	int m_x, m_y;
	int camp;
	int alife, inStack;
};
struct hongShi hongshi[2];
struct hongShuai {
	int b_x, b_y;
	int m_x, m_y;
	int camp;
	int alife, inStack;
};
struct hongShuai hongshuai;
struct hongPao {
	int b_x, b_y;
	int m_x, m_y;
	int camp;
	int alife, inStack;
};
struct hongPao hongpao[2];
struct hongBing {
	int b_x, b_y;
	int m_x, m_y;
	int camp;
	int alife, inStack;
};
struct hongBing hongbing[5];
struct heiChe {
	int b_x, b_y;
	int m_x, m_y;
	int camp;
	int alife, inStack;
};
struct heiChe heiche[2];
struct heiMa {
	int b_x, b_y;
	int m_x, m_y;
	int camp;
	int alife, inStack;
};
struct heiMa heima[2];
struct heiXiang {
	int b_x, b_y;
	int m_x, m_y;
	int camp;
	int alife, inStack;
};
struct heiXiang heixiang[2];
struct heiShi {
	int b_x, b_y;
	int m_x, m_y;
	int camp;
	int alife, inStack;
};
struct heiShi heishi[2];
struct heiJiang {
	int b_x, b_y;
	int m_x, m_y;
	int camp;
	int alife, inStack;
};
struct heiJiang heijiang;
struct heiPao {
	int b_x, b_y;
	int m_x, m_y;
	int camp;
	int alife, inStack;
};
struct heiPao heipao[2];
struct heiZu {
	int b_x, b_y;
	int m_x, m_y;
	int camp;
	int alife, inStack;
};
struct heiZu heizu[5];
IMAGE img_hongche,img_hongma,img_hongxiang,img_hongshi,img_hongshuai,img_hongpao,img_hongbing;
IMAGE img_heiche, img_heima, img_heixiang, img_heishi, img_heijiang, img_heipao, img_heizu;
IMAGE img_bk;
int main()
{
	initgraph(WIDTH, HIGH);
	
	startup();
	BeginBatchDraw();
	while (1)
	{
		setfillcolor(RGB(237, 145, 33));
		fillrectangle(0, 0, WIDTH, HIGH);
		//cleardevice();
		updateWithInput();
		updateIstap();
		show();
	}
	EndBatchDraw();
}
void cleanN1()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == -1 || board[i][j] == -2)
				board[i][j] = 0;
		}
	}
}
void remove(int a, int b)
{
	//红方
	if (hongshuai.m_x == a && hongshuai.m_y == b)
	{
		hongshuai.alife == 0;
	}

	//黑方
	for (int i = 0; i < 2; i++)
	{
		if (heiche[i].m_x == a && heiche[i].m_y == b)
		{
			heiche[i].alife = 0;
		}
	}
}
void showStar(int a, int b)
{
	//画8条线
	int lines = 15;
	a = reDis(a);
	b = reDis(b);
	setlinecolor(RGB(227, 23, 13));
	line(a - 5, b - 5, a - 5 - lines, b - 5);
	line(a - 5, b - 5, a - 5, b - 5 - lines);
	line(a + 5, b - 5, a + 5 + lines, b - 5);
	line(a + 5, b - 5, a + 5, b - 5 - lines);
	line(a - 5, b + 5, a - 5 - lines, b + 5);
	line(a - 5, b + 5, a - 5, b + 5 + lines);
	line(a + 5, b + 5, a + 5 + lines, b + 5);
	line(a + 5, b + 5, a + 5, b + lines + 5);

}
int rePiece(int a)
{
	return reDis(a) - 41;
}
int reDis(int a)
{
	return 75 + a * 97;
}
void updateIstap() //此函数仅做可能位置显示，不移动
{
	if (hongshuai.inStack == 1)
	{
		//帅在最下面，横坐标：3,4,5.纵坐标：9,8,7 
		if (hongshuai.m_x - 1 >= 3 && board[hongshuai.m_y][hongshuai.m_x - 1] == 0)
		{
			board[hongshuai.m_y][hongshuai.m_x - 1] = -1;
		}
		if (hongshuai.m_x + 1 <= 5 && board[hongshuai.m_y][hongshuai.m_x + 1] == 0)
		{
			board[hongshuai.m_y][hongshuai.m_x + 1] = -1;
		}
		if (hongshuai.m_y - 1 >= 7 && board[hongshuai.m_y - 1][hongshuai.m_x] == 0)
		{
			board[hongshuai.m_y - 1][hongshuai.m_x] = -1;
		}
		if (hongshuai.m_y + 1 <= 9 && board[hongshuai.m_y + 1][hongshuai.m_x] == 0)
		{
			board[hongshuai.m_y + 1][hongshuai.m_x] = -1;
		}
		if (hongshuai.m_x - 1 >= 3 && board[hongshuai.m_y][hongshuai.m_x - 1] == 2)
		{
			board[hongshuai.m_y][hongshuai.m_x - 1] = -2;
		}
		if (hongshuai.m_x + 1 <= 5 && board[hongshuai.m_y][hongshuai.m_x + 1] == 2)
		{
			board[hongshuai.m_y][hongshuai.m_x + 1] = -2;
		}
		if (hongshuai.m_y - 1 >= 7 && board[hongshuai.m_y - 1][hongshuai.m_x] == 2)
		{
			board[hongshuai.m_y - 1][hongshuai.m_x] = -2;
		}
		if (hongshuai.m_y + 1 <= 9 && board[hongshuai.m_y + 1][hongshuai.m_x] == 2)
		{
			board[hongshuai.m_y + 1][hongshuai.m_x] = -2;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		//左上，左下，右上，右下四个方向
		if (hongshi[i].inStack == 1)
		{
			//左上
			if (hongshi[i].m_x - 1 >= 3 && hongshi[i].m_y - 1 >= 7)
			{
				if (board[hongshi[i].m_y - 1][hongshi[i].m_x - 1] == 0)
				{
					board[hongshi[i].m_y - 1][hongshi[i].m_x - 1] = -1;
				}
				else if (board[hongshi[i].m_y - 1][hongshi[i].m_x - 1] == 2)
				{
					board[hongshi[i].m_y - 1][hongshi[i].m_x - 1] = -2;
				}
			}
			//右上
			if (hongshi[i].m_x + 1 <= 5 && hongshi[i].m_y - 1 >= 7)
			{
				if (board[hongshi[i].m_y - 1][hongshi[i].m_x + 1] == 0)
				{
					board[hongshi[i].m_y - 1][hongshi[i].m_x + 1] = -1;
				}
				else if (board[hongshi[i].m_y - 1][hongshi[i].m_x + 1] == 2)
				{
					board[hongshi[i].m_y - 1][hongshi[i].m_x + 1] = -2;
				}
			}
			//左下
			if (hongshi[i].m_x - 1 >= 3 && hongshi[i].m_y + 1 <= 9)
			{
				if (board[hongshi[i].m_y + 1][hongshi[i].m_x - 1] == 0)
				{
					board[hongshi[i].m_y + 1][hongshi[i].m_x - 1] = -1;
				}
				else if (board[hongshi[i].m_y + 1][hongshi[i].m_x - 1] == 2)
				{
					board[hongshi[i].m_y + 1][hongshi[i].m_x - 1] = -2;
				}
			}
			//右下
			if (hongshi[i].m_x + 1 <= 5 && hongshi[i].m_y + 1 <= 9)
			{
				if (board[hongshi[i].m_y + 1][hongshi[i].m_x + 1] == 0)
				{
					board[hongshi[i].m_y + 1][hongshi[i].m_x + 1] = -1;
				}
				else if (board[hongshi[i].m_y + 1][hongshi[i].m_x + 1] == 2)
				{
					board[hongshi[i].m_y + 1][hongshi[i].m_x + 1] = -2;
				}
			}
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (hongxiang[i].inStack == 1)
		{

		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (hongma[i].inStack == 1)
		{

		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (hongche[i].inStack == 1)
		{

		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (hongpao[i].inStack == 1)
		{

		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (hongbing[i].inStack == 1)
		{

		}
	}
	//
	if (heijiang.inStack == 1)
	{
		//将在最上面，横3,4,5，纵0,1,2,
		if (heijiang.m_x - 1 >= 3 && board[heijiang.m_y][heijiang.m_x - 1] == 0)
		{
			board[heijiang.m_y][heijiang.m_x - 1] = -1;
		}
		if (heijiang.m_x + 1 <= 5 && board[heijiang.m_y][heijiang.m_x + 1] == 0)
		{
			board[heijiang.m_y][heijiang.m_x + 1] = -1;
		}
		if (heijiang.m_y - 1 >= 0 && board[heijiang.m_y - 1][heijiang.m_x] == 0)
		{
			board[heijiang.m_y - 1][heijiang.m_x] = -1;
		}
		if (heijiang.m_y + 1 <= 2 && board[heijiang.m_y + 1][heijiang.m_x] == 0)
		{
			board[heijiang.m_y + 1][heijiang.m_x] = -1;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (heishi[i].inStack == 1)
		{
			if (heishi[i].m_x - 1 >= 3 && heishi[i].m_y - 1 >= 0)
			{
				if (board[heishi[i].m_y - 1][heishi[i].m_x - 1] == 0)
				{
					board[heishi[i].m_y - 1][heishi[i].m_x - 1];
				}
				else if (board[heishi[i].m_y - 1][heishi[i].m_x - 1] == 2)
				{
					board[heishi[i].m_y - 1][heishi[i].m_x - 1] = -2;
				}
			}
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (heixiang[i].inStack == 1)
		{

		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (heima[i].inStack == 1)
		{

		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (heiche[i].inStack == 1)
		{

		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (heipao[i].inStack == 1)
		{

		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (heizu[i].inStack == 1)
		{

		}
	}
}
void updateWithInput()
{
	MOUSEMSG m;
	if (MouseHit())
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (istap == 0) {
				searchPoint(m.x, m.y);
			}
			if (istap == 1) //此时已经选定了某一个棋子，如果点击了这个棋子有效的位置，棋子移动，否则本次选择取消
			{
				movePoint(m.x, m.y);
			}
		}
	}
}
void movePoint(int a, int b)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int s = (a - reDis(i)) * (a - reDis(i)) + (b - reDis(j)) * (b - reDis(j));
			if (s < 41 * 41)
			{
				if (board[j][i] == -1) //允许移动,有效位置
				{
					if (hongshuai.inStack == 1)
					{
						board[j][i] = 1;
						board[hongshuai.m_y][hongshuai.m_x] = 0;
						hongshuai.m_x = i;
						hongshuai.m_y = j;
						hongshuai.b_x = rePiece(hongshuai.m_x);
						hongshuai.b_y = rePiece(hongshuai.m_y);
						hongshuai.inStack = 0;
						istap = 0;
						cleanN1();
					}
					//红士
					for (int k = 0; k < 2; k++)
					{
						if (hongshi[k].inStack == 1)
						{
							board[j][i] = 1;
							board[hongshi[k].m_y][hongshi[k].m_x] = 0;
							hongshi[k].m_x = i;
							hongshi[k].m_y = j;
							hongshi[k].b_x = rePiece(hongshi[k].m_x);
							hongshi[k].b_y = rePiece(hongshi[k].m_y);
							hongshi[k].inStack = 0;
							istap = 0;
							cleanN1();
						}
					}
					
				}
				if (board[j][i] == -2)//吃子
				{
					if (hongshuai.inStack == 1)
					{
						board[j][i] = 1;
						//判断什么子被吃了
						remove(i, j);
						board[hongshuai.m_y][hongshuai.m_x] = 0;
						hongshuai.m_x = i;
						hongshuai.m_y = j;
						hongshuai.b_x = rePiece(hongshuai.m_x);
						hongshuai.b_y = rePiece(hongshuai.m_y);
						hongshuai.inStack = 0;
						istap = 0;
						cleanN1();
					}
					//红士
					for (int k = 0; k < 2; k++)
					{
						if (hongshi[k].inStack == 1)
						{
							board[j][i] = 1;
							remove(i, j);
							board[hongshi[k].m_y][hongshi[k].m_x] = 0;
							hongshi[k].m_x = i;
							hongshi[k].m_y = j;
							hongshi[k].b_x = rePiece(hongshi[k].m_x);
							hongshi[k].b_y = rePiece(hongshi[k].m_y);
							hongshi[k].inStack = 0;
							istap = 0;
							cleanN1();
						}
					}
				}
			}
		}
	}
}
void searchPoint(int a, int b)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int s = (a - reDis(i)) * (a - reDis(i)) + (b - reDis(j)) * (b - reDis(j));
			if (s < 41 * 41)
			{
				//判断哪一个棋子被点击了
				if (hongshuai.m_x == i && hongshuai.m_y == j)
				{
					hongshuai.inStack = 1;
					istap = 1;
				}
				for (int k = 0; k < 2; k++)
				{
					if (hongshi[k].m_x == i && hongshi[k].m_y == j && hongshi[k].alife == 1)
					{
						hongshi[k].inStack = 1;
						istap = 1;
					}
				}
				for (int k = 0; k < 2; k++)
				{
					if (hongxiang[k].m_x == i && hongxiang[k].m_y == j && hongxiang[k].alife == 1)
					{
						hongxiang[k].inStack = 1;
						istap = 1;
					}
				}
				for (int k = 0; k < 2; k++)
				{
					if (hongma[k].m_x == i && hongma[k].m_y == j && hongma[k].alife == 1)
					{
						hongma[k].inStack = 1;
						istap = 1;
					}
				}
				for (int k = 0; k < 2; k++)
				{
					if (hongche[k].m_x == i && hongche[k].m_y == j && hongche[k].alife == 1)
					{
						hongche[k].inStack = 1;
						istap = 1;
					}
				}
				for (int k = 0; k < 2; k++)
				{
					if (hongpao[k].m_x == i && hongpao[k].m_y == j && hongpao[k].alife == 1)
					{
						hongpao[k].inStack = 1;
						istap = 1;
					}
				}
				for (int k = 0; k < 5; k++)
				{
					if (hongbing[k].m_x == i && hongbing[k].m_y == j && hongbing[k].alife == 1)
					{
						hongbing[k].inStack = 1;
						istap = 1;
					}
				}
				//
				if (heijiang.m_x == i && heijiang.m_y == j && heijiang.alife == 1)
				{
					heijiang.inStack = 1;
					istap = 1;
				}
				for (int k = 0; k < 2; k++)
				{
					if (heishi[k].m_x == i && heishi[k].m_y == j && heishi[k].alife == 1)
					{
						heishi[k].inStack = 1;
						istap = 1;
					}
				}
				for (int k = 0; k < 2; k++)
				{
					if (heixiang[k].m_x == i && heixiang[k].m_y == j && heixiang[k].alife == 1)
					{
						heixiang[k].inStack = 1;
						istap = 1;
					}
				}
				for (int k = 0; k < 2; k++)
				{
					if (heima[k].m_x == i && heima[k].m_y == j && heima[k].alife == 1)
					{
						heima[k].inStack = 1;
						istap = 1;
					}
				}
				for (int k = 0; k < 2; k++)
				{
					if (heiche[k].m_x == i && heiche[k].m_y == j && heiche[k].alife == 1)
					{
						heiche[k].inStack = 1;
						istap = 1;
					}
				}
				for (int k = 0; k < 2; k++)
				{
					if (heipao[k].m_x == i && heipao[k].m_y == j && heipao[k].alife == 1)
					{
						heipao[k].inStack = 1;
						istap = 1;
					}
				}
				for (int k = 0; k < 5; k++)
				{
					if (heizu[k].m_x == i && heizu[k].m_y == j && heizu[k].alife == 1)
					{
						heizu[k].inStack = 1;
						istap = 1;
					}
				}
			}
		}
	}
}
void startup()
{
	boardLine_x = boardLine_y = 75;
	loadimage(&img_bk, _T("E:\\游戏入门素材\\背景.jpg"));
	loadimage(&img_hongche, _T("E:\\游戏入门素材\\红车1.jpg"));
	loadimage(&img_hongma, _T("E:\\游戏入门素材\\红马1.jpg"));
	loadimage(&img_hongxiang, _T("E:\\游戏入门素材\\红相1.jpg"));
	loadimage(&img_hongshi, _T("E:\\游戏入门素材\\红士1.jpg"));
	loadimage(&img_hongshuai, _T("E:\\游戏入门素材\\红帅1.jpg"));
	loadimage(&img_hongpao, _T("E:\\游戏入门素材\\红炮1.jpg"));
	loadimage(&img_hongbing, _T("E:\\游戏入门素材\\红兵1.jpg"));
	loadimage(&img_heiche, _T("E:\\游戏入门素材\\黑车1.jpg"));
	loadimage(&img_heima, _T("E:\\游戏入门素材\\黑马1.jpg"));
	loadimage(&img_heixiang, _T("E:\\游戏入门素材\\黑象1.jpg"));
	loadimage(&img_heishi, _T("E:\\游戏入门素材\\黑士1.jpg"));
	loadimage(&img_heijiang, _T("E:\\游戏入门素材\\黑将1.jpg"));
	loadimage(&img_heipao, _T("E:\\游戏入门素材\\黑炮1.jpg"));
	loadimage(&img_heizu, _T("E:\\游戏入门素材\\黑卒1.jpg"));

	//更新红方阵营数据
	//帅
	hongshuai.alife = hongshuai.camp = 1;
	hongshuai.m_x = 4;
	hongshuai.m_y = 9;
	hongshuai.b_x = rePiece(hongshuai.m_x);
	hongshuai.b_y = rePiece(hongshuai.m_y);
	hongshuai.inStack = 0;
	//士
	hongshi[0].alife = hongshi[1].alife = hongshi[0].camp = hongshi[1].camp = 1;
	hongshi[0].m_x = 3;
	hongshi[0].m_y = 9;
	hongshi[0].b_x = rePiece(hongshi[0].m_x);
	hongshi[0].b_y = rePiece(hongshi[0].m_y);
	hongshi[0].inStack = 0;

	hongshi[1].m_x = 5;
	hongshi[1].m_y = 9;
	hongshi[1].b_x = rePiece(hongshi[1].m_x);
	hongshi[1].b_y = rePiece(hongshi[1].m_y);
	hongshi[1].inStack = 0;
	//相
	hongxiang[0].alife = hongxiang[1].alife = hongxiang[0].camp = hongxiang[1].camp = 1;
	hongxiang[0].m_x = 2;
	hongxiang[0].m_y = 9;
	hongxiang[0].b_x = rePiece(hongxiang[0].m_x);
	hongxiang[0].b_y = rePiece(hongxiang[0].m_y);
	hongxiang[0].inStack = 0;

	hongxiang[1].m_x = 6;
	hongxiang[1].m_y = 9;
	hongxiang[1].b_x = rePiece(hongxiang[1].m_x);
	hongxiang[1].b_y = rePiece(hongxiang[1].m_y);
	hongxiang[1].inStack = 0;
	//马
	hongma[0].alife = hongma[1].alife = hongma[0].camp = hongma[1].camp = 1;
	hongma[0].m_x = 1;
	hongma[0].m_y = 9;
	hongma[0].b_x = rePiece(hongma[0].m_x);
	hongma[0].b_y = rePiece(hongma[0].m_y);
	hongma[0].inStack = 0;

	hongma[1].m_x = 7;
	hongma[1].m_y = 9;
	hongma[1].b_x = rePiece(hongma[1].m_x);
	hongma[1].b_y = rePiece(hongma[1].m_y);
	hongma[1].inStack = 0;
	//车
	hongche[0].alife = hongche[1].alife = hongche[0].camp = hongche[1].camp = 1;
	hongche[0].m_x = 0;
	hongche[0].m_y = 9;
	hongche[0].b_x = rePiece(hongche[0].m_x);
	hongche[0].b_y = rePiece(hongche[0].m_y);
	hongche[0].inStack = 0;

	hongche[1].m_x = 8;
	hongche[1].m_y = 9;
	hongche[1].b_x = rePiece(hongche[1].m_x);
	hongche[1].b_y = rePiece(hongche[1].m_y);
	hongche[1].inStack = 0;
	//炮
	hongpao[0].alife = hongpao[1].alife = hongpao[1].camp = hongpao[0].camp = 1;
	hongpao[0].m_x = 1;
	hongpao[0].m_y = 7;
	hongpao[0].b_x = rePiece(hongpao[0].m_x);
	hongpao[0].b_y = rePiece(hongpao[0].m_y);
	hongpao[0].inStack = 0;

	hongpao[1].m_x = 7;
	hongpao[1].m_y = 7;
	hongpao[1].b_x = rePiece(hongpao[1].m_x);
	hongpao[1].b_y = rePiece(hongpao[1].m_y);
	hongpao[1].inStack = 0;
	//兵
	for (int i = 0; i < 5; i ++)
	{
		hongbing[i].alife = hongbing[i].camp = 1;
		hongbing[i].m_x = i * 2;
		hongbing[i].m_y = 6;
		hongbing[i].b_x = rePiece(hongbing[i].m_x);
		hongbing[i].b_y = rePiece(hongbing[i].m_y);
		hongbing[i].inStack = 0;
	}
	//初始化黑方阵营数据
	//将
	heijiang.alife = 1;
	heijiang.camp = 2;
	heijiang.m_x = 4;
	heijiang.m_y = 0;
	heijiang.b_x = rePiece(heijiang.m_x);
	heijiang.b_y = rePiece(heijiang.m_y);
	heijiang.inStack = 0;
	//士
	heishi[0].alife = heishi[1].alife = 1;
	heishi[0].camp = heishi[1].camp = 2;
	heishi[0].m_x = 3;
	heishi[0].m_y = 0;
	heishi[0].b_x = rePiece(heishi[0].m_x);
	heishi[0].b_y = rePiece(heishi[0].m_y);
	heishi[0].inStack = 0;

	heishi[1].m_x = 5;
	heishi[1].m_y = 0;
	heishi[1].b_x = rePiece(heishi[1].m_x);
	heishi[1].b_y = rePiece(heishi[1].m_y);
	heishi[1].inStack = 0;
	//象
	heixiang[0].alife = heixiang[1].alife = 1;
	heixiang[0].camp = heixiang[1].camp = 2;
	heixiang[0].m_x = 2;
	heixiang[0].m_y = 0;
	heixiang[0].b_x = rePiece(heixiang[0].m_x);
	heixiang[0].b_y = rePiece(heixiang[0].m_y);
	heixiang[0].inStack = 0;

	heixiang[1].m_x = 6;
	heixiang[1].m_y = 0;
	heixiang[1].b_x = rePiece(heixiang[1].m_x);
	heixiang[1].b_y = rePiece(heixiang[1].m_y);
	heixiang[1].inStack = 0;
	//马
	heima[0].alife = heima[1].alife = 1;
	heima[0].camp = heima[1].camp = 2;
	heima[0].m_x = 1;
	heima[0].m_y = 0;
	heima[0].b_x = rePiece(heima[0].m_x);
	heima[0].b_y = rePiece(heima[0].m_y);
	heima[0].inStack = 0;

	heima[1].m_x = 7;
	heima[1].m_y = 0;
	heima[1].b_x = rePiece(heima[1].m_x);
	heima[1].b_y = rePiece(heima[1].m_y);
	heima[1].inStack = 0;
	//车
	heiche[0].alife = heiche[1].alife = 1;
	heiche[0].camp = heiche[1].camp = 2;
	heiche[0].m_x = 4;
	heiche[0].m_y = 8;
	heiche[0].b_x = rePiece(heiche[0].m_x);
	heiche[0].b_y = rePiece(heiche[0].m_y);
	heiche[0].inStack = 0;

	heiche[1].m_x = 8;
	heiche[1].m_y = 0;
	heiche[1].b_x = rePiece(heiche[1].m_x);
	heiche[1].b_y = rePiece(heiche[1].m_y);
	heiche[1].inStack = 0;
	//炮
	heipao[0].alife = heipao[1].alife = 1;
	heipao[0].camp = heipao[1].camp = 2;
	heipao[0].m_x = 1;
	heipao[0].m_y = 2;
	heipao[0].b_x = rePiece(heipao[0].m_x);
	heipao[0].b_y = rePiece(heipao[0].m_y);
	heipao[0].inStack = 0;

	heipao[1].m_x = 7;
	heipao[1].m_y = 2;
	heipao[1].b_x = rePiece(heipao[1].m_x);
	heipao[1].b_y = rePiece(heipao[1].m_y);
	heipao[1].inStack = 0;
	//卒
	for (int i = 0; i < 5; i ++)
	{
		heizu[i].alife = 1;
		heizu[i].camp = 2;
		heizu[i].m_x = i * 2;
		heizu[i].m_y = 3;
		heizu[i].b_x = rePiece(heizu[i].m_x);
		heizu[i].b_y = rePiece(heizu[i].m_y);
		heizu[i].inStack = 0;
	}
}

void show()
{
	int step = 97;
	setlinecolor(RED);
	for (int i = 0; i < 10; i++) //横着的
	{
		line(boardLine_x, boardLine_y + i * step, boardLine_x + 8 * step, boardLine_y + i * step);
	}
	for (int i = 0; i < 9; i++) //竖着的
	{
		if (i != 0 && i != 8) {
			line(boardLine_x + i * step, boardLine_y, boardLine_x + i * step, boardLine_y + 4 * step);
			line(boardLine_x + i * step, boardLine_y + 5 * step, boardLine_x + i * step, boardLine_y + 9 * step);
		}
		else {
			line(boardLine_x + i * step, boardLine_y, boardLine_x + i * step, boardLine_y + 9 * step);
		}
	}
	//绘制外边框
	line(boardLine_x - 8, boardLine_y - 8, boardLine_x + 8 * step + 8, boardLine_y - 8);
	line(boardLine_x - 8, boardLine_y + 8 + 9 * step, boardLine_x + 8 * step + 8, boardLine_y + 8 + 9 * step);
	line(boardLine_x - 8, boardLine_y - 8, boardLine_x - 8, boardLine_y + 8 + 9 * step);
	line(boardLine_x + 8 * step + 8, boardLine_y - 8, boardLine_x + 8 * step + 8, boardLine_y + 8 + 9 * step);
	//绘制斜线
	line(reDis(3), reDis(0), reDis(5), reDis(2));
	line(reDis(3), reDis(0) + 7 * step, reDis(5), reDis(2) + 7 * step);
	line(reDis(5), reDis(0), reDis(3), reDis(2));
	line(reDis(5), reDis(0) + 7 * step, reDis(3), reDis(2) + 7 * step);
	//画星星
	showStar(2, 3);
	showStar(4, 3);
	showStar(6, 3);
	showStar(2, 6);
	showStar(4, 6);
	showStar(6, 6);
	showStar(1, 2);
	showStar(1, 7);
	showStar(7, 2);
	showStar(7, 7);
	int lines = 15;
	line(reDis(0) + 5, reDis(3) - 5, reDis(0) + 5 + lines, reDis(3) - 5);
	line(reDis(0) + 5, reDis(3) - 5, reDis(0) + 5, reDis(3) - 5 - lines);
	line(reDis(0) + 5, reDis(3) + 5, reDis(0) + 5 + lines, reDis(3) + 5);
	line(reDis(0) + 5, reDis(3) + 5, reDis(0) + 5, reDis(3) + lines + 5);

	line(reDis(0) + 5, reDis(6) - 5, reDis(0) + 5 + lines, reDis(6) - 5);
	line(reDis(0) + 5, reDis(6) - 5, reDis(0) + 5, reDis(6) - 5 - lines);
	line(reDis(0) + 5, reDis(6) + 5, reDis(0) + 5 + lines, reDis(6) + 5);
	line(reDis(0) + 5, reDis(6) + 5, reDis(0) + 5, reDis(6) + lines + 5);

	line(reDis(8) - 5, reDis(3) - 5, reDis(8) - 5 - lines, reDis(3) - 5);
	line(reDis(8) - 5, reDis(3) - 5, reDis(8) - 5, reDis(3) - 5 - lines);
	line(reDis(8) - 5, reDis(3) + 5, reDis(8) - 5 - lines, reDis(3) + 5);
	line(reDis(8) - 5, reDis(3) + 5, reDis(8) - 5, reDis(3) + 5 + lines);

	line(reDis(8) - 5, reDis(6) - 5, reDis(8) - 5 - lines, reDis(6) - 5);
	line(reDis(8) - 5, reDis(6) - 5, reDis(8) - 5, reDis(6) - 5 - lines);
	line(reDis(8) - 5, reDis(6) + 5, reDis(8) - 5 - lines, reDis(6) + 5);
	line(reDis(8) - 5, reDis(6) + 5, reDis(8) - 5, reDis(6) + 5 + lines);

	
	//显示红方场上存活的棋子
	//帅
	if (hongshuai.alife == 1)
	{
		putimage(hongshuai.b_x, hongshuai.b_y, &img_bk, NOTSRCERASE);
		putimage(hongshuai.b_x, hongshuai.b_y, &img_hongshuai, SRCINVERT);
	}
	//士
	for (int i = 0; i < 2; i++)
	{
		if (hongshi[i].alife == 1)
		{
			putimage(hongshi[i].b_x, hongshi[i].b_y, &img_bk, NOTSRCERASE);
			putimage(hongshi[i].b_x, hongshi[i].b_y, &img_hongshi, SRCINVERT);
		}
	}
	//象
	for (int i = 0; i < 2; i++)
	{
		if (hongxiang[i].alife == 1)
		{
			putimage(hongxiang[i].b_x, hongxiang[i].b_y, &img_bk, NOTSRCERASE);
			putimage(hongxiang[i].b_x, hongxiang[i].b_y, &img_hongxiang, SRCINVERT);
		}
	}
	//马
	for (int i = 0; i < 2; i++)
	{
		if (hongma[i].alife == 1)
		{
			putimage(hongma[i].b_x, hongma[i].b_y, &img_bk, NOTSRCERASE);
			putimage(hongma[i].b_x, hongma[i].b_y, &img_hongma, SRCINVERT);
		}
	}
	//车
	for (int i = 0; i < 2; i++)
	{
		if (hongche[i].alife == 1)
		{
			putimage(hongche[i].b_x, hongche[i].b_y, &img_bk, NOTSRCERASE);
			putimage(hongche[i].b_x, hongche[i].b_y, &img_hongche, SRCINVERT);
		}
	}
	//炮
	for (int i = 0; i < 2; i++)
	{
		if (hongpao[i].alife == 1)
		{
			putimage(hongpao[i].b_x, hongpao[i].b_y, &img_bk, NOTSRCERASE);
			putimage(hongpao[i].b_x, hongpao[i].b_y, &img_hongpao, SRCINVERT);
		}
	}
	//兵
	for (int i = 0; i < 5; i++)
	{
		if (hongbing[i].alife == 1)
		{
			putimage(hongbing[i].b_x, hongbing[i].b_y, &img_bk, NOTSRCERASE);
			putimage(hongbing[i].b_x, hongbing[i].b_y, &img_hongbing, SRCINVERT);
		}
	}
	//显示黑方存活棋子
	//将
	if (heijiang.alife == 1)
	{
		putimage(heijiang.b_x, heijiang.b_y, &img_bk, NOTSRCERASE);
		putimage(heijiang.b_x, heijiang.b_y, &img_heijiang, SRCINVERT);
	}
	//士
	for (int i = 0; i < 2; i++)
	{
		if (heishi[i].alife == 1)
		{
			putimage(heishi[i].b_x, heishi[i].b_y, &img_bk, NOTSRCERASE);
			putimage(heishi[i].b_x, heishi[i].b_y, &img_heishi, SRCINVERT);
		}
	}
	//象
	for (int i = 0; i < 2; i++)
	{
		if (heixiang[i].alife == 1)
		{
			putimage(heixiang[i].b_x, heixiang[i].b_y, &img_bk, NOTSRCERASE);
			putimage(heixiang[i].b_x, heixiang[i].b_y, &img_heixiang, SRCINVERT);
		}
	}
	//马
	for (int i = 0; i < 2; i++)
	{
		if (heima[i].alife == 1)
		{
			putimage(heima[i].b_x, heima[i].b_y, &img_bk, NOTSRCERASE);
			putimage(heima[i].b_x, heima[i].b_y, &img_heima, SRCINVERT);
		}
	}
	//车
	for (int i = 0; i < 2; i++)
	{
		if (heiche[i].alife == 1)
		{
			putimage(heiche[i].b_x, heiche[i].b_y, &img_bk, NOTSRCERASE);
			putimage(heiche[i].b_x, heiche[i].b_y, &img_heiche, SRCINVERT);
		}
	}
	//炮
	for (int i = 0; i < 2; i++)
	{
		if (heipao[i].alife == 1)
		{
			putimage(heipao[i].b_x, heipao[i].b_y, &img_bk, NOTSRCERASE);
			putimage(heipao[i].b_x, heipao[i].b_y, &img_heipao, SRCINVERT);
		}
	}
	//卒
	for (int i = 0; i < 5; i++)
	{
		if (heizu[i].alife == 1)
		{
			putimage(heizu[i].b_x, heizu[i].b_y, &img_bk, NOTSRCERASE);
			putimage(heizu[i].b_x, heizu[i].b_y, &img_heizu, SRCINVERT);
		}
	}
	//显示棋盘待定落子方框
	if (istap == 1)
	{
		int y = reDis(5);
		int x = reDis(5);
		int k = 12;
		setlinecolor(BLUE);
		line(x - k, y - k, x + k, y - k);
		line(x + k, y - k, x + k, y + k);
		line(x + k, y + k, x - k, y + k);
		line(x - k, y + k, x - k, y - k);
	}
	static int speed = 0;
	static int k = 10;
	static int flag1 = 0;
	if (speed < 100) speed++;
	if (speed == 50)
	{
		speed = 0;
		if (k >= 12)
			flag1 = 1;
		if (k <= 10)
			flag1 = 0;

		if (flag1 == 0)
			k++;
		else
			k--;
	}
	if (istap == 1)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == -1)
				{
					int y = reDis(i);
					int x = reDis(j);
					setlinecolor(BLUE);
					line(x - k, y - k, x + k, y - k);
					line(x + k, y - k, x + k, y + k);
					line(x + k, y + k, x - k, y + k);
					line(x - k, y + k, x - k, y - k);
				}
				if (board[i][j] == -2)
				{
					int y = reDis(i);
					int x = reDis(j);
					setcolor(BLUE);
					circle(x, y,k);
				}
			}
		}
	}
	
	FlushBatchDraw();
	Sleep(3);
}
