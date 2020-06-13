#ifndef _PhoneBookTest_GameWindow_h_
#define _PhoneBookTest_GameWindow_h_
#include <GridCtrl/GridCtrl.h>

class ImageCtrlMy : public ImageCtrl {
	typedef ImageCtrlMy CLASSNAME;

public:
	virtual void   Paint(Draw& w);
};


#define LAYOUTFILE <PhoneBookTest/GameWindow.lay>
#include <CtrlCore/lay.h>

class GameWindow : public WithGameWindowLayout<TopWindow> {
	typedef GameWindow CLASSNAME;

public:
	GameWindow();
	void UpdateWindow();
};



#endif
