// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002ece90 @ 0x002ece90
extern "C" double sqrt(double);
extern float DAT_004d287c;

struct Listener_2ece90 {
    void FUN_002f7a60();
};
struct SystemA {
    char pad00[0x68];
    Listener_2ece90 listener;
};
struct SystemB {
    char pad00[0xb0];
    Listener_2ece90 listener;
};
extern SystemA* DAT_0055547c;
extern SystemB* DAT_00554c14;

class ScaledVec {
public:
    char pad00[0x10];
    float x, y, z;
    float sx, sy, sz;
    float length;
    void Set(float vx, float vy, float vz);
};

void ScaledVec::Set(float vx, float vy, float vz)
{
    x = vx;
    y = vy;
    z = vz;
    sx = DAT_004d287c * x;
    sy = DAT_004d287c * y;
    sz = DAT_004d287c * z;
    length = (float)sqrt(sx * sx + sy * sy + sz * sz);
    if (DAT_0055547c) {
        DAT_0055547c->listener.FUN_002f7a60();
    } else if (DAT_00554c14) {
        DAT_00554c14->listener.FUN_002f7a60();
    }
}
