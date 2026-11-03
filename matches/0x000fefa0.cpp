#include "gen/owners.h"
extern void Init(owners::C_fefa0*, int*);
hulk_intptr owners::C_fefa0::FUN_000fefa0() {
    if (!value)
        Init(this, &value);
    return value;
}