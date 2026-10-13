class Obj {
  public:
    char Set(void* p);
    char pad[0x60];
    void* mValue;
};

char Obj::Set(void* p) {
    mValue = p;
    return 1;
}
