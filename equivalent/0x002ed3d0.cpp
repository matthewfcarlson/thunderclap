// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 37/40, incomplete)
// FUN_002ed3d0 @ 0x002ed3d0
struct Vec3 {
    float x, y, z;
};

struct Shape {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual const Vec3 *v4();
    char pad04[0x24];
    float radius;           // 0x28
    char pad2c[4];
    float halfZ;            // 0x30
};

struct Body {
    char pad0[0x20];
    Shape *shape;           // 0x20
    char pad24[0x58 - 0x24];
    unsigned int maskALo;   // 0x58
    unsigned int maskAHi;   // 0x5c
    unsigned int maskBLo;   // 0x60
    unsigned int maskBHi;   // 0x64
};

struct BitSet {
    int header;
    unsigned int bits[1];
};

struct Pairs {
    char pad0[0x2c];
    void FUN_00302ed0(Shape *a, Shape *b, void *extra);
};

class SweepAndPrune {
public:
    char pad0[0x10];
    BitSet *skip;           // 0x10
    Body **bodies;          // 0x14
    unsigned int count;     // 0x18
    float margin;           // 0x1c
    float zSlack;           // 0x20
    char pad24[8];
    char contact[0x70 - 0x2c];  // 0x2c
    Pairs pairs;            // 0x70
    char pad9c[4];
    int found;              // 0xa0

    void FUN_002ed3d0(unsigned int index);
};

void SweepAndPrune::FUN_002ed3d0(unsigned int index)
{
    Body *self = bodies[index];
    float keySelf = self->shape->v4()->x;
    float mrg = margin;
    unsigned int bLo = self->maskBLo;
    unsigned int bHi = self->maskBHi;
    unsigned int aLo = self->maskALo;
    unsigned int aHi = self->maskAHi;

    if (index > 0) {
        unsigned int j = index;
        unsigned int k = index - 1;
        Body *other = bodies[k];
        float otherKey = other->shape->v4()->x;
        for (;;) {
            float r = self->shape->radius;
            k = j - 1;
            float lo = keySelf - mrg;
            if (!(lo < r + otherKey))
                break;
            if (!(skip->bits[k >> 5] & (1u << (k & 31)))) {
                if (((other->maskALo & bLo) != 0 || (other->maskAHi & bHi) != 0) &&
                    ((other->maskBLo & aLo) != 0 || (other->maskBHi & aHi) != 0)) {
                    bool hit = true;
                    Shape *hs = self->shape;
                    Shape *os = other->shape;
                    float t1 = hs->v4()->z - zSlack;
                    if (os->v4()->z + os->halfZ < t1) {
                        hs = self->shape;
                        os = other->shape;
                        float t2 = hs->v4()->z + zSlack;
                        if (os->v4()->z - os->halfZ > t2)
                            hit = false;
                    }
                    if (hit) {
                        found = 0;
                        pairs.FUN_00302ed0(self->shape, other->shape, contact);
                    }
                }
            }
            j--;
            k--;
            if (j == 0)
                break;
            other = bodies[j - 1];
            otherKey = other->shape->v4()->x;
        }
    }

    if (index >= count - 1)
        return;
    Body *other = bodies[index + 1];
    float nbKey = other->shape->v4()->x;
    float r = self->shape->radius;
    if (index >= count - 1)
        return;
    float limit = mrg + keySelf;
    unsigned int j = index;
    unsigned int m = index + 1;
    for (;;) {
        if (!(nbKey - r < limit))
            break;
        if (!(skip->bits[m >> 5] & (1u << (m & 31)))) {
            if ((self->maskBLo & other->maskALo) != 0 || (self->maskBHi & other->maskAHi) != 0) {
                bool hit = true;
                Shape *hs = self->shape;
                Shape *os = other->shape;
                float t1 = hs->v4()->z - zSlack;
                if (os->v4()->z + os->halfZ < t1) {
                    hs = self->shape;
                    os = other->shape;
                    float t2 = hs->v4()->z + zSlack;
                    if (os->v4()->z - os->halfZ > t2)
                        hit = false;
                }
                if (hit) {
                    found = 0;
                    pairs.FUN_00302ed0(self->shape, other->shape, contact);
                }
            }
        }
        j++;
        m++;
        if (j < count - 1) {
            other = bodies[j + 1];
            nbKey = other->shape->v4()->x;
            r = self->shape->radius;
        }
        if (!(j < count - 1))
            break;
    }
}
