// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 12/12)
// FUN_000843c0 @ 0x000843c0
struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022ba70(float angle);
};

struct Vec3 {
    float x, y, z;
    void FUN_0022d260(Matrix* m);
};

struct NameHolder {
    char pad[8];
    void FUN_0027af00();
    void FUN_0027af50();
};

class Mover;

// The argument block: after the inputs are consumed, its slots are reused for the rotation
// sign and the name holder.
union Args {
    struct {
        float dirX;
        float unused;
        float dirZ;
        float dt;
    } in;
    int sign;
    NameHolder name;
};

struct Registry {
    bool FUN_001dd930(void* key, NameHolder* name);
};

struct Controller {
    void FUN_001ebe10(Mover* who, NameHolder* name, const char* effect);
};

struct World {
    char pad00[0xc];
    Registry* registry;         // 0x0c
    char pad10[0x34 - 0x10];
    Controller* controller;     // 0x34
};

extern World* DAT_004dd700;

class Mover {
public:
    bool FUN_000843c0(Args args);

    char pad00[0x10];
    int state;                  // 0x10
    char pad14[4];
    float rate;                 // 0x18
    char pad1c[0x34 - 0x1c];
    void* key;                  // 0x34
    char pad38[0x60 - 0x38];
    Vec3 pos;                   // 0x60
    Vec3 axis;                  // 0x6c
    char pad78[0x84 - 0x78];
    Vec3 heading;               // 0x84
    Vec3 origin;                // 0x90
    Vec3 from;                  // 0x9c
    Vec3 to;                    // 0xa8
    float fb4;                  // angle
    float fb8;
    float fbc;
    float fc0;
};

bool Mover::FUN_000843c0(Args args)
{
    Vec3 d;
    double x;

    union { float f; unsigned int u; } a;
    a.f = fb4 - 3.14159274f;
    a.u &= 0x7fffffff;
    if (a.f <= 1e-5f) {
        x = fb4;
        d.x = to.x - from.x;
        d.z = to.z - from.z;
    } else {
        x = 3.14159274f - fb4;
        d.x = args.in.dirX;
        d.z = args.in.dirZ;
    }

    float n = args.in.dt * rate + fbc;
    double y = x * fb8;
    if (n >= y)
        return false;

    args.sign = 1;
    float r = (float)(n / y);
    float s = (float)(r * x);
    if ((double)d.x * heading.z - (double)d.z * heading.x < 0.0)
        args.sign = -1;

    Matrix m;
    m.FUN_0022b980();
    m.FUN_0022ba70((float)args.sign * s);

    axis = heading;
    axis.FUN_0022d260(&m);

    d.x = from.x - origin.x;
    d.y = from.y - origin.y;
    d.z = from.z - origin.z;
    d.FUN_0022d260(&m);

    pos.x = d.x + origin.x;
    pos.y = d.y + origin.y;
    pos.z = d.z + origin.z;
    int st = state;
    fbc = n;
    if (st == 0xf && r >= fc0) {
        state = 0x10;
        heading = axis;
        fbc = 0.0f;
        Registry* registry = DAT_004dd700->registry;
        Controller* controller = DAT_004dd700->controller;
        args.name.FUN_0027af00();
        if (registry->FUN_001dd930(key, &args.name))
            controller->FUN_001ebe10(this, &args.name, "skid");
        args.name.FUN_0027af50();
    }
    return true;
}
