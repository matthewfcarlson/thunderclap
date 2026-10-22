class Track_238a00 {
  public:
    Track_238a00();
    virtual void Fn();
    char pad[4];
};
class PrintTrack : public Track_238a00 {
  public:
    PrintTrack();
    int a, b, c, d;
    virtual void Fn();
};
PrintTrack::PrintTrack() : Track_238a00(), b(0), c(0), d(0) {
    a = 1;
}