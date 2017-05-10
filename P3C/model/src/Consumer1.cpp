/**
 * Source file for the Consumer1 model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "Consumer1.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace MainModel { namespace Consumer1 { 

Consumer1::Consumer1(ChannelOut<int> *C) :
    Sequential(NULL)
{
  SETNAME(this, "Consumer1");

  // Initialize model objects
  myC1_R_C = new Reader<int>(&VarIn, C);
  SETNAME(myC1_R_C, "C1_R_C");
  myCPPout1 = new CPPout1::CPPout1();
  SETNAME(myCPPout1, "CPPout1");


  // Register model objects
  this->append_child(myC1_R_C);
  this->append_child(myCPPout1);

  // protected region constructor on begin
  // protected region constructor end
}

Consumer1::~Consumer1()
{
  // TODO Properly destroy all additional objects that got defined in the constructor

  // protected region destructor on begin
  // protected region destructor end

  // Destroy model objects
  delete myCPPout1;
  delete myC1_R_C;
}



// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} } 