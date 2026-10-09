class CJumpTrack {
  public:
    char pad[0x28];
    float mHeight;

    float GetHeight();
};

float CJumpTrack::GetHeight() {
    return mHeight;
}