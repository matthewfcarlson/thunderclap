// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_002939a0 @ 0x002939a0
class __declspec(novtable) CameraBase {
  public:
    virtual void slot0();
    char pad[0xd0 - 4];
    void FUN_00292d70();
    CameraBase() { FUN_00292d70(); }
};
namespace pure3d {
class VectorCamera : public CameraBase {
  public:
    VectorCamera();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    int f_d0, f_d4, f_d8, f_dc, f_e0;
    float f_e4;
    int f_e8;
    float f_ec;
    int f_f0;
};
}
pure3d::VectorCamera::VectorCamera() {
    f_d0 = 0;
    f_d4 = 0;
    f_d8 = 0;
    f_dc = 0;
    f_e0 = 0;
    f_e4 = 1.0f;
    f_e8 = 0;
    f_f0 = 0;
    f_ec = 1.0f;
}
