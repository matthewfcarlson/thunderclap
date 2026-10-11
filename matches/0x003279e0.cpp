extern unsigned int DAT_005555b8;
struct ReceiverBaseA {
    int a;
};
struct ReceiverBaseB {
    int b;
};
struct Receiver : ReceiverBaseA, ReceiverBaseB {
    void set(unsigned int);
};
struct ParameterEntry {
    unsigned int key;
    unsigned int reserved;
    void (Receiver::*setter)(unsigned int);
    unsigned int extra[2];
};
namespace pure3d {
struct pddiBaseShader {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void FUN_00344f51();
    virtual bool vfunc_5(unsigned int key, unsigned int value);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void slot11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void slot14();
    virtual ParameterEntry* vfunc_15();
    unsigned int fields[2];
    unsigned int serial;
};
bool pddiBaseShader::vfunc_5(unsigned int key, unsigned int value) {
    ParameterEntry* entry = vfunc_15();
    if (!entry)
        return false;
    for (; entry->key; ++entry) {
        if (entry->key == key) {
            (reinterpret_cast<Receiver*>(this)->*(entry->setter))(value);
            unsigned int next = DAT_005555b8 + 1;
            DAT_005555b8 = next;
            if (next == 0xffffffffU)
                DAT_005555b8 = next = 0;
            serial = next;
            ++DAT_005555b8;
            return true;
        }
    }
    return false;
}
} // namespace pure3d
