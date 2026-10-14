class Obj_18cc40 {
  public:
    char pad[31];
    int m20;
    char FUN_0018cc40(int a);
};

char Obj_18cc40::FUN_0018cc40(int a) {
    *(volatile int*)&m20 = a;
    return 1;
}
