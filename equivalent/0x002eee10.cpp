// STATUS: equivalent (tools/equiv.py level 3: 29 inputs, branch coverage 24/24)
// FUN_002eee10 @ 0x002eee10
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);

extern unsigned int DAT_004d293c;
extern unsigned int DAT_004d2940;
extern unsigned int DAT_004d2944;
extern unsigned int DAT_004d2948;

struct RawVec {
    char *first;
    char *last;
    char *end;
};

class Pool {
public:
    RawVec ids;              // 0x00: DAT_004d293c * 4 bytes
    unsigned int *used;      // 0x0c unused
    unsigned int *bits;      // 0x10: bit set of DAT_004d293c bits
    int *slots;              // 0x14
    int slotCount[3];        // 0x18
    char *links;             // 0x24
    int linkCount;           // 0x28
    RawVec records;          // 0x2c: DAT_004d2944 * 0x44 bytes
    char pad38[4];
    RawVec indices;          // 0x3c: DAT_004d2940 * 4 bytes
    char pad48[4];
    RawVec edges;            // 0x4c: DAT_004d2948 * 20 bytes
    char pad58[4];
    RawVec flags;            // 0x5c: DAT_004d293c * 4 bytes
    Pool *FUN_002eee10();
};

Pool *Pool::FUN_002eee10()
{
    ids.first = 0; ids.last = 0; ids.end = 0;
    records.first = 0; records.last = 0; records.end = 0;
    indices.first = 0; indices.last = 0; indices.end = 0;
    edges.first = 0; edges.last = 0; edges.end = 0;
    flags.first = 0; flags.last = 0; flags.end = 0;

    if (DAT_004d293c != 0) {
        unsigned int bytes = DAT_004d293c * 4;
        char *p = (char *)FUN_0008d6d0(bytes);
        ids.first = p;
        if (p != 0) {
            ids.last = p;
            ids.end = p + bytes;
        } else {
            ids.last = 0;
            ids.end = 0;
        }
    } else {
        ids.first = 0;
        ids.last = 0;
        ids.end = 0;
    }

    if (DAT_004d2948 != 0) {
        unsigned int bytes = DAT_004d2948 * 20;
        char *p = (char *)FUN_0008d6d0(bytes);
        edges.first = p;
        if (p != 0) {
            edges.last = p;
            edges.end = p + bytes;
        } else {
            edges.last = 0;
            edges.end = 0;
        }
    } else {
        edges.first = 0;
        edges.last = 0;
        edges.end = 0;
    }

    if (DAT_004d293c != 0) {
        unsigned int bytes = DAT_004d293c * 4;
        char *p = (char *)FUN_0008d6d0(bytes);
        flags.first = p;
        if (p != 0) {
            flags.last = p;
            flags.end = p + bytes;
        } else {
            flags.last = 0;
            flags.end = 0;
        }
    } else {
        flags.first = 0;
        flags.last = 0;
        flags.end = 0;
    }

    slots = (int *)FUN_0008d6d0(DAT_004d293c * 4);
    slotCount[0] = 0;
    slotCount[1] = 0;
    slotCount[2] = 0;
    links = (char *)FUN_0008d6d0(DAT_004d293c * 20);
    linkCount = 0;

    unsigned int nbits = DAT_004d293c;
    unsigned int words = (nbits + 0x1f) >> 5;
    unsigned int *b = (unsigned int *)FUN_0008d6d0(words * 4 + 4);
    b[0] = nbits;
    for (unsigned int i = 0; i < words; i++)
        b[1 + i] = 0;
    bits = b;
    unsigned int words2 = (b[0] + 0x1f) >> 5;
    for (unsigned int i = 0; i < words2; i++)
        b[1 + i] = 0;

    if (DAT_004d2940 != 0) {
        unsigned int bytes = DAT_004d2940 * 4;
        char *p = (char *)FUN_0008d6d0(bytes);
        indices.first = p;
        if (p != 0) {
            indices.last = p;
            indices.end = p + bytes;
        } else {
            indices.last = 0;
            indices.end = 0;
        }
    } else {
        indices.first = 0;
        indices.last = 0;
        indices.end = 0;
    }

    if (DAT_004d2944 != 0) {
        unsigned int bytes = DAT_004d2944 * 0x44;
        char *p = (char *)FUN_0008d6d0(bytes);
        records.first = p;
        if (p != 0) {
            records.end = p + bytes;
            records.last = p;
        } else {
            records.last = 0;
            records.end = 0;
        }
    } else {
        records.first = 0;
        records.last = 0;
        records.end = 0;
    }
    return this;
}
