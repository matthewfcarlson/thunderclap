typedef unsigned int u32;
struct Obj { char pad[0x214]; u32 value; };
void FUN_002d6d10(Obj*, int*);
void FUN_002e6ab0(int*, u32);
void FUN_002d6ed0(Obj* self, int** out) {
    if (out && *out) {
        int* p = *out;
        FUN_002d6d10(self, p);
        FUN_002e6ab0(p, self->value);
        *out = 0;
    }
}