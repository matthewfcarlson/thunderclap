// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 14/14)
// FUN_001f6990 @ 0x001f6990
inline void *operator new(unsigned int, void *p) throw() { return p; }

void *FUN_0008d690(unsigned int size);
void *FUN_0008d710(unsigned int size, int tag);
extern "C" char __cdecl FUN_001d04d0(const char *);
extern "C" const char DAT_0048e100[];
extern "C" const char DAT_0048e0e4[];
extern "C" const char DAT_0049cad8[];
extern "C" const char DAT_0048e134[];

template <class T> struct TypeName;
template <> struct TypeName<void> { static const char *get() { return DAT_0048e100; } };
template <> struct TypeName<bool> { static const char *get() { return DAT_0048e0e4; } };
template <> struct TypeName<char *> { static const char *get() { return DAT_0049cad8; } };
template <> struct TypeName<int> { static const char *get() { return DAT_0048e134; } };

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
    Function(const char *name, int arity) { FUN_001d0480(name, arity); }
};

class CSoundVoiceManager;

template <class T, class R>
class Method0 : public Function {
public:
    typedef R (T::*Fn)();
    Method0(const char *name, Fn f) : Function(name, 0) {
        fn = f;
        ret = FUN_001d04d0(TypeName<R>::get());
    }
    Fn fn;
};

template <class T, class R, class A, class B, class C>
class Method3 : public Function {
public:
    typedef R (T::*Fn)(A, B, C);
    Method3(const char *name, Fn f) : Function(name, 3) {
        fn = f;
        ret = FUN_001d04d0(TypeName<R>::get());
        args[0] = FUN_001d04d0(TypeName<A>::get());
        args[1] = FUN_001d04d0(TypeName<B>::get());
        args[2] = FUN_001d04d0(TypeName<C>::get());
    }
    Fn fn;
};

template <class T, class R, class A, class B, class C, class D>
class Method4 : public Function {
public:
    typedef R (T::*Fn)(A, B, C, D);
    Method4(const char *name, Fn f) : Function(name, 4) {
        fn = f;
        ret = FUN_001d04d0(TypeName<R>::get());
        args[0] = FUN_001d04d0(TypeName<A>::get());
        args[1] = FUN_001d04d0(TypeName<B>::get());
        args[2] = FUN_001d04d0(TypeName<C>::get());
        args[3] = FUN_001d04d0(TypeName<D>::get());
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
public:
    Closure0(const char *name, T *o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T *owner;
};

template <class T, class R, class A, class B, class C>
class Closure3 : public Method3<T, R, A, B, C> {
public:
    Closure3(const char *name, T *o, typename Method3<T, R, A, B, C>::Fn f) : Method3<T, R, A, B, C>(name, f), owner(o) {}
    T *owner;
};

template <class T, class R, class A, class B, class C, class D>
class Closure4 : public Method4<T, R, A, B, C, D> {
public:
    Closure4(const char *name, T *o, typename Method4<T, R, A, B, C, D>::Fn f) : Method4<T, R, A, B, C, D>(name, f), owner(o) {}
    T *owner;
};

struct Registry_1f6990 {
    void FUN_001d3b70(const char *name, void *closure);
    void FUN_001d3600(const char *path, int flag);
};
Registry_1f6990 *FUN_001d4c90();

struct Buffer_1f6990 {
    char pad00[0x70];
    char flag;
    char pad71[0x128 - 0x71];
    Buffer_1f6990 *FUN_001f3780();
    void FUN_0027b040(const char *s);
};

class CSoundSequenceVoice {
public:
    CSoundSequenceVoice(CSoundVoiceManager *o) : owner(o), f04(0), f08(0), f10(0), f18(0), f1c(0), f1d(0), f20(0), f24(0), gain(1.0f) {}
    virtual void v0();
    int f04;
    int f08;
    CSoundVoiceManager *owner;
    int f10;
    int pad14;
    int f18;
    char f1c;
    char f1d;
    char pad1e[2];
    int f20;
    int f24;
    float gain;
};

class CSoundVoiceManager {
public:
    char pad00[8];
    CSoundSequenceVoice *voices[0x20];
    char pad88[0xd4 - 0x88];
    Buffer_1f6990 *buffers[0x94];

    void FUN_001f4610(bool a, bool b, bool c);
    void FUN_001f46a0();
    void FUN_001f30e0(char *a, char *b, char *c, int d);
    void FUN_001f6990();
};

void CSoundVoiceManager::FUN_001f6990()
{
    for (int i = 0; i < 0x94; i++) {
        void *mem = FUN_0008d710(0x128, 6);
        Buffer_1f6990 *b = 0;
        if (mem)
            b = ((Buffer_1f6990 *)mem)->FUN_001f3780();
        buffers[i] = b;
        b->FUN_0027b040(0);
        buffers[i]->flag = 0;
    }
    for (int i = 0; i < 0x20; i++) {
        void *mem = FUN_0008d710(0x30, 6);
        CSoundSequenceVoice *v = 0;
        if (mem)
            v = new (mem) CSoundSequenceVoice(this);
        voices[i] = v;
        v->f10 = 0;
    }

    Registry_1f6990 *reg = FUN_001d4c90();
    void *mem = FUN_0008d690(0x24);
    Closure3<CSoundVoiceManager, void, bool, bool, bool> *pause = 0;
    if (mem)
        pause = new (mem) Closure3<CSoundVoiceManager, void, bool, bool, bool>("snd_Pause", this, &CSoundVoiceManager::FUN_001f4610);
    reg->FUN_001d3b70("snd_Pause", pause);

    mem = FUN_0008d690(0x24);
    Closure0<CSoundVoiceManager, void> *unpause = 0;
    if (mem)
        unpause = new (mem) Closure0<CSoundVoiceManager, void>("snd_UnPause", this, &CSoundVoiceManager::FUN_001f46a0);
    reg->FUN_001d3b70("snd_UnPause", unpause);

    mem = FUN_0008d690(0x24);
    Closure4<CSoundVoiceManager, void, char *, char *, char *, int> *mapInst = 0;
    if (mem)
        mapInst = new (mem) Closure4<CSoundVoiceManager, void, char *, char *, char *, int>("snd_MapInstance", this, &CSoundVoiceManager::FUN_001f30e0);
    reg->FUN_001d3b70("snd_MapInstance", mapInst);

    FUN_001d4c90()->FUN_001d3600("sound\\map.lua", 0);
}
