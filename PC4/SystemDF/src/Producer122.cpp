/**
 * Source file for the Producer122 model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "Producer122.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace MainModel { namespace Producer122 { 

Producer122::Producer122(ChannelIn<int> *ch12, ChannelIn<int> *ch22) :
    Sequential(NULL)
{
  SETNAME(this, "Producer122");

  // Initialize model objects
  myCPP12 = new CPP12::CPP12(anotherValue, someValue);
  SETNAME(myCPP12, "CPP12");
  myP122_W_ch12 = new Writer<int>(&someValue, ch12);
  SETNAME(myP122_W_ch12, "P122_W_ch12");
  myP122_W_ch22 = new Writer<int>(&anotherValue, ch22);
  SETNAME(myP122_W_ch22, "P122_W_ch22");


  // Register model objects
  this->append_child(myCPP12);
  this->append_child(myP122_W_ch12);
  this->append_child(myP122_W_ch22);

  // protected region constructor on begin
  // protected region constructor end
}

Producer122::~Producer122()
{
  // TODO Properly destroy all additional objects that got defined in the constructor

  // protected region destructor on begin
  // protected region destructor end

  // Destroy model objects
  delete myP122_W_ch22;
  delete myP122_W_ch12;
  delete myCPP12;
}



// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} } 
