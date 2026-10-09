struct Triple { int a,b,c; };
class Obj { public: char pad[0x1ad4]; int x[6]; void Set(Triple* a, Triple* b); };
void Obj::Set(Triple* a, Triple* b) { x[0]=a->a; x[1]=a->b; x[2]=a->c; x[3]=b->a; x[4]=b->b; x[5]=b->c; }