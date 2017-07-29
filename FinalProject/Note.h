#pragma once
#ifndef NOTE_H
#define NOTE_H


#include <string>
#include <list>

using namespace std;

struct Note {
	wstring data;
	wstring tag;
	string time;
	int id;
};

class CNote
{
private:
	wstring data;
	wstring tag;
	string time;
	int id;
public:
	CNote();
	~CNote();

	wstring getData();
	string getTime();
	wstring getTag();
	int getId();

	void setData(wstring data);
	void setTime(string time);
	void setId(int id);
	void setTag(wstring tag);
};

#endif