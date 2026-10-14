struct Params {
    int a, b, c, d;
};
struct Obj_265b70 {
    Obj_265b70* Init(Params* p);
};
void* FUN_0008d690(int size);
Obj_265b70* g_obj_265b70;

void FUN_00265b70(Params* p) {
    if (!p) {
        Params def;
        def.a = 0x10;
        def.b = 0x80;
        def.c = 0x20;
        def.d = 0x10000;
        Obj_265b70* o = (Obj_265b70*)FUN_0008d690(0x3c);
        if (o) {
            g_obj_265b70 = o->Init(&def);
            return;
        }
        g_obj_265b70 = 0;
        return;
    }
    Obj_265b70* o = (Obj_265b70*)FUN_0008d690(0x3c);
    if (o) {
        g_obj_265b70 = o->Init(p);
        return;
    }
    g_obj_265b70 = 0;
}
