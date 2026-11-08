#include "decls/data/engine/core.h"
#include "decls/data/records.h"

extern "C" void _ReadWriteBarrier();
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042afa8[];
extern "C" char DAT_0042b85c[];
extern "C" char DAT_0042b86c[];
extern "C" char DAT_0042b87c[];
extern "C" char DAT_0042b884[];
extern "C" int* FUN_002705f0();
// the library list's constructor 0x00277a40 (called as a member named by that address)
class Sub_272d00 {
  public:
    void FUN_00277a40();
};
// core::Drive (records.h CoreDrive): the bases' vftables (core::IRefCount, core::Object, core::SafeRefCount), then
// core::Drive's own (0x0042b884 / +4 0x0042b87c / +0xc 0x0042b86c)
class Drive : public CoreDrive {
  public:
    Drive();
};
Drive::Drive() {
    vftable = DAT_003f6098;
    vftableObject = DAT_0042afa8;
    heap = DAT_004cdbb0;
    FUN_002705f0();
    vftableMutable = DAT_0042b85c;
    _ReadWriteBarrier();
    refs = 1;
    _ReadWriteBarrier();
    vftable = DAT_0042b884;
    vftableObject = DAT_0042b87c;
    vftableMutable = DAT_0042b86c;
    ((Sub_272d00*)&libraries)->FUN_00277a40();
    requests = 0;
    lastRequest = 0;
    state = 0;
    signal = 0;
    thread = 0;
    callback = 0;
    argument = 0;
    active = 0;
    request = 0;
    flag5c = 1;
    busy = 0;
    error = 3;
    driveThread = 0;
    FUN_002705f0();
}
