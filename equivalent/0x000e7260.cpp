// STATUS: equivalent (tools/equiv.py level 3: 33 inputs, branch coverage 38/44, incomplete)
// FUN_000e7260 @ 0x000e7260
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" char *strchr(const char *s, int c);
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);

class Node {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual int Lookup(const char *name);
};

class Registry_e7260 {
public:
    int FUN_000e7260(const char *name);
    Node *FUN_000e6490(const char *name);
    Node *FUN_000e6410(const char *name);

    char pad0[0xc];
    Node *groupA[0x40];
    Node *groupC[0x40];
    Node *groupB[0x100];
    char pad1[0x175c - 0x60c];
    Node *defaultA;
    Node *defaultB;
    char pad2[0x2218 - 0x1764];
    Node *defaultC;
};

struct Frame_e7260 {
    char buf[0x40];
    unsigned int cookie;
};

int Registry_e7260::FUN_000e7260(const char *name)
{
    Frame_e7260 f;
    f.cookie = DAT_004d9968;
    int result;
    if (name == 0) {
        result = 0;
    } else {
        const char *dot = strchr(name, '.');
        if (dot != 0) {
            int len = dot - name;
            if (len >= 0x40) {
                result = 0;
            } else {
                memcpy(f.buf, name, len);
                f.buf[len] = 0;
                Node *n = FUN_000e6490(f.buf);
                if (n == 0)
                    n = FUN_000e6410(f.buf);
                result = n->Lookup(dot + 1);
            }
        } else {
            result = 0;
            if (defaultA != 0)
                result = defaultA->Lookup(name);
            if (result == 0 && defaultB != 0)
                result = defaultB->Lookup(name);
            if (result == 0 && defaultC != 0)
                result = defaultC->Lookup(name);
            for (int i = 0; i < 0x40 && result == 0; i++) {
                Node *n = groupA[i];
                if (n != defaultA && n != 0)
                    result = n->Lookup(name);
            }
            for (int i = 0; i < 0x100 && result == 0; i++) {
                Node *n = groupB[i];
                if (n != defaultB && n != 0)
                    result = n->Lookup(name);
            }
            for (int i = 0; i < 0x40 && result == 0; i++) {
                Node *n = groupC[i];
                if (n != defaultC && n != 0)
                    result = n->Lookup(name);
            }
        }
    }
    __security_check_cookie(f.cookie);
    return result;
}
