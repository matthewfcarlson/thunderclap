#include "decls/address.h"
typedef unsigned __int64 U64;
namespace audio {
class ListenerEffectGcBase {
  public:
    ListenerEffectGcBase(const U64&, const U64&, int, int, int);
    virtual ~ListenerEffectGcBase();
};
class ListenerEffectGcType : public ListenerEffectGcBase {
  public:
    ListenerEffectGcType();
    virtual ~ListenerEffectGcType();
};
ListenerEffectGcType::ListenerEffectGcType()
    : ListenerEffectGcBase(FUN_002672f0("Data_Effect", 0, 0), FUN_002672f0("ListenerEffectGc", 0, 0),
                           0x1000102, 64, 8) {}
} // namespace audio
