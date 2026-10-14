// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 6/6)
// pure3d::SpriteParticleEmitter::vfunc_14 @ 0x002d5a70
struct Vec3_2d5a70 {
    float x, y, z;
};

struct Particle_2d5a70 {
    Vec3_2d5a70 pos;
    unsigned int color;
    float f10;
    float f14;
    unsigned char b18;
    unsigned char b19;
    short s1a;
    float f1c;
    Vec3_2d5a70 vel;
    int f2c;
    float f30;
    int f34;
    int f38;
    short s3c;
    unsigned char b3e;
};

struct ParticlePool {
    char pad0[8];
    unsigned int size;
    Particle_2d5a70** data;
};

struct Palette_2d5a70 {
    char pad0[8];
    int count;
};

struct Rng_2d5a70 {
    float FUN_00143100();
    char FUN_002d49c0(int lo, int hi);
    char FUN_00011380(int lo, int hi);
};

extern Rng_2d5a70 DAT_00554c04;

unsigned int* FUN_002e6780(unsigned int* out, int a, unsigned int b);
unsigned int* FUN_002e6840(unsigned int* out, unsigned int v, unsigned int b);

class SpriteParticleEmitter {
public:
    char pad0[0x84];
    ParticlePool* pool;
    char pad88[0x14c - 0x88];
    int count;
    char pad150[0x160 - 0x150];
    float f160;
    float f164;
    char pad168[4];
    float f16c;
    float f170;
    char pad174[4];
    float f178;
    float f17c;
    char pad180[4];
    float f184;
    float f188;
    float f18c;
    float f190;
    char pad194[4];
    float f198;
    float f19c;
    char pad1a0[0x1b4 - 0x1a0];
    int f1b4;
    signed char c1b8;
    signed char c1b9;
    char pad1ba[2];
    Palette_2d5a70* palette;
    char pad1c0[8];
    Particle_2d5a70** begin;
    Particle_2d5a70** end;
    bool vfunc_14(Vec3_2d5a70* dir, Vec3_2d5a70* pos, int arg2);
};

bool SpriteParticleEmitter::vfunc_14(Vec3_2d5a70* dir, Vec3_2d5a70* pos, int arg2)
{
    if ((unsigned int)count >= (unsigned int)(end - begin))
        return false;

    ParticlePool* pl = pool;
    unsigned int n = pl->size;
    if (n == 0)
        return false;
    Particle_2d5a70** items = pl->data;
    n--;
    pl->size = n;
    Particle_2d5a70* p = items[n];
    items[n] = 0;
    if (p == 0)
        return false;

    p->pos = *pos;
    p->f38 = 0;

    // The original spills the range limits into its (dead) argument slots; the slot of "pos" is
    // later handed to the colour helpers as their output cell, so keep the same frame layout.
    float* lo = (float*)&dir;
    float* hi = (float*)&pos;

    float lo4 = f16c;
    *hi = f170;
    float speed = DAT_00554c04.FUN_00143100() * *hi + lo4;
    p->vel.x = speed * dir->x;
    p->vel.y = speed * dir->y;
    p->vel.z = speed * dir->z;

    *hi = f19c;
    *lo = f198;
    float a = DAT_00554c04.FUN_00143100() * *hi + *lo;
    p->s3c = (short)(int)(a * 256.0f);

    *hi = f17c;
    *lo = f178;
    float b = DAT_00554c04.FUN_00143100() * *hi + *lo;
    p->f10 = b;
    p->s1a = (short)(int)(b * 256.0f);

    *hi = f190;
    *lo = f18c;
    p->f1c = DAT_00554c04.FUN_00143100() * *hi + *lo;

    *hi = f188;
    p->f14 = DAT_00554c04.FUN_00143100() * *hi + f184;

    *hi = f164;
    *lo = f160;
    p->f30 = DAT_00554c04.FUN_00143100() * *hi + *lo;

    p->f2c = arg2;
    p->f34 = 0;

    p->b3e = DAT_00554c04.FUN_002d49c0(0, c1b8);
    p->b18 = DAT_00554c04.FUN_002d49c0(0, c1b9);

    unsigned int* tmp = (unsigned int*)&pos;
    p->color = *FUN_002e6780(tmp, f1b4, p->b3e);
    p->color = *FUN_002e6840(tmp, p->color, p->b18);

    p->b19 = DAT_00554c04.FUN_00011380(0, palette->count - 1);

    begin[count] = p;
    count++;
    return true;
}
