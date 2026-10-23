// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// core::XboxSaveDrive::vfunc_0_adj4 @ 0x002786e0
namespace core {
class XboxSaveDrive {
public:
    int vfunc_2(unsigned flags);
    int vfunc_0_adj4(unsigned flags);
};
int XboxSaveDrive::vfunc_0_adj4(unsigned flags) {
    XboxSaveDrive* drive = reinterpret_cast<XboxSaveDrive*>(reinterpret_cast<char*>(this) - 4);
    drive->vfunc_2(flags);
    return 0;   // WRONG: the scalar deleting destructor returns its this, which the thunk passes on
}
}