// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 22/22)
// hulkfight::motion::VarCompareCondition::vfunc_6 @ 0x0018cf60
// hulkfight::motion::VarCompareCondition::vfunc_6 @ 0x0018cf60
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

struct Key { char data[8]; };
struct Vars { int FUN_00036e40(Key *key); };
struct Context { Vars *FUN_00059a30(); };
struct Owner { Context *FUN_000592a0(); };

namespace hulkfight { namespace motion {
class VarCompareCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, void *obj, int c);
    char pad04[12];
    Key key;
    unsigned op;
    int value;
};

bool VarCompareCondition::vfunc_6(int a, void *obj, int c)
{
    if (!FUN_00344e74(obj, 0, DAT_00494b44, DAT_00494b60, 0))
        return false;
    Vars *vars = ((Owner *)obj)->FUN_000592a0()->FUN_00059a30();
    int cur = vars->FUN_00036e40(&key);
    int v = value;
    switch (op) {
    case 0: return cur < v;
    case 1: return cur <= v;
    case 2: return cur == v;
    case 3: return cur != v;
    case 4: return cur >= v;
    case 5: return cur > v;
    }
    return false;
}
}}
