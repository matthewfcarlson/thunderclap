void __stdcall AllocRef(int);
void __fastcall InitSub(void *p);

class Ref {
public:
    virtual void f();
    char pad[0x24];
    Ref* init();
};

Ref* Ref::init() {
    AllocRef(4);
    *(int*)this = 0x428824;
    InitSub((char*)this + 0x28);
    return this;
}
