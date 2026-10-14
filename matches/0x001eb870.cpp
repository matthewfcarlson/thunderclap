class B_1eb870 {
  public:
    void F();
};
class A_1eb870 {
  public:
    void* v;
    char pad[4];
    char flag;
};
void __fastcall target(A_1eb870* p) {
    if (p->flag)
        ((B_1eb870*)**(void***)p)->F();
}