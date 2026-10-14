extern const float factor;
struct Obj {
    float pos[3];
    char a[0x14];
    float vel[3];
    char b[0xc];
    float x;
    short s;
};
struct Ctx {
    char a[0x1a4];
    float scale;
    char b[4];
    float gravity;
};
void step(float dt, Ctx* c, Obj* o) {
    float g = c->gravity;
    o->x += (float)o->s * c->scale * factor * dt;
    o->pos[0] += g * o->vel[0] * dt;
    o->pos[1] += g * (o->vel[1] + o->x) * dt;
    o->pos[2] += g * o->vel[2] * dt;
}