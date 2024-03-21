// Schedule.h: interface for the Schedule class.
//
//////////////////////////////////////////////////////////////////////

#include "Elevator.h"
#include "Floor.h"
#include "Reporter.h"

#if !defined(AFX_SCHEDULE_H__4071CAFE_1EE4_4FA7_A8B9_E5562C6A9B43__INCLUDED_)
#define AFX_SCHEDULE_H__4071CAFE_1EE4_4FA7_A8B9_E5562C6A9B43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Schedule{
public:
	Schedule(Floor**,Elevator*,Reporter*);
	virtual ~Schedule();
	
	void elevator_increment_time();
	
	void elevator_pooling();

	void floor_generate_person();
	

	void notify_reporter();
private:
	Floor** floors;
	Elevator* elevator;
	Reporter* reporter;

};

#endif // !defined(AFX_SCHEDULE_H__4071CAFE_1EE4_4FA7_A8B9_E5562C6A9B43__INCLUDED_)
