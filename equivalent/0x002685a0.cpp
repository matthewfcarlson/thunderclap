// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 12/12)
// core::ControllerXBox::vfunc_17 @ 0x002685a0
struct InputState {
    int packet;
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    short field_14;
};
extern "C" unsigned long __stdcall XInputGetState(void* handle, InputState* state);
extern "C" unsigned long __stdcall XInputSetState(void* handle, void* feedback);

class Receiver_2685a0 {
  public:
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5(InputState* state);
};
class Motor {
  public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual float m5();
};
class ControllerXBox {
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
    virtual void vfunc_17(int arg);
    unsigned int connected;
    void* handle;
    char pad_0c[0x428 - 0xc];
    Motor leftMotor;
    char pad_42c[0x438 - 0x42c];
    Motor rightMotor;
    char pad_43c[0x454 - 0x43c];
    Receiver_2685a0* receiver;
    unsigned long feedbackStatus;
    int feedbackField;
    char pad_460[0x49a - 0x460];
    short lastLeft;
    short lastRight;
};
void ControllerXBox::vfunc_17(int arg) {
    if (connected == 0)
        return;
    if (handle != 0) {
        InputState state;
        state.field_04 = 0;
        state.field_08 = 0;
        state.field_0c = 0;
        state.field_10 = 0;
        state.field_14 = 0;
        state.packet = 0;
        if (XInputGetState(handle, &state) == 0) {
            state.packet = arg;
            receiver->r5(&state);
        }
    }
    if (feedbackStatus == 0x3e5)
        return;
    short left = (short)(int)(leftMotor.m5() * 65535.0f);
    short right = (short)(int)(rightMotor.m5() * 65535.0f);
    if (left != lastLeft || right != lastRight) {
        feedbackStatus = 0;
        feedbackField = 0;
        lastLeft = left;
        lastRight = right;
        XInputSetState(handle, &feedbackStatus);
    }
}
