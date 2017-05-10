/**
 * Source file for the Consumer122 model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "Consumer122.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace MainModel { namespace Consumer122 { 

Consumer122::Consumer122(ChannelOut<int> *ch12, ChannelOut<int> *ch22) :
    Sequential(NULL)
{
  SETNAME(this, "Consumer122");

  // Initialize model objects
  myC122_R_ch12 = new Reader<int>(&aVariable, ch12);
  SETNAME(myC122_R_ch12, "C122_R_ch12");
  myC122_R_ch22 = new Reader<int>(&bVariable, ch22);
  SETNAME(myC122_R_ch22, "C122_R_ch22");
  myCPP22 = new CPP22::CPP22(aVariable, bVariable);
  SETNAME(myCPP22, "CPP22");


  // Register model objects
  this->append_child(myC122_R_ch12);
  this->append_child(myC122_R_ch22);
  this->append_child(myCPP22);

  // protected region constructor on begin
  // protected region constructor end
}

Consumer122::~Consumer122()
{
  // TODO Properly destroy all additional objects that got defined in the constructor

  // protected region destructor on begin
  // protected region destructor end

  // Destroy model objects
  delete myCPP22;
  delete myC122_R_ch22;
  delete myC122_R_ch12;
}



// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} } 
