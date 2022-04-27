#include "Polynomial.h" //Polynomial 헤더파일을 구현하기위한 Polynomial.h 선언
#include <algorithm> //copy 함수를 사용하기 위한 algorithm헤더 선언
#include <iostream> //표준 입출력을 사용하기 위한 iostream 헤더 선언
#include <vector> //vector 클래스를 사용하기 위한 vector 헤더 선언
#include <math.h> //pow 함수를 사용하기 위한 math헤더 선언

void Polynomial::SameExp(int terms) {  //동류항이 있거나 동류항끼리 계산했을 때의 계수가 0이거나 입력받은 계수가 0인 원소들을 제외할 SameExp함수
	int* exp = new int[terms];		   //최종적으로 저장될 지수를 임시로 저장할 exp배열(일단 객체의 최대 크기만큼 할당)
	float* coef = new float[terms];	   //최종적으로 저장될 계수를 임시로 저장할 coef배열(일단 객체의 최대 크기만큼 할당)
	int a = 0, length = terms;		   //a는 0부터시작하여 exp배열과 coef배열의 인덱스에 접근할 변수 
									   //현재 객체의 최대크기를 담고있지만 최종적인 객체의 크기를 결정할 length변수
	for (int i = 0; i < terms; i++) {  //0부터 시작하여 객체의 마지막 항까지 반복
		int cnt = 0;				   //동류항의 개수를 셀 cnt변수를 선언하고 반복문이 시작할때마다 0으로 초기화
		for (int j = i + 1; j < terms; j++) {// j는 i보다 1인덱스 뒤에서 시작하여 객체의 마지막 항까지 반복 (j는 항상 i보다 1만큼 뒤에있음)
			if (termArray[i].exp == termArray[j].exp) { //i번째와 j번째의 지수가 같은지 판별
				termArray[i].coef += termArray[j].coef; //같다면 i번째 계수에 j번째 계수의 값을 중첩하여 더함
				cnt++;								    //동류항이 하나 나왔으므로 cnt 1증가
				length--;								//동류항 두개가 합해지면 결국 하나가 되는것이므로 원래 항의 최대 길이에서 1감소
			}
		}
		if (termArray[i].coef == 0) {		//i번째 원소의 계수가 0인지 확인
			length--;						//계수가 0이면 값이 0이므로 원래 항의 최대길이가 1 감소
			i += cnt;						//현재 내림차순 정렬이 되어있고 i와 i로부터 cnt개의 원소의 지수가 모두 같아서 동류항의 개수(cnt)만큼 i의 인덱스를 뒤로 밀어냄
			continue;						//계수가 0이면 exp와 coef에 저장하면 안되기때문에 continue로 루프 스킵
		}
		exp[a] = termArray[i].exp;			//exp에 최종으로 계산된 항의 지수를 대입
		coef[a++] = termArray[i].coef;		//coef에 최종으로 계산된 항의 계수를 대입하고 exp와 coef의 다음 원소에 입력받기 위해 a를 증가시킴
		i += cnt;							//현재 내림차순 정렬이 되어있고 i와 i로부터 cnt개의 원소의 지수가 모두 같아서 동류항의 개수(cnt)만큼 i의 인덱스를 뒤로 밀어냄
	}
	if (length == 0) {				  //length가 0인 경우 (동류항이 모두 소거되어서 항이 없는 경우)
		std::cout << "\n항 없음\n"; //이 다항식은 항이 없는 다항식임을 출력
	}
	delete[] termArray;				  //기존의 termArray를 삭제
	termArray = new Term[length];	  //최종적인 배열의 크기가 될 length의 크기만큼 Term형 termArray배열 재생성
	for (int i = 0; i < length; i++) {//최종적인 계수와 지수의 값이 들어가있는 coef와 exp배열의 원소를
		termArray[i].coef = coef[i];  //최종적인 계수값이 들어가있는 coef 원소들을 termArray배열의 coef에 복사
		termArray[i].exp = exp[i];	  //최종적인 지수값이 들어가있는 exp 원소들을 termArray배열의 exp에 복사
	}
	delete[] exp;					  //할당한 exp메모리 해제
	delete[] coef;					  //할당한 coef메모리 해제
	this->terms = length;			  //중복된 지수나 0인 항을 뺀 length가 최종적인 항의 개수가되므로 terms에 대입
	capacity = length;				  //배열의 크기는 곧 최종적인 항의 개수가 되므로 capacity에 대입
}

void Polynomial::SortPolynomial() {				 //호출한 다항식의 지수를 내림차순으로 정렬하는 SortPolynomial함수 (여기에선 삽입 정렬 알고리즘 사용)
	for (int i = 1; i < terms; i++) {			 //두번째 원소부터 시작하여 마지막 원소까지 반복
		int key = termArray[i].exp, j = i - 1;	 //두번째 원소를 처음key값으로 설정하고 j는 i보다 1앞의 인덱스로 설정
		float temp_c = termArray[i].coef;		 //해당 키 값(지수) 뿐만 아니라 계수도 옮겨야 하므로 계수를 임시로 저장할 변수 temp_c선언
		while (j >= 0 && key >= termArray[j].exp) {	   // j가 j이전의 원소들과 비교하며 key값보다 작거나 같으면
			termArray[j + 1].exp = termArray[j].exp;   //j번째 위치에 해당 자료를 삽입하기 위해 자료를 한칸씩 뒤로 이동시킨다.
			termArray[j + 1].coef = termArray[j].coef; //지수 뿐만아니라 계수도 바꿔줘야 하므로 계수도 한칸씩 뒤로 이동시킨다.
			j--;									   //j를 하나씩 감소시키며 처음 원소와 비교할때까지 반복한다
		}
		termArray[j + 1].exp = key;					   //지정된 위치에 key값(지수)을 삽입한다.
		termArray[j + 1].coef = temp_c;				   //마찬가지로 지정된 위치에 계수를 삽입한다.
	}
	this->SameExp(terms); //정렬된 다항식을 가지고 동류항이 있거나 동류항끼리 계산했을 때의 계수가 0이거나 입력받은 계수가 0인 경우를 처리할 함수호출
}

Polynomial::Polynomial() {			//객체를 생성할때 호출될 기본 생성자 (입력을 받는 생성자)
	float n = 0;					//입력받을 값을 저장할 float형 변수 n 선언
	capacity = 0;					//termArray의 크기를 아직 모르므로 0으로 초기화
	terms = 0;						//마찬가지로 항의 개수를 아직 모르므로 0으로 초기화
	std::vector<float> v;			//float 자료형을 저장할 수 있는 vector 형 가변배열 v 생성
	do {							//아래의 while 문이 거짓이 될때 까지 반복
		std::cin >> n;				//cin으로 n에 계수 또는 지수를 입력받음
		v.push_back(n);				//입력하는데로 v배열의 뒤에 삽입받는다.
		terms++;					//이때 항의 개수를 알기 위해 입력받는 수만큼 terms변수 증가
	} while (getc(stdin) == ' ');	//입력받는 문자의 사이가 공백인 동안 반복
	terms /= 2;						//입력받음 숫자 두개당(계수, 지수) 하나의 항이므로 절반으로 나누고 다시 대입
	termArray = new Term[terms];	//항의 개수만큼 저장가능한 Term형 배열을 termArray에 할당
	for (int i = 0; i < terms; i++) { //0부터 시작하여 항의 개수만큼 반복한다.
		termArray[i].coef = v[capacity++]; //v배열에 저장되있는 원소를 초기값이 0인capctiy를 증가하며 짝수번째인 원소는 계수에, 홀수번째인 원소는 지수에 저장
		termArray[i].exp = (int)v[capacity++]; //지수는 정수 형태로 캐스팅하여 저장
	}
	capacity /= 2;					//마찬가지로 capacity도 숫자 개수만큼 증가 시킨것이므로 절반으로 나누고 다시 대입
	this->SortPolynomial();			//입력받은 다항식이 정렬되지 않았으므로 SortPolynomial함수를 이용하여 정렬
}

Polynomial::Polynomial(int c, int t) { //빈 객체를 생성하기위한 생성자 오버로딩)
	termArray = new Term;			   //termArray에 Term한개를 저장할 수 있는 공간할당
	capacity = c;					   //termArray배열의 크기는 1이고 필요에 따라 NewTerm함수로 확장 
	terms = t;						   //현재 가지고있는 항의 개수는 0개
}

void Polynomial::NewTerm(const float Coeff, const int Exp) { //계수와 지수를 받아 빈 객체에 입력해줄 NewTerm함수 
	if (terms == capacity) {								 //항의 개수와 termArray배열의 크기가 같은경우(항이 추가될 자리가 없을 때)
		capacity *= 2;										 //capacity의 크기를 기존 termArray배열의 두배 만큼 증가(빈 객체의 경우 생성자를 통해 만들어진 capacity의 초기값은 1임)
		Term* temp = new Term[capacity];					 //임시 변수 temp에 늘린capacity크기 만큼의 Term형 배열을 생성
		std::copy(termArray, termArray + terms, temp);		 //copy 함수를 이용하여 증가된 temp 배열에 기존 termArray배열의 원소를 모두 복사
		delete[]termArray;									 //기존 termArray배열은 필요없으므로 매모리 해제
		termArray = temp;									 //termArray배열에 증가된 크기와 기존 원소를 갖고있는 temp대입
	}
	termArray[terms].coef = Coeff;							 //termArray에 공간이 남아있다면 계수 입력
	termArray[terms++].exp = Exp;							 //지수까지 입력받고 다음 원소에 입력에 받기위해 terms증가
}

Polynomial Polynomial::Add(Polynomial B) {							//다항식 A와 다항식 B를 더하고 더한 값을 저장한 다항식 C를 반환하는 Add함수
	Polynomial C(1, 0);												//생성자 오버로딩으로 A와 B를 덧셈한 결과를 저장할 빈 객체 C 생성
	int aPos = 0, bPos = 0;										    //다항식 A와 B에 처음부터 접근할 인덱스 변수 aPos, bPos
	while ((aPos < terms) && (bPos < B.terms)) {					//aPos와 bPos 둘다 끝까지 접근하지 않을때 실행
		if (termArray[aPos].exp == B.termArray[bPos].exp) {//두 항의 지수가 같으면(덧셈연산 가능)
			float t = termArray[aPos].coef + B.termArray[bPos].coef; //두 항의 계수를 더한값을 저장할 float형 변수 t를 선언하고 저장
			if (t) C.NewTerm(t, termArray[aPos].exp);		 //t가 0이 아니면 aPos위치(둘의 지수가 같기때문에 bPos도 관계없음)의 지수와 t를 NewTerm 함수로 C객체에 추가
			aPos++;										 //aPos 위치의 원소에 접근했으므로 다음 원소에 접근하기위해 증가
			bPos++;										 //bPos 위치의 원소에 접근했으므로 다음 원소에 접근하기위해 증가
		}
		else if (termArray[aPos].exp < B.termArray[bPos].exp) {		 //두 항중 B항의 지수가 더 크면
			C.NewTerm(B.termArray[bPos].coef, B.termArray[bPos].exp);//그 B항의 계수와 지수를 NewTerm 함수로 C 객체에 추가
			bPos++;													 //bPos 위치의 원소에만 접근했으므로 다음 원소에 접근하기위해 증가
		}
		else {														 //그 외의 경우(두 항중 A항의 지수가 더크면)
			C.NewTerm(termArray[aPos].coef, termArray[aPos].exp);	 //그 A항의 계수와 지수를 NewTerm 함수로 C 객체에 추가
			aPos++;													 //bPos 위치의 원소에만 접근했으므로 다음 원소에 접근하기위해 증가
		}
	}
	for (; aPos < terms; aPos++) {									 //while 문이 끝나고 aPos가 A.termArray의 마지막 요소까지 접근하지 못했으면
		C.NewTerm(termArray[aPos].coef, termArray[aPos].exp);		 //남은 A.termArray의 요소를 끝까지 접근하며 Newterm을 사용하여 C객체에 추가
	}
	for (; bPos < B.terms; bPos++) {								 //while 문이 끝나고 bPos가 B.termArray의 마지막 요소까지 접근하지 못했으면
		C.NewTerm(B.termArray[bPos].coef, B.termArray[bPos].exp);	 //남은 B.termArray의 요소를 끝까지 접근하며 Newterm을 사용하여 C객체에 추가
	}
	return C;														 //C객체 반환
}

void Polynomial::ShowPolynomial() {		//호출한 객체를 실제 다항식의 형태로 출력할 ShowPolynomial 함수
	for (int i = 0; i < terms; i++) {   //첫번째 원소부터 접근하여 마지막 원소 까지 반복
		if (i == 0) {										//첫번째 항에 한하여 +와 1, -1을 생략해주기 위한 조건
			if (termArray[0].exp == 0)						//첫번째 항의계수가 0보다 크거나 작고 지수가 0인경우 
				std::cout << termArray[0].coef;				//상수만 출력
			else if (termArray[0].exp == 1) {				//지수가 1인경우
				if (termArray[0].coef == 1)					//지수 1이면서 계수 1
					std::cout << "x";						//+제외한 x만 출력
				else if (termArray[0].coef == -1)			//지수 1이면서 계수-1
					std::cout << "-x";						//1제외한 -x만 출력
				else										//나머지 경우(지수 0이고 계수가 1보다 크거나 -1보다 작을떄
					std::cout << termArray[0].coef << "x";  //계수 x 형태로 출력
			}
			else if (termArray[0].exp > 1) {				//지수가 1 이상인 경우
				if (termArray[0].coef == 1)					//지수가 1일때 계수가 1
					std::cout << "x^" << termArray[0].exp;  //1 생락하고 x지수 형태 출력
				else if (termArray[0].coef == -1)			//지수가 1일때 계수가 -1
					std::cout << "-x^" << termArray[0].exp; //1 생략하고 -x지수 형태 출력
				else
					std::cout << termArray[0].coef << "x^" << termArray[0].exp; //나머지경우(지수가 1이상이고 계수가 1보다 크거나 -1보다 작을때)
			}
			continue;						 //첫번째 항은 출력했으니 continue를 사용하여 바로 다음항으로  넘어감
		}
		if (termArray[i].exp == 0) {//지수가 0일때 (계수만 출력)
			if (termArray[i].coef > 0)			//지수가 0이면서 계수 0보다클때
				std::cout << " + " << termArray[i].coef;//지수가 0이면 계수*1이므로 계수만 출력
			else								//그외(지수가 0이면서 계수는 0보다 작을때)
				std::cout << termArray[i].coef;			//지수가 0이면 계수*1이므로 계수만 출력
		}
		else if (termArray[i].exp == 1) {//지수 1일때 (x^1에서 ^1생략)
			if (termArray[i].coef > 1)				//지수 1이면서 계수 1보다클때
				std::cout << " + " << termArray[i].coef << "x"; //지수를 제외한 계수x 형태로 출력
			else if (termArray[i].coef == 1)		//지수 1이면서 계수 1일때
				std::cout << " + x";					//지수, 계수를 제외한 +x 형태로 출력
			else if (termArray[i].coef == -1)		//지수 1이면서 계수 -1일때
				std::cout << " - x";					//지수, 계수를 제외한 -x 형태로 출력
			else									//지수 1이면서 계수 -1보다 작을때
				std::cout << termArray[i].coef << "x";	//지수를 제외한 계수x 형태로 출력
		}
		else if (termArray[i].coef == -1) {//계수 -1이고 지수는 1보다 클때
			std::cout << " - x^" << termArray[i].exp; //1을 생략한 -x^지수 형태로 출력
		}
		else if (termArray[i].coef == 1) {//계수 +1이고 지수는 1보다 클때
			std::cout << " + x^" << termArray[i].exp; //1을 생략한 +x^지수 형태로 출력
		}
		else if (termArray[i].coef > 0) {//계수가 0보다크고 지수는 1보다 클때
			std::cout << " + " << termArray[i].coef << "x^" << termArray[i].exp; // +기호를 붙여 계수x^지수 형태로 출력
		}
		else {							//그외의 경우(계수는 0보다작고 지수는 1보다 클때)
			std::cout << " " << termArray[i].coef << "x^" << termArray[i].exp; //계수와 지수 전부 그대로 출력
		}
	}
	std::cout << "\n\n"; //줄바꿈
}

Polynomial Polynomial::Mul(Polynomial B) {			//A와 B 객체를 곱셈하여 새 객체를 리턴하는 Mul함수
	Polynomial C(1, 0);								//생성자 오버로딩으로 A와 B를 곱셈한 결과를 저장할 빈 객체 C 생성
	C.termArray = new Term[terms * B.terms];		//나올 수 있는 최대 항의 개수인 A의 항개수*B의 항개수의 길이를 가지는 termArray생성
	C.terms = terms * B.terms;						//마찬가지로 나올 수 있는 최대 항의 개수인 A의 항개수*B의 항개수의 크기를 가지는 terms 
	C.capacity = C.terms;							//termArray 배열 길이를 뜻하는 capacity의 크기는 항의 개수와 동일하므로 terms 대입
	int cPos = 0;									//C객체의 termArray의 인덱스를 가리킬 c_Pos변수 생성 (배열이므로 초기값은0)
	for (int i = 0; i < terms; i++) {				//A객체의 termArray의 첫번째 원소부터 마지막 원소까지 반복
		for (int j = 0; j < B.terms; j++) {			//B객체의 termArray의 첫번째 원소부터 마지막 원소까지 반복(A 객체의 모든 원소와 B 객체의 모든 원소를 대응하는 것임)
			C.termArray[cPos].coef = termArray[i].coef * B.termArray[j].coef; //A와 B의 계수끼리 곱셈 한것을 C객체 termArray의 coef변수에 저장
			C.termArray[cPos++].exp = termArray[i].exp + B.termArray[j].exp; //지수까지 계산하여 저장했으면 c_Pos를 증가시켜 C객체 termArray의 다음 인덱스로 이동
		}
	}
	C.SortPolynomial();					//SortPolynomial과 내장된 SameExp까지 실행하여 모든 원소를 내림차순으로 정렬하고 동류항 끼리 계산하며 계수가 0인 부분 삭제
	return C;							//C객체 반환
}

void Polynomial::Eval(Polynomial A, Polynomial B) { //값을 대입할 A,B,C 객체를 포함하여 호출
	float n, value = 0;							    //대입할 값을 입력받을 변수 n과 대입한 값을 저장할 value 변수 선언
	std::cout << "대입할 값 x 입력 : ";			    //대입할 값을 입력받음을 알림
	std::cin >> n;									//입력한 값을 n에 대입
	std::cout << "\n결과 : ";						//결과 출력을 알림
	for (int i = 0; i < A.terms; i++) {				//0부터 시작하여 A의 항의개수 만큼 반복
		value += (pow(n, A.termArray[i].exp) * A.termArray[i].coef); //pow 함수를 사용하여 각 항별로 대입된 값의 지수만큼 제곱*계수의 값을 value 변수에 누적하여 저장
	}
	std::cout << "A(" << n << ") = " << value; //다항식 A에 대입한 값을 출력
	value = 0;								   //다른 다항식에 대입되는 값을 저장하기 위해 value 변수 초기화
	for (int i = 0; i < B.terms; i++) {		   //0부터 시작하여 B의 항의개수 만큼 반복
		value += (pow(n, B.termArray[i].exp) * B.termArray[i].coef); //pow 함수를 사용하여 각 항별로 대입된 값의 지수만큼 제곱*계수의 값을 value 변수에 누적하여 저장
	}
	std::cout << ",  B(" << n << ") = " << value; //다항식 B에 대입한 값을 출력
	value = 0;									  //다른 다항식에 대입되는 값을 저장하기 위해 value 변수 초기화
	for (int i = 0; i < terms; i++) {			  //0부터 시작하여 C의 항의개수 만큼 반복
		value += (pow(n, termArray[i].exp) * termArray[i].coef); //pow 함수를 사용하여 각 항별로 대입된 값의 지수만큼 제곱*계수의 값을 value 변수에 누적하여 저장
	}
	std::cout << ",  C(" << n << ") = " << value << "\n\n"; //다항식 C에 대입한 값을 출력
}