class Service { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int Get(); };
extern Service *g_service;
class Target { public: char pad0[0x18]; unsigned char initialized; char pad1[2]; float a; float b; char pad2[4]; int zero; char pad3[4]; unsigned char flag; };
void __fastcall FUN_001b8af0(Target *self) { if (!self->initialized) { self->flag=0; self->initialized=1; int n=g_service->Get(); self->zero=0; self->b=(float)n; self->a=(float)n; } }