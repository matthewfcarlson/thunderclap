class Obj {
  public:
    char pad[0x320];
    int state;
    int prev;
    int value;
    char rest[0x68];
    int reset;
    void f(int x);
};
void Obj::f(int x) {
    reset = 0;
    if (state == 7) {
        prev = value;
        state = x;
    } else {
        prev = state;
        state = x;
    }
}