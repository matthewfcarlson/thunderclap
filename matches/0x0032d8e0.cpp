class Shader {
  public:
    virtual void A();
    virtual void B();
};
class Base {
  public:
    void Cleanup();
};
class Thing {
  public:
    virtual void V();
    char pad[0x7c];
    Shader* a;
    Shader* b;
    void Fn();
};
void Thing::Fn() {
    Shader* a = this->a;
    *(unsigned long*)this = 0x433b9c;
    if (a)
        a->B();
    Shader* b = this->b;
    if (b)
        b->B();
    ((Base*)this)->Cleanup();
}