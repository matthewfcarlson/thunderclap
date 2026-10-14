extern "C" char DAT_00432578[];
extern int gCount_31bcf0;
extern void __stdcall ReleaseResource(void*);
extern void __cdecl FreeArray(void*);

class d3dPrimStream {
  public:
    int vtable;
    char pad[0x128];
    void** resources;
};

void __fastcall FUN_0031bcf0(d3dPrimStream* self) {
    self->vtable = ((int)DAT_00432578);
    int i = 0;
    if (gCount_31bcf0 > 0) {
        do {
            ReleaseResource(self->resources[i]);
            ++i;
        } while (i < gCount_31bcf0);
    }
    FreeArray(self->resources);
}
