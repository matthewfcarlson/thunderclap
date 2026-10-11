// STATUS: equivalent (tools/equiv.py level 3: 164 inputs, branch coverage 51/52, incomplete)
// CSmartPropNameCondition::vfunc_7 @ 0x000495d0
struct Value {
    char pad00[0xc0];
    unsigned long long raw;
};
unsigned long long __fastcall FUN_001d4f70(Value* v);

struct Key {
    char pad00[8];
    unsigned int lo;
    unsigned int hi;
};

struct Item {
    char pad00[0x9c];
    Key* key;
    char padA0[0x4c];
    Value* value;
};

struct Current {
    char pad00[8];
    Item* item;
    int kind;
};

struct Fighter {
    char pad00[0x3a4];
    Current* current;
    Item* FUN_00035ef0(int index);
};

void* __fastcall FUN_000592a0(void* owner);
Fighter* __fastcall FUN_00059a30(void* holder);

class CSmartPropNameCondition {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual bool vfunc_7(void* params);
    char pad04[8];
    int mode;
    int slot;
    char pad14[4];
    unsigned int keyLo;
    unsigned int keyHi;
};

bool CSmartPropNameCondition::vfunc_7(void* params)
{
    if ((keyLo | keyHi) == 0)
        return false;

    Fighter* fighter = FUN_00059a30(FUN_000592a0(params));
    Item* item;

    if (slot == -1) {
        bool none = true;
        for (int i = 0; i < 8; i++) {
            item = fighter->FUN_00035ef0(i);
            if (!item)
                continue;
            none = false;
            int m = mode;
            Key* key = item->key;
            if (m == 0) {
                unsigned int lo = keyLo;
                unsigned int hi = keyHi;
                if (lo == key->lo && hi == key->hi)
                    return true;
                unsigned long long v = FUN_001d4f70(item->value);
                if (lo == (unsigned int)v && hi == (unsigned int)(v >> 32))
                    return true;
            } else if (m == 1) {
                unsigned int lo = keyLo;
                unsigned int hi = keyHi;
                if (lo != key->lo || hi != key->hi) {
                    unsigned long long v = FUN_001d4f70(item->value);
                    if (lo != (unsigned int)v || hi != (unsigned int)(v >> 32))
                        return true;
                }
            }
        }
        if (!none)
            return false;
        Current* cur = fighter->current;
        if (!cur || cur->kind != 5)
            return false;
        item = cur->item;
    } else {
        item = fighter->FUN_00035ef0(slot);
        if (!item) {
            Current* cur = fighter->current;
            if (!cur || cur->kind != 5)
                return false;
            item = cur->item;
        }
    }

    int m = mode;
    Key* key = item->key;
    if (m == 0) {
        unsigned int lo = keyLo;
        unsigned int hi = keyHi;
        if (lo == key->lo && hi == key->hi)
            return true;
        unsigned long long v = FUN_001d4f70(item->value);
        if (lo == (unsigned int)v && hi == (unsigned int)(v >> 32))
            return true;
    } else if (m == 1) {
        unsigned int lo = keyLo;
        if (lo != key->lo || keyHi != key->hi)
            FUN_001d4f70(item->value);
    }
    return false;
}
