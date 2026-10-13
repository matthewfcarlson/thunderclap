class Obj {
  public:
    char pad[0x28];
    void* mVal;
    void* Get();
};
void* Obj::Get() {
    return mVal;
}