/**
 * Header file for the MainModel model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#pragma once

#include "csp/CSP.h"

// Models
#include "Consumer1.h"
#include "Consumer2.h"
#include "Consumer3.h"
#include "Producer.h"

// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

using namespace LUNA::CSP;

namespace MainModel { 

class MainModel : public Recursion<CSProcess>
{

public:
  // Define constructor and destructor
  MainModel();
  virtual ~MainModel();

private:

  // Class variables
  bool ChVar1;
  bool ChVar2;
  bool ChVar3;

  // Channel definitions
  UnbufferedChannel<bool, One2In, Out2One> *myProducerC1_to_Consumer1CChannel;
  UnbufferedChannel<bool, One2In, Out2One> *myProducerC2_to_Consumer2CChannel;
  UnbufferedChannel<bool, One2In, Out2One> *myProducerC3_to_Consumer3CChannel;

  // Model objects
  Consumer1::Consumer1 *myConsumer1;
  Consumer2::Consumer2 *myConsumer2;
  Consumer3::Consumer3 *myConsumer3;
  Producer::Producer *myProducer;

  // Model groups
  Alternative *myALTERNATIVE;
  Parallel *myPARALLEL;


  // Guard evaluation functions
  bool Consumer1GuardEvaluate();
  bool Consumer2GuardEvaluate();
  bool Consumer3GuardEvaluate();

  // protected region additional class members or functions on begin
  // protected region additional class members or functions end
};

// Close namespace(s)
} 
