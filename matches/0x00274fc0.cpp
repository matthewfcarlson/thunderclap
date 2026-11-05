#include "compat/ptr.h"
extern "C" char DAT_0042ba20[];
class FileOpenByKeyRequest_274fc0 {
  public:
    hulk_intptr vtable;
    char pad[12 - 4];
    int y;
    int z;
    void Init(int);
    FileOpenByKeyRequest_274fc0(hulk_intptr, int, hulk_intptr);
};
extern void Finish();
FileOpenByKeyRequest_274fc0::FileOpenByKeyRequest_274fc0(hulk_intptr x, int yy, hulk_intptr zz) {
    Init(x);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042ba20);
    y = yy;
    z = zz;
    Finish();
}