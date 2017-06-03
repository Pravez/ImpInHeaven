#ifndef IMPINHEAVEN_VECTOR_HPP
#define IMPINHEAVEN_VECTOR_HPP

class Vector{
private:
    int _x;
    int _y;

public:
    Vector(int x, int y) : _x(x), _y(y) {}

    int x() const {
        return _x;
    }

    void x(int _x) {
        Vector::_x = _x;
    }

    int y() const {
        return _y;
    }

    void y(int _y) {
        Vector::_y = _y;
    }
};

#endif //IMPINHEAVEN_VECTOR_HPP
