#pragma once
class Polynomial; //Polynomial ���漱��
class Term // Term Ÿ���� class ����
{
	friend Polynomial; //Polynomial Ŭ�������� ������ �����ϵ����ϱ����� friend�� ����
private:		   //Polynomial Ŭ������ �����ϰ� �ܺο��� �����͸� ������ �� ������ private ����(ĸ��ȭ)
	float coef;    //����� ������ ���� float�� coef���� ����
	int exp;       //������ ������ ���� int�� exp���� ����
};
