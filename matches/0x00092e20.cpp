struct Game {
    void FUN_000928f0(int x, int y);
    void FUN_00092e20(int x, int y);
};
void Game::FUN_00092e20(int x, int y) {
    if (x >= 0 && x < 0x2fe && y >= 0 && y < 0x2fe)
        FUN_000928f0(x, y);
}