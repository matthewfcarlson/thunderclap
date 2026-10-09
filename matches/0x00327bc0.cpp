class Callback {
  public:
    void Dummy();
};
typedef void (Callback::*InvokeFn)(int);
struct Item {
    int key;
    int x;
    InvokeFn fn;
    int adj;
    int pad[2];
};
extern int counter;
struct pddiBaseShader {
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
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual Item* GetResult();
    char pad[8];
    int id;
    bool v10(int key, int arg);
};
bool pddiBaseShader::v10(int key, int arg) {
    Item* p = GetResult();
    if (p) {
        int k = p->key;
        while (k) {
            if (k == key) {
                Callback* cb = (Callback*)((char*)this + p->adj);
                (cb->*(p->fn))(arg);
                counter++;
                if (counter == -1)
                    counter = 0;
                id = counter;
                counter++;
                return true;
            }
            p++;
            k = p->key;
        }
    }
    return false;
}
