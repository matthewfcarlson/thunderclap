// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001ef2a0 @ 0x001ef2a0
struct Rng;
Rng* FUN_000964d0();

class Spawner {
public:
    char pad0[0x14];
    int count;          // 0x14
    void FUN_001ef2a0(int a, int b);
};

class Pool {
public:
    class Emitter* FUN_001eefc0();
};

class Emitter {
public:
    void FUN_001eed50(Spawner* owner, int a, int b, int flags);
};

extern Pool* DAT_004e370c;
extern int DAT_004e3718;
extern int DAT_004e3740;
extern int DAT_004e3744;
extern Rng* DAT_004e3758;       // function-local static
extern unsigned int DAT_004e375c;   // its init guard

void Spawner::FUN_001ef2a0(int a, int b)
{
    DAT_004e3740++;
    if (count < 1)
        return;
    if ((DAT_004e375c & 1) == 0) {
        DAT_004e375c |= 1;
        DAT_004e3758 = FUN_000964d0();
    }
    Emitter* e = DAT_004e370c->FUN_001eefc0();
    if (e == 0) {
        DAT_004e3718++;
        return;
    }
    DAT_004e3744++;
    e->FUN_001eed50(this, a, b, 0);
}
