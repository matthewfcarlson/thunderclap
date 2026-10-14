class Obj_f7a10 {
  public:
    char pad[0x10];
    int m10;
    int m14;
    char pad18[8];
    int m20;
    void Set(int value, int unused);
};
void release(int);
void Obj_f7a10::Set(int value, int unused) {
    if (m10) {
        release(m10);
        m10 = 0;
        m14 = value;
        m20 = -1;
    } else {
        m14 = value;
        m20 = -1;
    }
}