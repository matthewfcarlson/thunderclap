typedef unsigned int uint;
extern "C" void* __cdecl FUN_0008d690(uint);
struct d3dBuildingShader_3280a0 {
    d3dBuildingShader_3280a0(void*);
    d3dBuildingShader_3280a0* fn(void* p);
};
d3dBuildingShader_3280a0* __cdecl FUN_003280a0(void* p) {
    d3dBuildingShader_3280a0* r = (d3dBuildingShader_3280a0*)FUN_0008d690(0x90);
    if (r)
        return r->fn(p);
    return 0;
}