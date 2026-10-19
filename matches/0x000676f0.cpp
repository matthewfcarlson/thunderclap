extern "C" void __cdecl FUN_00066930();
extern "C" void __cdecl FUN_00066a00();
struct Helper_676f0 {
    void Init(void (*)(), void*);
};
struct Obj_676f0 {
    char pad[0x2d8];
    void Run();
};
void Obj_676f0::Run() {
    ((Helper_676f0*)((char*)this + 0x310))->Init((void (*)())((int)(void (__cdecl*)())&FUN_00066930), (char*)this + 0x310);
    ((Helper_676f0*)((char*)this + 0x2f4))->Init((void (*)())((int)(void (__cdecl*)())&FUN_00066a00), (char*)this + 0x2f4);
    ((Helper_676f0*)((char*)this + 0x2d8))->Init((void (*)())((int)(void (__cdecl*)())&FUN_00066930), (char*)this + 0x2d8);
}