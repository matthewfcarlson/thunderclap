class D {
  public:
    void f(void*);
};
class C {
    char pad[8];
    D* d;

  public:
    bool target(void* p);
};
bool C::target(void* p) {
    void* a = *(void**)((char*)p + 0x100);
    if (a) {
        void* b = *(void**)((char*)a + 0x74);
        if (b)
            d->f(b);
    }
    return true;
}