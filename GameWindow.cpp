#include "PhoneBookTest.h"
#include "GameWindow.h"



void ImageCtrlMy::Paint(Draw& w){
	static int p=0;
	Size sz = GetSize();
	int sw = sz.cx;
	int sh = sz.cy;
	w.DrawRect(0,0,100,100,Green());
	w.DrawRect(sw-100,sh-100,100,100,Red());
	Image im;
	
	if ((p/4)%2==0){
		im = PhoneIconsImg::Man1();
	}else {
		im = PhoneIconsImg::Man2();
	}
	if (v>0){
		im=MirrorHorz(im);
	}
	Size szim = im.GetSize();
	w.DrawImage(0+p,sh-szim.cy,im);
	w.DrawText(120,120,"v="+AsString(v));
	w.DrawText(100,100,"p="+AsString(p));
	p=p+v;
	if (p<0){
		p=0;v=0;
	}
	if (p>(sw-szim.cx)){
	    p=(sw-szim.cx);v=0;
	}

}
void ImageCtrlMy::TurnRight(){
	v=1;
}
void ImageCtrlMy::TurnLeft(){
	v=-1;
}

bool GameWindow::Key(dword key, int count){
	DUMP((int)K_LEFT);
	DUMP((int)key);
	if (key == K_LEFT) {
		TurnLeft();
		return false;
	} else if (key == K_RIGHT) {
		TurnRight();
		return false;
	}
	return TopWindow::Key(key, count);
}


GameWindow::GameWindow()
{
	CtrlLayout(*this, "Окно игра");
	Sizeable().Zoomable();
	image.SetImage(PhoneIconsImg::GameIcon());
	SetTimeCallback(-20,THISBACK(UpdateWindow));
	btnright.WhenPush=THISBACK(TurnRight);
	btnleft.WhenPush=THISBACK(TurnLeft);
}

void GameWindow::UpdateWindow(){
	Refresh();
	
}

void GameWindow::TurnRight(){
	image.TurnRight();
}
void GameWindow::TurnLeft(){
	image.TurnLeft();
}



