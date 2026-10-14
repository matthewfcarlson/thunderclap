class Obj_16f210 {
  public:
    virtual void V();
    char pad[12];
    char Set(int value);
};
char Obj_16f210::Set(int value) {
    *(int*)((char*)this + 0x10) = value;
    return 1;
}