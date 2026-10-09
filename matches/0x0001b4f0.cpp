class Ref { public: virtual void A(); virtual void B(); };
class Obj { char pad[0x24]; public: Ref* ref; void F(); };
void Obj::F() { if (ref) { ref->B(); ref = 0; } }