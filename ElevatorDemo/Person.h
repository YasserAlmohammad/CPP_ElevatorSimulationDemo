// Person.h: interface for the Person class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PERSON_H__17A090E2_0F07_49D0_8EAD_182F2385B2C0__INCLUDED_)
#define AFX_PERSON_H__17A090E2_0F07_49D0_8EAD_182F2385B2C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Person{
public:
	Person();
	virtual ~Person(){--count;}

	static int count;
	
	int getDestination(){return destination;}
	void setDestination(int d){ destination=d;}
	
	int getLocation(){return location;}
	void setLocation(int l){location=l;}

	

private:

	int destination;
	int location; //0 for elevator, floor_id else

};

#endif // !defined(AFX_PERSON_H__17A090E2_0F07_49D0_8EAD_182F2385B2C0__INCLUDED_)
