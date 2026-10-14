extern int vftable_327030;
class pddiPrimBuffer {
  public:
    void Init();
    pddiPrimBuffer();
};
pddiPrimBuffer::pddiPrimBuffer() {
    Init();
    *(int*)this = (int)&vftable_327030;
}