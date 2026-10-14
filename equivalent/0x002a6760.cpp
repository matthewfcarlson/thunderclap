// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 12/12)
// pure3d::ProceduralVertexAnimController::vfunc_24 @ 0x002a6760
class SimpleFrameController {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void vfunc_24(int, int, int);
};

struct VertexAnimData {
    char pad0[0x1c];
    unsigned int tag;
};

void __cdecl FUN_002a5260();
void __cdecl FUN_002a58e0();
void __cdecl FUN_002a5df0();
void __cdecl FUN_002a6500();
void __cdecl FUN_002a6610();

class ProceduralVertexAnimController : public SimpleFrameController {
  public:
    void vfunc_24(int a, int b, int c);

    char pad04[0x3c - 4];
    VertexAnimData *data;
    char pad40[0x50 - 0x40];
    void (__cdecl *updateFn)();
};

void ProceduralVertexAnimController::vfunc_24(int a, int b, int c) {
    SimpleFrameController::vfunc_24(a, b, c);
    updateFn = FUN_002a5260;
    if (data == 0) {
        return;
    }
    switch (data->tag) {
    case 0x50525650:  // 'PVPR'
        updateFn = FUN_002a58e0;
        break;
    case 0x48535650:  // 'PVSH'
        updateFn = FUN_002a6610;
        break;
    case 0x534e5650:  // 'PVNS'
        updateFn = FUN_002a6500;
        break;
    case 0x56575650:  // 'PVWV'
        updateFn = FUN_002a5df0;
        break;
    default:
        updateFn = FUN_002a5260;
        break;
    }
}
