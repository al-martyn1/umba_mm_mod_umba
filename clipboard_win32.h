#pragma once

#include <windows.h>
#include <string>

//----------------------------------------------------------------------------



#if defined(WIN32) || defined(_WIN32)
//----------------------------------------------------------------------------
namespace umba {
namespace win32 {

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
inline
HWND clipboardGetConsoleHwnd()
{
    const std::size_t bufSize = 1024; // Buffer size for console window titles.
    HWND hwndFound;         // This is what is returned to the caller.
    char pszNewWindowTitle[bufSize]; // Contains fabricated
                                        // WindowTitle.
    WCHAR pszOldWindowTitle[bufSize]; // Contains original
                                        // WindowTitle.

    // Fetch current window title.

    ::GetConsoleTitleW(pszOldWindowTitle, bufSize);

    // Format a "unique" NewWindowTitle.

    wsprintfA(pszNewWindowTitle,"%d/%d",
                ::GetTickCount(),
                ::GetCurrentProcessId());

    // Change current window title.

    ::SetConsoleTitleA(pszNewWindowTitle);

    // Ensure window title has been updated.

    Sleep(50);

    // Look for NewWindowTitle.

    hwndFound = ::FindWindowA(NULL, pszNewWindowTitle);

    // Restore original window title.

    ::SetConsoleTitleW(pszOldWindowTitle);

    return(hwndFound);
}

//----------------------------------------------------------------------------
struct ClipboardAutoCloser
{
    ClipboardAutoCloser() {}
    ~ClipboardAutoCloser()
    {
        ::CloseClipboard();
    }
};

//----------------------------------------------------------------------------
inline
bool clipboardClear(HWND hWndNewOwner=0)
{
    if (!::OpenClipboard( hWndNewOwner ))
    {
        return false;
    }
    
    ClipboardAutoCloser autoCloser;

    return ::EmptyClipboard() ? true : false;
}
//----------------------------------------------------------------------------

template<typename StringType> inline
bool clipboardTextGet(StringType &text, HWND hWndNewOwner=0)
{
    typedef typename StringType::value_type     char_type;

    UINT cfText = CF_TEXT;
    if (sizeof(char_type)>sizeof(char))
    {
        cfText = CF_UNICODETEXT;
    }

    if (!IsClipboardFormatAvailable(cfText))
    {
        return false; // no data in this format
    }

    if (!::OpenClipboard( hWndNewOwner ))
    {
        return false;
    }

    ClipboardAutoCloser autoCloser;

    // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getclipboarddata
    // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setclipboarddata
    // https://learn.microsoft.com/en-us/windows/win32/dataxchg/clipboard-formats

    HGLOBAL hglb = (HGLOBAL)::GetClipboardData(cfText);
    if (!hglb) 
    {
         return false;
    }

    std::size_t dataLen  = (std::size_t)GlobalSize( hglb );
    char_type* lpClpText = (char_type*)GlobalLock(hglb); 
    if (!lpClpText)
    {
         return false;
    }

    text.clear();
    text.assign(lpClpText, dataLen);

    ::GlobalUnlock(hglb);

    return true;

}

//----------------------------------------------------------------------------
template<typename StringType> inline
bool clipboardTextSet(const StringType &text, HWND hWndNewOwner=0)
{
    typedef typename StringType::value_type     char_type;

    UINT cfText = CF_TEXT;
    if (sizeof(char_type)>sizeof(char))
    {
        cfText = CF_UNICODETEXT;
    }

    if (!::OpenClipboard( hWndNewOwner ))
    {
        return false;
    }

    ClipboardAutoCloser autoCloser;

    HGLOBAL hglb = ::GlobalAlloc(GMEM_MOVEABLE, text.size()+1 ); 
    if (!hglb)
    {
        return false;
    }

    char_type* lpGlobalData = (char_type*)::GlobalLock(hglb); 

    text.copy(lpGlobalData, text.size());
    lpGlobalData[text.size()] = 0;

    ::GlobalUnlock(hglb); 

    ::EmptyClipboard();

    ::SetClipboardData(cfText, hglb);

    return true;
}


//----------------------------------------------------------------------------



//----------------------------------------------------------------------------

} // namespace win32
} // namespace umba

#endif // defined(WIN32) || defined(_WIN32)
