// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00088600 @ 0x00088600
class CSimDb {
public:
    virtual void vfn0();
    CSimDb();
    int f[21];
    char pad[0x9d - 0x58];
    char flag;
};

CSimDb *DAT_004dd700;

CSimDb::CSimDb()
{
    for (int i = 0; i < 21; i++)
        f[i] = 0;
    DAT_004dd700 = this;
    flag = 0;
}
