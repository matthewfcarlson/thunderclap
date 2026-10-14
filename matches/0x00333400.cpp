class Thing {
    char pad[0x7c];
    char mFlag;

  public:
    void Set(void* p);
};

void Thing::Set(void* p) {
    mFlag = (p != 0);
}
