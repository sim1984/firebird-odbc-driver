/*
 *  
 *     The contents of this file are subject to the Initial 
 *     Developer's Public License Version 1.0 (the "License"); 
 *     you may not use this file except in compliance with the 
 *     License. You may obtain a copy of the License at 
 *     http://www.ibphoenix.com/main.nfs?a=ibphoenix&page=ibp_idpl.
 *
 *     Software distributed under the License is distributed on 
 *     an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either 
 *     express or implied.  See the License for the specific 
 *     language governing rights and limitations under the License.
 *
 *
 *  The Original Code was created by James A. Starkey for IBPhoenix.
 *
 *  Copyright (c) 1999, 2000, 2001 James A. Starkey
 *  All Rights Reserved.
 */

// IscStatementMetaData.h: interface for the IscStatementMetaData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_ISCSTATEMENTMETADATA_H_)
#define _ISCSTATEMENTMETADATA_H_

#include "Connection.h"

namespace IscDbcLibrary {

class Sqlda;
class IscConnection;

class IscStatementMetaData : public StatementMetaData  
{
public:
	virtual int objectVersion() override;
	virtual bool isNullable (int index) override;
	virtual int getScale (int index) override;
	virtual int getPrecision (int index) override;
	virtual int getNumPrecRadix (int index) override;
	virtual int getColumnType (int index, int &realSqlType) override;
	virtual int getColumnCount() override;
	virtual int getOctetLength(int index) override;
	virtual int getColumnDisplaySize(int index) override;
	virtual const char* getColumnLabel(int index) override;
	virtual const char* getSqlTypeName(int index) override;
	virtual const char* getColumnName(int index) override;
	virtual const char* getTableName(int index) override;
	virtual const char* getColumnTypeName(int index) override;
	virtual bool isSigned (int index) override;
	virtual bool isReadOnly (int index) override;
	virtual bool isWritable (int index) override;
	virtual bool isDefinitelyWritable (int index) override;
	virtual bool isCurrency (int index) override;
	virtual bool isCaseSensitive (int index) override;
	virtual bool isAutoIncrement (int index) override;
	virtual bool isSearchable (int index) override;
	virtual int	 isBlobOrArray(int index) override;
	virtual bool isColumnPrimaryKey(int index) override;
	virtual const char*	getSchemaName (int index) override;
	virtual const char*	getCatalogName (int index) override;
	virtual void getSqlData(int index, Blob *& ptDataBlob, HeadSqlVar *& ptHeadSqlVar) override;
	virtual void createBlobDataTransfer(int index, Blob *& ptDataBlob) override;
	virtual WCSTOMBS getAdressWcsToMbs( int index ) override;
	virtual MBSTOWCS getAdressMbsToWcs( int index ) override;

	IscStatementMetaData(IscStatement *stmt, Sqlda *ptSqlda);

	IscStatement	*statement;
	Sqlda			*sqlda;
};

}; // end namespace IscDbcLibrary

#endif // !defined(_ISCSTATEMENTMETADATA_H_)
