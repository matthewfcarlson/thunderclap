#include "decls/data/engine/audio.h"
// data: name1 = DAT_00429aec, name2 = DAT_00429ae4

extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int) throw();
class FUN_00240060 {
    char pad[12];

  public:
    FUN_00240060* FUN_0023fc40(const char*, int) throw();
    ~FUN_00240060() throw();
};
namespace audio {
class FUN_002605e0 {
  public:
    virtual void V();
    FUN_002605e0(FUN_00240060*, const __int64*, int, int) throw();
};
class SeqEventConditionType : public FUN_002605e0 {
  public:
    virtual void V();
    SeqEventConditionType() throw();
};
} // namespace audio
audio::SeqEventConditionType::SeqEventConditionType() throw()
    : FUN_002605e0(FUN_00240060().FUN_0023fc40(DAT_00429ae4, 0), &(__int64 const&)FUN_002672f0(DAT_00429aec, 0, 0), 32, 4) {}