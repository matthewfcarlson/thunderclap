class Mgr {
  public:
    char pad[0x30];
    float mVal;
    float Get();
};
float Mgr::Get() {
    return mVal;
}
