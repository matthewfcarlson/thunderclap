// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000ecd70 @ 0x000ecd70
// equiv-map: ??0WindowBase@@QAE@H@Z = 0x000e9240
#include "decls/data/game/global.h"

extern "C" void* __cdecl memset(void*, int, unsigned int);

class WindowBase {
public:
    WindowBase(int arg) throw();
    virtual void vfunc_0();
    char pad04[0x150 - 4];
};

class TextWindow : public WindowBase {
public:
    int f150, f154, f158, f15c, f160;
    int cells[0x200];       // 0x164
    int f964;
    char pad968[4];
    int f96c, f970, f974;
    int serial;             // 0x978
    float f97c;
    TextWindow(int arg) throw();
    virtual void vfunc_0();
};

TextWindow::TextWindow(int arg) throw()
    : WindowBase(arg)
{
    f150 = 0;
    f154 = 0;
    f158 = 0;
    f15c = 0;
    f160 = 0;
    memset(cells, 0, sizeof(cells));
    serial = DAT_004a0fe8++;
    f964 = 0;
    f96c = 0;
    f970 = 0;
    f974 = 0;
    f97c = 1.0f;
}
