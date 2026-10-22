// cl-flags: /O2 /GR /GX

extern "C" bool __cdecl CheckString(const char** ppStr);

extern const char* g_str1; // 0x48e100
extern const char* g_str2; // 0x48e0f0
extern const char* g_str3; // 0x48e134

class Function_94000 {
  public:
    virtual void Invoke(const char*, int, const char*, const char*, const char*, const char*);
    virtual void AddRef();
    virtual void Release();
    int m_base1;
    int m_base2;
    int m_base3;
    Function_94000(const char* name, int index);
};

class Method6_94000 : public Function_94000 {
    char m_flag1; // 0x10
    char m_flag2; // 0x11
    char m_flag3; // 0x12
    char m_flag4; // 0x13
    char m_flag5; // 0x14
    char m_flag6; // 0x15
    char pad[2];  // 0x16-0x17
    char m_flag7; // 0x18
    int m_data;   // 0x1c
  public:
    Method6_94000(const char* name, int data);
};

Method6_94000::Method6_94000(const char* name, int data) : Function_94000(name, 6) {
    m_data = data;
    m_flag7 = CheckString(&g_str1);
    m_flag1 = CheckString(&g_str2);
    m_flag2 = CheckString(&g_str3);
    m_flag3 = CheckString(&g_str2);
    m_flag4 = CheckString(&g_str2);
    m_flag5 = CheckString(&g_str2);
    m_flag6 = CheckString(&g_str2);
}