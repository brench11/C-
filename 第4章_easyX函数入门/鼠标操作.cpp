#include<graphics.h>
#include<conio.h>
int key=0;
int main()
{
	initgraph(640, 480);
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		
		if (m.uMsg == WM_MOUSEMOVE && key == 1)
		{
			putpixel(m.x, m.y, WHITE);
		}
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			rectangle(m.x - 5, m.y - 5, m.x + 5, m.y + 5);
			key = 1;
		}
		if (m.uMsg == WM_LBUTTONUP)
		{
			key = 0;
		}
		if (m.uMsg == WM_RBUTTONUP)
		{
			circle(m.x, m.y, 10);
		}
	}
	return 0;
}
