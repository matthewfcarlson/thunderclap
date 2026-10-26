struct Blur_Target {
    void FUN_001c3830(int a, int b);
};
Blur_Target* FUN_001c3d90();

namespace hulkfight { namespace motion {
class MotionBlurAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad[0x24 - 4];
    int a;
    int b;
};
void MotionBlurAction::vfunc_4() {
    int y = b;
    int x = a;
    FUN_001c3d90()->FUN_001c3830(x, y);
}
}}
