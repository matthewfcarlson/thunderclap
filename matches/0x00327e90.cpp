void* FUN_0008d690(unsigned int);
class d3dSimpleShader_327e90 {
  public:
    d3dSimpleShader_327e90* Init(void* arg);
};
d3dSimpleShader_327e90* FUN_00327e90(void* arg) {
    d3dSimpleShader_327e90* r = (d3dSimpleShader_327e90*)FUN_0008d690(0x94);
    if (r)
        return r->Init(arg);
    return 0;
}
