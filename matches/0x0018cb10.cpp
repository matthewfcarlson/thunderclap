class Obj_18cb10 {
  public:
    char Pad[0x1c];
    int mVal;
    char Set(int x);
};
char Obj_18cb10::Set(int x) {
    mVal = x;
    return 1;
}
