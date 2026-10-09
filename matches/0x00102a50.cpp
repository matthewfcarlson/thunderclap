class Origin {
  public:
    void Get(float*);
};
class Vec {
  public:
    float x, y, z;
    float Normalize();
};
class Owner {
  public:
    char pad[0x10];
    Origin* origin;
    float Scale();
};
void FUN_00102a50(Owner* owner, float* src, Vec* dst) {
    float local[3];
    owner->origin->Get(local);
    dst->x = src[0] - local[0];
    dst->y = src[1] - local[1];
    dst->z = src[2] - local[2];
    dst->Normalize();
    float scale = owner->Scale();
    dst->x = scale * dst->x;
    dst->y = scale * dst->y;
    dst->z = scale * dst->z;
}