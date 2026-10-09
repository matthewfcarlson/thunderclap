class Base { public: float Compute(); };
class Obj { public: char p[4]; Base *base; char q[0x34c]; float value; void Tick(int); void Do(float *, int); };
class B { public: char p[0x10]; void Run(float *); };
class A { public: char p[0x10]; B *y; };
class Manager { public: char p[0x124]; A *a; };
class Root { public: char p[0x20]; Manager *m; };
extern Root *gRoot;
void Obj::Tick(int arg) {
 value=base->Compute();
 float v[3]={0,0,0};
 B *b=gRoot->m->a->y;
 b->Run(v);
 Do(v,arg);
}
