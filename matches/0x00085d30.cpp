class Obj {
  public:
    virtual void AddRef();
    virtual void Release();
};
extern Obj* gObj;
void* operator new(unsigned int) throw();
class Made : public Obj {
    char pad[28];

  public:
    Made() throw();
};
void target() {
    Made* p = new Made;
    if (p)
        p->AddRef();
    if (gObj)
        gObj->Release();
    gObj = p;
}