struct Other {
    virtual void A();
    virtual void B();
};
struct C {
    void* vptr;
    char pad[8];
    Other* obj;
    void F();
};
void C::F() {
    vptr = (void*)0x41dc30;
    obj->B();
    vptr = (void*)0x3f6098;
}