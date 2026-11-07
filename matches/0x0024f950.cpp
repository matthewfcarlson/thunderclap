#include "decls/data/records.h"
extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int) throw();
class FUN_00240060 {
  public:
    FUN_00240060* FUN_0023fc40(const char*, int) throw();
    ~FUN_00240060() throw();
    char pad[12];
};
class FUN_002605e0 {
  public:
    FUN_002605e0(FUN_00240060*, const __int64&, int, int) throw();
    virtual void v0();
};
class SeqEventChannelSendsType_24f950 : public FUN_002605e0 {
  public:
    SeqEventChannelSendsType_24f950();
    virtual void v0();
};
SeqEventChannelSendsType_24f950::SeqEventChannelSendsType_24f950()
    : FUN_002605e0(FUN_00240060().FUN_0023fc40("ChSends", 0), FUN_002672f0("SeqEventChannelSends", 0, 0), (int)sizeof(AudioSeqEventChannelSends), (int)__alignof(AudioSeqEventChannelSends)) { HULK_SIZE32(AudioSeqEventChannelSends, 0x10c); }