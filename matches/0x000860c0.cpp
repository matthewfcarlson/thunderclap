#include "compat/ptr.h"
struct X {
    char pad[0x30];
    unsigned __int64 v;
    hulk_freg Get();
};
extern const float scale;
hulk_freg X::Get() {
    return (float)((double)v * scale);
}