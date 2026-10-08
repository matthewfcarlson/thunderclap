class CGrappleTimerCondition {
public:
    void* vfptr;        // +0x00
    int base0;          // +0x04
    int base1;          // +0x08
    int type;           // +0x0c
    int unk10;          // +0x10
    unsigned char flag; // +0x14
    int unk18;          // +0x18

    void Ctor(int flags);
};

extern char CGrappleTimerCondition_vftable[];
extern void* __cdecl AllocMem(unsigned int size);

void* vfunc_5()
{
    CGrappleTimerCondition* p = (CGrappleTimerCondition*)AllocMem(0x1c);
    if (p != 0) {
        p->Ctor(0);
        p->vfptr = CGrappleTimerCondition_vftable;
        p->type = 5;
        p->unk10 = 0;
        p->flag = 0;
        p->unk18 = 0;
        return p;
    }
    return 0;
}