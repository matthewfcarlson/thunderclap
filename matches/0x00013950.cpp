class CAction {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual bool vf5(int sel, int arg);
    virtual void vf5a();
    virtual bool vf6(int arg);
    virtual bool vf7(int arg);
};

bool CAction::vf5(int sel, int arg)
{
    bool r = false;
    switch (sel) {
    case 0: r = vf6(arg); break;
    case 1: r = vf7(arg); break;
    }
    return r;
}
