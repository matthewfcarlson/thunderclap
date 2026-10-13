class Target {
  public:
    char pad[0x42c];
    void* m;
    void* FUN_00320080();
};

void* Target::FUN_00320080() {
    return m;
}
