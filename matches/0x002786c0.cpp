namespace core {
struct SignedWriter {
    int FUN_0027a460(void*, unsigned int, unsigned int);
};
struct XboxSaveDrive {
    char padding[0xc0];
    SignedWriter writer;
    int vfunc_13(unsigned int a, unsigned int b, unsigned int c);
};
int XboxSaveDrive::vfunc_13(unsigned int a, unsigned int b, unsigned int c) {
    return writer.FUN_0027a460(this, a, b);
}
} // namespace core