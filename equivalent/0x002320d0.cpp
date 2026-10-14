// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_002320d0 @ 0x002320d0
extern "C" void *__cdecl FUN_0008d690(unsigned int size);
extern "C" int __cdecl FUN_00238190(int index);
extern "C" int __cdecl FUN_00266da0(int pool);

struct Spec_2320d0 {
    char pad0[0x28];
    void *source;              // 0x28
};

class RefObj_2320d0 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Owner_2320d0;

class Instance_2320d0 : public RefObj_2320d0 {
public:
    char pad04[0x5c - 4];
    Instance_2320d0 *FUN_0023a2a0(Spec_2320d0 *spec, int a, Owner_2320d0 *owner, int b);
    void FUN_002326d0(Instance_2320d0 *other);
};

class Owner_2320d0 {
public:
    char pad0[0x14];
    RefObj_2320d0 *primary;           // 0x14
    Instance_2320d0 *secondary;           // 0x18
    bool FUN_002320d0(Spec_2320d0 *spec, int a, int b);
};

bool Owner_2320d0::FUN_002320d0(Spec_2320d0 *spec, int a, int b)
{
    if (spec == 0)
        return false;
    if (spec->source == 0)
        return true;
    int oldPool = FUN_00266da0(FUN_00238190(3));
    Instance_2320d0 *mem = (Instance_2320d0 *)FUN_0008d690(0x5c);
    Instance_2320d0 *inst = 0;
    if (mem)
        inst = mem->FUN_0023a2a0(spec, a, this, b);
    if (secondary == 0) {
        if (inst)
            inst->AddRef();
        if (primary)
            primary->Release();
        primary = inst;
    } else {
        secondary->FUN_002326d0(inst);
    }
    if (inst)
        inst->AddRef();
    if (secondary)
        secondary->Release();
    secondary = inst;
    FUN_00266da0(oldPool);
    return true;
}
