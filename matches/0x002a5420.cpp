extern "C" void __cdecl FUN_002a5260();
extern "C" char DAT_0042d9dc[];
class Controller_2a5420 {
  public:
    char pad[0x40];
    int a;
    int pad44;
    int b;
    int c;
    int d;
    int e;
};
void __fastcall Init(void*);
Controller_2a5420* __fastcall Target(Controller_2a5420* self) {
    Init((void*)(self));
    *(int*)((char*)self + 0x40) = 0;
    *(int*)((char*)self + 0x48) = 0;
    *(int*)((char*)self + 0x4c) = 0;
    *(int*)self = ((int)DAT_0042d9dc);
    *(int*)((char*)self + 0x50) = ((int)(void (__cdecl*)())&FUN_002a5260);
    return self;
}