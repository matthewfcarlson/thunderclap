// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00294f10 @ 0x00294f10
struct Rect_294f10 {
    float l, t, r, b;
};

struct Source_294f10 {
    char pad0[0x18];
    Rect_294f10 uv;
};

struct VertexSink_294f10 {
    char pad0[8];
    float *pos;
    char pad0c[4];
    unsigned int *color;
    float *tex;
    void FUN_0008ef00();
};

class Quad_294f10 {
public:
    char pad0[0x18];
    float height;
    char pad1c[0x24 - 0x1c];
    unsigned int color;
    void Emit(VertexSink_294f10 *out, Source_294f10 *src, float x, float w);
};

void Quad_294f10::Emit(VertexSink_294f10 *out, Source_294f10 *src, float x, float w)
{
    float h = height;
    float uv0 = src->uv.l;
    float uv1 = src->uv.t;
    float uv2 = src->uv.r;
    float uv3 = src->uv.b;
    unsigned int c = color;

    // two triangles of a strip-less quad, one vertex at a time
    *out->color = c;
    out->tex[0] = uv0;
    out->tex[1] = uv1;
    out->pos[0] = x;
    out->pos[1] = 0;
    out->pos[2] = 0;
    out->FUN_0008ef00();

    *out->color = c;
    out->tex[0] = uv0;
    out->tex[1] = uv3;
    out->pos[0] = x;
    out->pos[1] = h;
    out->pos[2] = 0;
    out->FUN_0008ef00();

    float x2 = x + w;
    *out->color = c;
    out->tex[0] = uv2;
    out->tex[1] = uv3;
    out->pos[0] = x2;
    out->pos[1] = h;
    out->pos[2] = 0;
    out->FUN_0008ef00();

    *out->color = c;
    out->tex[0] = uv0;
    out->tex[1] = uv1;
    out->pos[0] = x;
    out->pos[1] = 0;
    out->pos[2] = 0;
    out->FUN_0008ef00();

    *out->color = c;
    out->tex[0] = uv2;
    out->tex[1] = uv3;
    out->pos[0] = x2;
    out->pos[1] = h;
    out->pos[2] = 0;
    out->FUN_0008ef00();

    *out->color = c;
    out->tex[0] = uv2;
    out->tex[1] = uv1;
    out->pos[0] = x2;
    out->pos[1] = 0;
    out->pos[2] = 0;
    out->FUN_0008ef00();
}
