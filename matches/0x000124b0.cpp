class Obj_124b0 {
  public:
    char pad[0x28];
    unsigned int mFlag;
    int GetFlag();
};

int Obj_124b0::GetFlag() {
    return (mFlag >> 7) & 1;
}
