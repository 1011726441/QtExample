#include "mousehook.h"

HWND MouseHook::wid = nullptr;
HWND MouseHook::workerWID = nullptr;
HHOOK MouseHook::mouseHook = nullptr;
UINT16 MouseHook::lastMsg = 0;;
UINT16 MouseHook::buttonMsg = 0;
Config *MouseHook::cfg = nullptr;
win32 MouseHook::winApi;
long MouseHook::bkId = 0;

MouseHook::MouseHook()
{

    pattern = 0;
}

bool MouseHook::installHook()
{
    mouseHook =SetWindowsHookEx( WH_MOUSE_LL,this->mouseProc,GetModuleHandle(NULL),0);//设置钩子
}

void MouseHook::setWinId(HWND _wid)
{
    wid = _wid;
}

void MouseHook::setConfig(Config *_cfg)
{
    cfg = _cfg;
}

void MouseHook::setBkId(long _bkId)
{
    bkId = _bkId;
}

bool MouseHook::removeHook()
{
    return UnhookWindowsHookEx(mouseHook);
}
LRESULT MouseHook::mouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{

    if(GetForegroundWindow()==workerWID&&nCode==HC_ACTION)//当最前面的窗口是WorkerW（就是只有桌面）
    {
        POINT p;//定义一个坐标
        GetCursorPos(&p);//获取鼠标坐标
        ClientToScreen(wid,&p);//转换成窗口坐标
        //给buttonMsg赋值
        if(wParam&MK_LBUTTON){
            buttonMsg=MK_LBUTTON;

        }
        else if(wParam&MK_MBUTTON){
            buttonMsg=MK_MBUTTON;
        }
        else if(wParam&MK_RBUTTON){
            buttonMsg=MK_MBUTTON;
        }
        else if(lastMsg==WM_MOUSEMOVE){
            buttonMsg=0;
        }
        SendMessage(wid,wParam,buttonMsg,MAKEWPARAM(p.x,p.y));
        if(wParam==lastMsg)
            lastMsg=wParam;//将二者比较，判断状态变化，用于响应拖拽消息


    }
    /*是否处于本界面*/
    if(cfg->readCfg("taskBar/taskBarPattern").toInt() == 2){

        HWND hd = FindWindowA("Shell_TrayWnd",nullptr);

        swca::ACCENTPOLICY policy;
        swca::WINCOMPATTRDATA data;


        policy.nColor = winApi.GetWindowsThemeColor();
        policy.nFlags = 2;
        policy.nAnimationId = 0;
        data.nAttribute =swca::WindowCompositionAttribute::WCA_ACCENT_POLICY;
        data.pData =&policy;
        data.ulDataSize = sizeof (policy);
        if(((GetForegroundWindow()==workerWID) or (GetForegroundWindow()==(HWND)bkId))){
            policy.nAccentState = swca::ACCENT::ACCENT_ENABLE_TRANSPARENTGRADIENT;
            winApi.setwinAttribute(hd,&data);
        }else{
            policy.nAccentState = swca::ACCENT::ACCENT_ENABLE_GRADIENT;
            winApi.setwinAttribute(hd,&data);
        }
    }

    return CallNextHookEx(mouseHook,nCode,wParam,lParam);//下一个钩子
}
