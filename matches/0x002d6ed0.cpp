typedef unsigned int u32_2d6ed0;
struct Obj_2d6ed0 {
    char pad[0x214];
    u32_2d6ed0 value;
};
void FUN_002d6d10(Obj_2d6ed0*, int*);
void FUN_002e6ab0(int*, u32_2d6ed0);
void FUN_002d6ed0(Obj_2d6ed0* self, int** out) {
    if (out && *out) {
        int* p = *out;
        FUN_002d6d10(self, p);
        FUN_002e6ab0(p, self->value);
        *out = 0;
    }
}