// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00280460 @ 0x00280460
// Claim a free slot (of 100) for a ref-counted object and return the slot's new id (0 when none is free).
class Transform_280460 {
public:
    char data[0x40];
    void FUN_0022b980();
};

class Object {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void Attach(int arg);
};

struct Item_280460 {
    int id;
    char flag;
    char pad5[3];
    Transform_280460 transform;
    Object* held;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
};

class SlotTable_280460 {
public:
    char pad0[0x10];
    int nextId;
    char pad14[4];
    Item_280460 items[100];

    int FUN_00280460(Object* object, int arg, int value);
};

int SlotTable_280460::FUN_00280460(Object* object, int arg, int value)
{
    Item_280460* item = items;
    for (int i = 0; ; ++i, ++item) {
        if (item->held == 0) {
            break;
        }
        if (i + 1 >= 100) {
            return 0;
        }
    }

    int id = nextId;
    item->id = id;
    item->transform.FUN_0022b980();
    if (object) {
        object->AddRef();
    }
    if (item->held) {
        item->held->Release();
    }
    item->held = object;
    object->Attach(arg);
    item->field4c = 0;
    item->flag = 0;
    item->field50 = 0;
    item->field54 = 0;
    item->field58 = 0xffff;
    item->field5c = value;
    ++nextId;
    return id;
}
