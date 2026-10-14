class Result_16650 {
  public:
    void finish(int);
};
class CMotionTrailAction {
  public:
    char pad[0x20];
    void* mObject;
    int mValue;
    Result_16650* first();
    void vfunc_4();
};
void CMotionTrailAction::vfunc_4() {
    Result_16650* r = first();
    char* p = (char*)mObject;
    if (p[0xc8])
        r->finish(mValue);
}
