struct Obj_1d2e80 {
    char pad[8];
    void* m;
    void F1d1cb0();
    bool target();
};
extern int __cdecl F212d70(void*);
extern void __cdecl F213380(void*, const char*, int);
extern void __cdecl F213600(void*, int);
extern int __cdecl F212f00(void*, int);
extern int __cdecl F212d80(void*, int);
extern const char event[];
bool Obj_1d2e80::target() {
    int v = F212d70(m);
    F1d1cb0();
    F213380(m, event, 5);
    F213600(m, -2);
    int r = F212f00(m, -1);
    if (r != 5) {
        F212d80(m, v);
        return false;
    }
    return true;
}