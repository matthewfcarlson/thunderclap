// STATUS: equivalent (tools/equiv.py level 3: 1479 inputs, branch coverage 6/6)
// FUN_002c59f0 @ 0x002c59f0
// Immediate-mode line list: draws n lines from a[i] to b[i], optionally colouring each from colors[i].
struct Vec3_2c59f0 {
    float x, y, z;
};

struct Buffer_2c59f0 {
    char pad00[8];
    Vec3_2c59f0 *position;                 // 8: write cursor for the next vertex
    char pad0c[4];
    unsigned int *colour;           // 0x10
    void FUN_0008ef00();            // emit the vertex written at the cursors
};

class Shader;

class Renderer_2c59f0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29();
    virtual Buffer_2c59f0 *Begin(Shader *shader, int primitive, int flags, int vertices, int zero);   // slot 30
    virtual void End(Buffer_2c59f0 *buffer);                                                          // slot 31
};

extern Renderer_2c59f0 *DAT_0052c2a8;

struct LineDrawer {
    Shader *shader;                 // 0
    unsigned int colour;            // 4
    void FUN_002c59f0(int count, const Vec3_2c59f0 *a, const Vec3_2c59f0 *b, const unsigned int *colours);
};

void LineDrawer::FUN_002c59f0(int count, const Vec3_2c59f0 *a, const Vec3_2c59f0 *b, const unsigned int *colours)
{
    Buffer_2c59f0 *buf = DAT_0052c2a8->Begin(shader, 2, 0x2020, count * 2, 0);
    for (int i = 0; i < count; i++) {
        if (colours)
            colour = colours[i];
        Vec3_2c59f0 *p = buf->position;
        unsigned int c = colour;
        p->x = a[i].x;
        p->y = a[i].y;
        p->z = a[i].z;
        *buf->colour = c;
        buf->FUN_0008ef00();
        p = buf->position;
        c = colour;
        p->x = b[i].x;
        p->y = b[i].y;
        p->z = b[i].z;
        *buf->colour = c;
        buf->FUN_0008ef00();
    }
    DAT_0052c2a8->End(buf);
}
