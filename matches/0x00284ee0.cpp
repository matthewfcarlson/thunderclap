// Same code shape as 0x000690a0 (propagated; names are from that function)
class CJumpTrack {
  public:
    char pad[0x28];
    float mHeight;

    float GetHeight();
};

float CJumpTrack::GetHeight() {
    return mHeight;
}