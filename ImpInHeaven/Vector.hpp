#ifndef IMPINHEAVEN_VECTOR_HPP
#define IMPINHEAVEN_VECTOR_HPP
#include <string>
#include <sstream>

template<class T>
class Vector2{
public:
	T _x;
	T _y;

	Vector2() : _x(0), _y(0) {}
    Vector2(int x, int y) : _x(x), _y(y) {}

    T x() const{
        return _x;
    }

    void x(int _x) {
		this->_x = _x;
    }

    T y() const {
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

    static Vector2<T> toIso(const Vector2<T> vec) 
	{
        return Vector2(vec._x - vec._y, (vec._x + vec._y) / 2);
    }

    static Vector2<T> to2D(const Vector2<T> vec)
	{
        return Vector2((2 * vec._y + vec._x ) / 2, (2 * vec._y - vec._x) / 2);
    }

	std::string toString()
    {
		std::ostringstream stringStream;
		stringStream << "(" << this->_x << "," << this->_y << ")";
		return stringStream.str();
    }

	bool operator ==(const Vector2<T>& vector) const
	{
		return this->_x == vector._x && this->_y == vector._y;
	}

	bool operator !=(const Vector2<T>& vector) const
	{
		return this->_x != vector._x || this->_y != vector._y;
	}
};


#endif //IMPINHEAVEN_VECTOR_HPP
