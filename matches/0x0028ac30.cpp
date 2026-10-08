class pure3d__Channel {
public:
    virtual ~pure3d__Channel();
    virtual void vfunc_1();
    virtual unsigned int GetTypeID();
};

class pure3d__SimpleChannel : public pure3d__Channel {
};

class pure3d__BoolChannel : public pure3d__SimpleChannel {
public:
    virtual ~pure3d__BoolChannel();
    virtual void vfunc_1();
    virtual unsigned int vfunc_2();
};

unsigned int pure3d__BoolChannel::vfunc_2() {
    return 0x4c4f4f42;
}