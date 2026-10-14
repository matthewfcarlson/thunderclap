// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001cf690 @ 0x001cf690
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;
extern "C" char __cdecl FUN_001d04d0(const char *);
extern "C" const char DAT_0048e100[];
extern "C" const char DAT_0048e134[];
extern "C" const char DAT_0048e128[];
extern "C" const char DAT_0048e0f0[];
inline void *operator new(unsigned int, void *p) throw() { return p; }

template <class T> struct Tid;
template <> struct Tid<void> { static const char *p() { return DAT_0048e100; } };
template <> struct Tid<int> { static const char *p() { return DAT_0048e134; } };
template <> struct Tid<float> { static const char *p() { return DAT_0048e128; } };
template <> struct Tid<const char *> { static const char *p() { return DAT_0048e0f0; } };

class __declspec(novtable) MethodBase_1cf690 {
public:
    virtual void m0();
    char pad_04[0xc];
    MethodBase_1cf690(const char *n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char *, int);
    void FUN_001d04a0();
};

template <class T, class R, class A, class B>
class Method2 : public MethodBase_1cf690 {
public:
    typedef R (T::*Fn)(A, B);
    Method2(const char *name, Fn f) : MethodBase_1cf690(name, 2) {
        fn = f;
        c18 = FUN_001d04d0(Tid<R>::p());
        c10 = FUN_001d04d0(Tid<A>::p());
        c11 = FUN_001d04d0(Tid<B>::p());
    }
    char c10;
    char c11;
    char pad12[6];
    char c18;
    char pad19[3];
    Fn fn;
};

template <class T, class R, class A, class B>
class Closure2 : public Method2<T, R, A, B> {
public:
    Closure2(const char *name, T *o, Fn f) : Method2<T, R, A, B>(name, f), owner(o) {}
    T *owner;
};

class CScenarioManager {
public:
    CScenarioManager() {}
    virtual void v0();
    char pad04[0x1c];
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
    int FUN_001ccfa0(int);
    void FUN_001ccfc0(int, int);
    void FUN_001ccfe0(bool);
    bool FUN_001ccff0();
    void FUN_001cd5b0(float);
    void FUN_001cf690();
};

struct Registry_1cf690 {
    void FUN_001ce990(const char *, CScenarioManager *, void (CScenarioManager::*)(int));
    void FUN_001cea20(const char *, CScenarioManager *, int (CScenarioManager::*)());
    void FUN_001ceaa0(const char *, CScenarioManager *, float (CScenarioManager::*)());
    void FUN_001ceb20(const char *, CScenarioManager *, void (CScenarioManager::*)(float));
    void FUN_001cebb0(const char *, CScenarioManager *, void (CScenarioManager::*)(bool));
    void FUN_001cec40(const char *, CScenarioManager *, bool (CScenarioManager::*)());
    void FUN_001cecc0(const char *, CScenarioManager *, float (CScenarioManager::*)(int));
    void FUN_001cee40(const char *, CScenarioManager *, void (CScenarioManager::*)());
    void FUN_001ceec0(const char *, CScenarioManager *, void (CScenarioManager::*)(const char *));
    void FUN_001cef50(const char *, CScenarioManager *, const char * (CScenarioManager::*)(int));
    void FUN_001cf030(const char *, CScenarioManager *, int (CScenarioManager::*)(int));
    void FUN_001d26d0(const char *, MethodBase_1cf690 *);
};

Registry_1cf690 *FUN_001d4c90();

void CScenarioManager::FUN_001cf690()
{
    unsigned int cookie = DAT_004d9968;
    new (this) CScenarioManager;
    FUN_001cced0();
    Registry_1cf690 *reg = FUN_001d4c90();
    if (reg) {
        reg->FUN_001ce990("sm_SetMissionState", this, &CScenarioManager::FUN_001cc620);
        reg->FUN_001cea20("sm_GetMissionState", this, &CScenarioManager::FUN_001cc840);
        reg->FUN_001ceaa0("sm_GetTimeElapsed", this, &CScenarioManager::FUN_001cc860);
        reg->FUN_001ceb20("sm_SetTimeElapsed", this, &CScenarioManager::FUN_001cc870);
        reg->FUN_001ceaa0("sm_GetTime", this, &CScenarioManager::FUN_001cc8a0);
        reg->FUN_001ceaa0("sm_GetScenarioEndTime", this, &CScenarioManager::FUN_001cc880);
        reg->FUN_001ceb20("sm_SetScenarioEndTime", this, &CScenarioManager::FUN_001cc890);
        reg->FUN_001cebb0("sm_FreezeTime", this, &CScenarioManager::FUN_001cc8e0);
        reg->FUN_001cec40("sm_IsTimeFrozen", this, &CScenarioManager::FUN_001cc8f0);
        reg->FUN_001cea20("sm_GetCheckpoint", this, &CScenarioManager::FUN_001cc900);
        reg->FUN_001ce990("sm_SetCheckpoint", this, &CScenarioManager::FUN_001cc910);
        reg->FUN_001cecc0("sm_GetVar", this, &CScenarioManager::FUN_001cc990);
        {
            Closure2<CScenarioManager, void, int, float> c("sm_SetVar", this, &CScenarioManager::FUN_001cc9b0);
            reg->FUN_001d26d0("sm_SetVar", &c);
            c.FUN_001d04a0();
        }
        reg->FUN_001cea20("sm_GetMaxVarCount", this, &CScenarioManager::FUN_001cc5e0);
        {
            Closure2<CScenarioManager, int, float, const char *> c("sm_StartTimer", this, &CScenarioManager::FUN_001cc9d0);
            reg->FUN_001d26d0("sm_StartTimer", &c);
            c.FUN_001d04a0();
        }
        reg->FUN_001ce990("sm_CancelTimer", this, &CScenarioManager::FUN_001cca80);
        reg->FUN_001ceaa0("sm_GetComboTimerLimit", this, &CScenarioManager::FUN_001ccc00);
        reg->FUN_001ceaa0("sm_GetComboTimerCurrent", this, &CScenarioManager::FUN_001ccc20);
        reg->FUN_001cea20("sm_GetComboHitCount", this, &CScenarioManager::FUN_001ccc80);
        reg->FUN_001ceaa0("sm_GetComboScore", this, &CScenarioManager::FUN_001ccca0);
        reg->FUN_001ceb20("sm_SetComboTimerLimit", this, &CScenarioManager::FUN_001ccc10);
        reg->FUN_001ceb20("sm_SetComboTimerCurrent", this, &CScenarioManager::FUN_001ccc30);
        reg->FUN_001ce990("sm_SetComboHitCount", this, &CScenarioManager::FUN_001ccc90);
        reg->FUN_001ceb20("sm_SetComboScore", this, &CScenarioManager::FUN_001cccb0);
        reg->FUN_001ceb20("sm_Combo", this, &CScenarioManager::FUN_001cd5b0);
        {
            Closure2<CScenarioManager, void, float, const char *> c("sm_AddComboGrade", this, &CScenarioManager::FUN_001cce80);
            reg->FUN_001d26d0("sm_AddComboGrade", &c);
            c.FUN_001d04a0();
        }
        reg->FUN_001cee40("sm_ResetComboSystem", this, &CScenarioManager::FUN_001cced0);
        reg->FUN_001ceec0("sm_SetComboHitText", this, &CScenarioManager::FUN_001cce60);
        reg->FUN_001cef50("sm_GetMissionObjective", this, &CScenarioManager::FUN_001ccf50);
        {
            Closure2<CScenarioManager, void, int, const char *> c("sm_SetMissionObjective", this, &CScenarioManager::FUN_001ccf70);
            reg->FUN_001d26d0("sm_SetMissionObjective", &c);
            c.FUN_001d04a0();
        }
        reg->FUN_001cf030("sm_GetMissionObjectiveState", this, &CScenarioManager::FUN_001ccfa0);
        {
            Closure2<CScenarioManager, void, int, int> c("sm_SetMissionObjectiveState", this, &CScenarioManager::FUN_001ccfc0);
            reg->FUN_001d26d0("sm_SetMissionObjectiveState", &c);
            c.FUN_001d04a0();
        }
        reg->FUN_001cebb0("sm_SetTutorialMode", this, &CScenarioManager::FUN_001ccfe0);
        reg->FUN_001cec40("sm_GetTutorialMode", this, &CScenarioManager::FUN_001ccff0);
    }
    __security_check_cookie(cookie);
}
