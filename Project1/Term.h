#pragma once
class Polynomial; //Polynomial 전방선언
class Term // Term 타입의 class 정의
{
	friend Polynomial; //Polynomial 클래스에서 접근이 가능하도록하기위해 friend로 선언
private:		   //Polynomial 클래스를 제외하고 외부에서 데이터를 수정할 수 없도록 private 선언(캡슐화)
	float coef;    //계수의 정보를 담을 float형 coef변수 선언
	int exp;       //지수의 정보를 담을 int형 exp변수 선언
};
