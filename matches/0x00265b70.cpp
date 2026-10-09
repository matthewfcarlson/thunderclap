struct Params {
    int a, b, c, d;
};
struct Obj {
    Obj* Init(Params* p);
};
void* FUN_0008d690(int size);
Obj* g_obj;

void FUN_00265b70(Params* p) {
    if (!p) {
        Params def;
        def.a = 0x10;
        def.b = 0x80;
        def.c = 0x20;
        def.d = 0x10000;
        Obj* o = (Obj*)FUN_0008d690(0x3c);
        if (o) {
            g_obj = o->Init(&def);
            return;
        }
        g_obj = 0;
        return;
    }
    Obj* o = (Obj*)FUN_0008d690(0x3c);
    if (o) {
        g_obj = o->Init(p);
        return;
    }
    g_obj = 0;
}
