class Thing {
  public:
    char pad0[4];
    int count;
    char pad8[0x5108 - 8];
    int state;
    int Check(int);
    void Init(int);
    int Target(int);
};
int Thing::Target(int arg) {
    if (Check(arg)) {
        state = 7;
        return 0;
    }
    int i = count;
    if (i >= 32) {
        state = 5;
        return 0;
    }
    ((Thing*)((char*)this + i * 0x288 + 8))->Init(arg);
    count++;
    return (int)((char*)this + i * 0x288 + 8);
}