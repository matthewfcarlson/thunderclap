// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 13/14, incomplete)
// FUN_000ce5c0 @ 0x000ce5c0
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
    virtual void v13(int a);
    virtual void v14();
};

struct Lookup {
    Node* FUN_000d3f10(int key);
};

struct Parent {
    char pad[0x114];
    Lookup* lookup;
};

class Obj {
public:
    int run(int key, int lo, int hi, int arg4);
    char p0[0x7c];
    Parent* parent;
    char p1[0x214 - 0x80];
    int counter;
    Node* node;
    int n21c;
    float f220;
    char active;
    char has;
    char pad226[2];
    int lo;
    int hi;
    char pad230[0x23c - 0x230];
    int n23c;
    int n240;
};

int Obj::run(int key, int lo_, int hi_, int arg4)
{
    counter = (counter + 1) % 10000;
    if (counter == 0)
        counter = 1;
    n240 = arg4;
    n23c = 0;

    Node* found = parent->lookup->FUN_000d3f10(key);
    if (found == 0) {
        active = 0;
        has = 0;
        lo = 0;
        hi = 0;
        return counter;
    }
    if (active != 0)
        return counter;

    if (node != 0) {
        node->v14();
        if (node != 0) {
            node->v1();
            node = 0;
        }
    }
    active = 1;
    found->v0();
    if (node != 0)
        node->v1();
    node = found;
    found->v13(n21c);
    if ((lo_ | hi_) != 0) {
        lo = lo_;
        has = 1;
        hi = hi_;
        f220 = 1.0f;
        return counter;
    }
    has = 0;
    lo = 0;
    hi = 0;
    f220 = 1.0f;
    return counter;
}
