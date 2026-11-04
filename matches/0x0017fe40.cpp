class Thing {
  public:
    char pad[12];
    int value;
    bool SetTimeBegin_0017fe40(int v);
};
bool Thing::SetTimeBegin_0017fe40(int v) {
    value = v;
    return true;
}