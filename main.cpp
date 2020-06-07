#include "PhoneBookTest.h"
#include "DataBase.h"






GUI_APP_MAIN{
	DataBase_Init(true);
	MainWindowDlg().Run();
}