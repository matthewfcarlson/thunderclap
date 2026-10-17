// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// pure3d::pddiBaseContext::vfunc_43 @ 0x0031dba0
namespace pure3d {
struct TextureStage {
    char reserved[0x78];
    unsigned int value;
};
class pddiBaseContext {
public:
    char padding[0x50];
    TextureStage* stages;
    void vfunc_43(unsigned int* result, int index);
};
void pddiBaseContext::vfunc_43(unsigned int* result, int index) {
    if (index < 8)
        *result = stages[index].value;
    else
        *result = 0;
}
}
