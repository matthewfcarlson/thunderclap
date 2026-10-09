class A {
  public:
    char pad[0xc];
    int count;
    int* items;
    char pad2[0xa8];
    int state;
    void f();
};
void A::f() {
    if (state == 0) {
        state = 2;
        for (int i = 0; i < count; ++i) {
            ((A*)items[i])->f();
        }
    }
}