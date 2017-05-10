/**
 * Main source file, activates and starts the MainModel
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 * protected region document description end
 */

#include "MainModel.h"
#include "csp/CSP.h"

// protected region Additional headers on begin
#ifdef CONFIG_COMPONENT_rtlogger
// For remote logger
#include "rtlogger/RemoteLogger.h"
#endif
// protected region Additional headers end  

#if LUNA_REVISION < 1854
#  warning "LUNA is (too) old, please update to last known version: 1854"
#endif

/* 
 * Provide functionality (static added code) for blocking OS threads
 * Needs to include once for each executable
 */
#include "threadblocker/OSThreadBlocker.h"

/** terminator used to stop the application (eg when the MainModel is finished) */
Terminator* term;

void signalHandler( int signum )
{
  LOG(LUNA::LOG_INFO, "Caught signal %d, exiting.\n", signum);
  term->exit();
}

int main(int argc, char *argv[])
{
  using namespace LUNA;
  using namespace LUNA::Logger;

// protected region RTlogger support on begin
  bool using_remote_logging = false;

#ifdef CONFIG_COMPONENT_rtlogger
  if(argc != 3 && argc != 1)
  {
    LOG(LOG_ERROR, "Usage %s: [<hostname> <port>]\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  else
  {
    if(argc == 3)
    {
      if(OSScheduler::Instance()->setSchedulerPolicy(FIFO))
      {
        LOGLOCAL(LOG_ERROR, "Could not set the scheduler policy to FIFO (required for the RTLogger). Do you have root permissions?\n");
        exit(EXIT_FAILURE);
      }
      LOGLOCAL(LOG_INFO, "Starting RTLogger.\n");
      if(!STARTREMOTELOGGER(argv[1], atoi(argv[2]), false ))
      {
        LOGLOCAL(LOG_ERROR, "Could not start remote logger.\n");
        exit(EXIT_FAILURE);
      }
      using_remote_logging = true;
    }
    else
    {
      LOGLOCAL(LOG_INFO, "No address + port specified, using local logger.\n");
    }
  }
#endif
// protected region RTlogger support end  

  LUNA::Threading::PThreadImplementation::thread_t tid = LUNA::Threading::PThreadImplementation::threadSelf();
  LUNA::Threading::OSScheduler::Instance()->setThreadPriority(tid, 11);

  LOGLOCAL(LOG_INFO, "Setting up a signal handler, press ctrl+c to stop SystemDF.\n");
  struct sigaction handler;
  memset(&handler, 0, sizeof(struct sigaction));

  /* Install the signal handler */
  /* Sigaction *must* be used so we can specify SA_ONSTACK */
  handler.sa_handler = &signalHandler;
  sigemptyset( &handler.sa_mask );

  if ( sigaction( SIGINT, &handler, NULL ) )
  {
    LOGLOCAL(LOG_ERROR, "Error: sigaction failed.\n" );
    return -1;
  }

  LOGLOCAL(LOG_INFO, "Constructing the SystemDF structure:\n");

  LOGLOCAL(LOG_INFO, "- Creating the MainModel\n");
  MainModel::MainModel *model = new MainModel::MainModel();

  LOGLOCAL(LOG_INFO, "- Creating the Terminator\n");
  term = new Terminator(model);

// protected region manual tree modifications on begin
  // For example show the CSP tree (for debugging purposes)
  // printCSPTree(term);
// protected region manual tree modifications end  

  LOGLOCAL(LOG_INFO, "- Creating the threads\n");

  Set<CSProcess*> modelThreads( filterCSProcesses( collectValues( TreeNode<CSPConstruct*>::depth_first_iterator(term) ) ) );

  Set<OSThread*> modelThreads_out(0);

  createThreads(&modelThreads, &modelThreads_out, NULL);

  LOGLOCAL(LOG_INFO, "- Starting the threads (#%d)\n", modelThreads_out.size());

  startThreads(&modelThreads_out);

  LOGLOCAL(LOG_INFO, "Starting SystemDF - term thread: %p\n", term->getIThread());
  term->activate();

// protected region additional code on begin
// protected region additional code end

  // Wait for the threads to finish
  joinThreads(&modelThreads_out);
  LOGLOCAL(LOG_INFO, "SystemDF stopped.\n");

// protected region cleanup code on begin
// protected region cleanup code end

  // Clean up processes
  delete term;
  delete model;

  return 0;
}
