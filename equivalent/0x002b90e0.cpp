// STATUS: equivalent (tools/equiv.py level 3: 12000 inputs, branch coverage 4/4)
// FUN_002b90e0 @ 0x002b90e0
struct Matrix;

struct V3_2b90e0 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_0022d210(Matrix *m);
};

struct Node {
    char pad0[0x30];
    V3_2b90e0 pos;
};

struct Quad_2b90e0 {
    V3_2b90e0 corner[4];
};

class Billboard_2b90e0 {
public:
    char pad0[0x80];
    float halfWidth;
    float halfHeight;
    float pull;
    unsigned char fixedSize;
    void FUN_002b90e0(Quad_2b90e0 *out, Node *from, Matrix *m, Node *target, float size);
};

void Billboard_2b90e0::FUN_002b90e0(Quad_2b90e0 *out, Node *from, Matrix *m, Node *target, float size)
{
    V3_2b90e0 goal = target->pos;
    V3_2b90e0 p = from->pos;
    if (pull != 0.0f) {
        V3_2b90e0 d;
        d.x = goal.x - p.x;
        d.y = goal.y - p.y;
        d.z = goal.z - p.z;
        d.FUN_0022d110();
        d.x = d.x * pull;
        volatile float dy = d.y * pull;
        volatile float dz = d.z * pull;
        p.x = d.x + p.x;
        p.y = dy + p.y;
        p.z = dz + p.z;
    }
    p.FUN_0022d210(m);
    double w = size * halfWidth;
    double h = size * halfHeight;
    if (!fixedSize) {
        w = w * p.z;
        h = h * p.z;
    }
    out->corner[0].x = p.x - w;
    out->corner[0].y = p.y - h;
    out->corner[0].z = p.z;
    out->corner[1].x = p.x + w;
    out->corner[1].y = p.y - h;
    out->corner[1].z = p.z;
    out->corner[2].x = p.x + w;
    out->corner[2].y = p.y + h;
    out->corner[2].z = p.z;
    out->corner[3].x = p.x - w;
    out->corner[3].y = p.y + h;
    out->corner[3].z = p.z;
}
