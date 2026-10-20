// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_001b84f0 @ 0x001b84f0
class CFMVManager;

struct HeapObj {
    static void* operator new(unsigned size) throw();
};

class MethodBase_1b84f0 : public HeapObj {
  public:
    virtual void m0();
    char pad_04[0x1c - 4];
};

template <class T, class R, class A, class B, class C, class D>
class Method4 : public MethodBase_1b84f0 {
  public:
    typedef R (T::*Fn)(A, B, C, D);
    Method4(const char* name, Fn fn) throw();
    Fn fn;
};

template <class T, class R, class A, class B, class C, class D>
class Closure4 : public Method4<T, R, A, B, C, D> {
  public:
    typedef R (T::*Fn)(A, B, C, D);
    Closure4(const char* name, T* owner, Fn f) throw() : Method4<T, R, A, B, C, D>(name, f), owner(owner) {}
    T* owner;
};

struct Closure2 {
    Closure2* FUN_001b81a0(const char* name, CFMVManager* owner, void (CFMVManager::*fn)(const char*, int));
};

struct Registry_1b84f0 {
    void FUN_001d3b70(const char* name, void* closure);
    void FUN_001b8420(const char* name, CFMVManager* owner, bool (CFMVManager::*fn)());
};

class CFMVManager {
  public:
    CFMVManager();
    virtual void v0();
    int field_04;
    char field_08;
    char field_09;
    int field_0c;
    int field_10;
    char field_14;
    char pad_15[0x114 - 0x15];
    char field_114;
    char pad_115[3];
    int field_118;
    int field_11c;
    int pad_120;
    int field_124;
    int field_128;
    int field_12c;
    char field_130;
    char field_131;
    char pad_132[2];
    int field_134;

    void FUN_001b7960(const char*, int);
    bool FUN_001b7910();
    void FUN_001b7290(float, float, float, float);
    bool FUN_001b6f00();
};

Registry_1b84f0* FUN_001d4c90();
void* FUN_0008d690(unsigned size);

CFMVManager::CFMVManager() {
    field_04 = 0;
    field_08 = 0;
    field_09 = 0;
    field_0c = 0;
    field_10 = 0x7d0;
    field_114 = 1;
    field_118 = 0;
    field_11c = 0;
    field_124 = 0;
    field_128 = 0;
    field_12c = 0;
    field_130 = 0;
    field_131 = 0;
    field_134 = 0;

    Registry_1b84f0* reg = FUN_001d4c90();

    Closure2* playMovie = (Closure2*)FUN_0008d690(0x24);
    if (playMovie != 0)
        playMovie = playMovie->FUN_001b81a0("fmvm_PlayMovie", this, &CFMVManager::FUN_001b7960);
    reg->FUN_001d3b70("fmvm_PlayMovie", playMovie);

    Closure2* playMovieAudio = (Closure2*)FUN_0008d690(0x24);
    if (playMovieAudio != 0)
        playMovieAudio = playMovieAudio->FUN_001b81a0("fmvm_PlayMovieWithAudio", this, &CFMVManager::FUN_001b7960);
    reg->FUN_001d3b70("fmvm_PlayMovieWithAudio", playMovieAudio);

    reg->FUN_001b8420("fmvm_IsPlaying", this, &CFMVManager::FUN_001b7910);

    Closure4<CFMVManager, void, float, float, float, float>* rumble =
        new Closure4<CFMVManager, void, float, float, float, float>("fmvm_SetRumbleEvent", this, &CFMVManager::FUN_001b7290);
    reg->FUN_001d3b70("fmvm_SetRumbleEvent", rumble);

    reg->FUN_001b8420("fmvm_GetUserSkippedLastTime", this, &CFMVManager::FUN_001b6f00);
    field_14 = 0;
}
