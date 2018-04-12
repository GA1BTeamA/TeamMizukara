#pragma once
class LineCollision
{
public:
	LineCollision();
	~LineCollision();

private:
	float Dot(float ax, float ay, float bx, float by);  //“àÏ
	float Cross(float ax, float ay, float bx, float by);  //ŠOÏ
};