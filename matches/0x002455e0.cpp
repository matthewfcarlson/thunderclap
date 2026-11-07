#include "decls/data/records.h"
struct Pair {
    unsigned a;
    unsigned b;
};
extern "C" Pair __cdecl FUN_002672f0(const char*, int, int);
namespace audio {
class FUN_00243310 {
  public:
    virtual void FUN_002455d0();
    FUN_00243310(const Pair*, const Pair*, int, int, int);
};
class ClipType : public FUN_00243310 {
  public:
    virtual void FUN_002455d0();
    ClipType();
};
} // namespace audio
audio::ClipType::ClipType()
    : FUN_00243310(&FUN_002672f0("Data_Clip", 0, 0), &FUN_002672f0("Clip", 0, 0), 0x1000000, (int)sizeof(AudioClip), 8) { HULK_SIZE32(AudioClip, 0x30); }
