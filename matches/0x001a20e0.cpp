class C_1a20e0 {
  public:
    char pad[0x60];
    char m;
    char Set(int v);
};

char C_1a20e0::Set(int v) {
    char* p = (char*)this;
    *(int*)(p + 0x60) = v;
    return 1;
}
