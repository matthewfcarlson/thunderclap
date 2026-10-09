class Entity { public: virtual void f0(); virtual void f1(); };
class Sequence : public Entity { public: virtual void f2(); virtual void f3(); virtual void f4(); virtual bool vfunc_5(int); virtual void f6(); virtual void f7(); virtual void f8(); bool first(int); bool second(int); };
extern bool __cdecl check(int, int*);
bool Sequence::vfunc_5(int x) { int t; if (check(x, &t) && t == 1 && first(x) && second(x)) return true; return false; }