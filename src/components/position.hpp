#ifndef IMPINHEAVEN_POSITION_HPP
#define IMPINHEAVEN_POSITION_HPP

struct Position {
    Position(int x, int y): x(x), y(y) {}

    int x, y;
};

struct FPosition {
    FPosition(float x, float y): x(x), y(y) {}

    float x, y;
};

#endif //IMPINHEAVEN_POSITION_HPP
