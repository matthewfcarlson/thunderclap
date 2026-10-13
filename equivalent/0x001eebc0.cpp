// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 4/4)
// FUN_001eebc0 @ 0x001eebc0
typedef unsigned int size_t;
void* operator new(size_t) throw();
inline void* operator new(size_t, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int);
char FUN_001d04d0(const void*) throw();
class CSoundSimManager;
namespace math { class Vector { public: float x, y, z; }; }
typedef float Float; typedef bool Bool; typedef int Int; typedef void Void;
typedef const char* String; typedef char* CharPtr; typedef math::Vector Vector;
extern char ;
class Base { public: virtual void v(); char p[12]; char a[8]; char result; char z[3]; Base(const char*, int) throw(); };
template<class C, class R, class A1, class A2, class A3, class A4> class Method4 : public Base { public: void (*f)(); Method4(const char* n, void (*x)(), const void* r, const void* a1, const void* a2, const void* a3, const void* a4) : Base(n, 4) { f = x; result = FUN_001d04d0(r); a[0] = FUN_001d04d0(a1); a[1] = FUN_001d04d0(a2); a[2] = FUN_001d04d0(a3); a[3] = FUN_001d04d0(a4); } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4 : public Method4<C, R, A1, A2, A3, A4> { public: C* owner; Closure4(const char* n, C* o, void (*f)(), const void* r, const void* a1, const void* a2, const void* a3, const void* a4) : Method4<C, R, A1, A2, A3, A4>(n, f, r, a1, a2, a3, a4) { owner = o; } virtual void v(); };
template<> class Closure4<CSoundSimManager, void, const char*, const char*, const char*, const char*> { public: virtual void v(); char pad[0x1c]; CSoundSimManager* owner; Closure4(CSoundSimManager* o) { owner = o; } };
class Registry { public:
    void FUN_001d3b70(const char*, void*);
};
class Entry { public:
    void* FUN_001ee4c0(const char*, CSoundSimManager*, void (*)());
};
class Raw_001ede10 { public: void FUN_001ede10(const char*, void (*)()); };
Registry* FUN_001d4c90();
#define FN(b) extern void FUN_##b();
#define M4(n, c, b, R, A1, A2, A3, A4) { FN(b) void* m = FUN_0008d690(0x24); void* x = 0; if (m) { ((Raw_##c*)m)->FUN_##c(n, FUN_##b); x = new (m) Closure4<CSoundSimManager, R, A1, A2, A3, A4>(this); } r->FUN_001d3b70(n, x); }
#define E(n, c, b) { FN(b) Entry* e = (Entry*)FUN_0008d690(0x24); void* x = 0; if (e) x = e->FUN_##c(n, this, FUN_##b); r->FUN_001d3b70(n, x); }

class CSoundSimManager {
public:
    void Register();
    int i0;
};

void CSoundSimManager::Register() {
    Registry* r = FUN_001d4c90();
M4("snd_PlayFightDialogue", 001ede10, 001ecda0, Void, String, String, String, String)
E("snd_HUDEvent", 001ee4c0, 001ebd00)
}
