// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_002a2130 @ 0x002a2130
// equiv-map: ??0DisplayTraversal@pure3d@@QAE@XZ = 0x002c6a80
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);

namespace pure3d {

class DisplayTraversal {
public:
    DisplayTraversal() throw();
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[8];
    unsigned int flags;         // 0x0c
    int mode;                   // 0x10
};

class TranslucentTraversal : public DisplayTraversal {
public:
    TranslucentTraversal(unsigned int capacity);
    virtual void vfunc_6();
    char pad14[4];
    unsigned int count;         // 0x18
    char *entriesBegin;         // 0x1c  (24-byte entries)
    char *entriesEnd;           // 0x20
    char pad24[4];
    char *orderBegin;           // 0x28  (pointer per entry)
    char *orderEnd;             // 0x2c
};

TranslucentTraversal::TranslucentTraversal(unsigned int capacity)
{
    count = 0;

    if (capacity != 0) {
        unsigned int bytes = capacity * 24;
        char *p = (char *)FUN_0008d6d0(bytes);
        entriesBegin = p;
        entriesEnd = (p != 0) ? p + bytes : 0;
    } else {
        entriesBegin = 0;
        entriesEnd = 0;
    }

    if (capacity != 0) {
        unsigned int bytes = capacity * 4;
        char *p = (char *)FUN_0008d6d0(bytes);
        orderBegin = p;
        orderEnd = (p != 0) ? p + bytes : 0;
    } else {
        orderBegin = 0;
        orderEnd = 0;
    }

    flags &= ~0x30u;
    mode = 1;
}

}
