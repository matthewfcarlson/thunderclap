struct X_68570 {
    char pad[0x14];
    int m14;
    bool SetComboTimer_00068570(int x);
};

bool X_68570::SetComboTimer_00068570(int x) {
    m14 = x;
    return true;
}
