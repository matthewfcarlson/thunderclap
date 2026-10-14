class X_258c80 {
  public:
    char pad[0x10];
    float value;
};
void FUN_00258c80(X_258c80* x, float v) {
    if (x->value != v)
        x->value = v;
}