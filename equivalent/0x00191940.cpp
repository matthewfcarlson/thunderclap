// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 16/16)
// FUN_00191940 @ 0x00191940
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class ImpulseVelocityTrack {
public:
    void FUN_0018ecb0();
    void FUN_0018ecc0();
    void FUN_0018ecf0();
    void FUN_0018ed30();
    void FUN_0018ed70();
    void FUN_0018eda0();
    void FUN_0018edc0();
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

class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234ba0(const char* name);
    ParamNameConstListBase(const char* name) { FUN_00234ba0(name); }
};
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
template <class T>
class ParamVector : public ParamVectorBase {
public:
    ParamVector(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

struct ParamRegistry {
};
extern ParamRegistry DAT_004e1530;
extern int DAT_004e1534;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00191940()
{
    if (DAT_004e1534 == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<ImpulseVelocityTrack>("timeBegin", &ImpulseVelocityTrack::FUN_0018ecb0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamNameConstList<ImpulseVelocityTrack>("joint", &ImpulseVelocityTrack::FUN_0018ecc0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamVector<ImpulseVelocityTrack>("offset", &ImpulseVelocityTrack::FUN_0018ecf0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamVector<ImpulseVelocityTrack>("velocity", &ImpulseVelocityTrack::FUN_0018ed30);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamVector<ImpulseVelocityTrack>("velocityMax", &ImpulseVelocityTrack::FUN_0018ed70);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamBool<ImpulseVelocityTrack>("useCollision", &ImpulseVelocityTrack::FUN_0018eda0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<ImpulseVelocityTrack>("collisionScale", &ImpulseVelocityTrack::FUN_0018edc0);
        FUN_002347b0(&DAT_004e1530, params, 7);
    }
    DAT_004e1534++;
}
