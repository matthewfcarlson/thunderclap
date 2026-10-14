class A_30ecb0 {
  public:
    char pad[0xc];
    int count;
    int* items;
    char pad2[0xa8];
    int state;
    void f();
};
void A_30ecb0::f() {
    if (state == 0) {
        state = 2;
        for (int i = 0; i < count; ++i) {
            ((A_30ecb0*)items[i])->f();
        }
    }
}