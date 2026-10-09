typedef unsigned int u32;
extern void thunk_FUN_00267090(u32);
struct Obj {
    int pad;
    int entries[128];
};
void __fastcall target(Obj* self) {
    int i = 0;
    do {
        int v = self->entries[i];
        if (v == 0)
            return;
        thunk_FUN_00267090(v);
        self->entries[i] = 0;
        ++i;
    } while (i < 128);
}