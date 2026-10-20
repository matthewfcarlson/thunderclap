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
} // namespace movie