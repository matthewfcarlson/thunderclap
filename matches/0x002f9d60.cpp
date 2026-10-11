class C {
  public:
    char pad0[0x30];
    void* m30;
    void* m34;
    char pad38[8];
    void* m40;
    void* m44;

    C* func(unsigned char p);
};

void __cdecl operator delete(void*);
void __cdecl operator delete[](void*);

C* C::func(unsigned char p) {
    void* v = m40;
    m44 = v;
    if (v) {
        operator delete[](v);
    }
    v = m30;
    m34 = v;
    if (v) {
        operator delete[](v);
    }
    if (p & 1) {
        operator delete(this);
    }
    return this;
}
