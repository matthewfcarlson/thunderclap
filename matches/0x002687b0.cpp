namespace core {
class ControllerXBox {
  public:
    char pad[8];
    int member;
    bool vfunc_3();
};
bool ControllerXBox::vfunc_3() {
    return member != 0;
}
} // namespace core