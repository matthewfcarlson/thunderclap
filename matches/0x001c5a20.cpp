class Ref { public: virtual void f0(); virtual void Release(); };
class Sub { public: Ref* Get(int); void Other(int); char pad[0x240]; };
class Owner { public: char pad0[8]; Sub sub; Ref* m248; void Target(int); };
void Owner::Target(int arg) { Ref* p = sub.Get(arg); sub.Other(arg); if (p == m248) m248 = 0; if (p) p->Release(); }
