class CControllerManager_ae9a0 {
  public:
    char pad[12];
    unsigned char data[15];
    void Fill(unsigned char v);
};
void CControllerManager_ae9a0::Fill(unsigned char v) {
    for (int i = 0; i < 13; i++)
        data[i] = v;
    for (int j = 13; j < 15; j++)
        data[j] = v;
}