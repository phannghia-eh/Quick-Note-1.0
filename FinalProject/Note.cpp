#include "stdafx.h"
#include "Note.h"


CNote::CNote()
{
}


CNote::~CNote()
{
}

std::wstring CNote::getData()
{
	return this->data;
}

std::string CNote::getTime()
{
	return this->time;
}

wstring CNote::getTag()
{
	return tag;
}

int CNote::getId()
{
	return this->id;
}

void CNote::setData(wstring data)
{
	this->data = data;
}

void CNote::setTime(string time)
{
	this->time = time;
}

void CNote::setId(int id)
{
	this->id = id;
}

void CNote::setTag(wstring tag)
{
	this->tag = tag;
}


