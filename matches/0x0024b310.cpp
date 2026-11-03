#include "compat/ptr.h"
#include "gen/owners.h"
hulk_intptr owners::X_24b310::FUN_0024b310(void* p) {
    hulk_intptr i = ((char*)p - (char*)this) / 12;
    if (i == ((int)b + (int)a - 1) % (int)c)
        return 0;
    return (hulk_intptr)this + ((i + 1) % (unsigned int)c) * 12;
}