class Thing {
  public:
    char pad[0x98];
    int a;
    int b;
    int c;
    void f(int* out);
};
void Thing::f(int* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
}