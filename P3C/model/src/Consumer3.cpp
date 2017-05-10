/**
 * Source file for the Consumer3 model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "Consumer3.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace MainModel { namespace Consumer3 { 

Consumer3::Consumer3(ChannelOut<int> *C) :
    Sequential(NULL)
{
  SETNAME(this, "Consumer3");

  // Initialize model objects
  myC3_R_C = new Reader<int>(&VarIn, C);
  SETNAME(myC3_R_C, "C3_R_C");
  myCPPout3 = new CPPout3::CPPout3();
  SETNAME(myCPPout3, "CPPout3");


  // Register model objects
  this->append_child(myC3_R_C);
  this->append_child(myCPPout3);

  // protected region constructor on begin
  // protected region constructor end
}

Consumer3::~Consumer3()
{
  // TODO Properly destroy all additional objects that got defined in the constructor

  // protected region destructor on begin
  // protected region destructor end

  // Destroy model objects
  delete myCPPout3;
  delete myC3_R_C;
}



// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} } 