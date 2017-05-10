/**
 * Header file for the Producer122 model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#pragma once

#include "csp/CSP.h"

// Models
#include "Producer122/CPP12.h"

// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

using namespace LUNA::CSP;

namespace MainModel { namespace Producer122 { 

class Producer122 : public Sequential
{

public:
  // Define constructor and destructor
  Producer122(ChannelIn<int> *ch12, ChannelIn<int> *ch22);
  virtual ~Producer122();

private:

  // Class variables
  int anotherValue;
  int someValue;

  // Model objects
  CPP12::CPP12 *myCPP12;
  Writer<int> *myP122_W_ch12;
  Writer<int> *myP122_W_ch22;



  // protected region additional class members or functions on begin
  // protected region additional class members or functions end
};

// Close namespace(s)
} } 
