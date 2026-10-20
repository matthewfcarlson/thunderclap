// STATUS: equivalent (tools/equiv.py level 3: 118 inputs, branch coverage 41/44, incomplete)
// FUN_002998d0 @ 0x002998d0
void *__cdecl FUN_0008d690(unsigned int size);

class RefCounted_2998d0 {
public:
    virtual void addRef();
    virtual void release();
};

class Item_2998d0 {
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
    virtual void v14();
    virtual void v15();
    virtual unsigned count();
    virtual void v17();
    virtual RefCounted_2998d0 *get(unsigned index);
};

struct Entry_2998d0 {
    int a;
    int b;
    Item_2998d0 *item;
};

struct Source_2998d0 {
    char pad[0x3c];
    Entry_2998d0 *begin;
    Entry_2998d0 *end;
};

class Bundle {
public:
    virtual void addRef();
    virtual void release();
    char pad04[0x24 - 4];
    RefCounted_2998d0 **slots;      // 0x24
    Bundle *FUN_00299680(unsigned count);
    void FUN_00298a60();
};

class Owner_2998d0 {
public:
    char pad00[0x44];
    Source_2998d0 *source;          // 0x44
    Bundle *bundle;          // 0x48
    RefCounted_2998d0 *extraA;      // 0x4c
    RefCounted_2998d0 *extraB;      // 0x50

    void FUN_002998d0(unsigned char release);
};

void Owner_2998d0::FUN_002998d0(unsigned char release)
{
    if (bundle != 0) {
        if (release == 1) {
            if (bundle != 0) {
                bundle->release();
                bundle = 0;
            }
        }
        if (bundle != 0)
            return;
    }

    int n = (unsigned char)(source->end - source->begin);
    unsigned total = 0;
    int i;
    for (i = 0; i < n; i++) {
        Item_2998d0 *item = source->begin[(unsigned char)i].item;
        if (item != 0)
            total += item->count();
    }
    if (extraA != 0)
        total++;
    if (extraB != 0)
        total++;

    Bundle *b = (Bundle *)FUN_0008d690(0x30);
    if (b != 0)
        b = b->FUN_00299680(total);
    bundle = b;
    b->addRef();

    for (i = 0; i < n; i++) {
        Item_2998d0 *item = source->begin[(unsigned char)i].item;
        unsigned j = 0;
        if (item->count() != 0) {
            do {
                *(RefCounted_2998d0 **)&bundle->slots[total - 1] = 0;
                RefCounted_2998d0 **slot = (RefCounted_2998d0 **)&bundle->slots[total - 1];
                RefCounted_2998d0 *r = item->get(j);
                if (r != 0)
                    r->addRef();
                RefCounted_2998d0 *old = *slot;
                if (old != 0)
                    old->release();
                *slot = r;
                total--;
                j++;
            } while (j < item->count());
        }
    }

    if (extraB != 0) {
        *(RefCounted_2998d0 **)&bundle->slots[total - 1] = 0;
        RefCounted_2998d0 *r = extraB;
        RefCounted_2998d0 **slot = (RefCounted_2998d0 **)&bundle->slots[total - 1];
        if (r != 0)
            r->addRef();
        RefCounted_2998d0 *old = *slot;
        if (old != 0)
            old->release();
        *slot = r;
        total--;
    }
    if (extraA != 0) {
        *(RefCounted_2998d0 **)&bundle->slots[total - 1] = 0;
        RefCounted_2998d0 *r = extraA;
        RefCounted_2998d0 **slot = (RefCounted_2998d0 **)&bundle->slots[total - 1];
        if (r != 0)
            r->addRef();
        RefCounted_2998d0 *old = *slot;
        if (old != 0)
            old->release();
        *slot = r;
    }
    bundle->FUN_00298a60();
}
