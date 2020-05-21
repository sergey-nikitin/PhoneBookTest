#ifndef flagPGSQL_DB
#else
#define AUTO_INCREMENT
#endif

#ifdef flagMYSQL_DB
#undef TABLE_
#define TABLE_(x)     DOID(x) TABLE(x) \
     TABLE_SUFFIX("CHARACTER SET utf8 COLLATE utf8_general_ci\n")
#endif
#define SERIAL_ INT_




//==========================================================================================//
//                                                                                          //
//                                          USERS                                           //
//                                                                                          //
//==========================================================================================//
TABLE_ ( USERS )
	SERIAL_ ( USR_ID ) PRIMARY_KEY AUTO_INCREMENT
	STRING_ ( USR_NAME, 250 )
	STRING_ ( USR_REALNAME, 250 )
	STRING_ ( USR_LOGINNAME, 250 ) INDEX
	STRING_ ( USR_PASSWORD, 250 )
	STRING_ ( USR_ROLE, 250 )
	STRING_ ( USR_PLOSHADKI, 250 )
	BLOB_   ( USR_RIGHTS )
END_TABLE


//=================================--- *** ---==============================================//
