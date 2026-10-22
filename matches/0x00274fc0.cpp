#include "compat/ptr.h"
extern "C" char DAT_0042ba20[];
class FileOpenByKeyRequest_274fc0 {
  public:
    char pad[12];
    int y;
    int z;
    void Init(int);
    FileOpenByKeyRequest_274fc0(int, int, int);
};
extern void Finish();
FileOpenByKeyRequest_274fc0::FileOpenByKeyRequest_274fc0(int x, int yy, int zz) {
    Init(x);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042ba20);
    y = yy;
    z = zz;
    Finish();
}