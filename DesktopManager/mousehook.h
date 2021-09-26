#ifndef MOUSEHOOK_H
#define MOUSEHOOK_H

#include "windows.h"
#include "config.h"
#include "win32.h"

class MouseHook
{

public:
    static HHOOK mouseHook;
    static HWND workerWID,wid;
    static UINT16 buttonMsg,lastMsg;
    static Config *cfg;
    static win32 winApi;
    static long bkId;

    MouseHook();
    bool removeHook();
    bool installHook();
    void setWinId(HWND _wid);
    void setWorkerWID(HWND _id);
    void setConfig(Config *);
    void setBkId(long);


private:

    int pattern;

    static LRESULT CALLBACK mouseProc(int nCode,WPARAM wParam,LPARAM lParam );
};

#endif // MOUSEHOOK_H
