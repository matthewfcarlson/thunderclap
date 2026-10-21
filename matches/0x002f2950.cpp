#include "compat/ptr.h"
struct V {
    char pad[8];
    float value;
};
extern const float Half;
hulk_freg __cdecl FUN_002f2950(V* a, V* b) {
    return (a->value + b->value) * Half;
}