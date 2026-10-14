class Target_24770 {
  public:
    char pad[0x584];
    int value;
    void Set(int x);
};

void Target_24770::Set(int x) {
    value = x;
}