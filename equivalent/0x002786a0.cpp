// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// core::XboxSaveDrive::vfunc_12 @ 0x002786a0
namespace core {
struct SaveInterface {
    void FUN_0027a370(void* drive, unsigned int first, unsigned int second);
};
struct XboxSaveDrive {
    char reserved[0xbc];
    SaveInterface saveInterface;
    void vfunc_12(unsigned int first, unsigned int second, unsigned int third);
};
void XboxSaveDrive::vfunc_12(unsigned int first, unsigned int second, unsigned int third) {
    saveInterface.FUN_0027a370(this, first, second);
}
}