// Same code shape as 0x001eb870 (propagated; names are from that function)
class B_1eb890 {
  public:
    void F();
};
class A_1eb890 {
  public:
    void* v;
    char pad[4];
    char flag;
};
void __fastcall target(A_1eb890* p) {
    if (p->flag)
        ((B_1eb890*)**(void***)p)->F();
}