/**
 * Source file for the CPPout3 model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "Consumer3/CPPout3.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace MainModel { namespace Consumer3 { namespace CPPout3 { 

CPPout3::CPPout3() :
    CodeBlock(){
  SETNAME(this, "CPPout3");

  // protected region constructor on begin
  // protected region constructor end
}

CPPout3::~CPPout3()
{
  // protected region destructor on begin
  // protected region destructor end
}

void CPPout3::execute()
{
  // protected region execute code on begin
	if(VarIn==1)
	{
		printf("Consumer 3 \n");
	}
  // protected region execute code end
}

// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} } } 
