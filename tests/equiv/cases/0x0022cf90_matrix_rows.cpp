extern "C" double sqrt(double);
bool FUN_00018960(float a, float b, float eps);

struct Mat3 {
    float r0[3]; float p0;
    float r1[3]; float p1;
    float r2[3]; float p2;
    bool FUN_0022cf90();
};

static float Len(const float* v)
{
    return (float)sqrt((double)(v[2] * v[2] + v[1] * v[1] + v[0] * v[0]));
}
static float Abs(float v)
{
    return v < 0.0f ? -v : v;
}

bool Mat3::FUN_0022cf90()
{
    const float eps = 1e-05f;
    float len1 = Len(r1);
    float len2 = Len(r2);
    float d10 = r1[1] * r0[1] + r1[2] * r0[2] + r1[0] * r0[0];
    float d21 = r2[2] * r1[2] + r2[1] * r1[1] + r2[0] * r1[0];
    float d20 = r2[1] * r0[1] + r2[2] * r0[2] + r2[0] * r0[0];
    float len0 = Len(r0);
    if (!(Abs(len0 - 1.0f) <= eps)) return false;
    if (!(Abs(len1 - 1.0f) <= eps)) return false;
    if (!(Abs(len2 - 1.0f) <= eps)) return false;
    if (!(Abs(d10) <= eps)) return false;
    if (!FUN_00018960(d21, 0.0f, eps)) return false;
    if (!FUN_00018960(d20, 0.0f, eps)) return false;
    return true;
}
