class Obj_146d00 {
  public:
    char Set(int v);

  private:
    char pad[0x20];
    int mField;
};

char Obj_146d00::Set(int v) {
    mField = v;
    return 1;
}