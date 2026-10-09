namespace pure3d {
class MultiController {
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
    virtual void f20();
    virtual void f21();
    virtual bool f22();
    virtual void f23();
    char pad[0x30];
    float value;
    char gap1[4];
    int flag;
    char gap2[4];
    unsigned count;
    MultiController **items;
};
}
extern const float zero;
bool pure3d::MultiController::f22() {
    if (flag == 0) {
        unsigned i = 0;
        if (count > 0) {
            do {
                if (!items[i]->f22()) return false;
                ++i;
            } while (i < count);
        }
        return true;
    }
    return value == zero;
}
