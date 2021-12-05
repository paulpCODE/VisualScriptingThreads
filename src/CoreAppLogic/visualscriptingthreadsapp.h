#ifndef VISUALSCRIPTINGTHREADSAPP_H
#define VISUALSCRIPTINGTHREADSAPP_H

#include "gigamanager.h"
#include "applogic.h"

class VisualScriptingThreadsApp
{
public:
    VisualScriptingThreadsApp();
    ~VisualScriptingThreadsApp();

    GigaManager *gigaManager;
    AppLogic *appLogic;
};

#endif // VISUALSCRIPTINGTHREADSAPP_H
