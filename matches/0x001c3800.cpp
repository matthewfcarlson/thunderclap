struct Other { void f(int,int,int,int,int); };
struct Obj { char pad[0x14]; Other* value; void run(int,int,int,int,int); };
void Obj::run(int a,int b,int c,int d,int e) { if (value) value->f(a,b,c,d,e); }