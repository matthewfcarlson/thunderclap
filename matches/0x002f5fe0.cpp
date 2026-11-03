#include "gen/owners.h"
struct Manager_2f5fe0 {
};
struct Owner_2f5fe0 {
    char pad[0x284];
    Manager_2f5fe0* mgr;
};
extern "C" void __cdecl FUN_002f5fe0(void * owner, float* dst) {
    float value;
    ((owners::X_2647e0 *)(((Owner_2f5fe0 *)owner)->mgr))->FUN_002647e0((hulk_intptr)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
    dst[1] = value;
    ((owners::X_2647e0 *)(((Owner_2f5fe0 *)owner)->mgr))->FUN_002647e0((hulk_intptr)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
    dst[2] = value;
    ((owners::X_2647e0 *)(((Owner_2f5fe0 *)owner)->mgr))->FUN_002647e0((hulk_intptr)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
    dst[3] = value;
    ((owners::X_2647e0 *)(((Owner_2f5fe0 *)owner)->mgr))->FUN_002647e0((hulk_intptr)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
    dst[4] = value;
    ((owners::X_2647e0 *)(((Owner_2f5fe0 *)owner)->mgr))->FUN_002647e0((hulk_intptr)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
    dst[5] = value;
    ((owners::X_2647e0 *)(((Owner_2f5fe0 *)owner)->mgr))->FUN_002647e0((hulk_intptr)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
    dst[6] = value;
}