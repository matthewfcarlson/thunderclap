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
    virtual void vfunc_37(int index, int first, int second, float turns);

    char pad[0xf4 - 4]; // vptr at 0, slots at 0xf4

    struct Slot {
        int field0;
        int field1;
        int field2;
        float field3;
    };
    Slot slots[6];
};

void CGameCamera::vfunc_37(int index, int first, int second, float turns) {
    if (index >= 0 && index < 6) {
        static const float twoPi = 6.2831855f;
        float scaled = turns * twoPi;
        slots[index].field1 = first;
        slots[index].field2 = second;
        slots[index].field3 = scaled;
        slots[index].field0 = 0;
    }
}