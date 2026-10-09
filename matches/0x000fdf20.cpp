class Obj { public: char pad0[0x40]; int a; int b; int c; };
class Target { public: char pad0[0x0c]; Obj* source; char pad1[0x50-0x10]; int a; int b; int c; void Run(); };
void Target::Run() { if (source) { a = source->a; b = source->b; c = source->c; } }