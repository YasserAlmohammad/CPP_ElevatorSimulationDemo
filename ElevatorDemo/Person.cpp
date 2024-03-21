// Person.cpp: implementation of the Person class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ElevatorDemo.h"
#include "Person.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int Person::count=0;

Person::Person(){
	++count;
	location=1;
	destination=2;
}



