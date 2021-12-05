#include "visualscriptingthreadsapp.h"


VisualScriptingThreadsApp::VisualScriptingThreadsApp()
{
    appLogic = new AppLogic();
    gigaManager = new GigaManager();
    // #TODO fill gigaManager fields with data
}

VisualScriptingThreadsApp::~VisualScriptingThreadsApp()
{
    delete appLogic;
    delete gigaManager;
}
