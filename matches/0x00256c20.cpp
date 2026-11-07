#include "decls/data/engine/audio.h"
// data: Data_Sequence = DAT_0042a630, Sequence = DAT_0042a620

typedef unsigned __int64 U64_256c20;
extern "C" U64_256c20 __cdecl FUN_002672f0(const char*, int, int);
class FUN_00243310 {
  public:
    FUN_00243310(const U64_256c20&, const U64_256c20&, int, int, int);
    virtual void f();
};
namespace audio {
class SequenceType : public FUN_00243310 {
  public:
    SequenceType();
    virtual void f();
};
} // namespace audio
audio::SequenceType::SequenceType()
    : FUN_00243310(FUN_002672f0(DAT_0042a620, 0, 0), FUN_002672f0(DAT_0042a630, 0, 0), 0x1000001, (int)sizeof(AudioSequence), 8) { HULK_SIZE32(AudioSequence, 0x58); }