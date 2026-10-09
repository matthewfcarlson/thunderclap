typedef unsigned int u32;
extern void* gPtr;
extern int gCount;
void __cdecl Init(void*, void*);
struct Sub {
    void Close();
};
struct Obj {
    u32 vf;
    char pad[0x54];
    void Tail();
};
void __fastcall Target(Obj* self) {
    void* p = gPtr;
    self->vf = 0x42aa7c;
    Init(p, self);
    --gCount;
    ((Sub*)((char*)self + 0x58))->Close();
    self->Tail();
}
