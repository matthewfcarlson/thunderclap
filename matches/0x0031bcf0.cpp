extern int gCount;
extern void __stdcall ReleaseResource(void*);
extern void __cdecl FreeArray(void*);

class d3dPrimStream {
  public:
    int vtable;
    char pad[0x128];
    void** resources;
};

void __fastcall FUN_0031bcf0(d3dPrimStream* self) {
    self->vtable = 0x432578;
    int i = 0;
    if (gCount > 0) {
        do {
            ReleaseResource(self->resources[i]);
            ++i;
        } while (i < gCount);
    }
    FreeArray(self->resources);
}
