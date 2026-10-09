class ZeroBlock {
  public:
    int words[32];
    ZeroBlock();
};

ZeroBlock::ZeroBlock() {
    int* p = words;
    for (int i = 0; i < 32; ++i)
        p[i] = 0;
}
