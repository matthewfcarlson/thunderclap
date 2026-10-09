class Inner { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); void helper(int); };
struct Wrap { char pad[0x10]; Inner* ptr; };
class Outer { public: char pad[0xa0]; Wrap* ptr; void run(); };
void Outer::run() { Wrap* w = ptr; if (w) { Inner* p = w->ptr; if (p) { p->helper(0); p->f7(); } } }