class Sub_13840 {
  public:
    void Run(int);
};
class O_13840 {
  public:
    char pad[0x18];
    void Forward(int);
};
void O_13840::Forward(int a0) {
    ((Sub_13840*)((char*)this + 0x18))->Run(a0);
}
