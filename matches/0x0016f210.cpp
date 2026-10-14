class Obj {
  public:
    virtual void V();
    char pad[12];
    char Set(int value);
};
char Obj::Set(int value) {
    *(int*)((char*)this + 0x10) = value;
    return 1;
}