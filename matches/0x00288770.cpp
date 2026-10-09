extern int EntityType, CompositeType, PoseType;
class Result { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); virtual void k(); virtual unsigned int run(); };
extern Result* __cdecl resolve(void*, int, const void*, const void*, int);
class Pose { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void vfunc_5(void*); void set(unsigned int); };
void Pose::vfunc_5(void* arg) { Result* p=resolve(arg,0,&EntityType,&CompositeType,0); if(p) { set(p->run()); } else { unsigned int x=(unsigned int)resolve(arg,0,&EntityType,&PoseType,0); set(x); } }