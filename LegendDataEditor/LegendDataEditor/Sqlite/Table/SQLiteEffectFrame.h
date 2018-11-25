﻿#ifndef _SQLITE_EFFECT_FRAME
#define _SQLITE_EFFECT_FRAME

#include "SQLiteTable.h"

class EffectFrameData : public SQLiteTableData
{
public:
	static string COL_ID;
	static string COL_LABEL;
	static string COL_DIRECTION;
	static string COL_ACTION;
	static string COL_FRAME_COUNT;
	static string COL_POSX;
	static string COL_POSY;
	int mID;
	string mLabel;
	int mDirection;
	string mAction;
	int mFrameCount;
	txVector<int> mPosX;
	txVector<int> mPosY;
public:
	virtual void parse(SQLiteDataReader* reader, SQLiteTable* table)
	{
		mID = reader->getInt(table->getCol(COL_ID));
		mLabel = reader->getString(table->getCol(COL_LABEL));
		mDirection = reader->getInt(table->getCol(COL_DIRECTION));
		mAction = reader->getString(table->getCol(COL_ACTION));
		mFrameCount = reader->getInt(table->getCol(COL_FRAME_COUNT));
		StringUtility::stringToIntArray(reader->getString(table->getCol(COL_POSX)), mPosX);
		StringUtility::stringToIntArray(reader->getString(table->getCol(COL_POSY)), mPosY);
	}
	static void registeColumn(SQLiteTable* table)
	{
		table->registeColumn(COL_ID);
		table->registeColumn(COL_LABEL);
		table->registeColumn(COL_DIRECTION);
		table->registeColumn(COL_ACTION);
		table->registeColumn(COL_FRAME_COUNT);
		table->registeColumn(COL_POSX);
		table->registeColumn(COL_POSY);
	}
};

class SQLiteEffectFrame : SQLiteTable
{
public:
	SQLiteEffectFrame(SQLite* sqlite)
		:SQLiteTable("EffectFrame", sqlite)
	{
		EffectFrameData::registeColumn(this);
	}
	void query(int ID, txVector<EffectFrameData>& dataList);
	void query(int ID, int direction, txVector<EffectFrameData>& dataList);
	void query(int ID, int direction, const string& action, txVector<EffectFrameData>& dataList);
	bool updateData(const EffectFrameData& data);
	bool insert(const EffectFrameData& data);
};

#endif