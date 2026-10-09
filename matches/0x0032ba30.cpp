extern int vtable;
class Shader {
  public:
    virtual void V();
    char pad[0x7c];
    int a;
    int b;
    char c;
    char d;
    int e;
    int f;
    void Init(int);
    Shader* Target(int);
};
Shader* Shader::Target(int arg) {
    Init(arg);
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    *(int*)this = (int)&vtable;
    return this;
}