// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 20/20)
// FUN_00288080 @ 0x00288080
struct Vec3 {
    float x, y, z;
};

struct Pair {
    unsigned int a;
    unsigned int b;
};

struct NameKey {
    char pad00[8];
    unsigned int lo;          // 0x08
    unsigned int hi;          // 0x0c
};

struct SkeletonData {
    NameKey *FUN_0027b670(unsigned int lo, unsigned int hi);
};

class Skeleton {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[4];
    SkeletonData *data;       // 0x08
    unsigned int jointCount;  // 0x0c
};

void FUN_0008d340(void *p);
void *FUN_0008d6d0(unsigned int size);
Pair FUN_002672f0(const char *name, int a, int b);

class SkeletonUser {
public:
    char pad000[0x110];
    Skeleton *skeleton;       // 0x110
    char pad114[4];
    unsigned int capacity;    // 0x118
    Vec3 *vecs0;              // 0x11c
    Vec3 *vecs1;              // 0x120
    Vec3 *vecs2;              // 0x124
    Vec3 *vecs3;              // 0x128
    Vec3 *vecs4;              // 0x12c
    unsigned char dirty;      // 0x130
    char pad131[3];
    float *vals0;             // 0x134
    float *vals1;             // 0x138
    float *vals2;             // 0x13c
    float *vals3;             // 0x140
    float *vals4;             // 0x144
    char pad148[4];
    NameKey *rootKey;         // 0x14c

    void FUN_00288080(Skeleton *sk);
};

void SkeletonUser::FUN_00288080(Skeleton *sk)
{
    if (sk == skeleton)
        return;
    if (skeleton == 0 || skeleton->data != sk->data)
        dirty = 1;
    if (sk)
        sk->AddRef();
    if (skeleton)
        skeleton->Release();
    skeleton = sk;

    if (capacity < sk->jointCount) {
        if (vecs0)
            FUN_0008d340(vecs0);
        capacity = skeleton->jointCount;
        vecs0 = (Vec3 *)FUN_0008d6d0(capacity * 0x3c);
        if (vals0)
            FUN_0008d340(vals0);
        vals0 = (float *)FUN_0008d6d0(capacity * 0x14);
        vecs1 = vecs0 + capacity;
        vals1 = vals0 + capacity;
        vecs2 = vecs1 + capacity;
        vals2 = vals1 + capacity;
        vecs3 = vecs2 + capacity;
        vals3 = vals2 + capacity;
        vecs4 = vecs3 + capacity;
        vals4 = vals3 + capacity;
    }

    if (rootKey)
        rootKey = skeleton->data->FUN_0027b670(rootKey->lo, rootKey->hi);
    if (rootKey == 0) {
        SkeletonData *d = skeleton->data;
        Pair p = FUN_002672f0("root", 0, 0);
        rootKey = d->FUN_0027b670(p.a, p.b);
    }
}
