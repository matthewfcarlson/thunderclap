struct Packet {
    int type;
    int first;
    int second;
};
struct Handler {
    void FUN_0026e140(Packet*, int);
    void FUN_0026e570(int first, int second);
};
void Handler::FUN_0026e570(int first, int second) {
    Packet packet;
    packet.type = 5;
    packet.first = first;
    packet.second = second;
    FUN_0026e140(&packet, 12);
}