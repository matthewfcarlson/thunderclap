typedef unsigned char byte;
class Bits {
  public:
    byte value;
    bool Test(int a, int b);
};
bool Bits::Test(int a, int b) {
    if (a < 0 || b < 0)
        return true;
    byte mask = 1;
    mask = (byte)(mask << (a + b * 4));
    return (mask & value) != 0;
}