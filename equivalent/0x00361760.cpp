// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00361760 @ 0x00361760
struct Slot_361760 {
    void* p;
    int a;
    int b;
};

extern void* DAT_004cd698;
extern void* DAT_004cd69c;
extern void* DAT_004cd6a0;
extern void* DAT_004cd6a4;
extern Slot_361760 DAT_004cd6a8[20];

void FUN_00361760()
{
    void* first = DAT_004cd698;
    void* fourth = DAT_004cd6a4;
    for (int i = 0; i < 8; i++) {
        DAT_004cd6a8[i].p = first;
    }
    void* second = DAT_004cd69c;
    for (int i = 8; i < 16; i++) {
        DAT_004cd6a8[i].p = second;
    }
    void* third = DAT_004cd6a0;
    DAT_004cd6a8[16].p = third;
    DAT_004cd6a8[17].p = fourth;
    DAT_004cd6a8[18].p = third;
    DAT_004cd6a8[19].p = fourth;
}
