typedef unsigned int u32;
extern "C" void* __cdecl FUN_00247530(void*);
struct Callee { u32 run(); };
extern char g_data[];
namespace audio { class MixType { public: virtual void f0(); virtual void f1(); virtual u32 vfunc_2(); }; u32 MixType::vfunc_2() { void* p = FUN_00247530(g_data); if (p) return ((Callee*)p)->run(); return 0; } }