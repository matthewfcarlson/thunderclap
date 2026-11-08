#include "decls/data/platform/xbox/core.h"
#include "decls/data/records.h"

// CloseHandle (the XDK row 0x0020bbc2)
extern "C" int __stdcall FUN_0020bbc2(int);
// core::XboxSaveDrive::vfunc_10 (records.h CoreXboxSaveDrive): commits (slot 11) and closes a file
class XboxSaveDrive {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual int f10(int, int);
    virtual void f11(int, int);
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
};
int XboxSaveDrive::f10(int a, int b) {
    f11(a, b);
    if ((*(int*)((char*)&DAT_0052c270 + 4)) == a)
        (*(int*)((char*)&DAT_0052c270 + 12)) = 0;
    FUN_0020bbc2(a);
    --((CoreXboxSaveDrive*)this)->openFiles;
    return 1;
}
