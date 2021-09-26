#include "win32.h"
#include<QDebug>
HWND win32::myWorkerw = nullptr;
win32::win32()
{
    QLibrary mylib("user32.dll");

    this->setwinAttribute =(SetWindowCompositionAttribute) mylib.resolve("SetWindowCompositionAttribute");
}

HWND win32::GetWorkerW(){
    PDWORD_PTR result=nullptr;
    HWND windowHandle = FindWindow(L"Progman", nullptr);
    SendMessageTimeout(windowHandle, 0x052c, 0 ,0, SMTO_NORMAL, 0x3e8,result);
    EnumWindows(this->myEnumWindowsProc,static_cast<LPARAM>(NULL));
    ShowWindow(win32::myWorkerw,SW_HIDE);
    return windowHandle;
}

COLORREF win32::GetWindowsThemeColor()
{
    DWORD crColorization;
    BOOL fOpaqueBlend;
    COLORREF theme_color{};
    HRESULT result = DwmGetColorizationColor(&crColorization, &fOpaqueBlend);
    if (result == S_OK)
    {
        BYTE r, g, b;
        r = (crColorization >> 16) % 256;
        g = (crColorization >> 8) % 256;
        b = crColorization % 256;
        theme_color = RGB(r, g, b);
    }
        return theme_color;
}

WINBOOL win32::myEnumWindowsProc(HWND tophandle, LPARAM topparamhandle)
{

    HWND defview = FindWindowEx(tophandle, nullptr, L"SHELLDLL_DefView", nullptr);
    if (defview != nullptr)
    {
        win32::myWorkerw = FindWindowEx(nullptr, tophandle, L"WorkerW", nullptr);

    }
    return true;
}
