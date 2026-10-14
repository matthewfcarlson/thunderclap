// STATUS: equivalent (tools/equiv.py level 3: 117 inputs, branch coverage 12/12)
// FUN_00300360 @ 0x00300360
struct Obj {
    virtual void v0();
    virtual void Release();
};
struct ObjArray {
    Obj** begin;
    Obj** end;
    int pad[2];
};

class Container {
public:
    ObjArray a;
    ObjArray b;
    ObjArray c;
    ObjArray d;
    ObjArray e;
    void FUN_00300360();
};

// Releases every element of the first three arrays, then empties all five.
void Container::FUN_00300360()
{
    for (unsigned i = 0; i < (unsigned)(a.end - a.begin); i++)
        a.begin[i]->Release();
    for (unsigned i = 0; i < (unsigned)(b.end - b.begin); i++)
        b.begin[i]->Release();
    for (unsigned i = 0; i < (unsigned)(c.end - c.begin); i++)
        c.begin[i]->Release();
    a.end = a.begin;
    b.end = b.begin;
    c.end = c.begin;
    d.end = d.begin;
    e.end = e.begin;
}
