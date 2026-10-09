class Obj { public: virtual void f0(); virtual void f1(); };
class Target { public: char pad[0x0c]; volatile int state; char pad2[0x20]; Obj* volatile ptr; void Run(); };
void Target::Run() { state = -1; Obj* p = ptr; if (p) { p->f1(); ptr = 0; } }