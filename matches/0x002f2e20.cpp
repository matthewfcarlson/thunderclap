struct Obj_2f2e20 {
    int Init();
    void Existing();
};
extern Obj_2f2e20* gThing_2f2e20;
extern void* __cdecl Alloc(int);
void __cdecl FUN_002f2e20() {
    if (!gThing_2f2e20) {
        Obj_2f2e20* p = (Obj_2f2e20*)Alloc(0x808);
        if (p) {
            gThing_2f2e20 = (Obj_2f2e20*)p->Init();
            return;
        }
        gThing_2f2e20 = 0;
        return;
    }
    gThing_2f2e20->Existing();
}