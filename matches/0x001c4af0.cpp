#include "decls/data/game/Render.h"

struct Obj_1c4af0 {
    char pad[8];
    int a;
    int b;
};
int __fastcall target(Obj_1c4af0* p) {
    if (p->a == (*(int*)&DAT_004e2330) && p->b == (*(int*)&DAT_004e2334))
        return 1;
    return 0;
}