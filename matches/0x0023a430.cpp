class BufferStringReader {
  public:
    char pad0[0x10];
    unsigned int m10;
    unsigned int m14;
    bool vfunc_6();
};
bool BufferStringReader::vfunc_6() {
    return m14 >= m10;
}