typedef unsigned int u32;
struct Obj {
    char pad0[0x1c];
    int field1c;
    char pad20[4];
    int(__cdecl* callback)(int, int);
    int field28;
};
void Cleanup(int, Obj*);
int __cdecl Target(Obj* p) {
    if (p && p->field1c && p->callback) {
        int v = *(int*)(p->field1c + 0x14);
        if (v)
            Cleanup(v, p);
        p->callback(p->field28, p->field1c);
        p->field1c = 0;
        return 0;
    }
    return -2;
}