namespace pure3d {
class Image8 {
  public:
    char pad[0x430];
    int value;
    void vfunc_13(int);
};
void Image8::vfunc_13(int x) {
    value = x;
}
} // namespace pure3d
