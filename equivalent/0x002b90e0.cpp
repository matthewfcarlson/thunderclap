// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_002b90e0 @ 0x002b90e0
struct Matrix;

struct V3 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_0022d210(Matrix *m);
};

struct Node {
    char pad0[0x30];
    V3 pos;
};

struct Quad {
    V3 corner[4];
};

class Billboard {
public:
    char pad0[0x80];
    float halfWidth;
    float halfHeight;
    float pull;
    unsigned char fixedSize;
    void FUN_002b90e0(Quad *out, Node *from, Matrix *m, Node *target, float size);
};

void Billboard::FUN_002b90e0(Quad *out, Node *from, Matrix *m, Node *target, float size)
{
    V3 goal = target->pos;
    V3 p = from->pos;
    if (pull != 0.0f) {
        V3 d;
        d.x = goal.x - p.x;
        d.y = goal.y - p.y;
        d.z = goal.z - p.z;
        d.FUN_0022d110();
        d.x = d.x * pull;
        d.y = d.y * pull;
        d.z = d.z * pull;
        p.x = d.x + p.x;
        p.y = d.y + p.y;
        p.z = d.z + p.z;
    }
    p.FUN_0022d210(m);
    float w = size * halfWidth;
    float h = size * halfHeight;
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
