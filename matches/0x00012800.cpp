class Obj {
  public:
    char pad[0xa8];
    char mVal;
    char Get();
};
char Obj::Get() {
    return mVal;
}
