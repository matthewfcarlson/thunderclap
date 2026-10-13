// STATUS: equivalent (tools/equiv.py level 3: 1920 inputs, branch coverage 10/10)
// FUN_001ea8b0 @ 0x001ea8b0
extern char DAT_0048e100;
extern char DAT_0048e0f0;
extern char DAT_0049cad8;
extern char DAT_0048e134;
extern char DAT_004e36c8;
extern float DAT_004e36a4;
char FUN_001d04d0(const void *type);
void *FUN_0008d690(unsigned int size);
inline void *operator new(unsigned int, void *p) throw() { return p; }

template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void *get() { return &DAT_0048e100; } };
template <> struct TypeTag<const char *> { static const void *get() { return &DAT_0048e0f0; } };
template <> struct TypeTag<char *> { static const void *get() { return &DAT_0049cad8; } };
template <> struct TypeTag<int> { static const void *get() { return &DAT_0048e134; } };

class __declspec(novtable) MethodBase {
public:
    virtual void m0();
    char pad_04[0xc];
    char argType;
    char pad_11[7];
    char retType;
    char pad_19[3];
    void FUN_001d0480(const char *, int);
    MethodBase(const char *n, int k) { FUN_001d0480(n, k); }
};

template <class T, class R, class A>
class Method1 : public MethodBase {
public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) : MethodBase(name, 1) {
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

struct Registry {
    void FUN_001d3b70(const char *name, void *closure);
};
Registry *FUN_001d4c90();

struct SoundConfig {
    int size;
    int chunk;
    char pad[0x20];
    int FUN_0023fc40(const char *lang, int flags);
    void FUN_00240060();
};

struct Streams {
    char pad0[0x14];
    Streams *FUN_00266480(int bufSize);
};

class CSoundResourceManager;
extern CSoundResourceManager *DAT_004e3690;

struct Fx {
    void FUN_00265240(CSoundResourceManager *owner, const char *name);
};
extern Fx *DAT_00527c58;

void *FUN_00263ed0(unsigned int size, int kind);
void FUN_002474f0(void *p);
void FUN_002407a0(int v);
void FUN_00241390(SoundConfig *cfg, int zero);
void FUN_00240e00(float v);
void FUN_00240760(int v);
int FUN_001e91c0();

class CSoundResourceManager {
public:
    char pad000[0x518];
    Streams *streams;
    int param;

    void FUN_001ea0c0(const char *);
    void FUN_001ea050(const char *);
    void FUN_001e9b00(char *);
    void FUN_001e9b20(int);
    int FUN_001ea8b0(int arg);
};

int CSoundResourceManager::FUN_001ea8b0(int arg)
{
    DAT_004e3690 = this;
    param = arg;
    FUN_002474f0(&DAT_004e36c8);
    FUN_002407a0(-1);

    SoundConfig cfg;
    cfg.size = 0x800000;
    cfg.chunk = 0x80000;
    FUN_00241390(&cfg, 0);
    FUN_00240e00(1.0f);
    DAT_004e36a4 = 2075528.0f;
    FUN_00240760(cfg.FUN_0023fc40("english", 0));
    cfg.FUN_00240060();

    void *raw = FUN_00263ed0(0x14, 6);
    Streams *s = 0;
    if (raw != 0)
        s = ((Streams *)raw)->FUN_00266480(0x400);
    streams = s;

    DAT_00527c58->FUN_00265240(this, "clips");
    Registry *reg = FUN_001d4c90();
    void *mem;

    mem = FUN_0008d690(0x24);
    Closure1<CSoundResourceManager, void, const char *> *c1 = 0;
    if (mem)
        c1 = new (mem) Closure1<CSoundResourceManager, void, const char *>("snd_PreloadSequenceOfRankN", this, &CSoundResourceManager::FUN_001ea0c0);
    reg->FUN_001d3b70("snd_PreloadSequenceOfRankN", c1);

    mem = FUN_0008d690(0x24);
    Closure1<CSoundResourceManager, void, const char *> *c2 = 0;
    if (mem)
        c2 = new (mem) Closure1<CSoundResourceManager, void, const char *>("snd_PrepareSequence", this, &CSoundResourceManager::FUN_001ea050);
    reg->FUN_001d3b70("snd_PrepareSequence", c2);

    mem = FUN_0008d690(0x24);
    Closure1<CSoundResourceManager, void, char *> *c3 = 0;
    if (mem)
        c3 = new (mem) Closure1<CSoundResourceManager, void, char *>("snd_SetDefaultMix", this, &CSoundResourceManager::FUN_001e9b00);
    reg->FUN_001d3b70("snd_SetDefaultMix", c3);

    mem = FUN_0008d690(0x24);
    Closure1<CSoundResourceManager, void, int> *c4 = 0;
    if (mem)
        c4 = new (mem) Closure1<CSoundResourceManager, void, int>("snd_ReturnToDefaultMix", this, &CSoundResourceManager::FUN_001e9b20);
    reg->FUN_001d3b70("snd_ReturnToDefaultMix", c4);

    return FUN_001e91c0();
}
