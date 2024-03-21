// PersonUI.h: interface for the PersonUI class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Person.h"

#if !defined(AFX_PERSONUI_H__86006C9F_9711_4667_9DF7_25C796D6D4E0__INCLUDED_)
#define AFX_PERSONUI_H__86006C9F_9711_4667_9DF7_25C796D6D4E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PersonUI  
{
public:
	PersonUI(int x,int y);
	virtual ~PersonUI();
	void setPos(int x,int y);

	void draw(CDC* dc,Person*);

	static void setHeight(int h);
	static int getHeight(){ return height;}
	static int getWidth(){ return width;}

private:
	static int width;
	static int height;
	CPoint pos;
};

#endif // !defined(AFX_PERSONUI_H__86006C9F_9711_4667_9DF7_25C796D6D4E0__INCLUDED_)
