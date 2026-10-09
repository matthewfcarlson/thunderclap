class Inner { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual bool f20(); virtual void f21(); };
class Manager { public: void update(); };
extern Manager* gThing;
extern int getThing();
class Target { public: char pad0[8]; Inner* obj; char padc[1]; bool flag; char pad_e[0x36]; int result; void run(); };
void Target::run() { if (obj) { if (flag) { obj->f21(); return; } while (!obj->f20()) { gThing->update(); result = getThing(); } } }