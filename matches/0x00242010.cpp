#include "decls/address.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"
// data: mixName = DAT_0042422c, otherName = DAT_004290c4
// The base constructor is om::EntityType's (0x00243310), named by its address for the native links.

class FUN_00243310 {
  public:
    virtual void f();
    FUN_00243310(const unsigned __int64*, const unsigned __int64*, int, int, int);
};
class MixType_242010 : public FUN_00243310 {
  public:
    MixType_242010();
    virtual void f();
};
MixType_242010::MixType_242010() : FUN_00243310(&(const unsigned __int64&)FUN_002672f0(((char*)&DAT_004290c4), 0, 0), &(const unsigned __int64&)FUN_002672f0(((char*)&DAT_0042422c), 0, 0), 0x1000002, 0x50, 8) {}
