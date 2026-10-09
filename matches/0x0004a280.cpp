class CMotionStateCondition {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual bool f7(int); virtual int f8(int);
    char pad[8];
    int mode;
    int state;
};
bool CMotionStateCondition::f7(int p) {
    int result = f8(p);
    if (!result) return false;
    int expected = state;
    int op = mode;
    switch (op) {
    case 0: return *(int *)(result + 0x140) == expected;
    case 1: return *(int *)(result + 0x140) != expected;
    }
    return false;
}