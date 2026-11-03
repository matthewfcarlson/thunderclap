#include "gen/owners.h"
typedef float F_1c61e0;
struct O_1c61e0 {
};
struct C_1c61e0 {
    char pad[0x284];
    O_1c61e0* m;
    F_1c61e0 Run();
};
F_1c61e0 C_1c61e0::Run() {
    F_1c61e0 x;
    ((owners::X_2647e0 *)m)->FUN_002647e0((hulk_intptr)(&x), (hulk_intptr)1, 4, (hulk_intptr)1);
    return x;
}