struct Packet {
    int kind;
    int first;
    int second;
    int third;
};
struct Sender {
    void FUN_0026e140(Packet*, int);
    void FUN_0026e530(int first, int second, int third);
};
void Sender::FUN_0026e530(int first, int second, int third) {
    Packet packet;
    packet.kind = 4;
    packet.first = first;
    packet.second = second;
    packet.third = third;
    FUN_0026e140(&packet, 16);
}