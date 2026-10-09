extern int g_4c3880;
extern void* g_554c10;
struct Arg { char p[0xc]; int a; char q[0x14]; int b; };
struct Obj { char p[0x4f0]; int a,b,c; void target(Arg*); };
struct Callee { void call(int); };
void Obj::target(Arg* arg) {
 a=arg->a;
 int t=arg->b;
 c=(int)arg;
 int g=g_4c3880;
 b=t;
 ((Callee*)g_554c10)->call(g);
}
