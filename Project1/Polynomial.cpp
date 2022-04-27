#include "Polynomial.h" //Polynomial ��������� �����ϱ����� Polynomial.h ����
#include <algorithm> //copy �Լ��� ����ϱ� ���� algorithm��� ����
#include <iostream> //ǥ�� ������� ����ϱ� ���� iostream ��� ����
#include <vector> //vector Ŭ������ ����ϱ� ���� vector ��� ����
#include <math.h> //pow �Լ��� ����ϱ� ���� math��� ����

void Polynomial::SameExp(int terms) {  //�������� �ְų� �����׳��� ������� ���� ����� 0�̰ų� �Է¹��� ����� 0�� ���ҵ��� ������ SameExp�Լ�
	int* exp = new int[terms];		   //���������� ����� ������ �ӽ÷� ������ exp�迭(�ϴ� ��ü�� �ִ� ũ�⸸ŭ �Ҵ�)
	float* coef = new float[terms];	   //���������� ����� ����� �ӽ÷� ������ coef�迭(�ϴ� ��ü�� �ִ� ũ�⸸ŭ �Ҵ�)
	int a = 0, length = terms;		   //a�� 0���ͽ����Ͽ� exp�迭�� coef�迭�� �ε����� ������ ���� 
									   //���� ��ü�� �ִ�ũ�⸦ ��������� �������� ��ü�� ũ�⸦ ������ length����
	for (int i = 0; i < terms; i++) {  //0���� �����Ͽ� ��ü�� ������ �ױ��� �ݺ�
		int cnt = 0;				   //�������� ������ �� cnt������ �����ϰ� �ݺ����� �����Ҷ����� 0���� �ʱ�ȭ
		for (int j = i + 1; j < terms; j++) {// j�� i���� 1�ε��� �ڿ��� �����Ͽ� ��ü�� ������ �ױ��� �ݺ� (j�� �׻� i���� 1��ŭ �ڿ�����)
			if (termArray[i].exp == termArray[j].exp) { //i��°�� j��°�� ������ ������ �Ǻ�
				termArray[i].coef += termArray[j].coef; //���ٸ� i��° ����� j��° ����� ���� ��ø�Ͽ� ����
				cnt++;								    //�������� �ϳ� �������Ƿ� cnt 1����
				length--;								//������ �ΰ��� �������� �ᱹ �ϳ��� �Ǵ°��̹Ƿ� ���� ���� �ִ� ���̿��� 1����
			}
		}
		if (termArray[i].coef == 0) {		//i��° ������ ����� 0���� Ȯ��
			length--;						//����� 0�̸� ���� 0�̹Ƿ� ���� ���� �ִ���̰� 1 ����
			i += cnt;						//���� �������� ������ �Ǿ��ְ� i�� i�κ��� cnt���� ������ ������ ��� ���Ƽ� �������� ����(cnt)��ŭ i�� �ε����� �ڷ� �о
			continue;						//����� 0�̸� exp�� coef�� �����ϸ� �ȵǱ⶧���� continue�� ���� ��ŵ
		}
		exp[a] = termArray[i].exp;			//exp�� �������� ���� ���� ������ ����
		coef[a++] = termArray[i].coef;		//coef�� �������� ���� ���� ����� �����ϰ� exp�� coef�� ���� ���ҿ� �Է¹ޱ� ���� a�� ������Ŵ
		i += cnt;							//���� �������� ������ �Ǿ��ְ� i�� i�κ��� cnt���� ������ ������ ��� ���Ƽ� �������� ����(cnt)��ŭ i�� �ε����� �ڷ� �о
	}
	if (length == 0) {				  //length�� 0�� ��� (�������� ��� �ҰŵǾ ���� ���� ���)
		std::cout << "\n�� ����\n"; //�� ���׽��� ���� ���� ���׽����� ���
	}
	delete[] termArray;				  //������ termArray�� ����
	termArray = new Term[length];	  //�������� �迭�� ũ�Ⱑ �� length�� ũ�⸸ŭ Term�� termArray�迭 �����
	for (int i = 0; i < length; i++) {//�������� ����� ������ ���� ���ִ� coef�� exp�迭�� ���Ҹ�
		termArray[i].coef = coef[i];  //�������� ������� ���ִ� coef ���ҵ��� termArray�迭�� coef�� ����
		termArray[i].exp = exp[i];	  //�������� �������� ���ִ� exp ���ҵ��� termArray�迭�� exp�� ����
	}
	delete[] exp;					  //�Ҵ��� exp�޸� ����
	delete[] coef;					  //�Ҵ��� coef�޸� ����
	this->terms = length;			  //�ߺ��� ������ 0�� ���� �� length�� �������� ���� �������ǹǷ� terms�� ����
	capacity = length;				  //�迭�� ũ��� �� �������� ���� ������ �ǹǷ� capacity�� ����
}

void Polynomial::SortPolynomial() {				 //ȣ���� ���׽��� ������ ������������ �����ϴ� SortPolynomial�Լ� (���⿡�� ���� ���� �˰��� ���)
	for (int i = 1; i < terms; i++) {			 //�ι�° ���Һ��� �����Ͽ� ������ ���ұ��� �ݺ�
		int key = termArray[i].exp, j = i - 1;	 //�ι�° ���Ҹ� ó��key������ �����ϰ� j�� i���� 1���� �ε����� ����
		float temp_c = termArray[i].coef;		 //�ش� Ű ��(����) �Ӹ� �ƴ϶� ����� �Űܾ� �ϹǷ� ����� �ӽ÷� ������ ���� temp_c����
		while (j >= 0 && key >= termArray[j].exp) {	   // j�� j������ ���ҵ�� ���ϸ� key������ �۰ų� ������
			termArray[j + 1].exp = termArray[j].exp;   //j��° ��ġ�� �ش� �ڷḦ �����ϱ� ���� �ڷḦ ��ĭ�� �ڷ� �̵���Ų��.
			termArray[j + 1].coef = termArray[j].coef; //���� �Ӹ��ƴ϶� ����� �ٲ���� �ϹǷ� ����� ��ĭ�� �ڷ� �̵���Ų��.
			j--;									   //j�� �ϳ��� ���ҽ�Ű�� ó�� ���ҿ� ���Ҷ����� �ݺ��Ѵ�
		}
		termArray[j + 1].exp = key;					   //������ ��ġ�� key��(����)�� �����Ѵ�.
		termArray[j + 1].coef = temp_c;				   //���������� ������ ��ġ�� ����� �����Ѵ�.
	}
	this->SameExp(terms); //���ĵ� ���׽��� ������ �������� �ְų� �����׳��� ������� ���� ����� 0�̰ų� �Է¹��� ����� 0�� ��츦 ó���� �Լ�ȣ��
}

Polynomial::Polynomial() {			//��ü�� �����Ҷ� ȣ��� �⺻ ������ (�Է��� �޴� ������)
	float n = 0;					//�Է¹��� ���� ������ float�� ���� n ����
	capacity = 0;					//termArray�� ũ�⸦ ���� �𸣹Ƿ� 0���� �ʱ�ȭ
	terms = 0;						//���������� ���� ������ ���� �𸣹Ƿ� 0���� �ʱ�ȭ
	std::vector<float> v;			//float �ڷ����� ������ �� �ִ� vector �� �����迭 v ����
	do {							//�Ʒ��� while ���� ������ �ɶ� ���� �ݺ�
		std::cin >> n;				//cin���� n�� ��� �Ǵ� ������ �Է¹���
		v.push_back(n);				//�Է��ϴµ��� v�迭�� �ڿ� ���Թ޴´�.
		terms++;					//�̶� ���� ������ �˱� ���� �Է¹޴� ����ŭ terms���� ����
	} while (getc(stdin) == ' ');	//�Է¹޴� ������ ���̰� ������ ���� �ݺ�
	terms /= 2;						//�Է¹��� ���� �ΰ���(���, ����) �ϳ��� ���̹Ƿ� �������� ������ �ٽ� ����
	termArray = new Term[terms];	//���� ������ŭ ���尡���� Term�� �迭�� termArray�� �Ҵ�
	for (int i = 0; i < terms; i++) { //0���� �����Ͽ� ���� ������ŭ �ݺ��Ѵ�.
		termArray[i].coef = v[capacity++]; //v�迭�� ������ִ� ���Ҹ� �ʱⰪ�� 0��capctiy�� �����ϸ� ¦����°�� ���Ҵ� �����, Ȧ����°�� ���Ҵ� ������ ����
		termArray[i].exp = (int)v[capacity++]; //������ ���� ���·� ĳ�����Ͽ� ����
	}
	capacity /= 2;					//���������� capacity�� ���� ������ŭ ���� ��Ų���̹Ƿ� �������� ������ �ٽ� ����
	this->SortPolynomial();			//�Է¹��� ���׽��� ���ĵ��� �ʾ����Ƿ� SortPolynomial�Լ��� �̿��Ͽ� ����
}

Polynomial::Polynomial(int c, int t) { //�� ��ü�� �����ϱ����� ������ �����ε�)
	termArray = new Term;			   //termArray�� Term�Ѱ��� ������ �� �ִ� �����Ҵ�
	capacity = c;					   //termArray�迭�� ũ��� 1�̰� �ʿ信 ���� NewTerm�Լ��� Ȯ�� 
	terms = t;						   //���� �������ִ� ���� ������ 0��
}

void Polynomial::NewTerm(const float Coeff, const int Exp) { //����� ������ �޾� �� ��ü�� �Է����� NewTerm�Լ� 
	if (terms == capacity) {								 //���� ������ termArray�迭�� ũ�Ⱑ �������(���� �߰��� �ڸ��� ���� ��)
		capacity *= 2;										 //capacity�� ũ�⸦ ���� termArray�迭�� �ι� ��ŭ ����(�� ��ü�� ��� �����ڸ� ���� ������� capacity�� �ʱⰪ�� 1��)
		Term* temp = new Term[capacity];					 //�ӽ� ���� temp�� �ø�capacityũ�� ��ŭ�� Term�� �迭�� ����
		std::copy(termArray, termArray + terms, temp);		 //copy �Լ��� �̿��Ͽ� ������ temp �迭�� ���� termArray�迭�� ���Ҹ� ��� ����
		delete[]termArray;									 //���� termArray�迭�� �ʿ�����Ƿ� �Ÿ� ����
		termArray = temp;									 //termArray�迭�� ������ ũ��� ���� ���Ҹ� �����ִ� temp����
	}
	termArray[terms].coef = Coeff;							 //termArray�� ������ �����ִٸ� ��� �Է�
	termArray[terms++].exp = Exp;							 //�������� �Է¹ް� ���� ���ҿ� �Է¿� �ޱ����� terms����
}

Polynomial Polynomial::Add(Polynomial B) {							//���׽� A�� ���׽� B�� ���ϰ� ���� ���� ������ ���׽� C�� ��ȯ�ϴ� Add�Լ�
	Polynomial C(1, 0);												//������ �����ε����� A�� B�� ������ ����� ������ �� ��ü C ����
	int aPos = 0, bPos = 0;										    //���׽� A�� B�� ó������ ������ �ε��� ���� aPos, bPos
	while ((aPos < terms) && (bPos < B.terms)) {					//aPos�� bPos �Ѵ� ������ �������� ������ ����
		if (termArray[aPos].exp == B.termArray[bPos].exp) {//�� ���� ������ ������(�������� ����)
			float t = termArray[aPos].coef + B.termArray[bPos].coef; //�� ���� ����� ���Ѱ��� ������ float�� ���� t�� �����ϰ� ����
			if (t) C.NewTerm(t, termArray[aPos].exp);		 //t�� 0�� �ƴϸ� aPos��ġ(���� ������ ���⶧���� bPos�� �������)�� ������ t�� NewTerm �Լ��� C��ü�� �߰�
			aPos++;										 //aPos ��ġ�� ���ҿ� ���������Ƿ� ���� ���ҿ� �����ϱ����� ����
			bPos++;										 //bPos ��ġ�� ���ҿ� ���������Ƿ� ���� ���ҿ� �����ϱ����� ����
		}
		else if (termArray[aPos].exp < B.termArray[bPos].exp) {		 //�� ���� B���� ������ �� ũ��
			C.NewTerm(B.termArray[bPos].coef, B.termArray[bPos].exp);//�� B���� ����� ������ NewTerm �Լ��� C ��ü�� �߰�
			bPos++;													 //bPos ��ġ�� ���ҿ��� ���������Ƿ� ���� ���ҿ� �����ϱ����� ����
		}
		else {														 //�� ���� ���(�� ���� A���� ������ ��ũ��)
			C.NewTerm(termArray[aPos].coef, termArray[aPos].exp);	 //�� A���� ����� ������ NewTerm �Լ��� C ��ü�� �߰�
			aPos++;													 //bPos ��ġ�� ���ҿ��� ���������Ƿ� ���� ���ҿ� �����ϱ����� ����
		}
	}
	for (; aPos < terms; aPos++) {									 //while ���� ������ aPos�� A.termArray�� ������ ��ұ��� �������� ��������
		C.NewTerm(termArray[aPos].coef, termArray[aPos].exp);		 //���� A.termArray�� ��Ҹ� ������ �����ϸ� Newterm�� ����Ͽ� C��ü�� �߰�
	}
	for (; bPos < B.terms; bPos++) {								 //while ���� ������ bPos�� B.termArray�� ������ ��ұ��� �������� ��������
		C.NewTerm(B.termArray[bPos].coef, B.termArray[bPos].exp);	 //���� B.termArray�� ��Ҹ� ������ �����ϸ� Newterm�� ����Ͽ� C��ü�� �߰�
	}
	return C;														 //C��ü ��ȯ
}

void Polynomial::ShowPolynomial() {		//ȣ���� ��ü�� ���� ���׽��� ���·� ����� ShowPolynomial �Լ�
	for (int i = 0; i < terms; i++) {   //ù��° ���Һ��� �����Ͽ� ������ ���� ���� �ݺ�
		if (i == 0) {										//ù��° �׿� ���Ͽ� +�� 1, -1�� �������ֱ� ���� ����
			if (termArray[0].exp == 0)						//ù��° ���ǰ���� 0���� ũ�ų� �۰� ������ 0�ΰ�� 
				std::cout << termArray[0].coef;				//����� ���
			else if (termArray[0].exp == 1) {				//������ 1�ΰ��
				if (termArray[0].coef == 1)					//���� 1�̸鼭 ��� 1
					std::cout << "x";						//+������ x�� ���
				else if (termArray[0].coef == -1)			//���� 1�̸鼭 ���-1
					std::cout << "-x";						//1������ -x�� ���
				else										//������ ���(���� 0�̰� ����� 1���� ũ�ų� -1���� ������
					std::cout << termArray[0].coef << "x";  //��� x ���·� ���
			}
			else if (termArray[0].exp > 1) {				//������ 1 �̻��� ���
				if (termArray[0].coef == 1)					//������ 1�϶� ����� 1
					std::cout << "x^" << termArray[0].exp;  //1 �����ϰ� x���� ���� ���
				else if (termArray[0].coef == -1)			//������ 1�϶� ����� -1
					std::cout << "-x^" << termArray[0].exp; //1 �����ϰ� -x���� ���� ���
				else
					std::cout << termArray[0].coef << "x^" << termArray[0].exp; //���������(������ 1�̻��̰� ����� 1���� ũ�ų� -1���� ������)
			}
			continue;						 //ù��° ���� ��������� continue�� ����Ͽ� �ٷ� ����������  �Ѿ
		}
		if (termArray[i].exp == 0) {//������ 0�϶� (����� ���)
			if (termArray[i].coef > 0)			//������ 0�̸鼭 ��� 0����Ŭ��
				std::cout << " + " << termArray[i].coef;//������ 0�̸� ���*1�̹Ƿ� ����� ���
			else								//�׿�(������ 0�̸鼭 ����� 0���� ������)
				std::cout << termArray[i].coef;			//������ 0�̸� ���*1�̹Ƿ� ����� ���
		}
		else if (termArray[i].exp == 1) {//���� 1�϶� (x^1���� ^1����)
			if (termArray[i].coef > 1)				//���� 1�̸鼭 ��� 1����Ŭ��
				std::cout << " + " << termArray[i].coef << "x"; //������ ������ ���x ���·� ���
			else if (termArray[i].coef == 1)		//���� 1�̸鼭 ��� 1�϶�
				std::cout << " + x";					//����, ����� ������ +x ���·� ���
			else if (termArray[i].coef == -1)		//���� 1�̸鼭 ��� -1�϶�
				std::cout << " - x";					//����, ����� ������ -x ���·� ���
			else									//���� 1�̸鼭 ��� -1���� ������
				std::cout << termArray[i].coef << "x";	//������ ������ ���x ���·� ���
		}
		else if (termArray[i].coef == -1) {//��� -1�̰� ������ 1���� Ŭ��
			std::cout << " - x^" << termArray[i].exp; //1�� ������ -x^���� ���·� ���
		}
		else if (termArray[i].coef == 1) {//��� +1�̰� ������ 1���� Ŭ��
			std::cout << " + x^" << termArray[i].exp; //1�� ������ +x^���� ���·� ���
		}
		else if (termArray[i].coef > 0) {//����� 0����ũ�� ������ 1���� Ŭ��
			std::cout << " + " << termArray[i].coef << "x^" << termArray[i].exp; // +��ȣ�� �ٿ� ���x^���� ���·� ���
		}
		else {							//�׿��� ���(����� 0�����۰� ������ 1���� Ŭ��)
			std::cout << " " << termArray[i].coef << "x^" << termArray[i].exp; //����� ���� ���� �״�� ���
		}
	}
	std::cout << "\n\n"; //�ٹٲ�
}

Polynomial Polynomial::Mul(Polynomial B) {			//A�� B ��ü�� �����Ͽ� �� ��ü�� �����ϴ� Mul�Լ�
	Polynomial C(1, 0);								//������ �����ε����� A�� B�� ������ ����� ������ �� ��ü C ����
	C.termArray = new Term[terms * B.terms];		//���� �� �ִ� �ִ� ���� ������ A�� �װ���*B�� �װ����� ���̸� ������ termArray����
	C.terms = terms * B.terms;						//���������� ���� �� �ִ� �ִ� ���� ������ A�� �װ���*B�� �װ����� ũ�⸦ ������ terms 
	C.capacity = C.terms;							//termArray �迭 ���̸� ���ϴ� capacity�� ũ��� ���� ������ �����ϹǷ� terms ����
	int cPos = 0;									//C��ü�� termArray�� �ε����� ����ų c_Pos���� ���� (�迭�̹Ƿ� �ʱⰪ��0)
	for (int i = 0; i < terms; i++) {				//A��ü�� termArray�� ù��° ���Һ��� ������ ���ұ��� �ݺ�
		for (int j = 0; j < B.terms; j++) {			//B��ü�� termArray�� ù��° ���Һ��� ������ ���ұ��� �ݺ�(A ��ü�� ��� ���ҿ� B ��ü�� ��� ���Ҹ� �����ϴ� ����)
			C.termArray[cPos].coef = termArray[i].coef * B.termArray[j].coef; //A�� B�� ������� ���� �Ѱ��� C��ü termArray�� coef������ ����
			C.termArray[cPos++].exp = termArray[i].exp + B.termArray[j].exp; //�������� ����Ͽ� ���������� c_Pos�� �������� C��ü termArray�� ���� �ε����� �̵�
		}
	}
	C.SortPolynomial();					//SortPolynomial�� ����� SameExp���� �����Ͽ� ��� ���Ҹ� ������������ �����ϰ� ������ ���� ����ϸ� ����� 0�� �κ� ����
	return C;							//C��ü ��ȯ
}

void Polynomial::Eval(Polynomial A, Polynomial B) { //���� ������ A,B,C ��ü�� �����Ͽ� ȣ��
	float n, value = 0;							    //������ ���� �Է¹��� ���� n�� ������ ���� ������ value ���� ����
	std::cout << "������ �� x �Է� : ";			    //������ ���� �Է¹����� �˸�
	std::cin >> n;									//�Է��� ���� n�� ����
	std::cout << "\n��� : ";						//��� ����� �˸�
	for (int i = 0; i < A.terms; i++) {				//0���� �����Ͽ� A�� ���ǰ��� ��ŭ �ݺ�
		value += (pow(n, A.termArray[i].exp) * A.termArray[i].coef); //pow �Լ��� ����Ͽ� �� �׺��� ���Ե� ���� ������ŭ ����*����� ���� value ������ �����Ͽ� ����
	}
	std::cout << "A(" << n << ") = " << value; //���׽� A�� ������ ���� ���
	value = 0;								   //�ٸ� ���׽Ŀ� ���ԵǴ� ���� �����ϱ� ���� value ���� �ʱ�ȭ
	for (int i = 0; i < B.terms; i++) {		   //0���� �����Ͽ� B�� ���ǰ��� ��ŭ �ݺ�
		value += (pow(n, B.termArray[i].exp) * B.termArray[i].coef); //pow �Լ��� ����Ͽ� �� �׺��� ���Ե� ���� ������ŭ ����*����� ���� value ������ �����Ͽ� ����
	}
	std::cout << ",  B(" << n << ") = " << value; //���׽� B�� ������ ���� ���
	value = 0;									  //�ٸ� ���׽Ŀ� ���ԵǴ� ���� �����ϱ� ���� value ���� �ʱ�ȭ
	for (int i = 0; i < terms; i++) {			  //0���� �����Ͽ� C�� ���ǰ��� ��ŭ �ݺ�
		value += (pow(n, termArray[i].exp) * termArray[i].coef); //pow �Լ��� ����Ͽ� �� �׺��� ���Ե� ���� ������ŭ ����*����� ���� value ������ �����Ͽ� ����
	}
	std::cout << ",  C(" << n << ") = " << value << "\n\n"; //���׽� C�� ������ ���� ���
}