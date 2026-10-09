class Ref { public: virtual void First(); virtual void Release(); };
class Base { public: Base(void*); };
class SimStateHairclub : public Base {
public:
    char pad0[0x85];
    unsigned char flag;
    char pad1[2];
    Ref* mRef;
    SimStateHairclub(Ref* r, void* p);
};
SimStateHairclub::SimStateHairclub(Ref* r, void* p) : Base(p) {
    *(void**)this = (void*)0x4319a4;
    mRef = 0;
    if (r) r->First();
    if (mRef) mRef->Release();
    mRef = r;
    flag = 1;
}