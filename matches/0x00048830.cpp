// Same code shape as 0x000485c0 (propagated; names are from that function)
class CAxisReleaseCondition {
  public:
    bool vfunc_10(int* param, int unused);
};
bool CAxisReleaseCondition::vfunc_10(int* param, int unused) {
    return *param == 3;
}