class D3DTexture {
    char pad[0xd8];

  public:
    int vfunc_6();
};
int D3DTexture::vfunc_6() {
    return *(int*)(this->pad + 0xd8);
}