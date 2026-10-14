extern "C" int vtable_170460;
void thunk(int);
class DriftToPositionTrack {
  public:
    int vf;
    char pad[0x24];
    int value;
    void f();
    void tail();
};
void DriftToPositionTrack::f() {
    vf = (int)&vtable_170460;
    thunk(value);
    tail();
}