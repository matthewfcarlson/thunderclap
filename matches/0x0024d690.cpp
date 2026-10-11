extern "C" char DAT_00429434[];
extern "C" char DAT_004e6320[];
extern "C" char DAT_004e6328[];
typedef unsigned int u32;
extern void __stdcall Init(void*, void*, int, int);
struct Obj {
    void* vf;
};
Obj* __fastcall Target(Obj* self) {
    Init((void*)((int)DAT_004e6328), (void*)((int)DAT_004e6320), 0x30, 4);
    self->vf = (void*)((int)DAT_00429434);
    return self;
}