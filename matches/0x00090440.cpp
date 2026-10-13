class C {
  public:
    char pad[0x10cc];
    int m;
};
int __fastcall Sub(C* p) {
    return p->m;
}