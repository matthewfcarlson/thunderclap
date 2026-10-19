extern "C" char DAT_003f3390[];
extern "C" char DAT_003f3c90[];
class Param {
  public:
    virtual void Add();
    virtual void Drop();
};
struct ThisCall_00232660 {
    void BaseInit();
};
class Obj_20a40 {
  public:
    void* v;
    char pad[0x18];
    Param* p;
    volatile int value;
    Obj_20a40* ctor(int value, Param* p);
};
Obj_20a40* Obj_20a40::ctor(int value, Param* p) {
    ((ThisCall_00232660*)(this))->BaseInit();
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
