// STATUS: equivalent (tools/equiv.py level 3: 2865 inputs, branch coverage 4/4)
// FUN_00283730 @ 0x00283730
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
extern "C" char DAT_0042c48c[];
extern "C" char DAT_0042c52c[];
void *FUN_0008d6d0(unsigned int size);
void *thunk_FUN_0008d690(unsigned int size);

class CMotionTrail {
public:
    int vt;
    char pad1[0x0c];
    int f10;
    char pad2[0x2c];
    int f40;
    int f44;
    char pad3[0x1c];
    void *f64;
    char pad4[0x0c];
    void *f74;
    void *f78;
    void FUN_002a5060();
};

class CMotionTrailQueue {
public:
    int vt;
    char pad1[0x54];
    int f58;
    unsigned char *flags;
    void FUN_002a4e10(int n);
    void FUN_002a4500(int idx, CMotionTrail *t);
    CMotionTrailQueue *FUN_00283730();
};

CMotionTrailQueue *CMotionTrailQueue::FUN_00283730()
{
    FUN_002a4e10(6);
    vt = (int)DAT_0042c48c;
    f58 = 1;
    flags = (unsigned char *)FUN_0008d6d0(0x30);
    for (int i = 0; i < 6; i++) {
        CMotionTrail *t = (CMotionTrail *)thunk_FUN_0008d690(0x88);
        if (t) {
            t->FUN_002a5060();
            t->vt = (int)DAT_0042c52c;
            t->f40 = 0;
            t->f44 = 0;
            t->f10 = 1;
            t->f64 = FUN_0008d6d0(8000);
            t->f74 = FUN_0008d6d0(0x18);
            t->f78 = FUN_0008d6d0(0x48);
        }
        FUN_002a4500(i, t);
        flags[i * 8 + 4] = 0;
    }
    return this;
}
