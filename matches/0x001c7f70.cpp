// Same code shape as 0x000679c0 (propagated; names are from that function)
#include "compat/ptr.h"
struct C_1c7f70 {
    char pad[0x18];
};
struct Cache_1c7f70 { int FUN_001c75e0(int); };
struct Mgr_1c7f70 { char pad[0x18]; Cache_1c7f70 cache; hulk_intptr FUN_001c7f70(hulk_intptr a); };
hulk_intptr Mgr_1c7f70::FUN_001c7f70(hulk_intptr a) {
    return cache.FUN_001c75e0(a);
}