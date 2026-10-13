class Obj {
  public:
    char pad[0x28];
    unsigned int mFlag;
    int GetFlag();
};

int Obj::GetFlag() {
    return (mFlag >> 7) & 1;
}
