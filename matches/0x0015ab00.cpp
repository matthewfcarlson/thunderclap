class Target_15ab00 {
  public:
    char Set(int value);
    char pad[16];
};

char Target_15ab00::Set(int value) {
    *(int*)((char*)this + 0x10) = value;
    return 1;
}
