class C_99750 {
  public:
    int pad;
    unsigned int x;
};
unsigned int __fastcall FUN_00099750(C_99750* p) {
    return (p->x >> 4) & 1;
}