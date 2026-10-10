// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// pure3d::pddiBaseContext::vfunc_87 @ 0x0031f290
namespace pure3d {
struct StateA {
    int a0;
    int a4;
    char c8;
    int ac;
    char c10;
    int d14;
    char c18;
    char c19;
    char c1a;
    char c1b;
};
struct StateB {
    char data[0x34];
    void FUN_0031eab0(const StateB* prev);
};
struct StateC {
    char data[0x3ec];
    void FUN_0031eb70(const StateC* prev);
};
struct StateD {
    int a0;
    char c4;
    int a8;
    int ac;
    int a10;
};
struct StateE {
    int a0;
    char c4;
    int a8;
    int ac;
    int a10;
    int a14;
    int a18;
    int a1c;
    int a20;
};
template <class T>
struct StateStack {
    int field_00;
    int field_04;
    int top;
    T* items;
};
class pddiBaseContext {
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
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71();
    virtual void vfunc_72();
    virtual void vfunc_73();
    virtual void vfunc_74();
    virtual void vfunc_75();
    virtual void vfunc_76();
    virtual void vfunc_77();
    virtual void vfunc_78();
    virtual void vfunc_79();
    virtual void vfunc_80();
    virtual void vfunc_81();
    virtual void vfunc_82();
    virtual void vfunc_83();
    virtual void vfunc_84();
    virtual void vfunc_85();
    virtual void vfunc_86();
    virtual void vfunc_87(unsigned char flags);

    char pad_04[0x34 - 4];
    StateStack<StateB>* stackB;
    StateStack<StateA>* stackA;
    StateStack<StateC>* stackC;
    StateStack<StateD>* stackD;
    StateStack<StateE>* stackE;
    StateB* currentB;
    StateA* currentA;
    StateC* currentC;
    StateD* currentD;
    StateE* currentE;
};
}

void pure3d::pddiBaseContext::vfunc_87(unsigned char flags) {
    if (flags & 1) {
        stackA->top++;
        StateA* cur = &stackA->items[stackA->top];
        const StateA* prev = cur - 1;
        cur->a4 = prev->a4;
        cur->c8 = prev->c8;
        cur->ac = prev->ac;
        cur->c10 = prev->c10;
        cur->d14 = prev->d14;
        cur->c18 = prev->c18;
        cur->c19 = prev->c19;
        cur->c1a = prev->c1a;
        cur->c1b = prev->c1b;
        currentA = &stackA->items[stackA->top];
    }
    if (flags & 2) {
        stackB->top++;
        StateB* cur = &stackB->items[stackB->top];
        cur->FUN_0031eab0(cur - 1);
        currentB = &stackB->items[stackB->top];
    }
    if (flags & 4) {
        stackC->top++;
        StateC* cur = &stackC->items[stackC->top];
        cur->FUN_0031eb70(cur - 1);
        currentC = &stackC->items[stackC->top];
    }
    if (flags & 8) {
        stackD->top++;
        StateD* cur = &stackD->items[stackD->top];
        const StateD* prev = cur - 1;
        cur->c4 = prev->c4;
        cur->a8 = prev->a8;
        cur->ac = prev->ac;
        cur->a10 = prev->a10;
        currentD = &stackD->items[stackD->top];
    }
    if (flags & 0x10) {
        stackE->top++;
        StateE* cur = &stackE->items[stackE->top];
        const StateE* prev = cur - 1;
        cur->c4 = prev->c4;
        cur->a8 = prev->a8;
        cur->ac = prev->ac;
        cur->a10 = prev->a10;
        cur->a14 = prev->a14;
        cur->a18 = prev->a18;
        cur->a1c = prev->a1c;
        cur->a20 = prev->a20;
        currentE = &stackE->items[stackE->top];
    }
}
