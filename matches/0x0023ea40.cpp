class A_23ea40 {
  public:
    char pad[0x14];
    int* Get();
};
int* A_23ea40::Get() {
    return (int*)((char*)this + 0x14);
}