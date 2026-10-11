// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 14/14)
// FUN_0014a6f0 @ 0x0014a6f0
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class GrappleStruggleTrack {
public:
    void FUN_00146be0();
    void FUN_00146bf0();
    void FUN_00146c10();
    void FUN_00146c30();
    void FUN_00146c50();
    void FUN_00146c70();
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
extern ParamRegistry DAT_004e0ff4;
extern int DAT_004e0ff8;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0014a6f0()
{
    if (DAT_004e0ff8 == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<GrappleStruggleTrack>("timeBegin", &GrappleStruggleTrack::FUN_00146be0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<GrappleStruggleTrack>("timeEnd", &GrappleStruggleTrack::FUN_00146bf0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<GrappleStruggleTrack>("timeInput", &GrappleStruggleTrack::FUN_00146c10);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<GrappleStruggleTrack>("chargeRateMin", &GrappleStruggleTrack::FUN_00146c30);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<GrappleStruggleTrack>("chargeRateMax", &GrappleStruggleTrack::FUN_00146c50);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<GrappleStruggleTrack>("chargeButtonRate", &GrappleStruggleTrack::FUN_00146c70);
        FUN_002347b0(&DAT_004e0ff4, params, 6);
    }
    DAT_004e0ff8++;
}
