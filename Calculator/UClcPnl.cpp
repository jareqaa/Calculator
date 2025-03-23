#include "UClcPnl.h"

#include <Windows.h>

using namespace Calculator;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew UClcPnl);
    return 0;
}