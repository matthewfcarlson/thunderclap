class Obj_16ed90 {
  public:
    char F(int x);
    char pad[0x44];
    int mVal;
};
char Obj_16ed90::F(int x) {
    mVal = x;
    return 1;
}