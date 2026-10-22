extern "C" void* __cdecl FUN_0008d690(unsigned int);
class d3dBumpMapVertexShader_3280d0 {
  public:
    void* Fn(void* a);
};
void* __cdecl FUN_003280d0(void* a) {
    d3dBumpMapVertexShader_3280d0* p = (d3dBumpMapVertexShader_3280d0*)FUN_0008d690(0x90);
    if (p)
        return p->Fn(a);
    return 0;
}