struct Sub_15b600 {
    char pad[0x40];
};
class A_15b600 {
  public:
    Sub_15b600 sub;
    void* Get();
};
void* A_15b600::Get() {
    return (char*)&sub + 0x40;
}
