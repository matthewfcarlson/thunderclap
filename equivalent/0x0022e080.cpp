// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0022e080 @ 0x0022e080
struct Plane_22e080 {
    float nx, ny, nz, w;
    bool FUN_0022e080(const float *box);
};

bool Plane_22e080::FUN_0022e080(const float *box)
{
    float x = (nx >= 0.0f) ? box[0] : box[3];
    float y = (ny >= 0.0f) ? box[1] : box[4];
    float z = (nz >= 0.0f) ? box[2] : box[5];
    return -w >= ((z * nz + x * nx) + y * ny);
}
