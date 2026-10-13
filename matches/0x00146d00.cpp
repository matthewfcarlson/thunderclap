class Obj {
  public:
    char Set(int v);

  private:
    char pad[0x20];
    int mField;
};

char Obj::Set(int v) {
    mField = v;
    return 1;
}