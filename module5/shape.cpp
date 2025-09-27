#include <iostream>
#include <optional>

namespace Shapes{

	enum class Shape {CIRCLE = 0, SQUARE = 1, TRIANGLE = 2};
	void printShape(const Shape item);
	std::optional<Shape> getShape(const char* str);
	const char* toStr(Shape);

}

bool rawStrCMP(const char* str1, const char* str2) ///  I know about <cstring>  --  strcmp() function
{
	int i = 0;
	int k = 0;
	while(str1[i] != '\0' && str2[k] != '\0') 
	{
		if(str1[i] != str2[k])
			return false;
		++i;
		++k;
	}

	if(i == 0 || k == 0)
		return false;
	else if(str1[i] == '\0' && str2[k] != '\0')
		return false;
	else if(str2[k] == '\0' && str1[i] != '\0') 
		return false;
	else
		return true;
}

const char* Shapes::toStr(const Shapes::Shape shp)
{
	switch (shp)
	{
	case Shapes::Shape::CIRCLE:
		return "CIRCLE";
	case Shapes::Shape::SQUARE:
		return "SQUARE";
	case Shapes::Shape::TRIANGLE:
		return "TRIANGLE";
	default:
		return "Unknown_Shape";
	}

}

std::optional<Shapes::Shape> Shapes::getShape(const char* str)
{
	if(rawStrCMP(str, "CIRCLE"))
		return Shapes::Shape::CIRCLE;
	if(rawStrCMP(str, "SQUARE"))
		return Shapes::Shape::SQUARE;
	if(rawStrCMP(str, "TRIANGLE"))
		return Shapes::Shape::TRIANGLE;
	
	std::cout << "Unknown Shape entered" << std::endl;
	return std::nullopt;
}

void Shapes::printShape(const Shapes::Shape item)
{
	const char* shape = Shapes::toStr(item);
	switch (item){
	case Shapes::Shape::CIRCLE:
		std::cout << shape << std::endl;
		return;
	case Shapes::Shape::SQUARE:
		std::cout << shape << std::endl;
		return;
	case Shapes::Shape::TRIANGLE:
		std::cout << shape << std::endl;
		return;
	default:
		std::cout << shape << std::endl;
		return;
	}
}


int main()
{

	Shapes::Shape myShape1 = Shapes::Shape::TRIANGLE;
	Shapes::printShape(myShape1);
	
	char input[16];
	std::cout << "Please Enter the shape you want: CIRCLE, SQUARE, TRANGLE" << std::endl;
	std::cin >> input;

	auto myShape2 = Shapes::getShape(input);
	if(myShape2)
		Shapes::printShape(myShape2.value());

	return 0;
}

