class A {
  public:
    char pad[0x284];
    int member;
    void First();
    void Last();
};
class B {
  public:
    void Second(int, int, int, int);
};
void __cdecl target(A* p1, int p2) {
    p1->First();
    ((B*)p1->member)->Second(p2, 3, 4, 1);
    p1->Last();
}