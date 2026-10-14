class Thing_16fc60 {
  public:
    char pad[0x98];
    int a;
    int b;
    int c;
    void f(int* out);
};
void Thing_16fc60::f(int* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
}