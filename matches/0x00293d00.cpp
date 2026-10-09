struct Data { int a,b,c; };
extern Data gData;
extern int gA,gB,gC;
struct InitObj { void foo(); };
extern InitObj gInit;
class Host { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(int, Data*); };
class Owner { public: Host *host; void run(Data *p); };
void Owner::run(Data *p) { gInit.foo(); gA=p->a; gB=p->b; gC=p->c; host->f17(0,&gData); }