class BufferStringReader {
  public:
    char pad[8];
    unsigned char* data;
    char pad2[4];
    unsigned int limit;
    unsigned int pos;
    unsigned char vfunc_5();
};
unsigned char BufferStringReader::vfunc_5() {
    unsigned int p = pos;
    if (p >= limit)
        return 0;
    unsigned char c = data[p];
    pos = p + 1;
    return c;
}