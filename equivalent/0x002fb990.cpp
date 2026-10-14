// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002fb990 @ 0x002fb990
struct V3_2fb990 {
    float x, y, z;
};

class Basis_2fb990 {
public:
    char pad0[0x48];
    float w[3];     // 0x48
    V3_2fb990 axis[3];     // 0x54
    void FUN_002fb990(V3_2fb990* out, int a, int negate);
};

// Blends two of the three axes, weighted by w[], into out.
void Basis_2fb990::FUN_002fb990(V3_2fb990* out, int a, int negate)
{
    int i;
    int j;
    if (a >= 2) {
        i = 0;
        j = 1;
    } else {
        i = a + 1;
        if (i < 2)
            j = i + 1;
        else
            j = 0;
    }
    float s = w[i];
    if (negate != 0)
        s = -s;
    out->x = s * axis[i].x;
    out->y = s * axis[i].y;
    out->z = s * axis[i].z;
    float t = w[j];
    out->x = t * axis[j].x + out->x;
    out->y = t * axis[j].y + out->y;
    out->z = t * axis[j].z + out->z;
}
