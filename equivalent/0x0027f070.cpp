// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0027f070 @ 0x0027f070
struct Vertex_27f070 {
    float x, y, z;
    unsigned char b, g, r, a;
    float u, v;

    void lerp(const Vertex_27f070* from, const Vertex_27f070* to, float t);
};

void Vertex_27f070::lerp(const Vertex_27f070* from, const Vertex_27f070* to, float t)
{
    x = (to->x - from->x) * t + from->x;
    y = (to->y - from->y) * t + from->y;
    z = (to->z - from->z) * t + from->z;
    r = (unsigned char)(int)((to->r - from->r) * t + from->r);
    g = (unsigned char)(int)((to->g - from->g) * t + from->g);
    b = (unsigned char)(int)((to->b - from->b) * t + from->b);
    a = (unsigned char)(int)((to->a - from->a) * t + from->a);
    u = (to->u - from->u) * t + from->u;
    v = (to->v - from->v) * t + from->v;
}
