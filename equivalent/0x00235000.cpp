// STATUS: equivalent (tools/equiv.py level 3: 192 inputs, branch coverage 12/12)
// fight::ParamValueEntity::vfunc_10 @ 0x00235000
struct Entry { char pad00[8]; int key0; int key1; };

class ParamValueEntity {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool v6(int param, Entry* entry);
    virtual Entry* v7(int param, int index);
    virtual int v8(int param);
    virtual void v9();
    virtual Entry* v10(int param, int key0, int key1);
};

Entry* ParamValueEntity::v10(int param, int key0, int key1)
{
    int count = v8(param);
    for (int i = 0; i < count; i++) {
        Entry* entry = v7(param, i);
        if (entry != 0 && entry->key0 == key0 && entry->key1 == key1) {
            if (v6(param, entry))
                return entry;
        }
    }
    return 0;
}
