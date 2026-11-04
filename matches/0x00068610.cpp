class Obj {
    char pad[0x14];
    int value;

  public:
    bool SetAmplitude_00068610(int x);
};
bool Obj::SetAmplitude_00068610(int x) {
    value = x;
    return true;
}