struct Vec3 { float x,y,z; };
void FUN_00083e00(Vec3* out, Vec3* in, float scale)
{
    float z = scale * in->z;
    float y = scale * in->y;
    float x = scale * in->x;
    out->x = x;
    out->y = y;
    out->z = z;
}
