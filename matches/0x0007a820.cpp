class Thing {
  public:
    char pad[0x374c];
    void* entries[1];
    float Get(int index);
};
float Thing::Get(int index) {
    return *(float*)((char*)entries[index] + 0x18);
}