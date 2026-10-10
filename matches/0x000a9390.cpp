// cl-flags: /O2 /GR /GX

class CGameCamera {
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
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37(int param_2, int param_3, int param_4, float param_5);

    char pad[0xf4 - 4]; // vptr at 0, slots at 0xf4

    struct Slot {
        int field0;
        int field1;
        int field2;
        float field3;
    };
    Slot slots[6];
};

void CGameCamera::vfunc_37(int param_2, int param_3, int param_4, float param_5) {
    if (param_2 >= 0 && param_2 < 6) {
        static const float twoPi = 6.28319f;
        float scaled = param_5 * twoPi;
        slots[param_2].field1 = param_3;
        slots[param_2].field2 = param_4;
        slots[param_2].field3 = scaled;
        slots[param_2].field0 = 0;
    }
}