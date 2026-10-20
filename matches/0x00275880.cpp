#include "compat/ptr.h"
extern "C" char DAT_0042bbc0[];
typedef unsigned int u32_275880;
struct ThisCall_00275600 {
    void FUN_00275600(int);
};
extern void FUN_002705f0();
extern char* _strncpy(char*, const char*, unsigned int);
class DriveCreateDirectoryRequest {
  public:
    void* vptr;
    char pad4[8];
    char path[16];
    DriveCreateDirectoryRequest* Create(int a, char* p);
};
DriveCreateDirectoryRequest* DriveCreateDirectoryRequest::Create(int a, char* p) {
    ((ThisCall_00275600*)(this))->FUN_00275600(a);
    vptr = (void*)((hulk_intptr)DAT_0042bbc0);
    FUN_002705f0();
    _strncpy(path, p, 0x10);
    path[16] = 0;
    return this;
}
