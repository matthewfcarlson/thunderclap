class Thing_333400 {
    char pad[0x7c];
    char mFlag;

  public:
    void Set(void* p);
};

void Thing_333400::Set(void* p) {
    mFlag = (p != 0);
}
