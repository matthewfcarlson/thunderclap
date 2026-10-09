struct Helper { void Init(void (*)(), void*); };
struct Obj { char pad[0x2d8]; void Run(); };
void Obj::Run() {
    ((Helper*)((char*)this + 0x310))->Init((void(*)())0x66930, (char*)this + 0x310);
    ((Helper*)((char*)this + 0x2f4))->Init((void(*)())0x66a00, (char*)this + 0x2f4);
    ((Helper*)((char*)this + 0x2d8))->Init((void(*)())0x66930, (char*)this + 0x2d8);
}