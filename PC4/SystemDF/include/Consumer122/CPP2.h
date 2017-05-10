/**
 * Header file for the CPP2 model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#pragma once

#include "csp/CSP.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

using namespace LUNA::CSP;

namespace MainModel { namespace Consumer122 { namespace CPP2 { 

class CPP2 : public CodeBlock
{

public:
  // Define constructor and destructor
  CPP2(int &aVariable, int &bVariable);
  virtual ~CPP2();

  void execute();

private:

  // Class variables
  int &aVariable;
  int &bVariable;

  // protected region additional class members or functions on begin

  // protected region additional class members or functions end
};

// Close namespace(s)
} } } 
