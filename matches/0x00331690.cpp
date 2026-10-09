class Shader {
  public:
    virtual void F0();
    virtual void F1();
};
class Obj {
  public:
    int vft;
    char pad[0x7c];
    Shader* a;
    Shader* b;
    void Fn();
    void End();
};
void Obj::Fn() {
    Shader* x = a;
    vft = 0x433e64;
    if (x)
        x->F1();
    x = b;
    if (x)
        x->F1();
    End();
}
