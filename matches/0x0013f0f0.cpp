class WallExitTrack {
  public:
    float GetValue();

    char pad[0xc];
    float mValue;
};

float WallExitTrack::GetValue() {
    return mValue;
}
