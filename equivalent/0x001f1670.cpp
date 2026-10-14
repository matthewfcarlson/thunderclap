// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001f1670 @ 0x001f1670
class Mgr {
public:
    void FUN_001ef260(void *p);
};

class Job {
public:
    void *FUN_001f03a0(int a, int b, int c, int d, int e);
};

extern Mgr *DAT_004e3710;
void *__cdecl FUN_0008d710(int size, int tag);

void __stdcall FUN_001f1670(int a, int b, int c, int d, int e)
{
    if (a == 0 || b == 0)
        return;
    Mgr *m = DAT_004e3710;
    if (m == 0)
        return;
    Job *j = (Job *)FUN_0008d710(0x28, 6);
    if (j != 0) {
        m->FUN_001ef260(j->FUN_001f03a0(a, b, c, d, e));
    } else {
        m->FUN_001ef260(0);
    }
}
