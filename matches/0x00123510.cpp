class T_123510 {
  public:
    char pad[12];
    unsigned char flag;
    unsigned char Set(void* p);
};

unsigned char T_123510::Set(void* p) {
    *(void**)((char*)this + 0xc) = p;
    return 1;
}
