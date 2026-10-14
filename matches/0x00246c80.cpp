extern "C" char DAT_004cc0c8[];
struct Obj_246c80 {
    char pad[0x1c];
    void* reader;
    char pad2[4];
    unsigned count;
};
typedef bool(__cdecl* ReadFn_246c80)(void*, const void*, unsigned);

bool __fastcall FUN_00246c80(Obj_246c80* self) {
    unsigned i = 0;
    if (self->count > 0) {
        do {
            void* r = self->reader;
            if (!((ReadFn_246c80*)r)[1](r, (const void*)((int)DAT_004cc0c8), 4))
                return false;
            ++i;
        } while (i < self->count);
    }
    return true;
}
