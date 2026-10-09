class CProjectile { char pad[0x20]; };
class ProjectileGroundShockwave : public CProjectile { public: virtual void v0(); virtual void v1(); virtual ProjectileGroundShockwave* vfunc_2(unsigned char); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); };
extern void FUN_00198ab0();
struct Alloc { void f(void*, int); };
ProjectileGroundShockwave* ProjectileGroundShockwave::vfunc_2(unsigned char flags) { FUN_00198ab0(); if (flags & 1) ((Alloc*)0x4e2210)->f(this, 0xc0); return this; }