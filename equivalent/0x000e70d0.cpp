// STATUS: equivalent (tools/equiv.py level 3: 39 inputs, branch coverage 36/42, incomplete)
// FUN_000e70d0 @ 0x000e70d0
extern "C" char *strchr(const char *s, int c);
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

struct Node {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void *find(const char *name);
};

class Registry_e70d0 {
public:
    char pad0[0xc];
    Node *groupA[0x40];      // 0xc
    Node *groupB[0x40];      // 0x10c
    Node *groupC[0x100];     // 0x20c
    char pad1[0x175c - 0x60c];
    Node *primaryA;          // 0x175c
    Node *primaryC;          // 0x1760
    char pad2[0x2218 - 0x1764];
    Node *primaryB;          // 0x2218
    Node *FUN_000e6410(const char *name);
    Node *FUN_000e6490(const char *name);
    void *FUN_000e70d0(const char *name);
};

void *Registry_e70d0::FUN_000e70d0(const char *name)
{
    unsigned int cookie = DAT_004d9968;
    char buf[0x40];
    const char *dot = strchr(name, '.');
    int i;
    if (dot != 0) {
        int len = dot - name;
        if (len >= 0x40) {
            __security_check_cookie(cookie);
            return 0;
        }
        memcpy(buf, name, len);
        buf[len] = 0;
        Node *n = FUN_000e6490(buf);
        if (n == 0)
            n = FUN_000e6410(buf);
        void *r = n->find(dot + 1);
        __security_check_cookie(cookie);
        return r;
    }
    void *r;
    if (primaryA != 0) {
        r = primaryA->find(name);
        if (r != 0) goto done;
    }
    if (primaryC != 0) {
        r = primaryC->find(name);
        if (r != 0) goto done;
    }
    if (primaryB != 0) {
        r = primaryB->find(name);
        if (r != 0) goto done;
    }
    r = 0;
    for (i = 0; i < 0x40; i++) {
        if (groupA[i] != primaryA && groupA[i] != 0) {
            r = groupA[i]->find(name);
            if (r != 0) goto done;
        }
    }
    for (i = 0; i < 0x100; i++) {
        if (groupC[i] != primaryC && groupC[i] != 0) {
            r = groupC[i]->find(name);
            if (r != 0) goto done;
        }
    }
    for (i = 0; i < 0x40; i++) {
        if (groupB[i] != primaryB && groupB[i] != 0) {
            r = groupB[i]->find(name);
            if (r != 0) goto done;
        }
    }
done:
    __security_check_cookie(cookie);
    return r;
}
