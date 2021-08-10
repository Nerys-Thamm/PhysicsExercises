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

//-----------------------
// EX 001.1
//-----------------------
void LagrangeTest()
{
	//Example Vectors
	std::vector<CVector::Vector3> Aexamples = {
		CVector::Vector3{1.0f, 2.0f, 3.0f},
		CVector::Vector3{5.0f, 3.0f, 6.0f},
		CVector::Vector3{2.0f, 4.0f, 7.0f},
	};
	std::vector<CVector::Vector3> Bexamples = {
		CVector::Vector3{2.0f, 3.0f, 1.0f},
		CVector::Vector3{2.0f, 6.0f, 3.0f},
		CVector::Vector3{3.0f, 3.0f, 5.0f},
	};
	std::vector<CVector::Vector3> Cexamples = {
		CVector::Vector3{3.0f, 1.0f, 2.0f},
		CVector::Vector3{7.0f, 5.0f, 8.0f},
		CVector::Vector3{2.0f, 2.0f, 6.0f},
	};

	//Check that the provided examples are valid
	if (Aexamples.size() != Bexamples.size() || Bexamples.size() != Cexamples.size())
	{
		std::cout << "Examples not the same size!" << std::endl;
		return;
	}

	//For each provided set of Example vectors
	for (int i = 0; i < Aexamples.size(); i++)
	{
		//Print the vectors
		std::cout << "Vector A: " << CVector::Stringify(Aexamples[i]) << std::endl;
		std::cout << "Vector B: " << CVector::Stringify(Bexamples[i]) << std::endl;
		std::cout << "Vector C: " << CVector::Stringify(Cexamples[i]) << std::endl;

		//Print the formula
		std::cout << "Formula:  A x (B x C) = (A DOT C)B -(A DOT B)C" << std::endl;

		//Calculate the left hand side
		CVector::Vector3 lhs = CVector::CrossProduct(Aexamples[i], CVector::CrossProduct(Bexamples[i], Cexamples[i]));

		//Print the left hand side
		std::cout << "A x (B x C) = " << CVector::Stringify(lhs) << std::endl;

		//Calculate the right hand side
		CVector::Vector3 rhs = (Bexamples[i] * CVector::Dot(Aexamples[i], Cexamples[i])) - (Cexamples[i] * CVector::Dot(Aexamples[i], Bexamples[i]));

		//Print the right hand side
		std::cout << "(A DOT C)B -(A DOT B)C = " << CVector::Stringify(rhs) << std::endl
				  << std::endl
				  << std::endl;
	}
}

//-----------------------
// EX 001.2
//-----------------------

enum PlanePosition
{
	ON_PLANE,
	INFRONT,
	BEHIND,
};

PlanePosition PointPlaneTest(CVector::Vector3 _planepos, CVector::Vector3 _planenormal, CVector::Vector3 _pointpos)
{

	if (CVector::Dot(_planepos - _pointpos, _planenormal) == 0) //If the vector between the plane and point is the same direction as the plane normal its on the plane
	{
		std::cout << "ON_PLANE" << std::endl;
		return PlanePosition::ON_PLANE;
	}
	else if (CVector::Dot(_planepos - _pointpos, _planenormal) > 0) //If its greater than zero its behind the plane
	{
		std::cout << "BEHIND" << std::endl;
		return PlanePosition::BEHIND;
	}
	else //If its less than zero its in front of the plane
	{
		std::cout << "INFRONT" << std::endl;
		return PlanePosition::INFRONT;
	}
}

//Function for getting a Vector3 input from the console
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

//-----------------------
// EX 001.3
//-----------------------

bool LinePlaneTest(CVector::Vector3 _planepos, CVector::Vector3 _planenormal, CVector::Vector3 _firstpointpos, CVector::Vector3 _secondpointpos)
{

	CVector::Vector3 line = _firstpointpos - _secondpointpos;

	float d = CVector::Dot((_planepos - _firstpointpos), _planenormal) / CVector::Dot(line, _planenormal);

	if (!CVector::Dot(_planenormal, line)) //If the line runs parallel to the plane do not collide
	{
		return false;
	}

	CVector::Vector3 p = _firstpointpos + (line * d);

	float x = CVector::Dot(_secondpointpos - _firstpointpos, p - _firstpointpos);

	if (x > 0 && x < (CVector::Magnitude(line) * CVector::Magnitude(line))) //If the collision is within the line segment
	{
		return true;
	}

	return false;
}

//Overload func that also provides a reference parameter which it populates with the collision position
bool LinePlaneTest(CVector::Vector3 _planepos, CVector::Vector3 _planenormal, CVector::Vector3 _firstpointpos, CVector::Vector3 _secondpointpos, CVector::Vector3 &_OUTpointofintersection)
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
		_OUTpointofintersection = _firstpointpos + line * d; //output the point where the intersection occurs to the reference param
		return true;
	}

	return false;
}

//-----------------------
// EX 001.4
//-----------------------

bool TriPlaneTest(CVector::Vector3 _planepos, CVector::Vector3 _planenormal, CVector::Vector3 _firstpointpos, CVector::Vector3 _secondpointpos, CVector::Vector3 _thirdpointpos)
{
	//Does a line intersection test for each line in the triangle
	bool intersects = (LinePlaneTest(_planepos, _planenormal, _firstpointpos, _secondpointpos) || LinePlaneTest(_planepos, _planenormal, _firstpointpos, _thirdpointpos) || LinePlaneTest(_planepos, _planenormal, _thirdpointpos, _secondpointpos));
	return intersects;
}

//-----------------------
// EX 001.5
//-----------------------

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

//OBSOLETE: I originally tried to split the triangle into a tri and a quad then split the quad, which was not a good way of doing it.
void SplitQuad(sf::VertexArray _quad, sf::VertexArray &_triA, sf::VertexArray &_triB)
{
	if (_quad.getVertexCount() != 4)
	{
		return;
	}
	_triA[0] = _quad[3];
	_triA[1] = _quad[0];
	_triA[2] = _quad[1];

	_triB[0] = _quad[3];
	_triB[1] = _quad[1];
	_triB[2] = _quad[2];
	return;
}

enum PlacementState
{
	NONE,
	PLACINGTRI,
	PLACINGLINE
};

//Converts SFML vectors to CVector3 to check line/line collisions
bool IsLineCollidingWithLine(sf::Vector2f _originA, sf::Vector2f _endA, sf::Vector2f _originB, sf::Vector2f _endB)
{
	CVector::Vector3 planenormal, planeposition, lineorigin, lineend;
	lineorigin.x = _originB.x;
	lineorigin.y = _originB.y;
	lineend.x = _endB.x;
	lineend.y = _endB.y;

	sf::Vector2f line = _endA - _originA;
	CVector::Vector3 convertedline;
	convertedline.x = line.x;
	convertedline.y = line.y;

	CVector::Vector3 znormal;
	znormal.z = 1.f;

	planeposition.x = _originA.x;
	planeposition.y = _originA.y;

	planenormal = CVector::CrossProduct(convertedline, znormal);

	return LinePlaneTest(planeposition, planenormal, lineorigin, lineend);
}

//Converts SFML vectors to CVector3 to check line/line collisions | OVERRIDE: provides reference parameter it populates with the collision point
bool IsLineCollidingWithLine(sf::Vector2f _originA, sf::Vector2f _endA, sf::Vector2f _originB, sf::Vector2f _endB, sf::Vector2f &_OUTpointofintersection)
{
	CVector::Vector3 planenormal, planeposition, lineorigin, lineend;
	lineorigin.x = _originB.x;
	lineorigin.y = _originB.y;
	lineend.x = _endB.x;
	lineend.y = _endB.y;

	sf::Vector2f line = _endA - _originA;
	CVector::Vector3 convertedline;
	convertedline.x = line.x;
	convertedline.y = line.y;

	CVector::Vector3 znormal;
	znormal.z = 1.f;

	planeposition.x = _originA.x;
	planeposition.y = _originA.y;

	planenormal = CVector::CrossProduct(convertedline, znormal);

	CVector::Vector3 intersection;
	bool iscolliding = LinePlaneTest(planeposition, planenormal, lineorigin, lineend, intersection);
	_OUTpointofintersection.x = intersection.x;
	_OUTpointofintersection.y = intersection.y;
	return iscolliding;
}

//SFML graphical program
void TriCutter()
{
	//window
	sf::RenderWindow window(sf::VideoMode(300, 300), "Nerys Thamm Triangle Cutter", sf::Style::Titlebar);
	window.setFramerateLimit(60);

	std::vector<sf::VertexArray> Triangles; //Vector of all triangles
	sf::VertexArray CachedTri;				//Cached triangle to restore on key press
	std::vector<sf::Vector2i> ClickBuffer;	//Buffer of click input positions

	sf::Vertex line[3];

	//program loop
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
				ClickBuffer.push_back(sf::Mouse::getPosition(window)); //Add clicks to buffer
				if (ClickBuffer.size() == 3 && Triangles.size() == 0)  //Make a triangle if there isnt already one, and there have been three clicks
				{
					Triangles.push_back(MakeTriangle((sf::Vector2f)ClickBuffer[0], (sf::Vector2f)ClickBuffer[1], (sf::Vector2f)ClickBuffer[2], sf::Color::Red));
					CachedTri = Triangles[0];
					ClickBuffer.clear();
				}
				else if (Triangles.size() > 0 && ClickBuffer.size() == 2) //If a triangle exists, make a line and cut the triangle along it if there have been two clicks
				{

					bool ABhit = false, BChit = false, CAhit = false;
					sf::Vector2f ABintersect, BCintersect, CAintersect;

					//Check collisions with the sides of the triangle
					ABhit = IsLineCollidingWithLine(Triangles.front()[0].position, Triangles.front()[1].position, (sf::Vector2f)ClickBuffer[0], (sf::Vector2f)ClickBuffer[1], ABintersect);
					BChit = IsLineCollidingWithLine(Triangles.front()[1].position, Triangles.front()[2].position, (sf::Vector2f)ClickBuffer[0], (sf::Vector2f)ClickBuffer[1], BCintersect);
					CAhit = IsLineCollidingWithLine(Triangles.front()[2].position, Triangles.front()[0].position, (sf::Vector2f)ClickBuffer[0], (sf::Vector2f)ClickBuffer[1], CAintersect);

					//Slice the triangle into three new ones
					if (ABhit && CAhit)
					{
						sf::VertexArray triA, triB, triC;

						triA = MakeTriangle(Triangles.front()[0].position, ABintersect, CAintersect, sf::Color::Green);

						triB = MakeTriangle(Triangles.front()[1].position, ABintersect, CAintersect, sf::Color::Blue);

						triC = MakeTriangle(Triangles.front()[1].position, Triangles.front()[2].position, CAintersect, sf::Color::Yellow);

						Triangles.push_back(triA);
						Triangles.push_back(triB);
						Triangles.push_back(triC);
					}
					else if (BChit && CAhit)
					{
						sf::VertexArray triA, triB, triC;

						triA = MakeTriangle(Triangles.front()[2].position, BCintersect, CAintersect, sf::Color::Green);

						triB = MakeTriangle(Triangles.front()[1].position, BCintersect, CAintersect, sf::Color::Blue);

						triC = MakeTriangle(Triangles.front()[0].position, Triangles.front()[1].position, CAintersect, sf::Color::Yellow);

						Triangles.push_back(triA);
						Triangles.push_back(triB);
						Triangles.push_back(triC);
					}
					else if (BChit && ABhit)
					{
						sf::VertexArray triA, triB, triC;

						triA = MakeTriangle(Triangles.front()[1].position, BCintersect, ABintersect, sf::Color::Green);

						triB = MakeTriangle(Triangles.front()[2].position, BCintersect, ABintersect, sf::Color::Blue);

						triC = MakeTriangle(Triangles.front()[2].position, Triangles.front()[0].position, ABintersect, sf::Color::Yellow);

						Triangles.push_back(triA);
						Triangles.push_back(triB);
						Triangles.push_back(triC);
					}

					ClickBuffer.clear();
				}
				else if (ClickBuffer.size() > 2) //Clear the buffer if nothing can be done
				{
					ClickBuffer.clear();
				}

				break;
			case sf::Event::KeyPressed:

				switch (event.key.code)
				{
				case sf::Keyboard::T:
					Triangles.clear();
					break;

				case sf::Keyboard::L:

					Triangles.clear();
					if (CachedTri.getVertexCount() == 3)
					{
						Triangles.push_back(CachedTri);
					}

					break;

				default:
					window.close();
					break;
				}
			default:
				break;
			}
		}
		//RENDER
		window.clear();

		for (int i = 0; i < Triangles.size(); i++)
		{
			window.draw(Triangles[i]);
		}

		if (ClickBuffer.size() == 1)
		{
			line[0].position = (sf::Vector2f)ClickBuffer[0];
			line[1].position = (sf::Vector2f)sf::Mouse::getPosition(window);
			line[2].position = (sf::Vector2f)sf::Mouse::getPosition(window);
			window.draw(line, 2, sf::Lines);
		}
		else if (ClickBuffer.size() >= 2)
		{
			line[0].position = (sf::Vector2f)ClickBuffer[0];
			line[1].position = (sf::Vector2f)ClickBuffer[1];
			line[2].position = (sf::Vector2f)sf::Mouse::getPosition(window);
			window.draw(line, 3, sf::LineStrip);
		}

		window.display();
	}

	return;
}

//-----------------------
//Main loop, has Menu
//-----------------------
int main()
{
	bool running = true;
	do
	{
		//Clear the console window using a different command based on Platform compiled for. This allows for cross-platform use.
#if _WIN32 || _WIN64
		system("cls");
#else
		system("clear");
#endif

		std::string input;
		std::cout << "Please input the Exercise number you would like to run\nAvailable Exercises are:\n[001.1] [001.2] [001.3] [001.4] [001.5]\nOr input [exit] to Close the program:" << std::endl;
		std::cin >> input;
		std::cin.ignore();
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
			PlanePosition p = PointPlaneTest(InputVector3("Plane Position"), InputVector3("Plane Normal"), InputVector3("Point Position"));
		}
		else if (input == "001.3")
		{
			bool result = LinePlaneTest(InputVector3("Plane Position"), InputVector3("Plane Normal"), InputVector3("First point position"), InputVector3("Second point position"));
			std::cout << (result ? "The Line intersects the plane" : "The Line does not intersect the plane") << std::endl;
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
}
