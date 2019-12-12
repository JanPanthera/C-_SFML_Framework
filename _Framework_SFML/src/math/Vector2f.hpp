#pragma once

namespace jp
{
	class Vector2f
	{
	public:
		Vector2f();
		Vector2f(float p_X);
		Vector2f(float p_X, float p_Y);
		Vector2f(Vector2f const &p_OtherVec);
		Vector2f(Vector2f &&p_OtherVec) noexcept;
		~Vector2f();

	public:
		friend bool operator==(const Vector2f &p_Vec2f1, const Vector2f &p_Vec2f2);
		friend bool operator!=(const Vector2f &p_Vec2f1, const Vector2f &p_Vec2f2);
		Vector2f &operator=(Vector2f const &p_OtherVec2);
		Vector2f &operator+=(const Vector2f &p_OtherVec2);
		Vector2f operator+(const Vector2f &p_OtherVec2);
		Vector2f &operator-=(const Vector2f &p_OtherVec2);
		Vector2f operator-(const Vector2f &p_OtherVec2);
		Vector2f &operator*=(const Vector2f &p_OtherVec2);
		Vector2f operator*(const Vector2f &p_OtherVec2);
		Vector2f &operator/=(const Vector2f &p_OtherVec2);
		Vector2f operator/(const Vector2f &p_OtherVec2);

	public:
		void add(const Vector2f &p_OtherVec2);
		void subtract(const Vector2f &p_OtherVec2);
		void multiply(const Vector2f &p_OtherVec2);
		void divide(const Vector2f &p_OtherVec2);

		void set_X(float p_X);
		void set_Y(float p_Y);
		void set_Vec2(const Vector2f &p_OtherVec2);

	public:
		float get_X() const;
		float get_Y() const;
		Vector2f get_Vec2() const;

	private:
		float m_X;
		float m_Y;

	};
}