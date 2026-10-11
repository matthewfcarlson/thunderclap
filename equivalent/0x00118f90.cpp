// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 14/14)
// FUN_00118f90 @ 0x00118f90
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class ComputeDropZoneCondition {
public:
    void FUN_00114f10();
    void FUN_00114f30();
    void FUN_00114f50();
    void FUN_00114f60();
    void FUN_00114f80();
    void FUN_00114fa0();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

struct ParamRegistry {
};
extern ParamRegistry DAT_004e0c34;
extern int DAT_004e0c38;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00118f90()
{
    if (DAT_004e0c38 == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<ComputeDropZoneCondition>("increment", &ComputeDropZoneCondition::FUN_00114f10);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<ComputeDropZoneCondition>("heightMax", &ComputeDropZoneCondition::FUN_00114f30);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<ComputeDropZoneCondition>("dropDistance", &ComputeDropZoneCondition::FUN_00114f50);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<ComputeDropZoneCondition>("boostHeightTolerance", &ComputeDropZoneCondition::FUN_00114f60);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<ComputeDropZoneCondition>("useOffset", &ComputeDropZoneCondition::FUN_00114f80);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<ComputeDropZoneCondition>("offset", &ComputeDropZoneCondition::FUN_00114fa0);
        FUN_002347b0(&DAT_004e0c34, params, 6);
    }
    DAT_004e0c38++;
}
