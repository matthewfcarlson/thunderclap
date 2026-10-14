// STATUS: equivalent (tools/equiv.py level 3: 26 inputs, branch coverage 24/24)
// FUN_00299da0 @ 0x00299da0
void* FUN_0008d6d0(unsigned int size);

class Ref_299da0 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual Ref_299da0* Clone();
};

struct PrimEntry {
    char flag;
    int value;
    Ref_299da0* ref;
};

struct PrimEntryList {
    PrimEntry* begin;
    PrimEntry* end;
    int pad;
    void FUN_00299540(int count, PrimEntryList* const* fill);
};

namespace pure3d {
namespace CompositeDrawable {

class ActivePrimitiveList {
public:
    virtual void v0();
    int field04;
    char* bufA;
    char* bufAEnd;
    int pad10;
    char* bufB;
    char* bufBEnd;
    int pad1c;
    char flag;
    char* data24;
    char* data24End;
    int pad2c;
    char* data30;
    char* data30End;
    int pad38;
    PrimEntryList entries;

    ActivePrimitiveList(const ActivePrimitiveList& src);
};

ActivePrimitiveList::ActivePrimitiveList(const ActivePrimitiveList& src)
{
    field04 = 0;

    char* p = (char*)FUN_0008d6d0(0x20);
    bufA = p;
    if (p) {
        bufAEnd = p + 0x20;
    } else {
        bufA = 0;
        bufAEnd = 0;
    }

    p = (char*)FUN_0008d6d0(0x20);
    bufB = p;
    if (p) {
        bufBEnd = p + 0x20;
    } else {
        bufB = 0;
        bufBEnd = 0;
    }

    flag = src.flag;

    int n = src.data24End - src.data24;
    if (n != 0) {
        p = (char*)FUN_0008d6d0(n);
        data24 = p;
        if (p) {
            data24End = p + n;
        } else {
            data24 = 0;
            data24End = 0;
        }
    } else {
        data24 = 0;
        data24End = 0;
    }

    n = src.data30End - src.data30;
    if (n != 0) {
        p = (char*)FUN_0008d6d0(n);
        data30 = p;
        if (p) {
            data30End = p + n;
        } else {
            data30 = 0;
            data30End = 0;
        }
    } else {
        data30 = 0;
        data30End = 0;
    }

    const ActivePrimitiveList* srcRef = &src;
    entries.FUN_00299540(src.entries.end - src.entries.begin, (PrimEntryList* const*)&srcRef);

    unsigned int count = src.entries.end - src.entries.begin;
    for (unsigned int i = 0; i < count; i++) {
        data24[i] = src.data24[i];
        data30[i] = src.data30[i];
        entries.begin[i].value = src.entries.begin[i].value;
        entries.begin[i].flag = src.entries.begin[i].flag;
        Ref_299da0* r = src.entries.begin[i].ref;
        if (r) {
            PrimEntry* d = &entries.begin[i];
            Ref_299da0* c = r->Clone();
            if (c)
                c->AddRef();
            if (d->ref)
                d->ref->Release();
            d->ref = c;
        }
    }

    for (unsigned int i = 0; i < 0x20; i++) {
        bufA[i] = src.bufA[i];
        bufB[i] = src.bufB[i];
    }
}

}
}
