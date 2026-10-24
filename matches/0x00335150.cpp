namespace movie {
struct Primary {
    virtual void f(int);
    int x;
};
struct Secondary {
    virtual void f(int);
};
struct __declspec(dllexport) BinkCallback : Primary, Secondary {
    virtual void f(int);
};
} // namespace movie