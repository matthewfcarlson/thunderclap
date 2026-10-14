// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000fd010 @ 0x000fd010
struct Vec_fd010 { float x,y,z; float FUN_0022d110(); };
struct Transform_fd010 { void FUN_0022c3b0(Vec_fd010* input, Vec_fd010* output); };
void __cdecl FUN_000fd010(Transform_fd010* transform, unsigned int unused1, unsigned int unused2, float a, float b, Vec_fd010* output)
{
    Vec_fd010 input;
    input.x=a; input.y=b; input.z=0.0f;
    transform->FUN_0022c3b0(&input,output);
    output->FUN_0022d110();
    union Bits { float f; unsigned int u; } aa,bb;
    aa.f=a; bb.f=b;
    aa.u &= 0x7fffffff; bb.u &= 0x7fffffff;
    float scale = aa.f > bb.f ? aa.f : bb.f;
    output->x = scale * output->x;
    output->y = scale * output->y;
    output->z = scale * output->z;
}
