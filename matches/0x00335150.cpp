namespace movie {
struct Primary {
    virtual void f();
    int x;
};
struct Secondary {
    virtual void f();
};
struct __declspec(dllexport) BinkCallback : Primary, Secondary {
    virtual void f();
};
void BinkCallback::f() {}
} // namespace movie