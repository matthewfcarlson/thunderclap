// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00250290 @ 0x00250290
#include "decls/address.h"
typedef unsigned __int64 U64;
extern "C" void * __cdecl memcpy(void *, const void *, unsigned int);
struct WaitName {
    char data[12];
    WaitName *FUN_0023fc40(const char *, int);
    void FUN_00240060();
};
namespace audio {
struct SeqEventWaitType {
    virtual void unused();
    void FUN_002605e0(WaitName *, const U64 *, int, int);
    void FUN_00250290();
};
void SeqEventWaitType::FUN_00250290() {
    U64 id = FUN_002672f0("SeqEventWait", 0, 0);
    WaitName name;
    FUN_002605e0(name.FUN_0023fc40("Wait", 0), &id, 20, 4);
    name.FUN_00240060();
    SeqEventWaitType fresh;
    memcpy(this, &fresh, sizeof fresh);
}
}