class Thing { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); };
class Manager { public: void Prep(int); Thing* Get(int); };
class Obj { public: char pad[0xbc]; Manager* mBC; int mC0; void Target(char flag); };
void Obj::Target(char flag) {
    mBC->Prep(mC0);
    Thing* t = mBC->Get(0);
    if (flag) t->f3();
    t->f4();
    t->f5();
}