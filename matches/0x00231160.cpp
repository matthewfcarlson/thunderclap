class Obj {
  public:
    void* m0;
    char pad[4];
    int m8;
    int mc;
    int m10;
    int m14;
    Obj(int arg);
};
Obj::Obj(int arg) {
    m0 = (void*)arg;
    m8 = 0;
    mc = 0;
    m10 = 0;
    m14 = 0;
}
