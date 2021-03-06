/*
 * Copyright (c) 2008-2011 Travis Geiselbrecht
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef __VECTOR4_H
#define __VECTOR4_H

#include <ostream>
#include "Vec.h"

namespace Libvec {

class Vector4 {
public:
    inline Vector4() {}
    inline ~Vector4() {}

    Vector4(float x1, float y1, float z1, float w1);

    /* constructors */
    Vector4(const Vector4 &v);
    Vector4 &operator=(const Vector4 &v);

    /* accessors */
    float getx() const;
    float gety() const;
    float getz() const;
    float getw() const;

    /* operators */
    Vector4 operator+(const Vector4 &v) const;
    Vector4 &operator+=(const Vector4 &v);
    Vector4 operator-(const Vector4 &v) const;
    Vector4 &operator-=(const Vector4 &v);
    Vector4 operator*(const Vector4 &v) const;
    Vector4 &operator*=(const Vector4 &v);

    /* scalar ops */
    Vector4 operator*(float scalar) const;
    friend Vector4 operator*(float scalar, const Vector4 &v);
    Vector4 &operator*=(float scalar);
    Vector4 operator/(float scalar) const;
    Vector4 &operator/=(float scalar);

    /* common vector stuff */
    float Length() const;
    float LengthSquared() const;
    float Dot(const Vector4 &v) const;
    friend float Dot(const Vector4 &v1, const Vector4 &v2);
    void Normalize();
    void Normalize(float n);

    operator const float*() const { return &x; }

private:
    /* data */
    float x, y, z, w;
};

/* debugging */
std::ostream &operator<<(std::ostream &os, const Vector4 &v);

/* inline constructors */
inline Vector4::Vector4(float x1, float y1, float z1, float w1)
{
    x = x1;
    y = y1;
    z = z1;
    w = w1;
}

inline Vector4::Vector4(const Vector4 &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

inline Vector4 &Vector4::operator=(const Vector4 &v)
{
    if (this == &v)
        return *this;

    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
    return *this;
}

inline float Vector4::getx() const { return x; }
inline float Vector4::gety() const { return y; }
inline float Vector4::getz() const { return z; }
inline float Vector4::getw() const { return w; }

inline Vector4 Vector4::operator+(const Vector4 &v) const
{
    return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
}

inline Vector4 &Vector4::operator+=(const Vector4 &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}

inline Vector4 Vector4::operator-(const Vector4 &f) const
{
    return Vector4(x - f.x, y - f.y, z - f.z, w - f.w);
}


inline Vector4 &Vector4::operator-=(const Vector4 &f)
{
    x -= f.x;
    y -= f.y;
    z -= f.z;
    w -= f.w;
    return *this;
}

inline Vector4 Vector4::operator*(const Vector4 &f) const
{
    return Vector4(x * f.x, y * f.y, z * f.z, w * f.w);
}

inline Vector4 &Vector4::operator*=(const Vector4 &f)
{
    x *= f.x;
    y *= f.y;
    z *= f.z;
    w *= f.w;
    return *this;
}

inline Vector4 Vector4::operator*(float scalar) const
{
    return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
}

inline Vector4 operator*(float scalar, const Vector4 &v)
{
    return Vector4(v.x * scalar, v.y * scalar, v.z * scalar, v.w * scalar);
}

inline Vector4 &Vector4::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
    return *this;
}

inline Vector4 Vector4::operator/(float scalar) const
{
    return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
}

inline Vector4 &Vector4::operator/=(float scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    w /= scalar;
    return *this;
}

inline float Vector4::LengthSquared() const
{
    return (x*x + y*y + z*z + w*w);
}

inline float Vector4::Length() const
{
    return Math<float>::sqrt(x*x + y*y + z*z + w*w);
}

inline float Vector4::Dot(const Vector4 &v) const
{
    return (x*v.x + y*v.y + z*v.z + w*v.w);
}

inline float Dot(const Vector4 &v1, const Vector4 &v2)
{
    return (v1.x*v2.x + v1.y*v2.y + v1.z*v2.z + v1.w*v2.w);
}

}

#endif

