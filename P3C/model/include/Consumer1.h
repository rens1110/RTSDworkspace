/**
 * Header file for the Consumer1 model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#pragma once

#include "csp/CSP.h"

// Models
#include "Consumer1/CPPout1.h"

// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

using namespace LUNA::CSP;

namespace MainModel { namespace Consumer1 { 

class Consumer1 : public Sequential
{

public:
  // Define constructor and destructor
  Consumer1(ChannelOut<bool> *C);
  virtual ~Consumer1();

private:

  // Class variables
  bool VarIn;

  // Model objects
  Reader<bool> *myC1_R_C;
  CPPout1::CPPout1 *myCPPout1;



  // protected region additional class members or functions on begin
  // protected region additional class members or functions end
};

// Close namespace(s)
} } 
