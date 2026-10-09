class Ref { public: virtual void A(); virtual void Release(); };
class Owner { public: char pad[4]; Ref *p; void Clear(); };
void Owner::Clear() { if (p) { p->Release(); p = 0; } }