#include "PhoneBookTest.h"
#include "GameWindow.h"



void ImageCtrlMy::Paint(Draw& w){
	static int t=0;
	Size sz = GetSize();
	int sw = sz.cx;
	int sh = sz.cy;
	w.DrawRect(0,0,100,100,Green());
	w.DrawRect(sw-100,sh-100,100,100,Red());
	Image im = PhoneIconsImg::GameIcon();
	Size szim = im.GetSize();
	w.DrawImage(0+t,sh-szim.cy-t,im);
	t++;
}




GameWindow::GameWindow()
{
	CtrlLayout(*this, "Окно игра");
	Sizeable().Zoomable();
	image.SetImage(PhoneIconsImg::GameIcon());
	SetTimeCallback(-10,THISBACK(UpdateWindow));
}

void GameWindow::UpdateWindow(){
	Refresh();
}



