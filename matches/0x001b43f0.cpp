class D {
  public:
    void f(void*);
};
class C_1b43f0 {
    char pad[8];
    D* d;

  public:
    bool target(void* p);
};
bool C_1b43f0::target(void* p) {
    void* a = *(void**)((char*)p + 0x100);
    if (a) {
        void* b = *(void**)((char*)a + 0x74);
        if (b)
            d->f(b);
    }
    return true;
}