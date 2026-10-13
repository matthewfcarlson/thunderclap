// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000436f0 @ 0x000436f0
typedef unsigned int size_t;
void* operator new(size_t) throw();
inline void* operator new(size_t, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int);
char FUN_001d04d0(const void*) throw();
class Unused;
namespace math { class Vector { public: float x, y, z; }; }
typedef float Float; typedef bool Bool; typedef int Int; typedef void Void;
typedef const char* String; typedef char* CharPtr; typedef math::Vector Vector;
extern char ;
class Base { public: virtual void v(); char p[12]; char a[8]; char result; char z[3]; Base(const char*, int) throw(); };
class Registry { public:
    void FUN_001d3b70(const char*, void*);
};
class Entry { public:
    void* FUN_0003eea0(const char*, void (*)());
    void* FUN_0003efb0(const char*, void (*)());
};
Registry* FUN_001d4c90();
#define FN(b) extern void FUN_##b();
#define EF(n, c, b) { FN(b) Entry* e = (Entry*)FUN_0008d690(0x20); void* x = 0; if (e) x = e->FUN_##c(n, FUN_##b); r->FUN_001d3b70(n, x); }

void FUN_000436f0() {
    Registry* r = FUN_001d4c90();
    if (r) {
EF("char_DefineForceReactionProfile", 0003eea0, 00044c60)
EF("char_SetNPCDefault", 0003efb0, 00044cb0)
EF("char_SetNPCParameter", 0003efb0, 000452e0)
    }
}
