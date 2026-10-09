extern const float zero;
class ParticleEmitter {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual float f18(float); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31(); virtual void f32();
 char pad[0x84]; struct Other { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void g(); virtual void h(); virtual void i(); virtual float f(float); } *ptr;
};
float ParticleEmitter::f18(float x) { if (ptr) return ptr->f(x); return zero; }