class Helper { public: void run(void *, unsigned int); };
class DebugConsole {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void vfunc_4(unsigned int);
 virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
 char pad[0x94 - 4]; unsigned int m94; char pad2[0xa4 - 0x98]; Helper *mA4;
};
void DebugConsole::vfunc_4(unsigned int p) {
 struct Data { unsigned int a,b,c; } d;
 d.a=2; d.b=(unsigned int)this; d.c=p;
 mA4->run(&d,12);
 m94=p;
}