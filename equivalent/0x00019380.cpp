// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00019380 @ 0x00019380
// CCollisionAction::CCollisionAction @ 0x00019380
struct Ref {
    virtual void AddRef();
    virtual void Release();
};

struct Owner {
    char pad00[0xe0];
    float x;
    float y;
    float z;
};

struct FUN_00232660 {
    FUN_00232660() throw();
    virtual void v0();
    char pad04[0x18];
};

class CAction : public FUN_00232660 {
public:
    Ref *target;
    Owner *owner;
    int param;
    char pad28[0x34 - 0x28];
    CAction(Owner *o, Ref *t, int p) {
        target = 0;
        if (t)
            t->AddRef();
        if (target)
            target->Release();
        target = t;
        param = p;
        owner = o;
    }
    virtual void v1();
};

class CCollisionAction : public CAction {
public:
    int f34;
    int f38;
    int f3c;
    float y;
    float z;
    Ref *source;
    CCollisionAction(Ref *s, Owner *o, Ref *t, int p);
    virtual void v1();
};

CCollisionAction::CCollisionAction(Ref *s, Owner *o, Ref *t, int p) : CAction(o, t, p)
{
    f34 = 0;
    f38 = 0;
    f3c = 0;
    source = 0;
    struct { float x, y, z; } pos;
    pos.x = o->x;
    pos.y = o->y;
    pos.z = o->z;
    y = pos.y;
    z = pos.z;
    if (s)
        s->AddRef();
    if (source)
        source->Release();
    source = s;
}
