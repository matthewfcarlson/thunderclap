#include "compat/ptr.h"
extern "C" char DAT_0040449c[];
extern "C" char DAT_004044a4[];
class Helper_91cc0 {
  public:
    void Run();
};
extern void __cdecl thunk_FUN_00267090(hulk_intptr);
class CUnlockableBlonskyFile {
  public:
    void Destroy();
};
void CUnlockableBlonskyFile::Destroy() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004044a4);
    ((Helper_91cc0*)((char*)this + 0x20))->Run();
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0040449c);
    int p = *(int*)((char*)this + 0x18);
    if (p) {
        thunk_FUN_00267090(p);
        *(int*)((char*)this + 0x18) = 0;
    }
    ((Helper_91cc0*)((char*)this + 0x10))->Run();
}