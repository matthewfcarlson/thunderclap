struct Item {
    int a;
    void* p;
    int c, d;
};
struct Obj {
    char pad[0x30];
    int count;
    char pad34[4];
    Item* items;
    char pad3c[0x64];
    void* a0;
    char pada4[8];
    void* ac;
    void** b0;
    char padb4;
    unsigned char b5;
};
extern void __cdecl Process(void* ctx, void* p);
extern void __cdecl Finish(Obj*);
void __cdecl Target(void* ctx, Obj* s) {
    if (s->items) {
        int i = 0;
        if (s->count > 0) {
            do {
                Process(ctx, s->items[i].p);
                ++i;
            } while (i < s->count);
        }
        Process(ctx, s->items);
    }
    Process(ctx, s->a0);
    Process(ctx, s->ac);
    if (s->b0) {
        int i = 0;
        if (s->b5 > 0) {
            do {
                Process(ctx, s->b0[i]);
                ++i;
            } while (i < (int)s->b5);
        }
        Process(ctx, s->b0);
    }
    Finish(s);
}
