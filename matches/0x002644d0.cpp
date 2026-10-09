class LoadStream {
  public:
    void* vp;
    int m;
    char pad[5];
    unsigned char value;
    unsigned char flag;
    LoadStream(void* a, int b, int c);
    void Base0();
    void Init(void* a);
};
LoadStream::LoadStream(void* a, int b, int c) {
    m = 0;
    vp = (void*)0x42ae9c;
    Base0();
    flag = (c == 1);
    value = ((unsigned char*)a)[0x10c];
    Init(a);
}
