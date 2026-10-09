typedef unsigned int u32;
extern void __stdcall Init(void*, void*, int, int);
struct Obj {
    void* vf;
};
Obj* __fastcall Target(Obj* self) {
    Init((void*)0x4e6328, (void*)0x4e6320, 0x30, 4);
    self->vf = (void*)0x429434;
    return self;
}