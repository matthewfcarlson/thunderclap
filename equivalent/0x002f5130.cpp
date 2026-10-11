// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_002f5130 @ 0x002f5130
extern "C" void* __cdecl FUN_00263ea0(unsigned int size);
inline void* operator new(unsigned int, void* p) throw() { return p; }

class __declspec(novtable) LoaderBase {
  public:
    virtual void slot0();
    int f04;
    int id;
    int f0c;
    int f10;
    LoaderBase(int i) { f04 = 0; id = i; f0c = 0; f10 = 0; }
};

namespace physics {
class ExportInfoLoader : public LoaderBase {
  public:
    ExportInfoLoader() : LoaderBase(0x7030) {}
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
};
}

struct Raw {
    LoaderBase* FUN_00308020();
    LoaderBase* FUN_00308060();
    LoaderBase* FUN_002f7060();
    LoaderBase* FUN_002f2c70();
};

struct Registry { void FUN_00265210(LoaderBase*, int); };
extern "C" Registry* DAT_00527c58;

void FUN_002f5130(){
    void* mem = FUN_00263ea0(0x14);
    LoaderBase* l = 0;
    if (mem) l = new (mem) physics::ExportInfoLoader();
    DAT_00527c58->FUN_00265210(l, 0x7030);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw*)mem)->FUN_00308020() : 0;
    DAT_00527c58->FUN_00265210(l, 0x7010000);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw*)mem)->FUN_00308060() : 0;
    DAT_00527c58->FUN_00265210(l, 0x7010025);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw*)mem)->FUN_002f7060() : 0;
    DAT_00527c58->FUN_00265210(l, 0x7011000);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw*)mem)->FUN_002f2c70() : 0;
    DAT_00527c58->FUN_00265210(l, 0x7011010);
}
