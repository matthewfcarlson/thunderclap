class Helper { public: void Init(void*); };
class Obj {
public:
    virtual void f();
    Obj* Make(void* arg);
    unsigned char pad[0x5c];
};
void Obj::f() {}
Obj* Obj::Make(void* arg) {
    ((Helper*)this)->Init(arg);
    *(unsigned int*)((char*)this + 0x58) = 0xff000000;
    *(unsigned int*)((char*)this + 0x50) = 0xff000000;
    *(unsigned int*)((char*)this + 0x54) = 0xff000000;
    *(unsigned int*)this = 0x4338f4;
    *(unsigned char*)((char*)this + 0x48) = 1;
    *(unsigned int*)((char*)this + 0x5c) = 0xffff80ff;
    return this;
}
