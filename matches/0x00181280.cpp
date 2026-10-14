class Helper_181280 {
  public:
    void Init();
};
extern char BallAndChainShootTrack_vftable;
class BallAndChainShootTrack {
  public:
    char pad[0x78];
    void Construct();
};
class Base_181280 {
  public:
    void Finish();
};
void BallAndChainShootTrack::Construct() {
    *(void**)this = &BallAndChainShootTrack_vftable;
    ((Helper_181280*)((char*)this + 0x78))->Init();
    ((Helper_181280*)((char*)this + 0x60))->Init();
    ((Base_181280*)this)->Finish();
}