// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::motion::PropMissionCriticalCondition::vfunc_6 @ 0x00181880
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

struct Status_181880 {
    char FUN_001d4e40();
};

struct Part_181880 {
    char pad0[0xec];
    Status_181880 *status;
};

struct Res_181880 {
    char pad00[0x128];
    Part_181880 *mainPart;
    Part_181880 *FUN_00035ef0(int index);
};

struct Resolver_181880 {
    Res_181880 *FUN_00059a30();
};

struct Target_181880 {
    Resolver_181880 *FUN_000592a0();
};

namespace hulkfight { namespace motion { class PropMissionCriticalCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, void *obj, int c);
    char pad04[8];
    int partIndex;      // +0x0c
    char wanted;        // +0x10
}; }}

bool hulkfight::motion::PropMissionCriticalCondition::vfunc_6(int a, void *obj, int c) {
    if (!FUN_00344e74(obj, 0, DAT_00494b44, DAT_00494b60, 0)) {
        return false;
    }
    bool result = false;
    Res_181880 *res = ((Target_181880 *)obj)->FUN_000592a0()->FUN_00059a30();
    if (res != 0) {
        Part_181880 *part;
        if (partIndex < 0) {
            part = res->mainPart;
        } else if (partIndex < 8) {
            part = res->FUN_00035ef0(partIndex);
        } else {
            return false;
        }
        if (part != 0) {
            char want = wanted;
            result = part->status->FUN_001d4e40() == want;
        }
    }
    return result;
}
