class Obj_68b20 {
  public:
    char pad[0x10];
    void* mValue;
    char mFlag;
    char Set(void* p);
};

char Obj_68b20::Set(void* p) {
    mValue = p;
    return 1;
}
