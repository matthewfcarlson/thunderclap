#include "decls/data/game/global.h"
// data: scale = DAT_003ffaa4

#include "compat/ptr.h"
struct X {
    char pad[0x30];
    unsigned __int64 v;
    hulk_freg Get();
};
hulk_freg X::Get() {
    return (double)v * DAT_003ffaa4;
}