class Sub_13840 {
  public:
    void Run();
};
class O_13840 {
  public:
    char pad[0x18];
    void Forward();
};
void O_13840::Forward() {
    ((Sub_13840*)((char*)this + 0x18))->Run();
}
