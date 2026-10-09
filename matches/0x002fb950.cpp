typedef unsigned int u32;
struct Vec { float x,y,z; };
class C { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual Vec* get(); void helper(Vec*,u32); void sum(Vec*,u32); };
void C::sum(Vec* p,u32 a) { helper(p,a); Vec* q=get(); p->x+=q->x; p->y+=q->y; p->z+=q->z; }