class Pose {
  public:
    void* vf;
    int a, b, c;
    void Init(int);
    Pose* Make(int);
};
Pose* Pose::Make(int arg) {
    a = 0;
    b = 0;
    c = 0;
    vf = (void*)0x43211c;
    Init(arg);
    return this;
}