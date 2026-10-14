// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 4/4)
// FUN_001f1270 @ 0x001f1270
extern char DAT_0042476c[];

void *__cdecl FUN_00263ed0(int size, int tag);
void *__cdecl FUN_0008d710(int size, int tag);

struct SoundBank {
    int vptr;
    int f04;
    char pad08[0x198 - 8];
    int f198;
    char pad19c[0x4bc - 0x19c];
    int f4bc;
    char pad4c0[0x510 - 0x4c0];
    int f510, f514, f518, f51c;
    char f520;
    char pad521[3];
};

struct SoundEngine {
    SoundEngine *FUN_001f4ba0(SoundBank *bank);
};

class SoundResourceManager;
extern SoundResourceManager *DAT_004e370c;

class SoundResourceManager {
public:
    SoundEngine *engine;
    SoundBank *bank;
    int f08;
    int f0c;
    SoundResourceManager *FUN_001f1270();
};

SoundResourceManager *SoundResourceManager::FUN_001f1270()
{
    SoundBank *b = (SoundBank *)FUN_00263ed0(0x524, 6);
    if (b) {
        b->f04 = 0;
        b->vptr = (int)DAT_0042476c;
        b->f198 = 0;
        b->f4bc = 0;
        b->f510 = 0;
        b->f514 = 0;
        b->f518 = 0;
        b->f51c = 0;
        b->f520 = 0;
    }
    bank = b;
    SoundEngine *e = (SoundEngine *)FUN_0008d710(0x340, 6);
    if (e)
        engine = e->FUN_001f4ba0(bank);
    else
        engine = 0;
    f08 = 0;
    f0c = 0;
    DAT_004e370c = this;
    return this;
}
