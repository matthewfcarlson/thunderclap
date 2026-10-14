int gCounter;
class Obj {
    char pad0[0x398];

  public:
    unsigned char flag;
    char pad1[3];
    int mode;
    char pad2[0x1d4c - 0x3a0];
    unsigned char enabled;
    void Update();
};
void Obj::Update() {
    if (enabled) {
        int n = ++gCounter;
        flag = (n % 2 == 0);
        if (n % 3 == 1)
            mode = 0;
        else
            mode = (n % 3 != 2) + 1;
    }
}