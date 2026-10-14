// STATUS: equivalent (tools/equiv.py level 3: 153 inputs, branch coverage 10/10)
// FUN_000afbf0 @ 0x000afbf0
void* __cdecl FUN_0008d690(unsigned size);
class Source {
public:
    virtual void AddRef();
    virtual void Release();
    char pad[0xc];
    int count;
};
struct Elem { int f0; char pad[0x2c - 4]; int f2c; };
class CHapticController {
public:
    virtual void v0();
    int f4;
    char f8;
    char pad9[3];
    Source* src;
    int count;
    Elem* items;
    int f18;
    CHapticController(Source* s);
};
CHapticController::CHapticController(Source* s) {
    f4 = 0;
    f8 = 1;
    src = 0;
    count = 0;
    items = 0;
    f18 = 0;
    if (s) s->AddRef();
    if (src) src->Release();
    src = s;
    int n = s->count;
    count = n;
    int* raw = (int*)FUN_0008d690(n * 0x30 + 4);
    if (!raw) {
        items = 0;
        return;
    }
    raw[0] = n;
    Elem* e = (Elem*)(raw + 1);
    for (int i = 0; i < n; i++) {
        e[i].f0 = 0;
        e[i].f2c = 0;
    }
    items = e;
}
