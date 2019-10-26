#pragma once
#include <math.h>

///
///
/// Vector3クラス
///
///

class Vector3 {
public:
	float x, y, z;

// コンストラクタ
	Vector3() {}

	Vector3(const Vector3 &a) : x(a.x), y(a.y), z(a.z) {}

	Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

// オブジェクトの保守

	// 代入
	Vector3 &operator = (const Vector3 &a) {
		x = a.x;
		y = a.y;
		z = a.z;
		return *this;
	}

	//イコール
	bool operator ==(const Vector3 &a) const {
		return x == a.x && y == a.y && z == a.z;
	}

	bool operator !=(const Vector3 &a) const {
		return x != a.x || y != a.y || z != a.z;
	}

// ベクトル操作

	// 0ベクトルにする
	void zero() { x = y = z = 0.0f; }

	// 単項式の場合、反転する
	Vector3 operator -() const { return Vector3(-x, -y, -z); }

	// ２講式の場合、加算・減算
	Vector3 operator +(const Vector3 &a) const {
		return Vector3(x + a.x, y + a.y , z + a.z);
	}

	Vector3 operator -(const Vector3 &a) const {
		return Vector3(x - a.x, y - a.y, z - a.z);
	}

	// スカラーの乗算、除算
	Vector3 operator *(float a) const {
		return Vector3(x*a, y*a, z*a);
	}

	Vector3 operator /(float a) const {
		if (a == 0)
			return Vector3(0, 0, 0);

		float oneOverA = 1.0f / a;
		return Vector3(x*oneOverA, y * oneOverA, z * oneOverA);
	}

	// 組み合わせ代入
	Vector3 &operator +=(const Vector3 &a) {
		x += a.x;
		y += a.y;
		z += a.z;
		return *this;
	}

	Vector3 &operator -=(const Vector3 &a) {
		x -= a.x;
		y -= a.y;
		z -= a.z;
		return *this;
	}

	Vector3 &operator *=(const float a) {
		x *= a;
		y *= a;
		z *= a;
		return *this;
	}

	Vector3 &operator /=(const float a) {
		if (a == 0)
			return Vector3(0,0,0);

		float oneOverA = 1.0f / a;
		x *= oneOverA;
		y *= oneOverA;
		z *= oneOverA;
		return *this;
	}

	// 正規化
	void normalize() {
		float magSq = x*x + y*y + z*z;
		if (magSq > 0.0f) {
			float oneOverMag = 1.0f / sqrt(magSq);
			x *= oneOverMag;
			y *= oneOverMag;
			z *= oneOverMag;
		}
	}

	// ベクトルの内積
	float operator *(const Vector3 &a) const {
		return x*a.x + y*a.y + z*a.z;
	}
};

///
/// 非メンバ関数
///

// ベクトルの大きさを計算する
inline float vectorMag(const Vector3 &a) {
	return sqrt(a.x*a.x + a.y *a.y + a.z * a.z);
}

// ベクトルの外積
inline Vector3 crossProduct(const Vector3 &a, const Vector3 &b) {
	return Vector3{
		a.y*b.z - a.z * b.y,
		b.z*b.x - a.x * b.z,
		a.x*b.y - a.y * b.x,
	};
}

// 対称性のため、左からのスカラー乗算
inline Vector3 operator *(float k, const Vector3 &v) {
	return Vector3(k*v.x, k*v.y, k*v.z);
}


// 2点の距離を計算
inline float distance(const Vector3 &a, const Vector3 &b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;

	return sqrt(dx*dx + dy*dy + dz*dz);
}


///
/// グローバル変数
///
extern const Vector3 kZeroVector;
