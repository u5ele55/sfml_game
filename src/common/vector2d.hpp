#ifndef VECTOR_2D_HPP
#define VECTOR_2D_HPP

namespace Common {
    template<typename T>
    struct Vector2D {
        T x;
        T y;

        Vector2D(const T &x, const T &y) : x(x), y(y) {}

        bool operator==(const Vector2D& other) {
            return x==other.x && y==other.y;
        }
        bool operator!=(const Vector2D& other) {
            return !(*this==other);
        }

        Vector2D operator+(const Vector2D& other) {
            return Vector2D(x+other.x, y+other.y);
        }
        Vector2D operator-(const Vector2D& other) {
            return Vector2D(x-other.x, y-other.y);
        }
        Vector2D operator*(const double& num) {
            return Vector2D(x*num, y*num);
        }
        Vector2D& operator+=(const Vector2D& other) {
            *this = *this + other;
            return *this;
        }
    };
}
#endif