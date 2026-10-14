// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// movie::PlayerBink::vfunc_6 @ 0x003338e0
namespace movie {

struct Param {
    int count;
    int* values;
};

class PlayerBink {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(unsigned int a1, Param* param, unsigned int a3, unsigned int a4);
    virtual void vfunc_6(unsigned int a1, int id, unsigned int a3, unsigned int a4);
};

void PlayerBink::vfunc_6(unsigned int a1, int id, unsigned int a3, unsigned int a4)
{
    struct Frame {
        int zero;
        int one;
        Param param;
        int values[2];
        int* zeroPtr;
    } f;

    if (id != -1) {
        f.values[0] = id;
        f.param.values = f.values;
        f.zeroPtr = &f.zero;
        f.param.count = 1;
        f.one = 1;
        f.zero = 0;
        f.values[1] = 2;
        vfunc_5(a1, &f.param, a3, a4);
    } else {
        f.param.count = 0;
        f.param.values = 0;
        vfunc_5(a1, &f.param, a3, a4);
    }
}

}
