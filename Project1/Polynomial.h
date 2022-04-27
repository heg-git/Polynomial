#pragma once
#include "Term.h" //Term.h ������� include
class Polynomial  //Polynomial Ÿ���� Ŭ���� ����
{
private:	//�ܺο��� ���� �������� ���ϰ� Private�� ����(ĸ��ȭ)
	Term* termArray; //����� ������ ���� ���� �迭�� ����ų Term�� ������ ���� termArray����
	int capacity;	 //termArray�� �迭 ���̸� ���� ���� capacity ����
	int terms;		 //termArray�� ���� ������ ���� ���� terms ����

public:
	Polynomial(); //�⺻ ������ ����(�Է¹޴� ���� ������ ��ü�� ������ ������)
	Polynomial(int, int); //������ �����ε�(�� ��ü�� ������ ������)
	Polynomial Add(Polynomial); //�� ���׽��� ���ϰ� ���� ���� ������ ��ü�� ��ȯ�� �Լ�
	Polynomial Mul(Polynomial); //�� ���׽��� ���ϰ� ���� ���� ������ ��ü�� ��ȯ�� �Լ�
	void SortPolynomial(); //ȣ���� ��ü�� ������ ������������ ������ �Լ�
	void Eval(Polynomial, Polynomial); //�Է¹��� ���� A, B, C �� ��ü�� �����Ͽ� ������ ���� ����� �Լ� 
	void NewTerm(const float, const int); //
	void ShowPolynomial(); //ȣ���� ��ü�� ���׽� ���·� ����� �Լ�
	void SameExp(int); //������������ ���ĵ� ��
};