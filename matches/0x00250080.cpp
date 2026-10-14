class Target_250080 {
  public:
    char pad[8];
    void* Get();
};
void* Target_250080::Get() {
    return (void*)((char*)this + 8);
}