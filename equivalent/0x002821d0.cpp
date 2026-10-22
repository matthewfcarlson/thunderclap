// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_002821d0 @ 0x002821d0
void *__cdecl FUN_00263ea0(unsigned int size);

class Attr_2821d0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void setInt(unsigned int tag, int value);
    virtual void setFloat(unsigned int tag, float value);
    virtual void setColor(unsigned int tag, unsigned int value);
};

class Shader_2821d0 {
public:
    virtual void addRef();
    char pad04[0xc];
    Attr_2821d0 *attr;              // 0x10
    char locked;             // 0x14
    char pad15[3];
    int mode;                // 0x18
    char pad1c[4];
    Shader_2821d0 *FUN_0028edf0(const char *name, int flags);
};

namespace pure3d {
namespace prop {

class __declspec(novtable) QueueBase {
public:
    virtual void v0();
    char pad04[0x10];
    void FUN_0027b070();
    QueueBase() { FUN_0027b070(); }
};

class CLightQueue : public QueueBase {
public:
    Shader_2821d0 *res;                // 0x14
    int f18;
    int f1c;
    int f20;
    char pad24[8];
    int f2c;
    char pad30[0x54 - 0x30];
    int f54;
    virtual void v1();
    virtual void v2();
    CLightQueue();
};

CLightQueue::CLightQueue()
{
    f18 = 0;
    f2c = 0;
    f1c = 0;
    f20 = 0;
    f54 = 0;
    void *mem = FUN_00263ea0(0x20);
    Shader_2821d0 *r = 0;
    if (mem)
        r = static_cast<Shader_2821d0 *>(mem)->FUN_0028edf0("simple", 0);
    res = r;
    res->addRef();

    Shader_2821d0 *e = res;
    e->attr->setInt(0x54494c, 1);
    e->locked = 1;
    res->attr->setInt(0x44495332, 0);
    res->attr->setInt(0x444d4853, 1);
    res->attr->setInt(0x444d4946, 1);
    e = res;
    e->attr->setInt(0x444d4c42, 2);
    e->mode = 2;
    res->attr->setInt(0x444d5655, 0);
    res->attr->setInt(0x4d564243, 4);
    res->attr->setInt(0x4e494d4d, 0);
    res->attr->setInt(0x504d4341, 4);
    res->attr->setInt(0x50564243, 0);
    res->attr->setInt(0x54535441, 0);
    res->attr->setInt(0x5642434d, 0);
    res->attr->setInt(0x58414d4d, 7);
    res->attr->setInt(0x59564243, 0);
    res->attr->setFloat(0x48544341, 0.5f);
    res->attr->setFloat(0x4e494853, 0.0f);
    res->attr->setFloat(0x5048534d, 0.5f);
    res->attr->setFloat(0x56564243, 0.0f);
    res->attr->setColor(0x43455053, 0xff000000);
    res->attr->setColor(0x46464944, 0xffffffff);
    res->attr->setColor(0x49424d41, 0xffffffff);
    res->attr->setColor(0x53494d45, 0xff000000);
}

}
}
