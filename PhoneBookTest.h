#ifndef _PhoneBookTest_PhoneBookTest_h_
#define _PhoneBookTest_PhoneBookTest_h_
#include <plugin/sqlite3/Sqlite3.h>
#include <CtrlLib/CtrlLib.h>
#include <GridCtrl/GridCtrl.h>
#include <Sql/Sql.h>
#include "DataBase.h"

using namespace Upp;
#define LAYOUTFILE <PhoneBookTest/PhoneBookTest.lay>
#include <CtrlCore/lay.h>
#include "DataBaseSchema.h"

#define IMAGECLASS PhoneIconsImg
#define IMAGEFILE <PhoneBookTest/PhoneIcons.iml>
#include <Draw/iml_header.h>

class AppConfig {
	public:
	String sqlite3_filename;
};

class MainWindowDlg : public WithMainWindowLayout<TopWindow> {
	typedef MainWindowDlg CLASSNAME;

public:
	EditString editname;
	EditString editphone;
	EditInt editage;
	MainWindowDlg();
	void TabloSetup();
	void LoadTablo();
	void UpdateTablo();
	void InsertTablo();
	void RemoveTablo();
};


extern AppConfig CFG;
#endif
