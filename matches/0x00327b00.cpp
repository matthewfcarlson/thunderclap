struct Receiver_327b00 {
    void set(unsigned);
};
typedef void (Receiver_327b00::*Setter_327b00)(unsigned);
struct ParameterEntry_327b00 {
    unsigned key;
    unsigned reserved;
    Setter_327b00 setter;
    int receiverOffset;
    unsigned unused[2];
};
extern unsigned DAT_005555b8;
namespace pure3d {
struct pddiBaseShader {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void slot4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual bool vfunc_8(unsigned key, unsigned value);
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void slot11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void slot14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual ParameterEntry_327b00* vfunc_18();
    unsigned unused[2];
    unsigned changeId;
};
bool pddiBaseShader::vfunc_8(unsigned key, unsigned value) {
    ParameterEntry_327b00* entry = vfunc_18();
    if (!entry)
        return false;
    for (; entry->key; ++entry) {
        if (entry->key == key) {
            Receiver_327b00* receiver =
                reinterpret_cast<Receiver_327b00*>(reinterpret_cast<char*>(this) + entry->receiverOffset);
            (receiver->*entry->setter)(value);
            unsigned id = DAT_005555b8 + 1;
            DAT_005555b8 = id;
            if (id == ~0u) {
                id = 0;
                DAT_005555b8 = 0;
            }
            changeId = id;
            ++DAT_005555b8;
            return true;
        }
    }
    return false;
}
} // namespace pure3d