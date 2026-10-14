class Source_1b7a80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void Finish(int);
    virtual float Get();
};
class Target_1b7a80 {
  public:
    char pad[12];
    Source_1b7a80* source;
    char pad2[0x120];
    unsigned char done;
    float value;
    void Run();
};
void Target_1b7a80::Run() {
    if (!done && source != 0) {
        value = source->Get();
        if (source != 0)
            source->Finish(0);
        done = 1;
    }
}