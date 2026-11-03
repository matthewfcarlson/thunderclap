#include "gen/owners.h"
struct X_16f8b0 {
    char pad[12];
    int mVal;
};
char owners::Obj_16f8b0::FUN_0016f8b0(int v) {
    *(int*)((char*)this + 12) = v;
    return 1;
}
