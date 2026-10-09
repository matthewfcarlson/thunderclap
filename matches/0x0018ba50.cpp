class PropStateByIndexCondition { public: int a; int b; int c; int d; int e; int f; void Init(int); };
extern void* Alloc(unsigned int);
class Factory { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual PropStateByIndexCondition* f5(); };
PropStateByIndexCondition* Factory::f5() {
    PropStateByIndexCondition* p = (PropStateByIndexCondition*)Alloc(0x18);
    if (p) {
        p->Init(0);
        p->a = 0x41922c;
        p->d = -1;
        p->e = 0;
        p->f = 0;
        return p;
    }
    return 0;
}