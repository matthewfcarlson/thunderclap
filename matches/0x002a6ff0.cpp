// Same code shape as 0x00069110 (propagated; names are from that function)
class CJumpTrack {
    char pad[0x44];

  public:
    float vfunc_27();
};
float CJumpTrack::vfunc_27() {
    return *(float*)((char*)this + 0x44);
}