#ifndef _PhoneBookTest_PhoneBookTest_h_
#define _PhoneBookTest_PhoneBookTest_h_
#include <plugin/sqlite3/Sqlite3.h>
#include <CtrlLib/CtrlLib.h>

#define LAYOUTFILE <PhoneBookTest/PhoneBookTest.lay>
#include <CtrlCore/lay.h>

using namespace Upp;

class AppConfig {
	public:
	String sqlite3_filename;
};

class MainWindowDlg : public WithMainWindowLayout<TopWindow> {
	typedef MainWindowDlg CLASSNAME;

public:
	MainWindowDlg();
};


extern AppConfig CFG;
#endif
