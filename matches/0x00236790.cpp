class Helper {
    char pad[0x18];

  public:
    Helper(void*);
    void Run(int, int);
};
class Target {
  public:
    char pad[0x14];
    void F(int a, int b);
};
void Target::F(int a, int b) {
    Helper h((char*)this + 0x14);
    h.Run(a, b);
}