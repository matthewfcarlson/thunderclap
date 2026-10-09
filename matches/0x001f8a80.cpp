class Helper { public: void Release(int); };
class Owner { public: char pad[0x20]; volatile int member; Helper* GetHelper(); void Set(int); };
void Owner::Set(int value) { Helper* h = GetHelper(); h->Release(member); member = value; }