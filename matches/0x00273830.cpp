class Interface { public: virtual void First(); virtual void Second(); };
class Object { public: char pad[4]; Interface iface; char pad2[0x0c]; int value; };
class Holder { public: char pad[8]; Object* obj; int Run(int a, int b); };
int Holder::Run(int a, int b) { obj->iface.First(); obj->value=b; obj->iface.Second(); return a; }