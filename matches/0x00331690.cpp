extern "C" char DAT_00433e64[];
class Shader {
  public:
    virtual void F0();
    virtual void F1();
};
class Obj_331690 {
  public:
    int vft;
    char pad[0x7c];
    Shader* a;
    Shader* b;
    void Fn();
    void End();
};
void Obj_331690::Fn() {
    Shader* x = a;
    vft = ((int)DAT_00433e64);
    if (x)
        x->F1();
    x = b;
    if (x)
        x->F1();
    End();
}
