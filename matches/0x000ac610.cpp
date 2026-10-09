class Thing {
  public:
    char pad[0x14];
    float a;
    float b;
    char gap[4];
    float c;
    float d;
    float out1;
    float out2;
    int copy1;
    int copy2;
    void f();
};
void Thing::f() {
    copy1 = *(int*)&c;
    copy2 = *(int*)&a;
    out1 = (a + a) - (b + b) + d + c;
    out2 = (b * 3.0f - a * 3.0f) - (c + c) - d;
}