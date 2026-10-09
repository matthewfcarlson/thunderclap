class Entry {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9(void*, void*, int);
};
class Owner {
  public:
    char pad[12];
    Entry* entries[128];
    void run(void*, void*);
};
void Owner::run(void* a, void* b) {
    for (int i = 0; i != 128; ++i) {
        Entry* p = entries[i];
        if (p != 0)
            p->f9(a, b, 0);
    }
}