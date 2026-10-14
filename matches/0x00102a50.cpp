class Origin_102a50 {
  public:
    void Get(float*);
};
class Vec_102a50 {
  public:
    float x, y, z;
    float Normalize();
};
class Owner_102a50 {
  public:
    char pad[0x10];
    Origin_102a50* origin;
    float Scale();
};
void FUN_00102a50(Owner_102a50* owner, float* src, Vec_102a50* dst) {
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