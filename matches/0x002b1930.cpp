namespace pure3d {
class MultiController {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual float a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    char pad[0x30];
    float time;
    int frame;
    int mode;
    char active;
    void vfunc_18(int);
};
void MultiController::vfunc_18(int value) {
    if (frame != value) {
        frame = value;
        time = a20();
        int r;
        if (mode == 3 || mode == 5)
            r = 0;
        else
            r = 1;
        active = (char)r;
    }
}
} // namespace pure3d
