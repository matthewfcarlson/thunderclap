// STATUS: equivalent (tools/equiv.py level 3: 455 inputs, branch coverage 38/38)
// FUN_001f2730 @ 0x001f2730
inline void *operator new(unsigned int, void *p) throw() { return p; }

extern "C" void *__cdecl FUN_0008d690(unsigned int size);
extern "C" char __cdecl FUN_001d04d0(const char *);
extern "C" const char DAT_0048e100[];
extern "C" const char DAT_0048e128[];

template <class T> struct TypeName;
template <> struct TypeName<void> { static const char *get() { return DAT_0048e100; } };
template <> struct TypeName<float> { static const char *get() { return DAT_0048e128; } };

class __declspec(novtable) Function {
public:
    virtual void f0();
    virtual void f1();
    char pad04[0x0c];
    char args[4];
    char pad14[4];
    char ret;
    char pad19[3];
    void FUN_001d0480(const char *name, int arity);
    Function() {}
    __forceinline Function(const char *name, int arity) { FUN_001d0480(name, arity); }
};

class CSoundSystem {
public:
    void FUN_001eef00();
    void FUN_001f13b0();
    void FUN_001f1480(char *, char *, float);
    void FUN_001f1540(char *, char *, float);
    void FUN_001f15a0(char *, char *, float);
    void FUN_001f1600(char *, char *, float, float, float, float);
    void FUN_001f1670(char *, char *, float, float, float);
    void FUN_001f16e0(char *, char *, float, float);
    void FUN_001f1740(char *, char *, float, float);
    void FUN_001f17f0(char *, char *, char *, float, float, float);
    void FUN_001f18b0(char *, char *, float, float, float);
    void FUN_001f1970(char *, char *, float);
    void FUN_001f1a20(char *, char *, float);
    void FUN_001f1ad0(char *, char *, float);
    void FUN_001f1b80(char *, char *, float);
    void FUN_001efca0(float);
    void FUN_001efd00(float);
    void FUN_001efd60(char *, float, float);
    void FUN_001efdc0();
    void FUN_001f1c30();
    void FUN_001f2730();
};

template <class T, class R, class A>
class Method1 : public Function {
public:
    typedef R (T::*Fn)(A);
    __forceinline Method1(const char *name, Fn f) : Function(name, 1) {
        fn = f;
        ret = FUN_001d04d0(TypeName<R>::get());
        args[0] = FUN_001d04d0(TypeName<A>::get());
    }
    Fn fn;
};

template <class T, class R, class A>
class Closure1 : public Method1<T, R, A> {
public:
    __forceinline Closure1(const char *name, T *o, typename Method1<T, R, A>::Fn f) : Method1<T, R, A>(name, f), owner(o) {}
    T *owner;
};

// Methods whose constructors were out of line
class __declspec(novtable) Method3A : public Function {
public:
    typedef void (CSoundSystem::*Fn)(char *, char *, float);
    __forceinline Method3A(const char *name, Fn f) : Function() { FUN_001f0af0(name, f); }
    void FUN_001f0af0(const char *name, Fn f);
    Fn fn;
};
class __declspec(novtable) Method3B : public Function {
public:
    typedef void (CSoundSystem::*Fn)(char *, float, float);
    __forceinline Method3B(const char *name, Fn f) : Function() { FUN_001f1050(name, f); }
    void FUN_001f1050(const char *name, Fn f);
    Fn fn;
};
class __declspec(novtable) Method4A : public Function {
public:
    typedef void (CSoundSystem::*Fn)(char *, char *, float, float);
    __forceinline Method4A(const char *name, Fn f) : Function() { FUN_001f0d10(name, f); }
    void FUN_001f0d10(const char *name, Fn f);
    Fn fn;
};
class __declspec(novtable) Method5A : public Function {
public:
    typedef void (CSoundSystem::*Fn)(char *, char *, float, float, float);
    __forceinline Method5A(const char *name, Fn f) : Function() { FUN_001f0dd0(name, f); }
    void FUN_001f0dd0(const char *name, Fn f);
    Fn fn;
};
class __declspec(novtable) Method6A : public Function {
public:
    typedef void (CSoundSystem::*Fn)(char *, char *, float, float, float, float);
    __forceinline Method6A(const char *name, Fn f) : Function() { FUN_001f0c00(name, f); }
    void FUN_001f0c00(const char *name, Fn f);
    Fn fn;
};
class __declspec(novtable) Method6B : public Function {
public:
    typedef void (CSoundSystem::*Fn)(char *, char *, char *, float, float, float);
    __forceinline Method6B(const char *name, Fn f) : Function() { FUN_001f0ed0(name, f); }
    void FUN_001f0ed0(const char *name, Fn f);
    Fn fn;
};

template <class T, class R, class A, class B, class C>
class Closure3;
template <class T, class R, class A, class B, class C, class D>
class Closure4;
template <class T, class R, class A, class B, class C, class D, class E>
class Closure5;
template <class T, class R, class A, class B, class C, class D, class E, class F>
class Closure6;

template <>
class Closure3<CSoundSystem, void, char *, char *, float> : public Method3A {
public:
    __forceinline Closure3(const char *name, CSoundSystem *o, Fn f) : Method3A(name, f), owner(o) {}
    CSoundSystem *owner;
};
template <>
class Closure3<CSoundSystem, void, char *, float, float> : public Method3B {
public:
    __forceinline Closure3(const char *name, CSoundSystem *o, Fn f) : Method3B(name, f), owner(o) {}
    CSoundSystem *owner;
};
template <>
class Closure4<CSoundSystem, void, char *, char *, float, float> : public Method4A {
public:
    __forceinline Closure4(const char *name, CSoundSystem *o, Fn f) : Method4A(name, f), owner(o) {}
    CSoundSystem *owner;
};
template <>
class Closure5<CSoundSystem, void, char *, char *, float, float, float> : public Method5A {
public:
    __forceinline Closure5(const char *name, CSoundSystem *o, Fn f) : Method5A(name, f), owner(o) {}
    CSoundSystem *owner;
};
template <>
class Closure6<CSoundSystem, void, char *, char *, float, float, float, float> : public Method6A {
public:
    __forceinline Closure6(const char *name, CSoundSystem *o, Fn f) : Method6A(name, f), owner(o) {}
    CSoundSystem *owner;
};
template <>
class Closure6<CSoundSystem, void, char *, char *, char *, float, float, float> : public Method6B {
public:
    __forceinline Closure6(const char *name, CSoundSystem *o, Fn f) : Method6B(name, f), owner(o) {}
    CSoundSystem *owner;
};

// closures whose constructors were out of line too
struct ClosureCreateObject {
    ClosureCreateObject *FUN_001f1cf0(const char *name, CSoundSystem *owner, void (CSoundSystem::*fn)());
};
struct ClosureDefaultMix {
    ClosureDefaultMix *FUN_001f21b0(const char *name, CSoundSystem *owner, void (CSoundSystem::*fn)());
};
struct ClosureInstallEffect {
    ClosureInstallEffect *FUN_001f2250(const char *name, CSoundSystem *owner, void (CSoundSystem::*fn)());
};

struct Registry {
    void FUN_001d3b70(const char *name, void *closure);
    void FUN_001f23f0(const char *name, CSoundSystem *owner, void (CSoundSystem::*fn)());
};
Registry *FUN_001d4c90();

void CSoundSystem::FUN_001f2730()
{
    Registry *reg = FUN_001d4c90();
    void *mem;

    mem = FUN_0008d690(0x24);
    ClosureCreateObject *obj = 0;
    if (mem)
        obj = ((ClosureCreateObject *)mem)->FUN_001f1cf0("snd_CreateObject", this, &CSoundSystem::FUN_001f13b0);
    reg->FUN_001d3b70("snd_CreateObject", obj);

    mem = FUN_0008d690(0x24);
    Closure3<CSoundSystem, void, char *, char *, float> *trig = 0;
    if (mem)
        trig = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_CreateTrigger", this, &CSoundSystem::FUN_001f1480);
    reg->FUN_001d3b70("snd_CreateTrigger", trig);

    reg->FUN_001f23f0("snd_StopAllTriggers", this, &CSoundSystem::FUN_001eef00);

    mem = FUN_0008d690(0x24);
    Closure3<CSoundSystem, void, char *, char *, float> *seq = 0;
    if (mem)
        seq = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_AddCommand_PlaySequenceEvent", this, &CSoundSystem::FUN_001f1540);
    reg->FUN_001d3b70("snd_AddCommand_PlaySequenceEvent", seq);

    mem = FUN_0008d690(0x24);
    Closure3<CSoundSystem, void, char *, char *, float> *intr = 0;
    if (mem)
        intr = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_AddCommand_PlayInterruptEvent", this, &CSoundSystem::FUN_001f15a0);
    reg->FUN_001d3b70("snd_AddCommand_PlayInterruptEvent", intr);

    mem = FUN_0008d690(0x24);
    Closure6<CSoundSystem, void, char *, char *, float, float, float, float> *tun = 0;
    if (mem)
        tun = new (mem) Closure6<CSoundSystem, void, char *, char *, float, float, float, float>("snd_AddCommand_PlayTunableEvent", this, &CSoundSystem::FUN_001f1600);
    reg->FUN_001d3b70("snd_AddCommand_PlayTunableEvent", tun);

    mem = FUN_0008d690(0x24);
    Closure4<CSoundSystem, void, char *, char *, float, float> *stoptun = 0;
    if (mem)
        stoptun = new (mem) Closure4<CSoundSystem, void, char *, char *, float, float>("snd_AddCommand_StopTunableEvent", this, &CSoundSystem::FUN_001f16e0);
    reg->FUN_001d3b70("snd_AddCommand_StopTunableEvent", stoptun);

    mem = FUN_0008d690(0x24);
    Closure5<CSoundSystem, void, char *, char *, float, float, float> *pitch = 0;
    if (mem)
        pitch = new (mem) Closure5<CSoundSystem, void, char *, char *, float, float, float>("snd_AddCommand_SetLoopPitchEvent", this, &CSoundSystem::FUN_001f1670);
    reg->FUN_001d3b70("snd_AddCommand_SetLoopPitchEvent", pitch);

    mem = FUN_0008d690(0x24);
    Closure4<CSoundSystem, void, char *, char *, float, float> *dlg = 0;
    if (mem)
        dlg = new (mem) Closure4<CSoundSystem, void, char *, char *, float, float>("snd_AddCommand_PlayDialogueEvent", this, &CSoundSystem::FUN_001f1740);
    reg->FUN_001d3b70("snd_AddCommand_PlayDialogueEvent", dlg);

    mem = FUN_0008d690(0x24);
    Closure6<CSoundSystem, void, char *, char *, char *, float, float, float> *mdlg = 0;
    if (mem)
        mdlg = new (mem) Closure6<CSoundSystem, void, char *, char *, char *, float, float, float>("snd_AddCommand_PlayMissionDialogueEvent", this, &CSoundSystem::FUN_001f17f0);
    reg->FUN_001d3b70("snd_AddCommand_PlayMissionDialogueEvent", mdlg);

    mem = FUN_0008d690(0x24);
    Closure5<CSoundSystem, void, char *, char *, float, float, float> *fdlg = 0;
    if (mem)
        fdlg = new (mem) Closure5<CSoundSystem, void, char *, char *, float, float, float>("snd_AddCommand_PlayFightDialogueEvent", this, &CSoundSystem::FUN_001f18b0);
    reg->FUN_001d3b70("snd_AddCommand_PlayFightDialogueEvent", fdlg);

    mem = FUN_0008d690(0x24);
    Closure3<CSoundSystem, void, char *, char *, float> *music = 0;
    if (mem)
        music = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_AddCommand_PlayMusicEvent", this, &CSoundSystem::FUN_001f1970);
    reg->FUN_001d3b70("snd_AddCommand_PlayMusicEvent", music);

    mem = FUN_0008d690(0x24);
    Closure3<CSoundSystem, void, char *, char *, float> *amb = 0;
    if (mem)
        amb = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_AddCommand_PlayAmbienceEvent", this, &CSoundSystem::FUN_001f1a20);
    reg->FUN_001d3b70("snd_AddCommand_PlayAmbienceEvent", amb);

    mem = FUN_0008d690(0x24);
    Closure3<CSoundSystem, void, char *, char *, float> *sfx = 0;
    if (mem)
        sfx = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_AddCommand_PlaySFXEvent", this, &CSoundSystem::FUN_001f1ad0);
    reg->FUN_001d3b70("snd_AddCommand_PlaySFXEvent", sfx);

    mem = FUN_0008d690(0x24);
    Closure3<CSoundSystem, void, char *, char *, float> *cue = 0;
    if (mem)
        cue = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_AddCommand_CueNISEvent", this, &CSoundSystem::FUN_001f1b80);
    reg->FUN_001d3b70("snd_AddCommand_CueNISEvent", cue);

    mem = FUN_0008d690(0x24);
    Closure1<CSoundSystem, void, float> *play = 0;
    if (mem)
        play = new (mem) Closure1<CSoundSystem, void, float>("snd_AddCommand_PlayCuedNISEvent", this, &CSoundSystem::FUN_001efca0);
    reg->FUN_001d3b70("snd_AddCommand_PlayCuedNISEvent", play);

    mem = FUN_0008d690(0x24);
    Closure1<CSoundSystem, void, float> *stop = 0;
    if (mem)
        stop = new (mem) Closure1<CSoundSystem, void, float>("snd_AddCommand_StopNISEvent", this, &CSoundSystem::FUN_001efd00);
    reg->FUN_001d3b70("snd_AddCommand_StopNISEvent", stop);

    mem = FUN_0008d690(0x24);
    Closure3<CSoundSystem, void, char *, float, float> *mixer = 0;
    if (mem)
        mixer = new (mem) Closure3<CSoundSystem, void, char *, float, float>("snd_AddCommand_InstallMixer", this, &CSoundSystem::FUN_001efd60);
    reg->FUN_001d3b70("snd_AddCommand_InstallMixer", mixer);

    mem = FUN_0008d690(0x24);
    ClosureDefaultMix *mix = 0;
    if (mem)
        mix = ((ClosureDefaultMix *)mem)->FUN_001f21b0("snd_AddCommand_ReturnToDefaultMix", this, &CSoundSystem::FUN_001efdc0);
    reg->FUN_001d3b70("snd_AddCommand_ReturnToDefaultMix", mix);

    mem = FUN_0008d690(0x24);
    ClosureInstallEffect *fx = 0;
    if (mem)
        fx = ((ClosureInstallEffect *)mem)->FUN_001f2250("snd_AddCommand_InstallEffect", this, &CSoundSystem::FUN_001f1c30);
    reg->FUN_001d3b70("snd_AddCommand_InstallEffect", fx);
}
