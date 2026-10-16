namespace pure3d {
class pddiPrimBufferStream {
  public:
    virtual void vfunc_0(int, int, int);
};
class d3dPrimBufferStream : public pddiPrimBufferStream {
  public:
    char pad[0x20];
    int* data;
    virtual void vfunc_0(int, int, int);
    void Advance();
};
void d3dPrimBufferStream::vfunc_0(int a, int b, int c) {
    data[0] = a;
    data[1] = b;
    data[2] = c;
    Advance();
}
} // namespace pure3d