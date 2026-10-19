// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 8/8)
// CGrabTrack::vfunc_10 @ 0x0005b1a0
namespace fight {
class Params {
public:
    virtual void v0();
};
}

class CFightParams : public fight::Params {
public:
    virtual void v1();
    struct Table_5b1a0 *FUN_000592a0();
};

struct Skeleton {
    int FUN_0027b200(int a, int b);
};

struct Binding_5b1a0 {
    Skeleton *FUN_002226b0();
};

struct Table_5b1a0 {
    Binding_5b1a0 *FUN_00059a40();
};

class GrabAction;
void *FUN_0008d690(unsigned int size);

class GrabAction {
public:
    GrabAction *FUN_0001de50(int a1, void *track, CFightParams *params, int index);
};

class CGrabTrack {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual GrabAction *vfunc_10(int a1, int a2, fight::Params *params);
    virtual void vfunc_11();
    char pad04[0x14];
    int key0;
    int key1;
};

GrabAction *CGrabTrack::vfunc_10(int a1, int a2, fight::Params *params)
{
    CFightParams *fp = dynamic_cast<CFightParams *>(params);
    if (fp == 0)
        return 0;
    Table_5b1a0 *table = fp->FUN_000592a0();
    Binding_5b1a0 *binding = table->FUN_00059a40();
    if (binding == 0)
        return 0;
    int index = binding->FUN_002226b0()->FUN_0027b200(key0, key1);
    if (index < 0)
        return 0;
    GrabAction *mem = (GrabAction *)FUN_0008d690(0x40);
    if (mem == 0)
        return 0;
    return mem->FUN_0001de50(a1, this, fp, index);
}
