class C_231e80 {
  public:
    char pad0[0x14];
    struct N_231e80* m;
    bool f(void*);
};
struct N_231e80 {
    char pad0[8];
    N_231e80* next;
    char pad1[0x10];
    void* value;
};
bool C_231e80::f(void* p) {
    N_231e80* n = m;
    while (n) {
        if (n->value == p)
            return true;
        n = n->next;
    }
    return false;
}