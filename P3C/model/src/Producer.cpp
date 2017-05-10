/**
 * Source file for the Producer model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "Producer.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace MainModel { namespace Producer { 

Producer::Producer(GuardedChannelIn<int> *C1, GuardedChannelIn<int> *C2, GuardedChannelIn<int> *C3) :
    Sequential(NULL)
{
  SETNAME(this, "Producer");

  // Initialize model objects
  myCPPin = new CPPin::CPPin();
  SETNAME(myCPPin, "CPPin");
  myP_W_C1 = new GuardedWriter<int>(&ChVar1, C1);
  SETNAME(myP_W_C1, "P_W_C1");
  myP_W_C2 = new GuardedWriter<int>(&ChVar2, C2);
  SETNAME(myP_W_C2, "P_W_C2");
  myP_W_C3 = new GuardedWriter<int>(&ChVar3, C3);
  SETNAME(myP_W_C3, "P_W_C3");

  // Create ALTERNATIVE group
  myALTERNATIVE = new Alternative(
    true,
    (CSPConstruct *) myP_W_C3,
    (CSPConstruct *) myP_W_C2,
    (CSPConstruct *) myP_W_C1,
    NULL
  );
  SETNAME(myALTERNATIVE, "ALTERNATIVE");


  // Register model objects
  this->append_child(myCPPin);
  this->append_child(myALTERNATIVE);

  // protected region constructor on begin
  // protected region constructor end
}

Producer::~Producer()
{
  // TODO Properly destroy all additional objects that got defined in the constructor

  // protected region destructor on begin
  // protected region destructor end

  // Destroy model groups
  delete myALTERNATIVE;

  // Destroy model objects
  delete myP_W_C3;
  delete myP_W_C2;
  delete myP_W_C1;
  delete myCPPin;
}



// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} } 