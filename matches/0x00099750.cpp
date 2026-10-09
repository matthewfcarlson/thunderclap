class C {
  public:
    int pad;
    unsigned int x;
};
unsigned int __fastcall FUN_00099750(C* p) {
    return (p->x >> 4) & 1;
}