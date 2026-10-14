// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001f1600 @ 0x001f1600
class Mgr {
public:
    void FUN_001ef260(void *p);
};

class Job {
public:
    void *FUN_001f0230(int a, int b, int c, int d, int e, int f);
};

extern Mgr *DAT_004e3710;
void *__cdecl FUN_0008d710(int size, int tag);

void __stdcall FUN_001f1600(int a, int b, int c, int d, int e, int f)
{
    if (a == 0 || b == 0)
        return;
    Mgr *m = DAT_004e3710;
    if (m == 0)
        return;
    Job *j = (Job *)FUN_0008d710(0x28, 6);
    if (j != 0) {
        m->FUN_001ef260(j->FUN_001f0230(a, b, c, d, e, f));
    } else {
        m->FUN_001ef260(0);
    }
}
