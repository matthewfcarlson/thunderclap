struct Vec3_fae50 {
    float x, y, z;
};
class Obj_fae50 {
    char pad[8];
    int active;

  public:
    float Next();
    void Get(Vec3_fae50* out);
};
void Obj_fae50::Get(Vec3_fae50* out) {
    if (active == 0) {
        out->x = 0.0f;
        out->z = 0.0f;
        out->y = 0.0f;
    } else {
        float a = Next();
        float b = Next();
        float c = Next();
        out->x = a;
        out->y = b;
        out->z = c;
    }
}