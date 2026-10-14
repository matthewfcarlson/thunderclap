// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00245040 @ 0x00245040
struct Key_245040 {
    int lo;
    int hi;
};

struct Region_245040 {
    char pad0[0x30];
    int boundsLo;           // 0x30
    int boundsHi;           // 0x34
};

struct Query_245040 {
    int keyLo;
    int keyHi;
    int boundsLo;
    int boundsHi;
};

struct Index;
extern Index *DAT_004cc08c;
int __cdecl FUN_00244be0(Index *idx, Query_245040 *q);
void __cdecl FUN_00244b20(Index *idx, void *item);
void __cdecl FUN_002448b0(Index *idx, void *item, Query_245040 *q);

class Item_245040 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual Region_245040 *GetRegion();                    // slot 8
    char pad4[0x14];
    Key_245040 key;                // 0x18

    bool FUN_00245040(const Key_245040 *newKey);
};

bool Item_245040::FUN_00245040(const Key_245040 *newKey)
{
    if (newKey->lo == key.lo && newKey->hi == key.hi)
        return true;

    Region_245040 *r = GetRegion();
    Query_245040 q;
    q.keyLo = newKey->lo;
    q.keyHi = newKey->hi;
    q.boundsLo = r->boundsLo;
    q.boundsHi = r->boundsHi;
    if (FUN_00244be0(DAT_004cc08c, &q))
        return false;

    Index *idx = DAT_004cc08c;
    FUN_00244b20(idx, this);
    key.lo = newKey->lo;
    key.hi = newKey->hi;
    FUN_002448b0(idx, this, &q);
    return true;
}
