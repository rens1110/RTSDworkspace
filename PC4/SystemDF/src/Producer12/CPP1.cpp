/**
 * Source file for the CPP1 model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "Producer12/CPP1.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace MainModel { namespace Producer12 { namespace CPP1 { 

CPP1::CPP1(int &anotherValue, int &someValue) :
    CodeBlock(), anotherValue(anotherValue), someValue(someValue){
  SETNAME(this, "CPP1");

  // protected region constructor on begin
  // protected region constructor end
}

CPP1::~CPP1()
{
  // protected region destructor on begin
  // protected region destructor end
}

void CPP1::execute()
{
  // protected region execute code on begin
	someValue = rand() % 100;
	printf("CPP1 set someValue to %d \n",someValue);
	anotherValue = rand() % 100;
	printf("CPP1 set anotherValue to %d \n",anotherValue);
  // protected region execute code end
}

// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} } } 