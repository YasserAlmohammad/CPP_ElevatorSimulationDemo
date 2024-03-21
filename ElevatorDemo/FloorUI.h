// FloorUI.h: interface for the FloorUI class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Floor.h"

#if !defined(AFX_FLOORUI_H__ED092426_03D6_44F2_974D_F0B2CEF33DF0__INCLUDED_)
#define AFX_FLOORUI_H__ED092426_03D6_44F2_974D_F0B2CEF33DF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class FloorUI  
{
public:
	FloorUI();
	virtual ~FloorUI();

	static int getWidth(){ return width;}

	static void setHeight(int h);
	static int getHeight(){ return height;}

	void setPos(int x,int y);
	CPoint getPos(){return pos;}
	CPoint getHolePos(){return elevatorHolePos;}
	void setFloor(Floor* f){ floor=f;}

	void draw(CDC* dc);
	

private:
	CPoint pos;

	CPoint personsPos; //from where we draw persons
	CPoint elevatorHolePos; 

	static int width;
	static int elevatorHoleWidth;
	static int personSpaceWidth;
	static int height;

	int persons_num;
	//bool* persons;
	Floor* floor;


};

#endif // !defined(AFX_FLOORUI_H__ED092426_03D6_44F2_974D_F0B2CEF33DF0__INCLUDED_)
