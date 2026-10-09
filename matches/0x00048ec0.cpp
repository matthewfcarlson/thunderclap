class Result { char pad[0x24]; public: unsigned char value; };
class Input { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual Result* f3(); };
class CCollisionInterruptCondition {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(Input*);
    char pad[8];
    unsigned char value;
};
bool CCollisionInterruptCondition::vfunc_7(Input* param) {
    Result* result = param->f3();
    if (!result) return false;
    return result->value == value;
}