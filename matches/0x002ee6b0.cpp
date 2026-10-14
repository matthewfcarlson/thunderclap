class Obj_2ee6b0 {
  public:
    char pad[0x6c];
    unsigned char flag;
    void callee(int);
    void target(int);
};
void Obj_2ee6b0::target(int arg) {
    callee(arg);
    flag = 1;
}