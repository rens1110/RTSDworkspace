/**
 * Source file for the Consumer2 model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "Consumer2.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace MainModel { namespace Consumer2 { 

Consumer2::Consumer2(ChannelOut<bool> *C) :
    Sequential(NULL)
{
  SETNAME(this, "Consumer2");

  // Initialize model objects
  myC2_R_C = new Reader<bool>(&VarIn, C);
  SETNAME(myC2_R_C, "C2_R_C");
  myCPPout2 = new CPPout2::CPPout2();
  SETNAME(myCPPout2, "CPPout2");


  // Register model objects
  this->append_child(myC2_R_C);
  this->append_child(myCPPout2);

  // protected region constructor on begin
  // protected region constructor end
}

Consumer2::~Consumer2()
{
  // TODO Properly destroy all additional objects that got defined in the constructor

  // protected region destructor on begin
  // protected region destructor end

  // Destroy model objects
  delete myCPPout2;
  delete myC2_R_C;
}



// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} } 
