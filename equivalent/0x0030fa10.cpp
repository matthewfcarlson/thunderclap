// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 30/30)
// FUN_0030fa10 @ 0x0030fa10
struct Mat;

struct Elem {
    int index;
    Elem *parent;
    char pad8[4];
    int depth;
    char pad10[0xc0 - 0x10];
    void FUN_0030ebd0();
    void FUN_0030edc0(void *m);
    void FUN_0030ec20(int depth);
    void FUN_0030ec70(Elem *child);
};

class Skeleton {
public:
    virtual void AddRef();
    virtual void Release();
    char pad4[0xc];
    unsigned int count;
    char pad14[0x28 - 0x14];
    unsigned short *parents;
};

struct Source {
    char pad0[8];
    Skeleton *skeleton;
    char pad0c[8];
    char *data;
    void FUN_00284820(int flag);
};

void *__cdecl FUN_0008d6d0(unsigned int size);
void __cdecl FUN_0008d340(void *p);
void __fastcall FUN_0030eba0(void *self);
void __stdcall FUN_00011520(void *base, unsigned int size, int count, void *ctor);

struct Tmp {
    char data[0x54];
    void *FUN_0030f070(const char *src);
};

struct Frame {
    int off;
    Tmp tmp;
};

class Pose {
public:
    char pad0[8];
    Skeleton *skeleton;
    Elem *elems;

    void FUN_0030fa10(Source *src);
};

void Pose::FUN_0030fa10(Source *src)
{
    Frame f;
    src->FUN_00284820(0);
    Skeleton *sk = src->skeleton;
    if (sk == skeleton) {
        unsigned int n = 0;
        if (skeleton)
            n = skeleton->count;
        if (n == 0)
            return;
        for (unsigned int i = 0; i < n; i++)
            elems[i].FUN_0030edc0(f.tmp.FUN_0030f070(src->data + i * 0x40));
        return;
    }
    if (sk)
        sk->AddRef();
    if (skeleton)
        skeleton->Release();
    skeleton = sk;
    if (elems) {
        Elem *base = elems;
        int *cookie = (int *)base - 1;
        int n = *cookie;
        Elem *p = base + n;
        for (int i = n - 1; i >= 0; i--) {
            p--;
            p->FUN_0030ebd0();
        }
        FUN_0008d340(cookie);
    }
    int count = skeleton->count;
    Elem *arr = 0;
    if (count <= 0) {
        elems = arr;
        return;
    }
    int *mem = (int *)FUN_0008d6d0(count * 0xc0 + 4);
    if (mem) {
        *mem = count;
        arr = (Elem *)(mem + 1);
        FUN_00011520(arr, 0xc0, count, (void *)FUN_0030eba0);
    }
    elems = arr;
    elems[0].FUN_0030edc0(f.tmp.FUN_0030f070(src->data));
    f.off = 0x40;
    for (int i = 1; i < count; i++) {
        elems[i].index = i;
        Elem *parent = &elems[skeleton->parents[i]];
        elems[i].parent = parent;
        parent->FUN_0030ec20(parent->depth + 1);
        elems[i].FUN_0030edc0(f.tmp.FUN_0030f070(src->data + f.off));
        f.off += 0x40;
    }
    for (int i = 1; i < count; i++)
        elems[skeleton->parents[i]].FUN_0030ec70(&elems[i]);
}
