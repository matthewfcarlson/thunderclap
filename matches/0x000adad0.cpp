struct Block_adad0 {
    int x[0x11];
};
class Thing_adad0 {
  public:
    char pad[0xf0];
    Block_adad0 data;
    void Copy(Block_adad0* out);
};
void Thing_adad0::Copy(Block_adad0* out) {
    *out = data;
}