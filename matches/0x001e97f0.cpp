extern "C" char DAT_00423f38[];
extern void* __cdecl FUN_0008d710(unsigned int, unsigned int);
struct CSoundSequence {
    unsigned int vt;
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int f;
    unsigned int g;
    unsigned int h;
    unsigned char pad[4];
    unsigned char j;
    unsigned char k;
    unsigned char pad2[0x102];
    unsigned int z;
};
class Owner_1e97f0 {
  public:
    char pad0[8];
    CSoundSequence* slots[100];
    int count;
    CSoundSequence* Add();
};
CSoundSequence* Owner_1e97f0::Add() {
    if (count >= 100)
        return 0;
    CSoundSequence* r0 = (CSoundSequence*)FUN_0008d710(0x130, 6);
    CSoundSequence* p;
    if (r0) {
        r0->vt = ((int)DAT_00423f38);
        r0->a = 0;
        r0->d = 0;
        r0->e = 0;
        r0->f = 0;
        r0->g = 0;
        r0->h = 0;
        r0->j = 0;
        r0->k = 0;
        r0->z = 0;
        r0->b = 0;
        p = r0;
    } else
        p = 0;
    slots[count] = p;
    CSoundSequence* r = slots[count];
    ++count;
    return r;
}