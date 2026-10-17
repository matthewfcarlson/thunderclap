// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// core::XboxSaveDrive::vfunc_0_adj4 @ 0x002786e0
namespace core {
class XboxSaveDrive {
public:
    int vfunc_2();
    int vfunc_0_adj4();
};
int XboxSaveDrive::vfunc_0_adj4() {
    XboxSaveDrive* drive = reinterpret_cast<XboxSaveDrive*>(reinterpret_cast<char*>(this) - 4);
    return drive->vfunc_2();
}
}