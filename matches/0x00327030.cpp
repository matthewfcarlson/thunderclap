extern int vftable;
class pddiPrimBuffer {
  public:
    void Init();
    pddiPrimBuffer();
};
pddiPrimBuffer::pddiPrimBuffer() {
    Init();
    *(int*)this = (int)&vftable;
}