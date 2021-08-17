#include "CVector.h"

CVector::Vector3 CVector::Normalize(Vector3& _vec3)
{
	const double len = Magnitude(_vec3);
	_vec3 /= len;
	return _vec3;
}

float CVector::Dot(Vector3 _a, Vector3 _b)
{
	float product = 0;
	product += _a.x * _b.x;
	product += _a.y * _b.y;
	product += _a.z * _b.z;
	return product;
}

CVector::Vector3 CVector::CrossProduct(Vector3 _a, Vector3 _b)
{
	Vector3 product;
	product.x = _a.y * _b.z - _a.z * _b.y;
	product.y = _a.z * _b.x - _a.x * _b.z;
	product.z = _a.x * _b.y - _a.y * _b.x;
	return product;
}

float CVector::Magnitude(Vector3 _vec3)
{
	return sqrt((_vec3.x * _vec3.x) + (_vec3.y * _vec3.y) + (_vec3.z * _vec3.z));
}

std::string CVector::Stringify(Vector3 _vec3)
{
	std::string result = "";
	result += "(" + std::to_string(_vec3.x) + ", " + std::to_string(_vec3.y) + ", " + std::to_string(_vec3.z) + " )";
	return result;
}

double CVector::Angle(Vector3 _vec3)
{
	return atan(_vec3.y / _vec3.x) / (2 * 3.14f) * 360;
}

sf::Vector2f CVector::ToVector2f(Vector3 _vec3)
{
	return sf::Vector2f(_vec3.x, _vec3.y);
}

CVector::Vector3 CVector::ToVector3(sf::Vector2f _vec2f)
{
	return Vector3{_vec2f.x, _vec2f.y, 0.0f};
}


