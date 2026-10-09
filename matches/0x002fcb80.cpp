class X {
  public:
    char pad[4];
    float a[6];
    void Scale(float);
};
void X::Scale(float s) {
    a[0] *= s;
    a[1] *= s;
    a[2] *= s;
    a[3] *= s;
    a[4] *= s;
    a[5] *= s;
}