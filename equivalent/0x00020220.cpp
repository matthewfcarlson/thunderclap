// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00020220 @ 0x00020220
class RefCounted {
public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase {
public:
    ActionBase() throw();
    virtual void v0();
    char pad04[0x1c - 4];
};

class CAction : public ActionBase {
public:
    CAction(RefCounted *r) throw() {
        owner = 0;
        if (r != 0)
            r->AddRef();
        if (owner != 0)
            owner->Release();
        owner = r;
    }
    virtual void v1();
    RefCounted *owner;
};

class CHeadTrackerAction : public CAction {
public:
    CHeadTrackerAction(int id, RefCounted *r) throw();
    virtual void v2();
    int id;
    int field24;
    char pad28[0x74 - 0x28];
    char flag74;
    char pad75[3];
    int w78;
    int w7c;
    int w80;
    float w84;
    int w88;
    int w8c;
};

// equiv-map: ??0ActionBase@@QAE@XZ = 0x00232660
CHeadTrackerAction::CHeadTrackerAction(int actionId, RefCounted *r) throw() : CAction(r)
{
    field24 = 0;
    w88 = 0;
    w8c = 0;
    id = actionId;
    flag74 = 0;
    w80 = 0;
    w7c = 0;
    w78 = 0;
    w84 = 1.0f;
}
