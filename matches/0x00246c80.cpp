struct Obj {
    char pad[0x1c];
    void* reader;
    char pad2[4];
    unsigned count;
};
typedef bool(__cdecl* ReadFn)(void*, const void*, unsigned);

bool __fastcall FUN_00246c80(Obj* self) {
    unsigned i = 0;
    if (self->count > 0) {
        do {
            void* r = self->reader;
            if (!((ReadFn*)r)[1](r, (const void*)0x4cc0c8, 4))
                return false;
            ++i;
        } while (i < self->count);
    }
    return true;
}
