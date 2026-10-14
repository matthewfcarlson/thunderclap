class Thing_7a820 {
  public:
    char pad[0x374c];
    void* entries[1];
    float Get(int index);
};
float Thing_7a820::Get(int index) {
    return *(float*)((char*)entries[index] + 0x18);
}