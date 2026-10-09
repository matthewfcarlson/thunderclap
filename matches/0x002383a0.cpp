class MaybeCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool v6(int a, int b, int c);
    char pad[8];
    float value;
};
typedef float(__cdecl* Fn)(int, int);
extern Fn globalFn;
extern int globalArg;
extern float zeroValue;
bool MaybeCondition::v6(int a, int b, int c) {
    float x;
    if (globalFn == 0)
        x = 0.0f;
    else
        x = globalFn(b, globalArg);
    return 100.0f * x < value;
}