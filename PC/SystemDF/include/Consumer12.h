/**
 * Header file for the Consumer12 model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#pragma once

#include "csp/CSP.h"

// Models
#include "Consumer12/CPP2.h"

// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

using namespace LUNA::CSP;

namespace MainModel { namespace Consumer12 { 

class Consumer12 : public Sequential
{

public:
  // Define constructor and destructor
  Consumer12(ChannelOut<int> *ch1, ChannelOut<int> *ch2);
  virtual ~Consumer12();

private:

  // Class variables
  int aVariable;
  int bVariable;

  // Model objects
  Reader<int> *myC12_R_ch1;
  Reader<int> *myC12_R_ch2;
  CPP2::CPP2 *myCPP2;



  // protected region additional class members or functions on begin
  // protected region additional class members or functions end
};

// Close namespace(s)
} } 