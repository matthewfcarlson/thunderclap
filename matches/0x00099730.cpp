class C_99730 {
  public:
    int pad;
    unsigned int m;
};
unsigned int __fastcall FUN_00099730(C_99730* p) {
    return (p->m >> 1) & 1;
}