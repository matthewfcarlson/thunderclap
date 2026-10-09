struct COrientTargetTrack { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); void init(); char pad[0x28]; };
void* operator_new(unsigned int);
extern void* orient_vtable;
class Factory { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual COrientTargetTrack* v5(); };
COrientTargetTrack* Factory::v5() { COrientTargetTrack* p=(COrientTargetTrack*)operator_new(0x2c); if(p) { p->init(); *(void**)p=&orient_vtable; return p; } return 0; }