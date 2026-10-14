class Obj_68670 {
  public:
    char Set(void* p);
    char pad[0x60];
    void* mValue;
};

char Obj_68670::Set(void* p) {
    mValue = p;
    return 1;
}
