class Sub { public: virtual void A(); virtual void B(); };
struct Container { char pad[4]; Sub sub; char pad2[0x10]; unsigned int value; };
class Outer { public: char pad[8]; Container *obj; unsigned int target(unsigned int a, unsigned int b); };
unsigned int Outer::target(unsigned int a, unsigned int b) {
    obj->sub.A();
    obj->value = b;
    obj->sub.B();
    return a;
}