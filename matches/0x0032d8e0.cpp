extern "C" char DAT_00433b9c[];
class Shader {
  public:
    virtual void A();
    virtual void B();
};
class Base_32d8e0 {
  public:
    void Cleanup();
};
class Thing_32d8e0 {
  public:
    virtual void V();
    char pad[0x7c];
    Shader* a;
    Shader* b;
    void Fn();
};
void Thing_32d8e0::Fn() {
    Shader* a = this->a;
    *(unsigned long*)this = ((int)DAT_00433b9c);
    if (a)
        a->B();
    Shader* b = this->b;
    if (b)
        b->B();
    ((Base_32d8e0*)this)->Cleanup();
}