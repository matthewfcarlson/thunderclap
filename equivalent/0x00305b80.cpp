// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00305b80 @ 0x00305b80
struct Node {
    char pad[0x30];
    float x, y, z;
};

union FloatBits {
    float f;
    unsigned int u;
};

// True when every component of a and b differs by no more than tol.
bool FUN_00305b80(const Node* a, const Node* b, float tol)
{
    FloatBits d;
    d.f = a->x - b->x;
    d.u &= 0x7fffffff;
    if (d.f > tol)
        return false;
    d.f = a->y - b->y;
    d.u &= 0x7fffffff;
    if (d.f > tol)
        return false;
    d.f = a->z - b->z;
    d.u &= 0x7fffffff;
    if (d.f > tol)
        return false;
    return true;
}
