#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"

struct Temp_1eb560 {
    char pad[0x48];
    void SetName(const char*);
};
struct Obj_1eb560 {};
struct Owner_1eb560 {
};
struct Renderer_1eb560 {
    void Draw(Temp_1eb560*, int, int, float);
};
void Build(Obj_1eb560*, Temp_1eb560*);
struct C_1eb560 {
    Renderer_1eb560* m0;
    Owner_1eb560* m4;
    char m8;
    void Fn(hulk_intptr);
};
void C_1eb560::Fn(hulk_intptr t) {
    Temp_1eb560 a;
    ((owners::Obj_1ef320 *)&a)->FUN_001ef320();
    a.SetName(DAT_00424208);
    a.SetName(DAT_00424200);
    Obj_1eb560* o = ((Obj_1eb560 *)((owners::C_86310 *)m4)->FUN_00086310());
    if (o)
        Build(o, &a);
    if (m8)
        m0->Draw(&a, 0, t, 100.0f);
    ((owners::C_1ef350 *)&a)->FUN_001ef350();
}