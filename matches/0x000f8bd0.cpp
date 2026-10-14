typedef unsigned int u32_f8bd0;
extern void thunk_FUN_00267090(u32_f8bd0);
struct Obj_f8bd0 {
    int pad;
    int entries[128];
};
void __fastcall target(Obj_f8bd0* self) {
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