extern "C" void __stdcall FUN_00013420(void*, int, int, const float*);
class Obj {
    char pad[0x3d04];

  public:
    void f();
};
void Obj::f() {
    char* p = ((char*)this) + 0x3d04;
    for (int i = 0x14; i != 0; --i) {
        p -= 0x30c;
        FUN_00013420((void*)p, 0x18, 0x20, (const float*)0x329000);
    }
}
