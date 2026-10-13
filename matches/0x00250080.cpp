class Target {
  public:
    char pad[8];
    void* Get();
};
void* Target::Get() {
    return (void*)((char*)this + 8);
}