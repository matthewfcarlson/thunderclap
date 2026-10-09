class Ref { public: virtual void f0(); virtual void Release(); };
class Owner { public: char pad[0x14]; Ref* second; Ref* first; void Clear(); };
void Owner::Clear() { if (first) { first->Release(); first = 0; } if (second) { second->Release(); second = 0; } }