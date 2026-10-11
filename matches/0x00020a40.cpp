extern "C" char DAT_003f3390[];
extern "C" char DAT_003f3c90[];
class Param {
  public:
    virtual void Add();
    virtual void Drop();
};
void BaseInit();
class Obj {
  public:
    void* v;
    char pad[0x18];
    Param* p;
    volatile int value;
    Obj* ctor(int value, Param* p);
};
Obj* Obj::ctor(int value, Param* p) {
    BaseInit();
    v = (void*)((int)DAT_003f3390);
    this->p = 0;
    if (p)
        p->Add();
    if (this->p)
        this->p->Drop();
    *(Param* volatile*)&this->p = p;
    *(void* volatile*)&v = (void*)((int)DAT_003f3c90);
    this->value = 0;
    this->value = value;
    return this;
}
