class Ref_1c5d30 {
  public:
    virtual void f0();
    virtual void Release();
};
class Base_1c5d30 {
  public:
    void Finish();
};
class Target_1c5d30 : public Base_1c5d30 {
  public:
    char pad[8];
    Ref_1c5d30* volatile b;
    Ref_1c5d30* volatile a;
    void Clear();
};
void Target_1c5d30::Clear() {
    Ref_1c5d30* x = a;
    if (x)
        x->Release();
    a = 0;
    x = b;
    if (x)
        x->Release();
    b = 0;
    Finish();
}