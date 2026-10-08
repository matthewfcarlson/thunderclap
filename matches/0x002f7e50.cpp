extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Alloc { void* init(); };
struct Obj { char pad[8]; void* member; };
void __fastcall FUN_002f7e50(Obj* self) {
    if (self->member == 0) {
        void* p = FUN_0008d690(0x6c);
        void* r;
        if (p != 0) {
            r = ((Alloc*)p)->init();
        } else {
            r = 0;
        }
        self->member = r;
    }
}
