class Sub {
  public:
    void Run();
};
class O {
  public:
    char pad[0x18];
    void Forward();
};
void O::Forward() {
    ((Sub*)((char*)this + 0x18))->Run();
}
