#ifndef WIN32_H
#define WIN32_H
#include <windows.h>
#include <QtCore>
#include <dwmapi.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "Dwmapi.lib")



namespace swca {
    enum class ACCENT {							// Values passed to SetWindowCompositionAttribute determining the appearance of a window
        ACCENT_ENABLE_GRADIENT = 1,					// （补充个人理解 修改梯度颜色，在policy第三个参数中生效）Use a solid color specified by nColor. This mode ignores the alpha value and is fully opaque.
        ACCENT_ENABLE_TRANSPARENTGRADIENT = 2,		//（补充个人理解 直接透明，color有效极浅色看不出） Use a tinted transparent overlay. nColor is the tint color.
        ACCENT_ENABLE_BLURBEHIND = 3,				// （补充个人理解 直接模糊，忽视在policy第三个参数类似上一个）Use a tinted blurry overlay. nColor is the tint color.
        ACCENT_ENABLE_FLUENT = 4,					//  使用类似流畅设计的方面。nColor是浅色。如果alpha值为0，此模式会出错。

        ACCENT_NORMAL = 150							// （补充个人理解 默认设置RGB颜色）(Fake value) Emulate regular taskbar appearance
    };
    enum class WindowCompositionAttribute {		// Possible kinds of data sent to SetWindowCompositionAttribute
        WCA_ACCENT_POLICY = 19						// The data sent is an ACCENTPOLICY struct
    };
    struct ACCENTPOLICY				// Determines how a window's transparent region will be painted
    {
        ACCENT   nAccentState;			// Appearance
        int32_t  nFlags;				// Nobody knows how this value works
        uint32_t nColor;				// A color in the hex format AABBGGRR
        int32_t  nAnimationId;			// Nobody knows how this value works
    };
    struct WINCOMPATTRDATA						// Composition Attributes
    {
        WindowCompositionAttribute nAttribute;		// Type of the data struct passed
        void *pData;								// Opaque pointer to the data struct (ACCENTPOLICY in our case)
        uint32_t ulDataSize;						// Size of data struct
    };
}

class win32
{
public:
    win32();
    HWND GetWorkerW();
    typedef bool ( *SetWindowCompositionAttribute)(HWND,swca::WINCOMPATTRDATA *);
    SetWindowCompositionAttribute setwinAttribute ;
    static COLORREF GetWindowsThemeColor();
    static HWND myWorkerw ;
private:
    static BOOL CALLBACK  myEnumWindowsProc(_In_ HWND tophandle, _In_ LPARAM topparamhandle);
protected:
};

#endif // WIN32_H
