// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 14/14)
// FUN_0027b670 @ 0x0027b670
struct Record_27b670 {
    int vptr;
    int pad4;
    unsigned int keyLo;     // 0x8
    unsigned int keyHi;     // 0xc
    int pad10[2];
};

extern Record_27b670 DAT_004ce400;         // default record
extern unsigned int DAT_004ce408;   // its key
extern unsigned int DAT_004ce40c;

class RecordTable_27b670 {
public:
    char pad0[0x34];
    Record_27b670 *begin;          // 0x34
    Record_27b670 *end;            // 0x38

    Record_27b670 *FUN_0027b670(unsigned int keyLo, unsigned int keyHi);
};

Record_27b670 *RecordTable_27b670::FUN_0027b670(unsigned int keyLo, unsigned int keyHi)
{
    if ((keyLo | keyHi) == 0)
        return &DAT_004ce400;
    if (keyLo == DAT_004ce408 && keyHi == DAT_004ce40c)
        return &DAT_004ce400;

    Record_27b670 *first = begin;
    for (unsigned int i = 0; i < (unsigned int)(end - begin); i++) {
        if (first[i].keyLo == keyLo && first[i].keyHi == keyHi)
            return &first[i];
    }
    return 0;
}
