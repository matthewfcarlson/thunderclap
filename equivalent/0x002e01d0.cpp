// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002e01d0 @ 0x002e01d0
// equiv-map: ??0Sub@@QAE@HHH@Z = 0x002c86d0
// equiv-map: ??0PrimGroupBase@pure3d@@QAE@XZ = 0x002a5060
inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* __cdecl FUN_0008d690(unsigned int size);

class Sub {
public:
    Sub(int a, int b, int c) throw();
    virtual void AddRef();
    virtual void Release();
};

namespace pure3d {

class PrimGroupBase {
public:
    virtual void b0();
    char pad04[0x3c];
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    char pad54[4];
    int f58;
    Sub* f5c;
    PrimGroupBase() throw();
};

class PrimGroupStreamed : public PrimGroupBase {
public:
    PrimGroupStreamed(int a, int b, int c);
    virtual void s0();
};

PrimGroupStreamed::PrimGroupStreamed(int a, int b, int c) : PrimGroupBase() {
    f40 = 0;
    f44 = 0;
    f48 = a;
    f4c = b;
    f50 = -1;
    f5c = 0;
    void* mem = FUN_0008d690(0x5c);
    Sub* sub = 0;
    if (mem)
        sub = new (mem) Sub(f48, b, c);
    f5c = sub;
    sub->AddRef();
    f58 = 0;
}

}
