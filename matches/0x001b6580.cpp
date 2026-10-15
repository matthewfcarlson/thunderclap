typedef unsigned int size_t;
void* operator new(size_t) throw();
class Thing {
  public:
    Thing() throw();
    virtual void Init() throw();
    char pad[0x5a8];
};
extern Thing* gThing;
Thing* GetThing() {
    if (!gThing) {
        gThing = new Thing;
        gThing->Init();
        return gThing;
    }
    return gThing;
}
