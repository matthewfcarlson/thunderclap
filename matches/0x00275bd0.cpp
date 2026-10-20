#include "compat/ptr.h"
extern "C" char DAT_0042bc60[];
struct ThisCall_00275600 {
    void BaseInit(void*);
};
extern "C" void InitMore();
extern "C" char* strncpy(char*, const char*, unsigned int);
class DriveFileDestroyRequest {
  public:
    char pad[0x10c];
    DriveFileDestroyRequest* Run(hulk_intptr, char*);
};
DriveFileDestroyRequest* DriveFileDestroyRequest::Run(hulk_intptr a, char* p) {
    ((ThisCall_00275600*)(this))->BaseInit((void*)a);
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_0042bc60);
    InitMore();
    strncpy((char*)this + 0xc, p, 0x100);
    ((char*)this)[0x10c] = 0;
    return this;
}