// Floor.h: interface for the Floor class.
//
//////////////////////////////////////////////////////////////////////

#include "Person.h"
#include "Reporter.h"

#if !defined(AFX_FLOOR_H__5A99D8FC_37CA_48C9_89A0_4A29CFA70207__INCLUDED_)
#define AFX_FLOOR_H__5A99D8FC_37CA_48C9_89A0_4A29CFA70207__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class Floor{
public:
	Floor(Reporter*);
	virtual ~Floor();
	static int count;
	int get_id(); //only getter

	int get_persons_num();
	bool add_person(Person*); //can't exceede MAX number
	Person* remove_person(); //when he gets in elevator
	
	Person** waiting_persons; //we need access from elevator

	bool light_is_on();
	void switch_light();

	bool button_is_pressed();
	void set_button_pressed(bool);

	CString toString();
	static int MAX_FLOOR_PERSONS;
	static int TOTAL_FLOOR_NUM;
	void reset();
	

private:
	int ID;
	int persons_num;
	bool light_on;
	bool button_pressed;  //true if the floor holds people
	Reporter* reporter;


};


#endif // !defined(AFX_FLOOR_H__5A99D8FC_37CA_48C9_89A0_4A29CFA70207__INCLUDED_)
