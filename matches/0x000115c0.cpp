class Color {
  public:
    unsigned int value;
    Color(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
};
Color::Color(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    value = (((d << 8) | a) << 8 | b) << 8 | c;
}