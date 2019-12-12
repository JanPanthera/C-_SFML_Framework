#include "Vector2f.hpp"

namespace jp
{

	Vector2f::Vector2f() :
		m_X(0.f),
		m_Y(0.f) //
	{
	}

	Vector2f::Vector2f(float p_X) :
		m_X(p_X),
		m_Y(p_X) //
	{
	}

	Vector2f::Vector2f(float p_X, float p_Y) :
		m_X(p_X),
		m_Y(p_Y) //
	{
	}

	Vector2f::Vector2f(Vector2f const &p_OtherVec) :
		m_X(p_OtherVec.get_X()),
		m_Y(p_OtherVec.get_Y()) //
	{
	}

	Vector2f::Vector2f(Vector2f &&p_OtherVec) noexcept :
		m_X(p_OtherVec.get_X()),
		m_Y(p_OtherVec.get_Y()) //
	{
		p_OtherVec.set_X(0.f);
		p_OtherVec.set_Y(0.f);
	}

	Vector2f::~Vector2f() {
	}

	// = operator
	Vector2f &Vector2f::operator=(Vector2f const &p_OtherVec2) {
		if (this != &p_OtherVec2)
		{
			this->m_X = p_OtherVec2.get_X();
			this->m_Y = p_OtherVec2.get_Y();
		}
		return *this;
	}

	// compairsion operator overloading
	bool operator==(const Vector2f &p_Vec2f1, const Vector2f &p_Vec2f2) {
		return (p_Vec2f1.get_X() == p_Vec2f2.get_X() and
				p_Vec2f1.get_Y() == p_Vec2f2.get_Y());
	}

	bool operator!=(const Vector2f &p_Vec2f1, const Vector2f &p_Vec2f2) {
		return !(p_Vec2f1.get_X() == p_Vec2f2.get_X() and
				 p_Vec2f1.get_Y() == p_Vec2f2.get_Y());
	}

	// addition
	void Vector2f::add(const Vector2f &p_OtherVec2) {
		m_X = m_X + p_OtherVec2.m_X;
		m_Y = m_Y + p_OtherVec2.m_Y;
	}

	Vector2f &Vector2f::operator+=(const Vector2f &p_OtherVec2) {
		add(p_OtherVec2);
		return *this;
	}

	Vector2f Vector2f::operator+(const Vector2f &p_OtherVec2) {
		return Vector2f(*this) += p_OtherVec2;
	}

	// subtraction
	void Vector2f::subtract(const Vector2f &p_OtherVec2) {
		m_X = m_X - p_OtherVec2.get_X();
		m_Y = m_Y - p_OtherVec2.get_Y();
	}

	Vector2f &Vector2f::operator-=(const Vector2f &p_OtherVec2) {
		subtract(p_OtherVec2);
		return *this;
	}

	Vector2f Vector2f::operator-(const Vector2f &p_OtherVec2) {
		return Vector2f(*this) -= p_OtherVec2;
	}

	// multiplication
	void Vector2f::multiply(const Vector2f &p_OtherVec2) {
		m_X = m_X * p_OtherVec2.get_X();
		m_Y = m_Y * p_OtherVec2.get_Y();
	}

	Vector2f &Vector2f::operator*=(const Vector2f &p_OtherVec2) {
		multiply(p_OtherVec2);
		return *this;
	}

	Vector2f Vector2f::operator*(const Vector2f &p_OtherVec2) {
		return Vector2f(*this) *= p_OtherVec2;
	}

	// division
	void Vector2f::divide(const Vector2f &p_OtherVec2) {
		m_X = m_X / p_OtherVec2.get_X();
		m_Y = m_Y / p_OtherVec2.get_Y();
	}

	Vector2f &Vector2f::operator/=(const Vector2f &p_OtherVec2) {
		divide(p_OtherVec2);
		return *this;
	}

	Vector2f Vector2f::operator/(const Vector2f &p_OtherVec2) {
		return Vector2f(*this) /= p_OtherVec2;
	}

	// Setter
	void Vector2f::set_X(float p_X) {
		m_X = p_X;
	}

	void Vector2f::set_Y(float p_Y) {
		m_Y = p_Y;
	}

	void Vector2f::set_Vec2(const Vector2f &p_OtherVec2) {
		m_X = p_OtherVec2.get_X();
		m_Y = p_OtherVec2.get_Y();
	}

	// Getter
	float Vector2f::get_X() const {
		return m_X;
	}

	float Vector2f::get_Y() const {
		return m_Y;
	}

	Vector2f Vector2f::get_Vec2() const {
		return *this;
	}



}