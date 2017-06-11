#ifndef IMPINHEAVEN_VECTOR_HPP
#define IMPINHEAVEN_VECTOR_HPP

class Vector2{
private:
    int _x;
    int _y;

public:
    Vector2(int x, int y) : _x(x), _y(y) {}

    int x() const {
        return _x;
    }

    void x(int _x) {
        Vector2::_x = _x;
    }

    int y() const {
        return _y;
    }

    void y(int _y) {
        Vector2::_y = _y;
    }

    static const Vector2 toIso(const Vector2 vec) {
        return Vector2(vec._x - vec._y, (vec._x + vec._y) / 2);
    }

    static const Vector2 to2D(const Vector2 vec){
        return Vector2((2 * vec._y + vec._x ) / 2, (2 * vec._y - vec._x) / 2);
    }
};

#endif //IMPINHEAVEN_VECTOR_HPP
