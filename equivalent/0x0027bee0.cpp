// STATUS: equivalent (tools/equiv.py level 3: 9 inputs, branch coverage 15/16, incomplete)
// FUN_0027bee0 @ 0x0027bee0
#include "compat/ptr.h"
extern "C" void *__cdecl FUN_0008d6d0(hulk_uintptr size);
extern "C" void *memset(void *dst, int c, unsigned int n);
void FUN_0027b8f0();

struct Name_27bee0 {
    char data[8];
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void e0();
    char pad4[4];
    Name_27bee0 name;
    void FUN_0027b070();
    Entity() throw() { FUN_0027b070(); }
};

class Skeleton : public Entity {
public:
    class Partition {
    public:
        virtual void p0();
        char pad4[0xc];
        unsigned int *bits;
        char pad14[4];
        Partition() throw() { bits = 0; }
    };

    class Limb {
    public:
        virtual void l0();
        char pad4[0xc];
        unsigned int *bits;
        char pad14[0x28 - 0x14];
        Limb() throw() { bits = 0; }
    };

    struct PartitionArray {
        Partition *begin;
        Partition *end;
        char *cap;
        void FUN_0027bd70(unsigned int n, Partition *proto);
    };

    struct LimbArray {
        Limb *begin;
        Limb *end;
        char *cap;
        void FUN_0027be00(unsigned int n, Limb *proto);
    };

    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();

    int count;
    char *weights;
    char *positions;
    char *rotations;
    char *scales;
    char *flags;
    char *marks;
    int field2c;
    char *storage;
    PartitionArray partitions;
    char pad40[4];
    LimbArray limbs;

    Skeleton(int n, unsigned int numPartitions, unsigned int numLimbs) throw();
};
}

static unsigned int *NewBitSet(int bitCount)
{
    unsigned int words = ((unsigned int)bitCount + 0x1f) >> 5;
    unsigned int *bits = (unsigned int *)FUN_0008d6d0(words * 4 + 4);
    bits[0] = bitCount;
    if (words != 0)
        memset(bits + 1, 0, words * 4);
    return bits;
}

pure3d::Skeleton::Skeleton(int n, unsigned int numPartitions, unsigned int numLimbs) throw()
{
    partitions.begin = 0;
    partitions.end = 0;
    partitions.cap = 0;
    limbs.begin = 0;
    limbs.end = 0;
    count = n;

    unsigned int reserve = numPartitions + 5;
    if (reserve != 0) {
        unsigned int bytes = reserve * sizeof(Partition);
        Partition *mem = (Partition *)FUN_0008d6d0(bytes);
        partitions.begin = mem;
        if (mem != 0) {
            partitions.cap = (char *)mem + bytes;
            partitions.end = mem;
        } else {
            partitions.end = 0;
            partitions.cap = 0;
        }
    }

    {
        Partition partitionProto;
        partitions.FUN_0027bd70(numPartitions, &partitionProto);
    }
    {
        Limb limbProto;
        limbs.FUN_0027be00(numLimbs, &limbProto);
    }

    field2c = 0;
    char *mem = (char *)FUN_0008d6d0(count * 0xda);
    storage = mem;
    positions = mem;
    rotations = mem + count * 64;
    scales = rotations + count * 64;
    weights = scales + count * 64;
    flags = weights + count * 16;
    marks = flags + count * 8;

    for (unsigned int i = 0; i < numPartitions; i++)
        partitions.begin[i].bits = NewBitSet(count);
    for (unsigned int i = 0; i < numLimbs; i++)
        limbs.begin[i].bits = NewBitSet(count);
    FUN_0027b8f0();
}
