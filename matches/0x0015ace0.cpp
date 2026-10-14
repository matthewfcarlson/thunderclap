class A_15ace0 {
  public:
    char pad[0x80];
    int* Get();
};
int* A_15ace0::Get() {
    return (int*)((char*)this + 0x80);
}
