#include "decls/data/game/global.h"

struct Temp_1eb6c0 {
    char pad[0x48];
    void Init();
    void SetName(const char*);
    void Finish();
};
struct Obj_1eb6c0 {};
struct Owner_1eb6c0 {
    Obj_1eb6c0* Get();
};
struct Renderer_1eb6c0 {
    void Draw(Temp_1eb6c0*, int, int, float);
};
void Build(Obj_1eb6c0*, Temp_1eb6c0*);
struct C_1eb6c0 {
    Renderer_1eb6c0* m0;
    Owner_1eb6c0* m4;
    char m8;
    void Fn(int);
};
void C_1eb6c0::Fn(int t) {
    Temp_1eb6c0 a;
    a.Init();
    a.SetName(DAT_00424208);
    a.SetName(DAT_00424214);
    Obj_1eb6c0* o = m4->Get();
    if (o)
        Build(o, &a);
    if (m8)
        m0->Draw(&a, 0, t, 100.0f);
    a.Finish();
}