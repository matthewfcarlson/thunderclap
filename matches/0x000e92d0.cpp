namespace pure3d {
class FrameController {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void SetValue(float value);
};
class TextureAnimationController : public FrameController {
public:
    virtual void SetValue(float value);
};
}

class ControllerHolder {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual pure3d::FrameController* GetController(int index);
};

struct Level3 {
    char pad[8];
    ControllerHolder* holder;
};
struct Level2 {
    char pad[0x3c];
    Level3* next;
};
struct Level1 {
    char pad[0x44];
    Level2* next;
};

class TextButton {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13(int unused);
    char pad4[0x50 - 4];
    Level1* parent;
    char pad54[0x148 - 0x54];
    int current;
    int target;
};

void TextButton::vfunc_13(int unused)
{
    current = target;
    if (parent) {
        pure3d::TextureAnimationController* tac =
            dynamic_cast<pure3d::TextureAnimationController*>(parent->next->next->holder->GetController(0));
        if (tac)
            tac->SetValue(1.0f);
    }
}
