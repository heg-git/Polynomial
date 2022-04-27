#include "Polynomial.h"					//Polynomial 객체를 생성하고 멤버함수를 쓰기위해 Polynomial 헤더파일 선언
#include <iostream>						//표준 입출력을 사용하기 위한 iostream 헤더 선언
int main() {							//메인 함수 선언
	std::cout << "다항식 A입력: ";		//A 객체에 입력받음을 알림
	Polynomial A;						//생성자를 호출하고 A객체에 공백으로 계수, 지수를 구분하여 엔터입력 전까지 값 대입하고 정렬(정렬함수는 생성자에 내장)
	std::cout << "\n다항식 B입력: ";	//B 객체에 입력받음을 알림
	Polynomial B;					    //생성자를 호출하고 B객체에 공백으로 계수, 지수를 구분하여 엔터입력 전까지 값 대입하고 정렬(정렬함수는 생성자에 내장)

	std::cout << "\n입력한 식 A: ";     //입력받은 식을 출력함을 알림
	A.ShowPolynomial();					//ShowPolynomial 함수를 사용하여 정렬된 A 객체를 출력
	std::cout << "입력한 식 B: ";		//입력받은 식을 출력함을 알림
	B.ShowPolynomial();				    //ShowPolynomial 함수를 사용하여 정렬된 B 객체를 출력!

	Polynomial C = A.Mul(B);			//C 객체를 생성하고 A와 B 객체를 곱한 값을 대입하고 정렬(정렬함수는 생성자에 내장).
	std::cout << "A X B = ";			//A와 B의 곱셈한 값을 출력함을 알림
	C.ShowPolynomial();					// ShowPolynomial 함수를 사용하여 정렬된 C 객체를 출력
	C.Eval(A, B);						//Eval함수 안에서 값을 입력받고 A, B, C 에 대입하여 그 값을 각각 출력
}