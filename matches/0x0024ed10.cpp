#include "gen/owners.h"
#include "decls/data/records.h"
extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int) throw();
class Key {
    __int64 n;

  public:
    Key(__int64 v) : n(v) {}
    operator void*() { return &n; }
};
class FUN_00240060 {
    char pad[12];

  public:
    ~FUN_00240060() throw();
};
class FUN_002605e0 {
  public:
    FUN_002605e0(FUN_00240060*, void*, int, int) throw();
    virtual void f();
};
class SeqEventChannelSendVolumesType_24ed10 : public FUN_002605e0 {
  public:
    SeqEventChannelSendVolumesType_24ed10() throw();
    virtual void f();
};
SeqEventChannelSendVolumesType_24ed10::SeqEventChannelSendVolumesType_24ed10() throw()
    : FUN_002605e0(((FUN_00240060 *)((owners::String_23fc40 *)&(FUN_00240060()))->FUN_0023fc40("ChSendVol", (hulk_intptr)0)), Key(FUN_002672f0("SeqEventChannelSendVolumes", 0, 0)), (int)sizeof(AudioSeqEventChannelSendVolumes), (int)__alignof(AudioSeqEventChannelSendVolumes)) { HULK_SIZE32(AudioSeqEventChannelSendVolumes, 0x50); }