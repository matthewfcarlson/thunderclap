class GlobalThing { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); };
extern GlobalThing* gThing;
class Other { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); };
class Target { public: char pad[0xe8]; Other* other; char pad2[8]; unsigned char flag; void run(bool); };
void Target::run(bool b) { gThing->f5(); flag = 0; if (b) other->f14(); }