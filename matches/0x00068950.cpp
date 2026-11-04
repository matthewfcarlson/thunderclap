class T_68950 {
  public:
    char pad[0x14];
    int m14;
    bool SetExtensionTime_00068950(int value);
};

bool T_68950::SetExtensionTime_00068950(int value) {
    m14 = value;
    return true;
}
