#ifndef IMPINHEAVEN_VECTOR_HPP
#define IMPINHEAVEN_VECTOR_HPP
#include <string>
#include <sstream>

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
		this->_x = _x;
    }

    int y() const {
        return _y;
    }

    void y(int _y) {
        this->_y = _y;
    }

	void plus_y(int plus)
    {
		this->_y += plus;
    }

	void plus_x(int plus)
    {
		this->_x += plus;
    }

	void minus_y(int minus)
    {
		this->_y -= minus;
    }

	void minus_x(int minus)
	{
		this->_x -= minus;
	}

    static Vector2 toIso(const Vector2 vec) 
	{
        return Vector2(vec._x - vec._y, (vec._x + vec._y) / 2);
    }

    static Vector2 to2D(const Vector2 vec)
	{
        return Vector2((2 * vec._y + vec._x ) / 2, (2 * vec._y - vec._x) / 2);
    }

	std::string toString()
    {
		std::ostringstream stringStream;
		stringStream << "Vector2: (x: " << this->_x << ", y: " << this->_y << ")";
		return stringStream.str();
    }
};

#endif //IMPINHEAVEN_VECTOR_HPP
