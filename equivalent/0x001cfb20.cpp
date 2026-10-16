// STATUS: equivalent (tools/equiv.py level 3: 581 inputs, branch coverage 44/44)
// FUN_001cfb20 @ 0x001cfb20
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
inline void *operator new(unsigned int, void *p) throw() { return p; }

enum eMissionObjectiveState { eMOS_dummy };

template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void *get() { return ((char*)&DAT_0048e100); } };
template <> struct TypeTag<int> { static const void *get() { return ((char*)&DAT_0048e134); } };
template <> struct TypeTag<float> { static const void *get() { return ((char*)&DAT_0048e128); } };
template <> struct TypeTag<bool> { static const void *get() { return &DAT_0048e0e4; } };
template <> struct TypeTag<const char *> { static const void *get() { return ((char*)&DAT_0048e0f0); } };
template <> struct TypeTag<eMissionObjectiveState> { static const void *get() { return &DAT_004c55f0; } };

class __declspec(novtable) MethodBase_1cfb20 {
  public:
    virtual void m0();
    char pad_04[0xc];
    char argType;
    char pad_11[7];
    char retType;
    char pad_19[3];
    void FUN_001d0480(const char *, int);
    MethodBase_1cfb20(const char *n, int k) { FUN_001d0480(n, k); }
};

template <class T, class R, class A>
class Method1 : public MethodBase_1cfb20 {
  public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) : MethodBase_1cfb20(name, 1) {
        fn = f;
        retType = FUN_001d04d0(TypeTag<R>::get());
        argType = FUN_001d04d0(TypeTag<A>::get());
    }
    Fn fn;
};

template <class T, class R, class A>
class Closure1 : public Method1<T, R, A> {
  public:
    Closure1(const char *name, T *o, typename Method1<T, R, A>::Fn f) : Method1<T, R, A>(name, f), owner(o) {}
    T *owner;
};

class CScenarioManager {
  public:
    virtual void v0();
    int f4;
    int FUN_001cc5e0();
    void FUN_001cc620(int);
    int FUN_001cc840();
    float FUN_001cc860();
    void FUN_001cc870(float);
    float FUN_001cc880();
    void FUN_001cc890(float);
    float FUN_001cc8a0();
    void FUN_001cc8e0(bool);
    bool FUN_001cc8f0();
    int FUN_001cc900();
    void FUN_001cc910(int);
    float FUN_001cc990(int);
    void FUN_001cc9b0(int, float);
    int FUN_001cc9d0(float, const char *);
    void FUN_001cca80(int);
    float FUN_001ccc00();
    void FUN_001ccc10(float);
    float FUN_001ccc20();
    void FUN_001ccc30(float);
    int FUN_001ccc80();
    void FUN_001ccc90(int);
    float FUN_001ccca0();
    void FUN_001cccb0(float);
    void FUN_001cce60(const char *);
    void FUN_001cce80(float, const char *);
    void FUN_001cced0();
    const char * FUN_001ccf50(int);
    void FUN_001ccf70(int, const char *);
    eMissionObjectiveState FUN_001ccfa0(int);
    void FUN_001ccfc0(int, int);
    void FUN_001ccfe0(bool);
    bool FUN_001ccff0();
    void FUN_001cd5b0(float);
    void FUN_001cfb20(int arg);
};

struct Raw_1cfb20 {
    void *FUN_001ce440(const char *name, CScenarioManager *o, void (CScenarioManager::*fn)(int, float));
    void *FUN_001ce4e0(const char *name, CScenarioManager *o, int (CScenarioManager::*fn)(float, const char *));
    void *FUN_001ce590(const char *name, CScenarioManager *o, void (CScenarioManager::*fn)(float, const char *));
    void *FUN_001ce7c0(const char *name, CScenarioManager *o, void (CScenarioManager::*fn)(int, const char *));
    void *FUN_001ce8f0(const char *name, CScenarioManager *o, void (CScenarioManager::*fn)(int, int));
};

struct Registry_1cfb20 {
    void FUN_001d3b70(const char *name, void *closure);
    void FUN_001cf160(const char *name, CScenarioManager *o, int (CScenarioManager::*fn)());
    void FUN_001cf1d0(const char *name, CScenarioManager *o, float (CScenarioManager::*fn)());
    void FUN_001cf2e0(const char *name, CScenarioManager *o, bool (CScenarioManager::*fn)());
    void FUN_001cf490(const char *name, CScenarioManager *o, void (CScenarioManager::*fn)());
};
Registry_1cfb20 *FUN_001d4c90();

void CScenarioManager::FUN_001cfb20(int arg)
{
    f4 = arg;
    Registry_1cfb20 *reg = FUN_001d4c90();
    if (reg) {
    {
        void *mem = FUN_0008d690(0x24);
        Closure1<CScenarioManager, void, int> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, int>("sm_SetMissionState", this, &CScenarioManager::FUN_001cc620);
        reg->FUN_001d3b70("sm_SetMissionState", c);
    }
    reg->FUN_001cf160("sm_GetMissionState", this, &CScenarioManager::FUN_001cc840);
    reg->FUN_001cf1d0("sm_GetTimeElapsed", this, &CScenarioManager::FUN_001cc860);
    {
        void *mem = FUN_0008d690(0x24);
        Closure1<CScenarioManager, void, float> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, float>("sm_SetTimeElapsed", this, &CScenarioManager::FUN_001cc870);
        reg->FUN_001d3b70("sm_SetTimeElapsed", c);
    }
    reg->FUN_001cf1d0("sm_GetTime", this, &CScenarioManager::FUN_001cc8a0);
    reg->FUN_001cf1d0("sm_GetScenarioEndTime", this, &CScenarioManager::FUN_001cc880);
    {
        void *mem = FUN_0008d690(0x24);
        Closure1<CScenarioManager, void, float> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, float>("sm_SetScenarioEndTime", this, &CScenarioManager::FUN_001cc890);
        reg->FUN_001d3b70("sm_SetScenarioEndTime", c);
    }
    {
        void *mem = FUN_0008d690(0x24);
        Closure1<CScenarioManager, void, bool> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, bool>("sm_FreezeTime", this, &CScenarioManager::FUN_001cc8e0);
        reg->FUN_001d3b70("sm_FreezeTime", c);
    }
    reg->FUN_001cf2e0("sm_IsTimeFrozen", this, &CScenarioManager::FUN_001cc8f0);
    reg->FUN_001cf160("sm_GetCheckpoint", this, &CScenarioManager::FUN_001cc900);
    {
        void *mem = FUN_0008d690(0x24);
        Closure1<CScenarioManager, void, int> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, int>("sm_SetCheckpoint", this, &CScenarioManager::FUN_001cc910);
        reg->FUN_001d3b70("sm_SetCheckpoint", c);
    }
    {
        void *mem = FUN_0008d690(0x24);
        Closure1<CScenarioManager, float, int> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, float, int>("sm_GetVar", this, &CScenarioManager::FUN_001cc990);
        reg->FUN_001d3b70("sm_GetVar", c);
    }
    {
        void *mem = FUN_0008d690(0x24);
        void *c;
        if (mem)
            c = ((Raw_1cfb20 *)mem)->FUN_001ce440("sm_SetVar", this, &CScenarioManager::FUN_001cc9b0);
        else
            c = 0;
        reg->FUN_001d3b70("sm_SetVar", c);
    }
    reg->FUN_001cf160("sm_GetMaxVarCount", this, &CScenarioManager::FUN_001cc5e0);
    {
        void *mem = FUN_0008d690(0x24);
        void *c;
        if (mem)
            c = ((Raw_1cfb20 *)mem)->FUN_001ce4e0("sm_StartTimer", this, &CScenarioManager::FUN_001cc9d0);
        else
            c = 0;
        reg->FUN_001d3b70("sm_StartTimer", c);
    }
    {
        void *mem = FUN_0008d690(0x24);
        Closure1<CScenarioManager, void, int> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, int>("sm_CancelTimer", this, &CScenarioManager::FUN_001cca80);
        reg->FUN_001d3b70("sm_CancelTimer", c);
    }
    reg->FUN_001cf1d0("sm_GetComboTimerLimit", this, &CScenarioManager::FUN_001ccc00);
    reg->FUN_001cf1d0("sm_GetComboTimerCurrent", this, &CScenarioManager::FUN_001ccc20);
    reg->FUN_001cf160("sm_GetComboHitCount", this, &CScenarioManager::FUN_001ccc80);
    reg->FUN_001cf1d0("sm_GetComboScore", this, &CScenarioManager::FUN_001ccca0);
    {
        void *mem = FUN_0008d690(0x24);
        Closure1<CScenarioManager, void, float> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, float>("sm_SetComboTimerLimit", this, &CScenarioManager::FUN_001ccc10);
        reg->FUN_001d3b70("sm_SetComboTimerLimit", c);
    }
    {
        void *mem = FUN_0008d690(0x24);
        Closure1<CScenarioManager, void, float> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, float>("sm_SetComboTimerCurrent", this, &CScenarioManager::FUN_001ccc30);
        reg->FUN_001d3b70("sm_SetComboTimerCurrent", c);
    }
    {
        void *mem = FUN_0008d690(0x24);
        Closure1<CScenarioManager, void, int> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, int>("sm_SetComboHitCount", this, &CScenarioManager::FUN_001ccc90);
        reg->FUN_001d3b70("sm_SetComboHitCount", c);
    }
    {
        void *mem = FUN_0008d690(0x24);
        Closure1<CScenarioManager, void, float> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, float>("sm_SetComboScore", this, &CScenarioManager::FUN_001cccb0);
        reg->FUN_001d3b70("sm_SetComboScore", c);
    }
    {
        void *mem = FUN_0008d690(0x24);
        Closure1<CScenarioManager, void, float> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, float>("sm_Combo", this, &CScenarioManager::FUN_001cd5b0);
        reg->FUN_001d3b70("sm_Combo", c);
    }
    {
        void *mem = FUN_0008d690(0x24);
        void *c;
        if (mem)
            c = ((Raw_1cfb20 *)mem)->FUN_001ce590("sm_AddComboGrade", this, &CScenarioManager::FUN_001cce80);
        else
            c = 0;
        reg->FUN_001d3b70("sm_AddComboGrade", c);
    }
    reg->FUN_001cf490("sm_ResetComboSystem", this, &CScenarioManager::FUN_001cced0);
    {
        void *mem = FUN_0008d690(0x24);
        Closure1<CScenarioManager, void, const char *> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, const char *>("sm_SetComboHitText", this, &CScenarioManager::FUN_001cce60);
        reg->FUN_001d3b70("sm_SetComboHitText", c);
    }
    {
        void *mem = FUN_0008d690(0x24);
        Closure1<CScenarioManager, const char *, int> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, const char *, int>("sm_GetMissionObjective", this, &CScenarioManager::FUN_001ccf50);
        reg->FUN_001d3b70("sm_GetMissionObjective", c);
    }
    {
        void *mem = FUN_0008d690(0x24);
        void *c;
        if (mem)
            c = ((Raw_1cfb20 *)mem)->FUN_001ce7c0("sm_SetMissionObjective", this, &CScenarioManager::FUN_001ccf70);
        else
            c = 0;
        reg->FUN_001d3b70("sm_SetMissionObjective", c);
    }
    {
        void *mem = FUN_0008d690(0x24);
        Closure1<CScenarioManager, eMissionObjectiveState, int> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, eMissionObjectiveState, int>("sm_GetMissionObjectiveState", this, &CScenarioManager::FUN_001ccfa0);
        reg->FUN_001d3b70("sm_GetMissionObjectiveState", c);
    }
    {
        void *mem = FUN_0008d690(0x24);
        void *c;
        if (mem)
            c = ((Raw_1cfb20 *)mem)->FUN_001ce8f0("sm_SetMissionObjectiveState", this, &CScenarioManager::FUN_001ccfc0);
        else
            c = 0;
        reg->FUN_001d3b70("sm_SetMissionObjectiveState", c);
    }
    {
        void *mem = FUN_0008d690(0x24);
        Closure1<CScenarioManager, void, bool> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, bool>("sm_SetTutorialMode", this, &CScenarioManager::FUN_001ccfe0);
        reg->FUN_001d3b70("sm_SetTutorialMode", c);
    }
    reg->FUN_001cf2e0("sm_GetTutorialMode", this, &CScenarioManager::FUN_001ccff0);
    }
}
