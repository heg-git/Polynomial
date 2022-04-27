#pragma once
#include "Term.h" //Term.h 헤더파일 include
class Polynomial  //Polynomial 타입의 클래스 정의
{
private:	//외부에서 값을 수정하지 못하게 Private로 선언(캡슐화)
	Term* termArray; //계수와 지수의 값을 담은 배열을 가르킬 Term형 포인터 변수 termArray선언
	int capacity;	 //termArray의 배열 길이를 담을 변수 capacity 선언
	int terms;		 //termArray의 항의 개수를 담을 변수 terms 선언

public:
	Polynomial(); //기본 생성자 선언(입력받는 수를 저장할 객체를 생성할 생성자)
	Polynomial(int, int); //생성자 오버로딩(빈 객체를 생성할 생성자)
	Polynomial Add(Polynomial); //두 다항식을 더하고 더한 값을 저장한 객체를 반환할 함수
	Polynomial Mul(Polynomial); //두 다항식을 곱하고 곱한 값을 저장한 객체를 반환할 함수
	void SortPolynomial(); //호출한 객체의 지수의 내림차순으로 정렬할 함수
	void Eval(Polynomial, Polynomial); //입력받은 값을 A, B, C 의 객체에 대입하여 각각의 값을 출력할 함수 
	void NewTerm(const float, const int); //
	void ShowPolynomial(); //호출한 객체를 다항식 형태로 출력할 함수
	void SameExp(int); //내림차순으로 정렬된 객
};