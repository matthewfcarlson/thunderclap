#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"
// data: mixName = DAT_0042422c, otherName = DAT_004290c4

extern "C" unsigned __int64 __cdecl lookup(const char*, int, int);
class EntityType_242010 {
  public:
    virtual void f();
    EntityType_242010(const unsigned __int64&, const unsigned __int64&, int, int, int);
};
class MixType_242010 : public EntityType_242010 {
  public:
    MixType_242010();
    virtual void f();
};
MixType_242010::MixType_242010() : EntityType_242010(lookup(((char*)&DAT_004290c4), 0, 0), lookup(((char*)&DAT_0042422c), 0, 0), 0x1000002, 0x50, 8) {}