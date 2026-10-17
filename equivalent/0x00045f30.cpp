// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 11/12, incomplete)
// FUN_00045f30 @ 0x00045f30
struct Obj {
    virtual void FUN_0();
    virtual void FUN_1();
    virtual void FUN_2();
    virtual void FUN_3();
    virtual void FUN_4();
    virtual void FUN_5();
    virtual void FUN_6();
    virtual void FUN_7();
    virtual void FUN_8();
    virtual void FUN_9();
    virtual void FUN_10();
    virtual void FUN_11();
    virtual void FUN_12();
    virtual void FUN_13();
    virtual void FUN_14();
    virtual void FUN_15();
    virtual void FUN_16();
    virtual void FUN_17();
    virtual void FUN_18();
    virtual void FUN_19();
    virtual void FUN_20();
    virtual void FUN_21();
    virtual void FUN_22();
    virtual void FUN_23();
    virtual void FUN_24();
    virtual void FUN_25();
    virtual void* FUN_26();
};
struct Provider {
    virtual void FUN_0();
    virtual void FUN_1();
    virtual void FUN_2();
    virtual void FUN_3();
    virtual void FUN_4();
    virtual void FUN_5();
    virtual void FUN_6();
    virtual void FUN_7();
    virtual void FUN_8();
    virtual void FUN_9();
    virtual void FUN_10();
    virtual char* FUN_11();
};
struct Target {
    char pad0[8];
    Provider* provider;
    Obj* held;
    bool FUN_00045f30(Obj* incoming);
};
bool Target::FUN_00045f30(Obj* incoming) {
    if (incoming) {
        if (!provider) return false;
        char* value = provider->FUN_11();
        void* expected = *(void**)(value + 8);
        if (!expected || incoming->FUN_26() != expected) return false;
        incoming->FUN_0();
    }
    if (held) held->FUN_1();
    held = incoming;
    return true;
}