class Base { public: virtual void Foo(); };
class Holder {
public:
    Base *ptr;
    Holder *Set(Base *p);
};
Holder * Holder::Set(Base *p) {
    ptr = p;
    p->Foo();
    return this;
}