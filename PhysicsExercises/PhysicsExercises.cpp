// PhysicsExercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CVector.h"
#include <vector>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

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

PlanePosition PointPlaneTest(CVector::Vector3 _planepos, CVector::Vector3 _planenormal, CVector::Vector3 _pointpos)
{

	if (CVector::Dot(_planepos - _pointpos, _planenormal) == 0)
	{
		std::cout << "ON_PLANE" << std::endl;
		return PlanePosition::ON_PLANE;
	}
	else if (CVector::Dot(_planepos - _pointpos, _planenormal) > 0)
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

CVector::Vector3 InputVector3(std::string _prompttext)
{
	CVector::Vector3 output;
	std::cout << _prompttext << "[In format x y z (seperated by spaces)]:" << std::endl;
	std::string temp;
	std::cin.clear();
	std::getline(std::cin, temp);
	std::stringstream stream(temp);
	stream >> output.x;
	stream >> output.y;
	stream >> output.z;
	return output;
}

bool LinePlaneTest()
{
	CVector::Vector3 planepos;
	CVector::Vector3 planenormal;
	CVector::Vector3 firstpointpos;
	CVector::Vector3 secondpointpos;
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
	std::cout << "Please enter first point position of line in format x y z" << std::endl;
	temp = "";
	std::cin.clear();
	std::getline(std::cin, temp);
	std::stringstream ssstream(temp);
	stream << temp;
	ssstream >> firstpointpos.x;
	ssstream >> firstpointpos.y;
	ssstream >> firstpointpos.z;
	std::cout << "Please enter first point position of line in format x y z" << std::endl;
	temp = "";
	std::cin.clear();
	std::getline(std::cin, temp);
	std::stringstream sssstream(temp);
	stream << temp;
	sssstream >> secondpointpos.x;
	sssstream >> secondpointpos.y;
	sssstream >> secondpointpos.z;

	CVector::Vector3 line = firstpointpos - secondpointpos;

	float d = CVector::Dot((planepos - firstpointpos), planenormal) / CVector::Dot(line, planenormal);

	if (!CVector::Dot(planenormal, line))
	{
		return false;
	}

	CVector::Vector3 p = firstpointpos + (line * d);

	float x = CVector::Dot(secondpointpos - firstpointpos, p - firstpointpos);

	if (x > 0 && x < (CVector::Magnitude(line) * CVector::Magnitude(line)))
	{
		return true;
	}

	return false;
}

bool LinePlaneTest(CVector::Vector3 _planepos, CVector::Vector3 _planenormal, CVector::Vector3 _firstpointpos, CVector::Vector3 _secondpointpos)
{

	CVector::Vector3 line = _firstpointpos - _secondpointpos;

	float d = CVector::Dot((_planepos - _firstpointpos), _planenormal) / CVector::Dot(line, _planenormal);

	if (!CVector::Dot(_planenormal, line))
	{
		return false;
	}

	CVector::Vector3 p = _firstpointpos + (line * d);

	float x = CVector::Dot(_secondpointpos - _firstpointpos, p - _firstpointpos);

	if (x > 0 && x < (CVector::Magnitude(line) * CVector::Magnitude(line)))
	{
		return true;
	}

	return false;
}

bool TriPlaneTest(CVector::Vector3 _planepos, CVector::Vector3 _planenormal, CVector::Vector3 _firstpointpos, CVector::Vector3 _secondpointpos, CVector::Vector3 _thirdpointpos)
{
	bool intersects = (!LinePlaneTest(_planepos, _planenormal, _firstpointpos, _secondpointpos) && !LinePlaneTest(_planepos, _planenormal, _firstpointpos, _thirdpointpos) && !LinePlaneTest(_planepos, _planenormal, _thirdpointpos, _secondpointpos));
	return intersects;
}

sf::VertexArray MakeTriangle(sf::Vector2f PointA, sf::Vector2f PointB, sf::Vector2f PointC, sf::Color Color)
{
	// create an array of 3 vertices that define a triangle primitive
	sf::VertexArray triangle(sf::Triangles, 3);

	// define the position of the triangle's points
	triangle[0].position = PointA;
	triangle[1].position = PointB;
	triangle[2].position = PointC;

	// define the color of the triangle's points
	triangle[0].color = Color;
	triangle[1].color = Color;
	triangle[2].color = Color;

	return triangle;
}

enum PlacementState
{
	NONE,
	PLACINGTRI,
	PLACINGLINE
};

void TriCutter()
{
	//window
	sf::RenderWindow window(sf::VideoMode(960, 1080), "Nerys Thamm Triangle Cutter");
	window.setFramerateLimit(60);

	std::vector<sf::VertexArray> Triangles;
	std::vector<sf::Vector2i> ClickBuffer;

	while (window.isOpen())
	{

		window.clear();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				ClickBuffer.push_back(sf::Mouse::getPosition());
				if (ClickBuffer.size() == 3 && Triangles.size() == 0)
				{
					Triangles.push_back(MakeTriangle((sf::Vector2f)ClickBuffer[0], (sf::Vector2f)ClickBuffer[1], (sf::Vector2f)ClickBuffer[2], sf::Color::Red));
					ClickBuffer.clear();
				}
				else if (Triangles.size() > 0 && ClickBuffer.size() == 2)
				{
					ClickBuffer.clear();
				}
				else if (ClickBuffer.size() > 2)
				{
					ClickBuffer.clear();
				}

				break;

			default:
				break;
			}
		}
		window.clear();
		for (int i = 0; i < Triangles.size(); i++)
		{
			window.draw(Triangles[i]);
		}

		window.display();
	}

	return;
}

int main()
{
	bool running = true;
	do
	{
#if _WIN32 || _WIN64
		system("cls");
#else
		system("clear");
#endif

		std::string input;
		std::cout << "Please input the Exercise number you would like to run\nAvailable Exercises are:\n[001.1] [001.2] [001.3] [001.4] [001.5]\nOr input [exit] to Close the program:" << std::endl;
		std::cin >> input;
		if (input == "exit")
		{
			running = false;
			break;
		}
		else if (input == "001.1")
		{
			LagrangeTest();
		}
		else if (input == "001.2")
		{
		}
		else if (input == "001.3")
		{
		}
		else if (input == "001.4")
		{
			bool result = TriPlaneTest(InputVector3("Plane Position"), InputVector3("Plane Normal"), InputVector3("First point position"), InputVector3("Second point position"), InputVector3("Third point position"));
			std::cout << (result ? "The Triangle intersects the plane" : "The Triangle does not intersect the plane") << std::endl;
		}
		else if (input == "001.5")
		{
			TriCutter();
		}
		else
		{
			std::cout << "Invalid input, please try again!" << std::endl;
		}
		std::cout << "Input anything to continue..." << std::endl;
		std::string temp;
		std::cin >> temp;

	} while (running);

	//LagrangeTest();
	//PointPlaneTest();
	//std::cout << std::endl
	//		  << LinePlaneTest();
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
