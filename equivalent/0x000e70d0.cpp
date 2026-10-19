// STATUS: equivalent (tools/equiv.py level 3: 119 inputs, branch coverage 42/42)
// FUN_000e70d0 @ 0x000e70d0
// FUN_000e70d0 @ 0x000e70d0
// cl-flags: /GS
extern "C" char *strchr(const char *s, int c);
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);

struct Node {
    virtual void vfn0(); virtual void vfn1(); virtual void vfn2(); virtual void vfn3();
    virtual void vfn4(); virtual void vfn5(); virtual void vfn6(); virtual void vfn7();
    virtual void vfn8(); virtual void vfn9(); virtual void vfn10(); virtual void vfn11();
    virtual void vfn12(); virtual void vfn13(); virtual void vfn14(); virtual void vfn15();
    virtual void vfn16(); virtual void vfn17(); virtual void vfn18(); virtual void vfn19();
    virtual void vfn20(); virtual void vfn21(); virtual void vfn22(); virtual void vfn23();
    virtual void vfn24(); virtual void vfn25(); virtual void vfn26(); virtual void vfn27();
    virtual void vfn28(); virtual void vfn29(); virtual void vfn30(); virtual void vfn31();
    virtual void vfn32(); virtual void vfn33(); virtual void vfn34(); virtual void vfn35();
    virtual void *find(const char *name);
};

class Registry_e70d0 {
public:
    char pad0[0xc];
    Node *groupA[0x40];
    Node *groupB[0x40];
    Node *groupC[0x100];
    char pad1[0x175c - 0x60c];
    Node *primaryA;
    Node *primaryC;
    char pad2[0x2218 - 0x1764];
    Node *primaryB;
    Node *FUN_000e6410(const char *name);
    Node *FUN_000e6490(const char *name);
    void *FUN_000e70d0(const char *name);
};

void *Registry_e70d0::FUN_000e70d0(const char *name)
{
    const char *dot = strchr(name, '.');
    if (dot != 0) {
        int length = dot - name;
        if (length >= 0x40)
            return 0;
        char prefix[0x40];
        memcpy(prefix, name, length);
        prefix[length] = 0;
        Node *node = FUN_000e6490(prefix);
        if (node == 0)
            node = FUN_000e6410(prefix);
        return node->find(dot + 1);
    }

    void *result;
    if (primaryA != 0) {
        result = primaryA->find(name);
        if (result != 0) return result;
    }
    if (primaryC != 0) {
        result = primaryC->find(name);
        if (result != 0) return result;
    }
    if (primaryB != 0) {
        result = primaryB->find(name);
        if (result != 0) return result;
    }
    for (int i = 0; i < 0x40; ++i) {
        Node *node = groupA[i];
        if (node != primaryA && node != 0) {
            result = node->find(name);
            if (result != 0) return result;
        }
    }
    for (int i = 0; i < 0x100; ++i) {
        Node *node = groupC[i];
        if (node != primaryC && node != 0) {
            result = node->find(name);
            if (result != 0) return result;
        }
    }
    for (int i = 0; i < 0x40; ++i) {
        Node *node = groupB[i];
        if (node != primaryB && node != 0) {
            result = node->find(name);
            if (result != 0) return result;
        }
    }
    return 0;
}
