class Obj {
  public:
    char pad[0x10];
    void* mValue;
    char mFlag;
    char Set(void* p);
};

char Obj::Set(void* p) {
    mValue = p;
    return 1;
}
