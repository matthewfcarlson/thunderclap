struct Owner {
    void* Get();
};
extern "C" int __cdecl FUN_00344e74(void*, int, const char*, const char*, int);
extern "C" const char g1[];
extern "C" const char g2[];
void* __fastcall FUN_0028fcf0(Owner* self, void*) {
    void* p = self->Get();
    while (p) {
        if (FUN_00344e74(p, 0, g1, g2, 0))
            break;
        p = self->Get();
    }
    return p;
}