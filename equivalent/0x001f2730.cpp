// STATUS: equivalent (tools/equiv.py level 3: 455 inputs, branch coverage 38/38)
// FUN_001f2730 @ 0x001f2730
#include "compat/ptr.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
inline void *operator new(hulk_uintptr, void *p) throw() { return p; }

extern "C" void *__cdecl FUN_0008d690(unsigned int size);

template <class T> struct TypeName;
template <> struct TypeName<void> { static const char *get() { return ((const char*)&DAT_0048e100); } };
template <> struct TypeName<float> { static const char *get() { return ((const char*)&DAT_0048e128); } };

// Function (include/decls/data/script.h): the vftable, then Function's fields.
class __declspec(novtable) Function : public ScriptFunctionFields {
public:
    virtual void f0();
    virtual void f1();
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
        retType = FUN_001d04d0(TypeName<R>::get());
        argTypes[0] = FUN_001d04d0(TypeName<A>::get());
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
struct Closure2_1f2730 {
    Closure2_1f2730 *FUN_001f1cf0(const char *name, CSoundSystem *owner, void (CSoundSystem::*fn)());
};
struct ClosureDefaultMix {
    ClosureDefaultMix *FUN_001f21b0(const char *name, CSoundSystem *owner, void (CSoundSystem::*fn)());
};
struct ClosureInstallEffect {
    ClosureInstallEffect *FUN_001f2250(const char *name, CSoundSystem *owner, void (CSoundSystem::*fn)());
};

struct Registry_1f2730 {
    void FUN_001d3b70(const char *name, void *closure);
    void FUN_001f23f0(const char *name, CSoundSystem *owner, void (CSoundSystem::*fn)());
};
extern "C" Registry_1f2730 *FUN_001d4c90();

void CSoundSystem::FUN_001f2730()
{
    Registry_1f2730 *reg = FUN_001d4c90();
    void *mem;

    { HULK_SIZE32(ScriptClosureView, 0x24); }
    mem = FUN_0008d690((int)sizeof(ScriptClosureView));
    Closure2_1f2730 *obj = 0;
    if (mem)
        obj = ((Closure2_1f2730 *)mem)->FUN_001f1cf0("snd_CreateObject", this, &CSoundSystem::FUN_001f13b0);
    reg->FUN_001d3b70("snd_CreateObject", obj);

    { typedef Closure3<CSoundSystem, void, char *, char *, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure3<CSoundSystem, void, char *, char *, float>));
    Closure3<CSoundSystem, void, char *, char *, float> *trig = 0;
    if (mem)
        trig = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_CreateTrigger", this, &CSoundSystem::FUN_001f1480);
    reg->FUN_001d3b70("snd_CreateTrigger", trig);

    reg->FUN_001f23f0("snd_StopAllTriggers", this, &CSoundSystem::FUN_001eef00);

    { typedef Closure3<CSoundSystem, void, char *, char *, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure3<CSoundSystem, void, char *, char *, float>));
    Closure3<CSoundSystem, void, char *, char *, float> *seq = 0;
    if (mem)
        seq = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_AddCommand_PlaySequenceEvent", this, &CSoundSystem::FUN_001f1540);
    reg->FUN_001d3b70("snd_AddCommand_PlaySequenceEvent", seq);

    { typedef Closure3<CSoundSystem, void, char *, char *, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure3<CSoundSystem, void, char *, char *, float>));
    Closure3<CSoundSystem, void, char *, char *, float> *intr = 0;
    if (mem)
        intr = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_AddCommand_PlayInterruptEvent", this, &CSoundSystem::FUN_001f15a0);
    reg->FUN_001d3b70("snd_AddCommand_PlayInterruptEvent", intr);

    { typedef Closure6<CSoundSystem, void, char *, char *, float, float, float, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure6<CSoundSystem, void, char *, char *, float, float, float, float>));
    Closure6<CSoundSystem, void, char *, char *, float, float, float, float> *tun = 0;
    if (mem)
        tun = new (mem) Closure6<CSoundSystem, void, char *, char *, float, float, float, float>("snd_AddCommand_PlayTunableEvent", this, &CSoundSystem::FUN_001f1600);
    reg->FUN_001d3b70("snd_AddCommand_PlayTunableEvent", tun);

    { typedef Closure4<CSoundSystem, void, char *, char *, float, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure4<CSoundSystem, void, char *, char *, float, float>));
    Closure4<CSoundSystem, void, char *, char *, float, float> *stoptun = 0;
    if (mem)
        stoptun = new (mem) Closure4<CSoundSystem, void, char *, char *, float, float>("snd_AddCommand_StopTunableEvent", this, &CSoundSystem::FUN_001f16e0);
    reg->FUN_001d3b70("snd_AddCommand_StopTunableEvent", stoptun);

    { typedef Closure5<CSoundSystem, void, char *, char *, float, float, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure5<CSoundSystem, void, char *, char *, float, float, float>));
    Closure5<CSoundSystem, void, char *, char *, float, float, float> *pitch = 0;
    if (mem)
        pitch = new (mem) Closure5<CSoundSystem, void, char *, char *, float, float, float>("snd_AddCommand_SetLoopPitchEvent", this, &CSoundSystem::FUN_001f1670);
    reg->FUN_001d3b70("snd_AddCommand_SetLoopPitchEvent", pitch);

    { typedef Closure4<CSoundSystem, void, char *, char *, float, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure4<CSoundSystem, void, char *, char *, float, float>));
    Closure4<CSoundSystem, void, char *, char *, float, float> *dlg = 0;
    if (mem)
        dlg = new (mem) Closure4<CSoundSystem, void, char *, char *, float, float>("snd_AddCommand_PlayDialogueEvent", this, &CSoundSystem::FUN_001f1740);
    reg->FUN_001d3b70("snd_AddCommand_PlayDialogueEvent", dlg);

    { typedef Closure6<CSoundSystem, void, char *, char *, char *, float, float, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure6<CSoundSystem, void, char *, char *, char *, float, float, float>));
    Closure6<CSoundSystem, void, char *, char *, char *, float, float, float> *mdlg = 0;
    if (mem)
        mdlg = new (mem) Closure6<CSoundSystem, void, char *, char *, char *, float, float, float>("snd_AddCommand_PlayMissionDialogueEvent", this, &CSoundSystem::FUN_001f17f0);
    reg->FUN_001d3b70("snd_AddCommand_PlayMissionDialogueEvent", mdlg);

    { typedef Closure5<CSoundSystem, void, char *, char *, float, float, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure5<CSoundSystem, void, char *, char *, float, float, float>));
    Closure5<CSoundSystem, void, char *, char *, float, float, float> *fdlg = 0;
    if (mem)
        fdlg = new (mem) Closure5<CSoundSystem, void, char *, char *, float, float, float>("snd_AddCommand_PlayFightDialogueEvent", this, &CSoundSystem::FUN_001f18b0);
    reg->FUN_001d3b70("snd_AddCommand_PlayFightDialogueEvent", fdlg);

    { typedef Closure3<CSoundSystem, void, char *, char *, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure3<CSoundSystem, void, char *, char *, float>));
    Closure3<CSoundSystem, void, char *, char *, float> *music = 0;
    if (mem)
        music = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_AddCommand_PlayMusicEvent", this, &CSoundSystem::FUN_001f1970);
    reg->FUN_001d3b70("snd_AddCommand_PlayMusicEvent", music);

    { typedef Closure3<CSoundSystem, void, char *, char *, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure3<CSoundSystem, void, char *, char *, float>));
    Closure3<CSoundSystem, void, char *, char *, float> *amb = 0;
    if (mem)
        amb = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_AddCommand_PlayAmbienceEvent", this, &CSoundSystem::FUN_001f1a20);
    reg->FUN_001d3b70("snd_AddCommand_PlayAmbienceEvent", amb);

    { typedef Closure3<CSoundSystem, void, char *, char *, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure3<CSoundSystem, void, char *, char *, float>));
    Closure3<CSoundSystem, void, char *, char *, float> *sfx = 0;
    if (mem)
        sfx = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_AddCommand_PlaySFXEvent", this, &CSoundSystem::FUN_001f1ad0);
    reg->FUN_001d3b70("snd_AddCommand_PlaySFXEvent", sfx);

    { typedef Closure3<CSoundSystem, void, char *, char *, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure3<CSoundSystem, void, char *, char *, float>));
    Closure3<CSoundSystem, void, char *, char *, float> *cue = 0;
    if (mem)
        cue = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_AddCommand_CueNISEvent", this, &CSoundSystem::FUN_001f1b80);
    reg->FUN_001d3b70("snd_AddCommand_CueNISEvent", cue);

    { typedef Closure1<CSoundSystem, void, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure1<CSoundSystem, void, float>));
    Closure1<CSoundSystem, void, float> *play = 0;
    if (mem)
        play = new (mem) Closure1<CSoundSystem, void, float>("snd_AddCommand_PlayCuedNISEvent", this, &CSoundSystem::FUN_001efca0);
    reg->FUN_001d3b70("snd_AddCommand_PlayCuedNISEvent", play);

    { typedef Closure1<CSoundSystem, void, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure1<CSoundSystem, void, float>));
    Closure1<CSoundSystem, void, float> *stop = 0;
    if (mem)
        stop = new (mem) Closure1<CSoundSystem, void, float>("snd_AddCommand_StopNISEvent", this, &CSoundSystem::FUN_001efd00);
    reg->FUN_001d3b70("snd_AddCommand_StopNISEvent", stop);

    { typedef Closure3<CSoundSystem, void, char *, float, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure3<CSoundSystem, void, char *, float, float>));
    Closure3<CSoundSystem, void, char *, float, float> *mixer = 0;
    if (mem)
        mixer = new (mem) Closure3<CSoundSystem, void, char *, float, float>("snd_AddCommand_InstallMixer", this, &CSoundSystem::FUN_001efd60);
    reg->FUN_001d3b70("snd_AddCommand_InstallMixer", mixer);

    { HULK_SIZE32(ScriptClosureView, 0x24); }
    mem = FUN_0008d690((int)sizeof(ScriptClosureView));
    ClosureDefaultMix *mix = 0;
    if (mem)
        mix = ((ClosureDefaultMix *)mem)->FUN_001f21b0("snd_AddCommand_ReturnToDefaultMix", this, &CSoundSystem::FUN_001efdc0);
    reg->FUN_001d3b70("snd_AddCommand_ReturnToDefaultMix", mix);

    { HULK_SIZE32(ScriptClosureView, 0x24); }
    mem = FUN_0008d690((int)sizeof(ScriptClosureView));
    ClosureInstallEffect *fx = 0;
    if (mem)
        fx = ((ClosureInstallEffect *)mem)->FUN_001f2250("snd_AddCommand_InstallEffect", this, &CSoundSystem::FUN_001f1c30);
    reg->FUN_001d3b70("snd_AddCommand_InstallEffect", fx);
}
