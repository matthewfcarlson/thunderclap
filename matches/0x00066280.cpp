#include "decls/address.h"
struct World {
    char pad[0x2c];
    int value;
};
extern const float DAT_003f3388;
extern "C" float __fastcall Run(int);
class Obj {
  public:
    int cached;
    int enabled;
    float Get();
};
float Obj::Get() {
    if (!enabled)
        return DAT_003f3388;
    if (!cached) {
        cached = DAT_004dd700->value;
        if (!cached)
            return DAT_003f3388;
    }
    return Run(enabled);
}