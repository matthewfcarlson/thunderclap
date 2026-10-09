namespace hulkfight {
namespace ai {

class HulkActionTrack {
  public:
    char pad0[0xc];
    float mValue;

    float vfunc_6();
};

float HulkActionTrack::vfunc_6() {
    return mValue;
}

} // namespace ai
}; // namespace hulkfight