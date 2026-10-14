extern "C" char DAT_0042aa7c[];
typedef unsigned int u32_260680;
extern void* gPtr;
extern int gCount_260680;
void __cdecl Init(void*, void*);
struct Sub_260680 {
    void Close();
};
struct Obj_260680 {
    u32_260680 vf;
    char pad[0x54];
    void Tail();
};
void __fastcall Target(Obj_260680* self) {
    void* p = gPtr;
    self->vf = ((int)DAT_0042aa7c);
    Init(p, self);
    --gCount_260680;
    ((Sub_260680*)((char*)self + 0x58))->Close();
    self->Tail();
}
