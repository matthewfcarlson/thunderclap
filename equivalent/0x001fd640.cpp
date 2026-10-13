// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001fd640 @ 0x001fd640
struct Vec3 { float x,y,z; };
extern "C" double __cdecl sqrt(double);
extern void __cdecl FUN_0022d3a0(void*, Vec3*, Vec3*, float, float*);
void __cdecl FUN_001fd640(void* context, Vec3* start, Vec3* end, Vec3* output) {
    double dx = (double)end->x - start->x;
    float dy = end->y - start->y;
    double dz = (double)end->z - start->z;
    float length = (float)sqrt((dz*dz + (double)dy*dy) + dx*dx);
    if (length == 0.0f) {
        output->x = start->x;
        output->y = start->y;
        output->z = start->z;
        return;
    }
    double inv = 1.0 / length;
    Vec3 direction;
    direction.x = (float)(dx*inv);
    direction.y = (float)(dy*inv);
    direction.z = (float)(dz*inv);
    FUN_0022d3a0(context,start,&direction,length,&length);
    double x = (double)direction.x * length;
    float y = direction.y * length;
    float z = direction.z * length;
    double ox = x + start->x;
    double oy = (double)y + start->y;
    double oz = (double)z + start->z;
    output->x = (float)ox;
    output->y = (float)oy;
    output->z = (float)oz;
}
