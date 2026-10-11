// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 10/10)
// FUN_000a0940 @ 0x000a0940
extern "C" int _isnan(double);

struct Vec3 {
    union { float x; int xi; };
    union { float y; int yi; };
    union { float z; int zi; };
};

Vec3* FUN_0009fbd0(Vec3* out, Vec3* a, Vec3* b, Vec3* c, float tau, float dt);

struct Mover {
    char pad000[0x170];
    Vec3 prev;
    Vec3 f17c;
    Vec3 saved;
    Vec3 pos;
    char pad1a0[0x1c4 - 0x1a0];
    float off1c4;
    float off1c8;
    union { float off1cc; int off1cci; };
    char pad1d0[0x234 - 0x1d0];
    float tau;
    char pad238[0x254 - 0x238];
    Vec3 v254;
    Vec3 v260;
    char pad26c[0x346 - 0x26c];
    char clamped;
    char pad347[0x444 - 0x347];
    float base444;
    char pad448[0x498 - 0x448];
    union { float hi; int hii; };
    union { float lo; int loi; };
    void FUN_000a0940(float dt);
};

void Mover::FUN_000a0940(float dt)
{
    Vec3 out;
    if (_isnan(pos.x) || _isnan(pos.y) || _isnan(pos.z)) {
        pos.x = base444 + off1c4;
        pos.y = off1c8;
        pos.zi = off1cci;
        out.zi = off1cci;
    }
    prev.xi = pos.xi;
    prev.yi = pos.yi;
    prev.zi = pos.zi;
    if (pos.y > hi) {
        pos.yi = hii;
        clamped = 1;
    } else if (pos.y < lo) {
        pos.yi = loi;
        clamped = 1;
    }
    f17c.xi = pos.xi;
    f17c.yi = pos.yi;
    f17c.zi = pos.zi;
    Vec3* r = FUN_0009fbd0(&out, &v260, &v254, &f17c, tau, dt);
    pos.xi = r->xi;
    pos.yi = r->yi;
    pos.zi = r->zi;
    saved.xi = pos.xi;
    saved.yi = pos.yi;
    saved.zi = pos.zi;
}
