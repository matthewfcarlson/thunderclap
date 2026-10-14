class A_293e40 {
    char pad[8];

  public:
    void f(int a, int b, int c, int d);
};
void A_293e40::f(int a, int b, int c, int d) {
    *(int*)((char*)this + 8) = a;
    *(int*)((char*)this + 12) = b;
    *(int*)((char*)this + 16) = c;
    *(int*)((char*)this + 20) = d;
}