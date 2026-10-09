struct Obj { int Init(); void Existing(); };
extern Obj *gThing;
extern void * __cdecl Alloc(int);
void __cdecl FUN_002f2e20() {
    if (!gThing) {
        Obj *p = (Obj *)Alloc(0x808);
        if (p) { gThing = (Obj *)p->Init(); return; }
        gThing = 0;
        return;
    }
    gThing->Existing();
}