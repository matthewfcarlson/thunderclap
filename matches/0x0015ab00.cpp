class Target {
  public:
    char Set(int value);
    char pad[16];
};

char Target::Set(int value) {
    *(int*)((char*)this + 0x10) = value;
    return 1;
}
