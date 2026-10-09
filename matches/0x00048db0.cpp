struct Obj {
    char _pad[0x2098];
    int f1;
    int f2;
};
struct Stage {
    Obj* Get();
};
struct Lookup {
    Stage* Resolve();
};

class CNameFlagCondition {
  public:
    virtual ~CNameFlagCondition();
    virtual bool vfunc_7(int arg);
    char _pad[8];
    int m_mode;
    int m_a;
    int m_b;
};

bool CNameFlagCondition::vfunc_7(int arg) {
    Obj* obj = ((Lookup*)arg)->Resolve()->Get();
    switch (m_mode) {
    case 1:
        return (m_a != obj->f1 || m_b != obj->f2);
    case 0:
        return (m_a == obj->f1 && m_b == obj->f2);
    }
    return false;
}
