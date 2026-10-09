class C {
  public:
    char pad0[0x14];
    struct N* m;
    bool f(void*);
};
struct N {
    char pad0[8];
    N* next;
    char pad1[0x10];
    void* value;
};
bool C::f(void* p) {
    N* n = m;
    while (n) {
        if (n->value == p)
            return true;
        n = n->next;
    }
    return false;
}