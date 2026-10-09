class Node {
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
    virtual void update(int);
};
class MultiController {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16(int);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual float time();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    char pad[0x30];
    float mTime;
    char gap[4];
    int mode;
    unsigned char active;
    char pad2[3];
    int count;
    Node** nodes;
    void vfunc_16(int);
};
void MultiController::vfunc_16(int p) {
    if (mode != p) {
        mode = p;
        for (unsigned int i = 0; i < (unsigned int)count; i++)
            nodes[i]->update(p);
        mTime = time();
        int r;
        if (mode != 3 && mode != 5)
            r = 1;
        else
            r = 0;
        active = (unsigned char)r;
    }
}