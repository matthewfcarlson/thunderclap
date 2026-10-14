// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 13/14, incomplete)
// core::ControllerXBox::vfunc_14 @ 0x00268970
namespace core {
struct Entry_268970 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual const char* vfunc_4();
    char reserved[12];
};
struct ControllerXBox {
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
    virtual Entry_268970* vfunc_14(const char* name, int ordinal);
    char reserved[0x424];
    Entry_268970 entries[2];
};
Entry_268970* ControllerXBox::vfunc_14(const char* name, int ordinal) {
    int matches = 0;
    for (unsigned int i = 0; i < 2; ++i) {
        const char* candidate = entries[i].vfunc_4();
        const char* requested = name;
        while (*candidate == *requested) {
            if (*candidate == '\0') {
                if (matches == ordinal)
                    return &entries[i];
                ++matches;
                break;
            }
            ++candidate;
            ++requested;
        }
    }
    return 0;
}
}
