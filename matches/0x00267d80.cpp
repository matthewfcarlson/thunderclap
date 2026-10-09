class Timer {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(int); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13();
    char pad[8];
    int value;
    unsigned char active;
};
void Timer::f6(int x) {
    if (active) {
        f10();
        value = x;
        f9();
    } else {
        value = x;
    }
}