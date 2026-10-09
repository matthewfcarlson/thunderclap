class Thing { public: virtual void f(); virtual void Release(); };
class Obj { public: char pad[0x20]; Thing* a; char pad2[8]; Thing* b; char pad3[0x24]; Thing* c; void Clear(); };
void Obj::Clear() { if (b) { b->Release(); b = 0; } if (a) { a->Release(); a = 0; } if (c) { c->Release(); c = 0; } }