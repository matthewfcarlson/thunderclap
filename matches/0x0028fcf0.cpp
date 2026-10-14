struct Owner_28fcf0 {
    void* Get();
};
extern "C" int __cdecl FUN_00344e74(void*, int, const char*, const char*, int);
extern "C" const char g1_28fcf0[];
extern "C" const char g2_28fcf0[];
void* __fastcall FUN_0028fcf0(Owner_28fcf0* self, void*) {
    void* p = self->Get();
    while (p) {
        if (FUN_00344e74(p, 0, g1_28fcf0, g2_28fcf0, 0))
            break;
        p = self->Get();
    }
    return p;
}