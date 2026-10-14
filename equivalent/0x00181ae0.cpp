// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// hulkfight::motion::SmartPropIsCargoCondition::vfunc_6 @ 0x00181ae0
extern "C" void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern char DAT_00494b44[];
extern char DAT_00494b60[];

struct Sink {
    bool FUN_001d4e20();
};
struct Part {
    char pad[0xec];
    Sink *sink;
};

struct Fighter {
    char pad[0x128];
    Part *part;
    Part *FUN_00035ef0(int index);
};

struct Owner {
    char pad[1];
};
Owner *__fastcall FUN_000592a0(void *obj);
Fighter *__fastcall FUN_00059a30(Owner *o);

class SmartPropIsCargoCondition {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(int a1, void *subject, int a3);
    char pad04[8];
    int index;
};

bool SmartPropIsCargoCondition::vfunc_6(int a1, void *subject, int a3)
{
    if (FUN_00344e74(subject, 0, DAT_00494b44, DAT_00494b60, 0) == 0)
        return false;
    bool result = false;
    Fighter *f = FUN_00059a30(FUN_000592a0(subject));
    if (f != 0) {
        Part *part;
        if (index < 0) {
            part = f->part;
        } else if (index < 8) {
            part = (Part *)f->FUN_00035ef0(index);
        } else {
            return result;
        }
        if (part != 0)
            result = part->sink->FUN_001d4e20();
    }
    return result;
}
