#pragma once
class LineCollision
{
public:
	LineCollision();
	~LineCollision();

private:
	float Dot(float ax, float ay, float bx, float by);  //����
	float Cross(float ax, float ay, float bx, float by);  //�O��
};