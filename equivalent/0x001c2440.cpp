// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 12/12)
// FUN_001c2440 @ 0x001c2440
// Update an entry's value; refresh the owner through its virtual slot unless the entry is still active.
struct Entry {
    char pad0[8];
    float value;
    float weight;
    float fade;
};

class Owner {
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

Entry* __stdcall FUN_001c23c0(Owner* owner, bool nonZero);

bool __stdcall FUN_001c2440(Owner* owner, float value)
{
    Entry* e = FUN_001c23c0(owner, value != 0.0f);
    if (e) {
        e->value = value;
        if (value > 0.0f || e->fade > 0.0f || e->weight < 1.0f) {
            return value != 0.0f;
        }
    }
    owner->Refresh();
    return value != 0.0f;
}
