class Ref { public: virtual void f0(); virtual void f1(); };
class Obj { char pad[0x2c]; Ref* ref; public: void clear(); };
void Obj::clear() { if (ref) { ref->f1(); ref = 0; } }