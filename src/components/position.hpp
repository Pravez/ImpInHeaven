#ifndef IMPINHEAVEN_POSITION_HPP
#define IMPINHEAVEN_POSITION_HPP

struct Position {
    Position(int x = 0, int y = 0): x(x), y(y) {}

    int x, y;
};

struct FPosition {
    FPosition(float x = 0.0f, float y = 0.0f): x(x), y(y) {}

    float x, y;
};

bool collide(const FPosition* left, const FPosition* right) {
    return left->y == right->y && left->x == right->x;
}

#endif //IMPINHEAVEN_POSITION_HPP
