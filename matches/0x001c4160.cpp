class Base { public: virtual void f0(); virtual void f1(); };
class Obj { public: char pad[0x10]; Base* member; int target(unsigned char flag); };
void thunk(Obj*);
int Obj::target(unsigned char flag) {
    if (member) member->f1();
    member = 0;
    if (flag & 1) thunk(this);
    return (int)this;
}