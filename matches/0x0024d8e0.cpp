#include "decls/address.h"
typedef unsigned __int64 U64;
namespace audio {
class FUN_0025e6c0 {
  public:
    FUN_0025e6c0(const U64*, const U64*, int, int, int);
    virtual ~FUN_0025e6c0();
};
class ListenerEffectGcType : public FUN_0025e6c0 {
  public:
    ListenerEffectGcType();
    virtual ~ListenerEffectGcType();
};
ListenerEffectGcType::ListenerEffectGcType()
    : FUN_0025e6c0(&(const U64&)FUN_002672f0("Data_Effect", 0, 0), &(const U64&)FUN_002672f0("ListenerEffectGc", 0, 0),
                           0x1000102, 64, 8) {}
} // namespace audio
