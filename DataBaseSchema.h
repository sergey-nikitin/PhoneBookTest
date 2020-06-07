#ifndef _PhoneBookTest_DataBaseSchema_h_
#define _PhoneBookTest_DataBaseSchema_h_



#ifdef flagSQLITE3_DB
#include <plugin/sqlite3/Sqlite3.h>
#define SCHEMADIALECT <plugin/sqlite3/Sqlite3Schema.h>
#endif

#ifdef flagMYSQL_DB
#include <MySql/MySql.h>
#define SCHEMADIALECT <MySql/MySqlSchema.h>
#endif

#ifdef flagPGSQL_DB
#include <PostgreSQL/PostgreSQL.h>
#define SCHEMADIALECT <PostgreSQL/PostgreSQLSchema.h>
#endif

//===================================================//

#define MODEL <PhoneBookTest/DataBase.sch>
#include "Sql/sch_header.h"


#endif
