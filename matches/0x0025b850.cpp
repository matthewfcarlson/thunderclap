struct Elem {
    void clean();
    char pad[12];
};
struct Obj {
    char pad[0x10];
    Elem a;
    Elem b;
    Elem arr[10];
};
void prep(void*, Obj*);
void freeobj(void*, Obj*);
extern char bss;
void __cdecl target(void* p, Obj* o) {
    prep(p, o);
    if (o) {
        Elem* e = o->arr + 10;
        int n = 10;
        do {
            --e;
            e->clean();
        } while (--n);
        o->b.clean();
        o->a.clean();
        freeobj(&bss, o);
    }
}