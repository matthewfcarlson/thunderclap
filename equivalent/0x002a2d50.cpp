// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_002a2d50 @ 0x002a2d50
// 0x002a2d50: OpaqueTraversal constructor reserving n 16-byte records and n 4-byte indices
extern char DAT_0042d78c[];
void* __cdecl FUN_0008d6d0(unsigned int size);

class OpaqueTraversal {
public:
    int vptr;
    char pad04[8];
    unsigned int flags;
    int field_10;
    char pad14[4];
    int field_18;
    char field_1c;
    char pad1d[3];
    char* recordsBegin;
    char* recordsEnd;
    char pad28[4];
    char* indicesBegin;
    char* indicesEnd;
    void FUN_002c6a80();
    OpaqueTraversal* FUN_002a2d50(unsigned int n);
};

OpaqueTraversal* OpaqueTraversal::FUN_002a2d50(unsigned int n)
{
    FUN_002c6a80();
    vptr = (int)DAT_0042d78c;
    field_18 = 0;
    field_1c = 1;
    if (n != 0) {
        unsigned int size = n * 16;
        char* mem = (char*)FUN_0008d6d0(size);
        recordsBegin = mem;
        if (mem != 0)
            recordsEnd = mem + size;
        else {
            recordsBegin = 0;
            recordsEnd = 0;
        }
    } else {
        recordsBegin = 0;
        recordsEnd = 0;
    }
    if (n != 0) {
        unsigned int size = n * 4;
        char* mem = (char*)FUN_0008d6d0(size);
        indicesBegin = mem;
        if (mem != 0)
            indicesEnd = mem + size;
        else {
            indicesBegin = 0;
            indicesEnd = 0;
        }
    } else {
        indicesBegin = 0;
        indicesEnd = 0;
    }
    flags &= 0xffffffcf;
    field_10 = 0;
    return this;
}
