// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 12/12)
// FUN_002b1eb0 @ 0x002b1eb0
class Child_2b1eb0 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual float GetValue();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void SetPair(float a, float b);
    virtual void v15();
    virtual void SetParam(int p);
};

class Mixer {
public:
    char pad0[0x28];
    float scaleA;           // 0x28
    float scaleB;           // 0x2c
    char pad30[0xc];
    int param;              // 0x3c
    char pad40[4];
    unsigned int count;     // 0x44
    Child_2b1eb0 **children;       // 0x48
    Child_2b1eb0 **capacityEnd;    // 0x4c
    void FUN_002b1eb0(Child_2b1eb0 *child);
};

void Mixer::FUN_002b1eb0(Child_2b1eb0 *child)
{
    unsigned int n = count;
    for (unsigned int i = 0; i < count; i++) {
        if (children[i] == child)
            return;
    }
    if (n >= (unsigned int)(capacityEnd - children))
        return;

    Child_2b1eb0 **slot = &children[n];
    if (child)
        child->AddRef();
    if (*slot)
        (*slot)->Release();
    *slot = child;

    float v = children[count]->GetValue();
    children[count]->SetPair(v * scaleA, v * scaleB);
    children[count]->SetParam(param);
    count++;
}
