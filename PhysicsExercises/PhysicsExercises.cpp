// PhysicsExercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CVector.h"
#include <vector>
#include <sstream>

void LagrangeTest()
{
	std::vector<CVector::Vector3> Aexamples = {CVector::Vector3{1.0f, 2.0f, 3.0f}};
	std::vector<CVector::Vector3> Bexamples = {CVector::Vector3{2.0f, 3.0f, 1.0f}};
	std::vector<CVector::Vector3> Cexamples = {CVector::Vector3{3.0f, 1.0f, 2.0f}};

	if (Aexamples.size() != Bexamples.size() || Bexamples.size() != Cexamples.size())
	{
		std::cout << "Examples not the same size!" << std::endl;
		return;
	}

	for (int i = 0; i < Aexamples.size(); i++)
	{
		std::cout << "Vector A: " << CVector::Stringify(Aexamples[i]) << std::endl;
		std::cout << "Vector B: " << CVector::Stringify(Bexamples[i]) << std::endl;
		std::cout << "Vector C: " << CVector::Stringify(Cexamples[i]) << std::endl;

		std::cout << "Formula:  A x (B x C) = (A DOT C)B -(A DOT B)C" << std::endl;

		CVector::Vector3 lhs = CVector::CrossProduct(Aexamples[i], CVector::CrossProduct(Bexamples[i], Cexamples[i]));

		std::cout << "A x (B x C) = " << CVector::Stringify(lhs) << std::endl;

		CVector::Vector3 rhs = (Bexamples[i] * CVector::Dot(Aexamples[i], Cexamples[i])) - (Cexamples[i] * CVector::Dot(Aexamples[i], Bexamples[i]));

		std::cout << "(A DOT C)B -(A DOT B)C = " << CVector::Stringify(rhs) << std::endl;
	}
}

enum PlanePosition
{
	ON_PLANE,
	INFRONT,
	BEHIND,
};

PlanePosition PointPlaneTest()
{
	CVector::Vector3 planepos;
	CVector::Vector3 planenormal;
	CVector::Vector3 pointpos;
	std::string temp;
	std::cout << "Please enter plane position in format x y z" << std::endl;
	std::getline(std::cin, temp);
	std::stringstream stream(temp);
	stream >> planepos.x;
	stream >> planepos.y;
	stream >> planepos.z;

	std::cout << "Please enter plane normal in format x y z" << std::endl;
	temp = "";
	std::cin.clear();
	std::getline(std::cin, temp);
	std::stringstream sstream(temp);
	sstream >> planenormal.x;
	sstream >> planenormal.y;
	sstream >> planenormal.z;
	sstream.clear();
	std::cout << "Please enter point position in format x y z" << std::endl;
	temp = "";
	std::cin.clear();
	std::getline(std::cin, temp);
	std::stringstream ssstream(temp);
	stream << temp;
	ssstream >> pointpos.x;
	ssstream >> pointpos.y;
	ssstream >> pointpos.z;

	if (CVector::Dot(planepos - pointpos, planenormal) == 0)
	{
		std::cout << "ON_PLANE" << std::endl;
		return PlanePosition::ON_PLANE;
	}
	else if (CVector::Dot(planepos - pointpos, planenormal) > 0)
	{
		std::cout << "BEHIND" << std::endl;
		return PlanePosition::BEHIND;
	}
	else
	{
		std::cout << "INFRONT" << std::endl;
		return PlanePosition::INFRONT;
	}
}

int main()
{

	//LagrangeTest();
	PointPlaneTest();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
