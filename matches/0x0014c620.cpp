class Base_14c620 {
  public:
    char pad[0x10];
};
class A_14c620 : public Base_14c620 {
  public:
    void* Get();
};
void* A_14c620::Get() {
    return (char*)this + 0x10;
}