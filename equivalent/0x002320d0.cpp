// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_002320d0 @ 0x002320d0
extern "C" void *__cdecl FUN_0008d690(unsigned int size);
extern "C" int __cdecl FUN_00238190(int index);
extern "C" int __cdecl FUN_00266da0(int pool);

struct Spec {
    char pad0[0x28];
    void *source;              // 0x28
};

class RefObj {
public:
    virtual void AddRef();
    virtual void Release();
};

class Owner;

class Instance : public RefObj {
public:
    char pad04[0x5c - 4];
    Instance *FUN_0023a2a0(Spec *spec, int a, Owner *owner, int b);
    void FUN_002326d0(Instance *other);
};

class Owner {
public:
    char pad0[0x14];
    RefObj *primary;           // 0x14
    Instance *secondary;           // 0x18
    bool FUN_002320d0(Spec *spec, int a, int b);
};

bool Owner::FUN_002320d0(Spec *spec, int a, int b)
{
    if (spec == 0)
        return false;
    if (spec->source == 0)
        return true;
    int oldPool = FUN_00266da0(FUN_00238190(3));
    Instance *mem = (Instance *)FUN_0008d690(0x5c);
    Instance *inst = 0;
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
