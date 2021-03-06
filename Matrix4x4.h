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
#ifndef __MATRIX4X4_H
#define __MATRIX4X4_H

#include <iostream>

#include "Vector3.h"

namespace Libvec {

class Vector4;

class Matrix4x4 {
public:
    Matrix4x4() {}
    Matrix4x4(const float[16]);

    /* constructors */
//  Matrix4x4(const Matrix4x4 &v);
//  Matrix4x4 &operator=(const Matrix4x4 &v);

    static const Matrix4x4 Identity;

    /* temp constructors */
    static Matrix4x4 GetScaling(const Vector3f &scale);
    static Matrix4x4 GetTranslation(const Vector3f &xlate);
    static Matrix4x4 GetRotationX(float angle);
    static Matrix4x4 GetRotationY(float angle);
    static Matrix4x4 GetRotationZ(float angle);

    /* accessors */
    float operator[](int idx) const;

    /* set the matrix to various ops */
    Matrix4x4 &SetIdentity();
    Matrix4x4 &SetScaling(const Vector3f &scale);
    Matrix4x4 &SetTranslation(const Vector3f &xlate);
    Matrix4x4 &SetRotationX(float angle);
    Matrix4x4 &SetRotationY(float angle);
    Matrix4x4 &SetRotationZ(float angle);
    Matrix4x4 &SetProjectionPerspective(float fovy, float aspect, float nearz, float farz);
    Matrix4x4 &SetProjectionOrtho(float left, float right, float bottom, float top, float nearz, float farz);

    void SetRow(int row, const Vector3f &v);
    void SetRow(int row, const Vector4 &v);
    void SetCol(int col, const Vector3f &v);
    void SetCol(int col, const Vector4 &v);

    /* operators */
    Matrix4x4 operator*(const Matrix4x4 &v) const;
    Matrix4x4 &operator*=(const Matrix4x4 &v);
    Vector4 operator*(const Vector4 &v) const;

    Matrix4x4 Inverse() const;

    Vector3f Transform(const Vector3f &point) const;

    operator const float*() const { return val; }

private:
    /* data */
    float val[16];
};

/* debugging */
std::ostream &operator<<(std::ostream &os, const Matrix4x4 &v);

/* inline bits */
inline float Matrix4x4::operator[](int idx) const
{
    return val[idx];
}

inline Matrix4x4 Matrix4x4::GetScaling(const Vector3f &scale)
{
    Matrix4x4 temp;
    temp.SetScaling(scale);
    return temp;
}

inline Matrix4x4 Matrix4x4::GetTranslation(const Vector3f &xlate)
{
    Matrix4x4 temp;
    temp.SetTranslation(xlate);
    return temp;
}

inline Matrix4x4 Matrix4x4::GetRotationX(float angle)
{
    Matrix4x4 temp;
    temp.SetRotationX(angle);
    return temp;
}

inline Matrix4x4 Matrix4x4::GetRotationY(float angle)
{
    Matrix4x4 temp;
    temp.SetRotationY(angle);
    return temp;
}

inline Matrix4x4 Matrix4x4::GetRotationZ(float angle)
{
    Matrix4x4 temp;
    temp.SetRotationZ(angle);
    return temp;
}

}

#endif

