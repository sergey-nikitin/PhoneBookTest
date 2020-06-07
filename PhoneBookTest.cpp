#include "PhoneBookTest.h"

AppConfig CFG;

MainWindowDlg::MainWindowDlg()
{
	CtrlLayout(*this, "НАША ПЕРВАЯ ДЫРА");
	Zoomable().Sizeable();
	MaximizeBox();
	Maximize();
	TabloSetup();
	//tablo.WhenChangeRow = THISBACK(UpdateTablo);
	tablo.WhenInsertRow = THISBACK(InsertTablo);
	tablo.WhenUpdateRow = THISBACK(UpdateTablo);
	
	tablo.RejectNullRow();
	LoadTablo();
}

void MainWindowDlg::TabloSetup(){
	tablo.AddIndex(USR_ID);
	tablo.AddColumn(USR_NAME,"Name",200).Edit(editname);
	tablo.AddColumn(USR_PHONE,"Tilifon",200).Edit(editphone);
	tablo.AddColumn(USR_AGE,"Vozrast",60).Edit(editage);
	tablo.Editing();
	tablo.Inserting();
	tablo.Removing();
}
void MainWindowDlg::LoadTablo(){
	SQL * Select(SqlAll()).From(USERS);
	while (SQL.Fetch()){
		tablo.Add();
		
		tablo(USR_ID) = SQL[USR_ID];
		tablo(USR_PHONE) = SQL[USR_PHONE];
		tablo(USR_NAME) = SQL[USR_NAME];
		tablo(USR_AGE) = SQL[USR_AGE];
	}
}

void MainWindowDlg::UpdateTablo(){
	PromptOK("UpdateTablo()");
	SQL * SqlUpdate(USERS)(USR_PHONE,tablo(USR_PHONE))
		(USR_NAME,tablo(USR_NAME))
		(USR_AGE,tablo(USR_AGE))
		.Where(USR_ID == tablo(USR_ID));
}

void MainWindowDlg::InsertTablo(){
	PromptOK("Инсерт табло()");
	SQL * SqlInsert(USERS)(USR_PHONE,tablo(USR_PHONE))
		(USR_NAME,tablo(USR_NAME))
		(USR_AGE,tablo(USR_AGE));
}