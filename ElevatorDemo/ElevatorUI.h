// ElevatorUI.h: interface for the ElevatorUI class.
//
//////////////////////////////////////////////////////////////////////

#include "Elevator.h"
#include "stdafx.h"

#if !defined(AFX_ELEVATORUI_H__DBCDD3D1_1491_4E1B_9693_7AB3C35F4295__INCLUDED_)
#define AFX_ELEVATORUI_H__DBCDD3D1_1491_4E1B_9693_7AB3C35F4295__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ElevatorUI  
{
public:
	ElevatorUI();
	virtual ~ElevatorUI();

	static int getWidth(){ return width;}

	static void setHeight(int h);
	static int getHeight(){ return height;}

	void setPos(int x,int y);
	void setElevator(Elevator* e){ elevator=e;}

	void draw(CDC* dc);
private:
	static int width;
	static int height;
	CPoint pos;
	int persons_num;
	Elevator* elevator;

};

#endif // !defined(AFX_ELEVATORUI_H__DBCDD3D1_1491_4E1B_9693_7AB3C35F4295__INCLUDED_)
