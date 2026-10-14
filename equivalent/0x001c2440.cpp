// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 12/12)
// FUN_001c2440 @ 0x001c2440
// Update an entry's value; refresh the owner through its virtual slot unless the entry is still active.
struct Entry_1c2440 {
    char pad0[8];
    float value;
    float weight;
    float fade;
};

class Owner_1c2440 {
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
    virtual void Refresh();
};

Entry_1c2440* __stdcall FUN_001c23c0(Owner_1c2440* owner, bool nonZero);

bool __stdcall FUN_001c2440(Owner_1c2440* owner, float value)
{
    Entry_1c2440* e = FUN_001c23c0(owner, value != 0.0f);
    if (e) {
        e->value = value;
        if (value > 0.0f || e->fade > 0.0f || e->weight < 1.0f) {
            return value != 0.0f;
        }
    }
    owner->Refresh();
    return value != 0.0f;
}
