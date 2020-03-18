#include <Foundation/Application/Application.h>
#include <Foundation/Logging/ConsoleWriter.h>
#include <Foundation/Logging/VisualStudioWriter.h>

class ezHelloWorldApp : public ezApplication
{
public:
    ezHelloWorldApp() : ezApplication("ezHelloWorld")
    {
    }

    virtual void AfterCoreSystemsStartup() override
    {
        ezGlobalLog::AddLogWriter(ezLogWriter::Console::LogMessageHandler);
        ezGlobalLog::AddLogWriter(ezLogWriter::VisualStudio::LogMessageHandler);
    }

    virtual void BeforeCoreSystemsShutdown() override
    {
        // prevent further output during shutdown
        ezGlobalLog::RemoveLogWriter(ezLogWriter::Console::LogMessageHandler);
        ezGlobalLog::RemoveLogWriter(ezLogWriter::VisualStudio::LogMessageHandler);
    }

    ApplicationExecution Run() override
    {
        ezLog::Info("Hello ezWorld!");

        return ezApplication::Quit;
    }
};

EZ_CONSOLEAPP_ENTRY_POINT(ezHelloWorldApp);
