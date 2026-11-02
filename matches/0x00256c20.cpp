#include "decls/data/engine/audio.h"
// data: Data_Sequence = DAT_0042a630, Sequence = DAT_0042a620

typedef unsigned __int64 U64_256c20;
extern "C" U64_256c20 __cdecl FUN_002672f0(const char*, int, int);
class EntityType_256c20 {
  public:
    EntityType_256c20(const U64_256c20&, const U64_256c20&, int, int, int);
    virtual void f();
};
namespace audio {
class SequenceType : public EntityType_256c20 {
  public:
    SequenceType();
    virtual void f();
};
} // namespace audio
audio::SequenceType::SequenceType()
    : EntityType_256c20(FUN_002672f0(DAT_0042a620, 0, 0), FUN_002672f0(DAT_0042a630, 0, 0), 0x1000001, 0x58, 8) {}