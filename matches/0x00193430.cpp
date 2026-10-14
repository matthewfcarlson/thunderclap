class T_193430 {
  public:
    char Set(int value);
    char pad[0xa8];
    int value;
};

char T_193430::Set(int value) {
    int v = value;
    *(int*)((char*)this + 0xa8) = v;
    return 1;
}
