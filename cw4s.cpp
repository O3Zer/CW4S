#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include <string>
#include <limits>

using namespace std;
//Класс "Товар", содержащий номер магазина, название товара и его цену
class Product {
private:
	int num; //Номер магазина
	string prod; //Название продукта
	int price;  //Цена продукта
				//Функция копирования
	void Fill(int stnum, string stprod, int stprice) {
		num = stnum;
		prod = stprod;
		price = stprice;
	}

public:
	//Функция очистки элемента
	void Clear();
	~Product() {
		Clear();
	};
	//Перегрузка оператора "=", для копирования элемента
	Product &operator =  (const Product &Old) {
		Clear(); //Очистка элемента

		Fill(Old.num, Old.prod, Old.price); //Копирование элемента
		return *this;
	};
	//Конструктор без операторов, создающий пустой элемент
	Product() {
		num = 0;
		prod = "";
		price = 0;
	};
	//Конструктор заполнения
	Product(int a) : num(a) {
		cout << "Enter the name of the product:" << endl;
		getline(cin, prod); //Считывание названия продукта
		cout << "Enter the price of the product:" << endl;
		char char1[256]; //Объявление временной переменной типа char
		cin >> char1; //Считывание переменной типа char
		cin.clear(); //Очистка поля ввода
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Игнорирование лишних данных
		price = atoi(char1); //Преобразование к типу integer
		while (1) { //Бесконечный цикл
			if (price <= 0) //Если цена неотрицательна, повторяется ввод, пока она не будет удовлетворять условиям
			{
				cout << "Wrong price, enter again: " << endl;
				cin >> char1;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				price = atoi(char1);
			}
			else
				break;
		}
	}
	//Функция, возвращающая номер магазина
	int shop() {
		return num; //Возврат номера магазина
	}
	//Функция, проверяющая соответствие название товара
	bool tov(string h) { //Если получаемая строка равна названию товара возвращает true, иначе false
		if (h == prod)
		{
			return true;
		}
		else {
			return false;
		}
	}
	//Функция, возвращающая цену товара
	int pric() {
		return price; //Возврат цены товара
	}
	//Виртуальная функция вывода элемента на экран
	virtual void show() {
		cout << "The number of shop is:" << num << endl << "The name of product: " << prod << endl << "The price of product: " << price << endl << "-------------------------------------------------------------" << endl;;
	}
	//Функция проверки заполненности элемента
	bool check() {
		if (num == 1 || num == 2 || num == 3 || num == 4) //Проверка допустимых значений
		{
			if (price >= 0) //Если цена неотрицательна
			{
				if (prod != "") //Если название продукта не пустое
					return true; //Возврат true
				else
					return false; //Иначе false
			}
			else
				return false; //Иначе false
		}
		else
			return false; //Иначе false
	}
	//Функция изменения
	void chan() {
		char m[256]; //Временная переменная типа char
		int z; //Временная переменная
		cout << "=======================================================================" << endl; //Декоративная линия
		cout << "Choose the number of shop: " << endl << "1. Auchan" << endl << "2. Lenta" << endl << "3. Spar" << endl << "4. Karusel'" << endl; //Меню выбора номера магазина
		cin >> m; //Считывание переменной типа char
		cin.clear(); //Очистка потока ввода
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Игнорирование лишних данных
		z = atoi(m); //Преобразование полученных данных в тип integer
		cout << endl; //Перевод строки
		if (z == 1 || z == 2 || z == 3 || z == 4) //Проверка допустимых значений
		{
			num = z; //Запись номера магазина
			cout << "Enter the name of the product:" << endl;
			getline(cin, prod); //Запись названия продукта
			cout << "Enter the price of the product:" << endl;
			char char1[256]; //Объявление временной переменной типа char
			cin >> char1; //Считывание переменной типа char
			cin.clear(); //Очистка потока ввода
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Игнорирование лишних данных
			price = atoi(char1); //Присваивание цене значения типа integer
			while (1) { //Бесконечный цикл
				if (price <= 0) //Если цена неположительна, повторяется до "успеха"
				{
					cout << "Wrong price, enter again: " << endl;
					cin >> char1;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					price = atoi(char1);
				}
				else
					break;
			}
		}
		else
		{
			cout << "You've entered wrong data" << endl;
		}
	}
	//Функция возврата названия товара
	string names() {
		return prod;
	};
};
//Функция очистки элемента
void Product::Clear() {
	if (num != 0 && prod != "" && price != 0) { //Если какая-либо переменная не пуста, все обнуляется
		num = 0;
		prod = "";
		price = 0;
	}
};
//Структура, являющаяся элементом списка, содержит элемент класса "Товар"
struct Node
{
	Product x; //Элемент типа Product
	Node *Next, *Prev; //Начало и конец
};
//Класс список
class List
{
	Node *Head, *Tail; //Адреса начала и конца списка
public:
	int count = 0; //Счетчик элементов
	List() :Head(NULL), Tail(NULL) {}; //Конструктор, инициализирующий пустой список
	~List(); //Деструктор
	void Show(string h); //Функция поиска и вывода самой дешевой цены на продукт
	void Add(Product x); //Функия добавления элемента в список
	void ShowAll(); //Функция вывода всех элементов списка
	void Del(int k); //Функция удаления элемента из списка
	int found(); //Функция поиска элемента
	void change();//Функця изменения элемента
	bool again(Product x);//Функция поиска повторения
};
//Деструктор
List::~List()
{
	while (Head) //Пока список не пуст
	{
		Tail = Head->Next; //"Сдвиг"
		delete Head; //Удаление первого элемента
		Head = Tail; //Начало=Конец
	}
}
//Функция добавления нового элемента в список
void List::Add(Product x) {
	if (again(x)) //Проверка на наличие данного элемента в списке
	{
		cout << "This element is already created!" << endl; //Если да, пользователь оповещается об этом
		return;										//И происходит выход из функции
	}
	if (x.check()) { //Если добавляемый элемент не пустой
		Node *temp = new Node; //Временная переменная 
		temp->Next = NULL; //"Сдвиг" списка
		temp->x = x;      //Ввод элемента

		if (Head != NULL) { //Если список не пустой
			temp->Prev = Tail; //"Сдвиг конца списка
			Tail->Next = temp;
			Tail = temp;
		}
		else { //Создание первого элемента
			temp->Prev = NULL;
			Head = Tail = temp;
		}
		count++; //Увеличение переменной, содержащей количество элементов списка
	}
	else
	{
		cout << "This is wrong element, sorry" << endl;
		return;
	}
	return;
};
//Функция поиска и вывода самой дешевой цены на продукт
void List::Show(string h) {
	int min = 10000000; //Переменная с минимальной ценой
	int i = 10; // Номер магазина
	Node *temp = Tail; //Временная переменная с адресом конца списка
	while (temp != NULL) { //Пока не конец списка
		if (temp->x.tov(h)) //Если строка h равна строке prod из этого элемента списка
		{
			if (temp->x.pric() < min) { //Если цена меньше минимальной
				min = temp->x.pric(); //Минимальная равна этой цене
				i = temp->x.shop(); //Изменение номера магазина
			}
		};
		temp = temp->Prev; //"Переход" не предыдущий элемент
	}
	switch (i) //В зависимости от значения i выводятся наименовение товара, название магазина и сама минимальная цена
	{
	case 1:
		cout << "The cheapest price on " << h << " is in Auchan, the price is " << min << " rubles" << endl;
		break;
	case 2:
		cout << "The cheapest price on " << h << " is in Lenta, the price is " << min << " rubles" << endl;
		break;
	case 3:
		cout << "The cheapest price on " << h << " is in Spar, the price is " << min << " rubles" << endl;
		break;
	case 4:
		cout << "The cheapest price on " << h << " is in Karusel', the price is " << min << " rubles" << endl;
		break;
	default:
		cout << "Sorry, try again later";
		break;
	}
	cout << endl; //Перевод строки
}
//Функция показа всех элементов списка
void List::ShowAll() {
	Node *temp = Head; //Временная переменная, содержащая адрес первого элемента
	while (temp != NULL) { //Пока не конец списка
		temp->x.show(); //Вывод элемента на экран
		temp = temp->Next; //"Переход" на следующий элемент списка
	};

};
//Поиск повторения
bool List::again(Product y) {

	if (Head == NULL)//Проверка наличия элементов в списке
	{
		cout << "Done!" << endl;
	}
	else
	{
		Node *temp = Head; //Временная переменная с адресом первого элемента списка
		while (temp != NULL) { //Пока временная переменная не пуста, т.е. пока не конец списка
			if (temp->x.shop() == y.shop())  //Проверка соответствия номеру магазина
				if (temp->x.tov(y.names()))  //Проверка соответствия названия товара
					if (temp->x.pric() == y.pric()) //Проверка соответствия цены	
						return true;  //Если товар соответствует то возвращается true
			temp = temp->Next; //Переход на следующий элемент		
		}

	}
	return false; //Иначе false
};
//Поиск элемента
int List::found() {
	int t = 0; //В эту переменную внесется порядковый номер найденного элемента, и 0, если элемента нет
	if (Head == NULL)//Проверка наличия элементов в списке
	{
		cout << "Enter the elements firstly!" << endl;
	}
	else
	{
		//Временные переменные
		bool f = false;
		char st[256];
		int kl;
		cout << "Choose the number of shop: " << endl << "1. Auchan" << endl << "2. Lenta" << endl << "3. Spar" << endl << "4. Karusel'" << endl;
		cin >> st; //Считывание переменной типа char
		cin.clear(); //Очистка потока ввода
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Игнорирование лишних данных ввода
		kl = atoi(st); //Преобразование введенных данных к типу integer
		if (kl == 1 || kl == 2 || kl == 3 || kl == 4) { //Проверка на допустимые значения
			Node *temp = Head; //Временная переменная с адресом первого элемента списка
			while (temp != NULL) { //Пока временная переменная не пуста, т.е. пока не конец списка
				t++; //Увеличение порядкового номера
				if (temp->x.shop() == kl) { //Проверка соответствия номеру магазина
					cout << "Enter the name of the product:" << endl;
					string pr; //Переменная типа string
					getline(cin, pr); //Считывание данных типа string
					if (temp->x.tov(pr)) { //Если проверяемый элемент списка соответствует необходимому
						return t;			//То возвращается его порядковый номер
					}
				}
				temp = temp->Next; //Переход на следующий элемент
			};
		}
		else
		{
			cout << "You have entered wrong data, try again." << endl;
			return 0; //Возврат 0
		}
	};
	return 0; //Возврат 0
};
//Функиця удаления элемента из списка
void List::Del(int k) {
	if (k == 0) //Проверка наличия элемента
	{
		cout << "Not found." << endl;
		return;
	};
	if ((k == 1) && (Head->Next)) { //Если элемент первый и не единственный
		Node *temp = Head; //Присваивание временной переменной адреса первого элемента	
		Head = Head->Next;	//Второй элемент становится первым
		Head->Prev = NULL;	//Первый элемент пустой
		delete temp;	//Удаление временной переменной	
		count--;		//Уменьшение переменной, в которой содержится количество элементов списка
		return;		//Выход из функции
	}
	else if ((k == 1) && (Head == Tail)) { //Если элемент первый и единственный
		Tail = Head->Next; //Конец списка "ставится" после начала
		delete Head;  //Удаление первого элемента
		Head = Tail; // "Начало = конец"
		count = 0;	//Переменная, содержащая количество элементов списка, приравнивается нулю	
		return;			//Выход из функции
	}


	if (k == count) { //Если элемент последний
		Node *temp = Tail;	//Присваивание временной переменной адреса последнего элемента	
		Tail = Tail->Prev;	//Предпоследний элемент "становится" последним
		Tail->Next = NULL;	//Последний элемент пустой
		delete temp; //Удаление временной переменной	
		count--;	//Уменьшение переменной, в которой содержится количество элементов списка
		return;		//Выход из функции
	}

	//Если элемент в середине списка
	Node *temp = Head, *temp2; //Временные переменные

	for (int q = 0; q < k - 1; q++) { //"Переход" к необходимому элементу
		temp = temp->Next;
	}

	temp2 = temp;	//"Запись" во временную переменную адреса необходимого элемента
	temp2->Prev->Next = temp->Next;	//Для предыдещего элемента следующим становится элемент "через один"
	temp2->Next->Prev = temp->Prev;  //Для следующего элемента предыдущим становитя элемент "через один"
	delete temp; //Удаление элемента
	count--; //Уменьшение переменной, в которой содержится количество элементов списка
}
//Функция изменения элемента
void List::change() {
	int j = found(); //Поиск изменяемого элемента в списке
					 //Проверка наличия элемента
	if (j == 0)
	{
		cout << "Not found." << endl;
		return;
	};
	Node *temp = Head; //Временная переменная, содержащая адрес начала списка
					   //Если изменяемый элемент не первый, то "переход" к нужному элементу и его изменение
	if (j != 1) {
		for (int q = 0; q < j - 1; q++) {
			temp = temp->Next;
		}
		temp->x.chan();
		return;
	}
	//Если изменяемый элемент первый в списке, то он изменяется
	else {
		temp->x.chan();
		return;
	};
};

int main()
{
	setlocale(LC_ALL, "RUS"); //Подключение дополнительного языкового пакета
	int x, z, fkl; //Объявление временных переменных
	char y[256], m[256], fk[256]; //Объявление временных переменных
	string tov; //Объявление переменной типа string, в которую будет записываться название товара
	List lst; //Объявление списка
	cout << "                           Course work" << endl << "WARNING! Do not use any wrong symbols to correct work of programm!" << endl; //Предупреждение пользователя о возможных проблемах, при вводе неверных данных, вера в то, что это не будет как красная тряпка для быка
																																			  //Меню
	for (int j = 0; j<500; j++) { //Меню выводится с помощью цикла на 500 "прогонов"
		cout << "=======================================================================" << endl; //Декоративная линия
		cout << "Choose your next move: " << endl << "1. Add a new product" << endl << "2. Find the cheapest" << endl << "3. Show All" << endl << "4. Delete the element" << endl << "5. Change exsisting element" << endl << "6. Exit" << endl; //Пункты меню
		cin >> y; //Считывание переменной типа char
		cin.clear(); //Очистка потока ввода
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Игнорирование лишних данных
		x = atoi(y); //Преобразование к типу integer
		cout << endl; //Перевод строки

		if (x == 1) { //Если выбран первый пункт меню
			cout << "Choose the way to add element:" << endl << "1. Create new" << endl << "2. Back to the main menu" << endl; //Подпункты меню
			cin >> fk; //Считывание переменной типа char
			cin.clear(); //Очистка потока ввода
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Игнорирование лишних данных
			fkl = atoi(fk);//Преобразование к типу integer
			if (fkl == 1) { //Если выбран первый пункт меню
				cout << "=======================================================================" << endl; //Декоративная линия
				cout << "Choose the number of shop: " << endl << "1. Auchan" << endl << "2. Lenta" << endl << "3. Spar" << endl << "4. Karusel'" << endl; //Выбор номера магазина
				cin >> m; //Считывание переменной типа char
				cin.clear(); //Очистка потока ввода
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Игнорирование лишних данных
				z = atoi(m); //Преобразование к типу integer
				cout << endl; //Перевод строки
				switch (z) { //В зависимости от полученного значения, вызывается функция добавления элемента в список с определенным оператором
				case 1: {
					lst.Add(1);
					break; }
				case 2: {
					lst.Add(2);
					break; }
				case 3: {
					lst.Add(3);
					break; }
				case 4: {
					lst.Add(4);
					break; }
				default: { //Иначе выход в меню
					cout << "Sorry, you have entered wrong number" << endl;
					break; }
				}
			}
			else if (fkl == 2) //Если выбран второй пункт меню, происходит выход в главное меню
			{
			}
			else //Если введены неверные данные, пользователь оповещается и происходит выход в главное меню
				cout << "You've entered wrong data" << endl;
		}
		else if (x == 2) { //Если выбран второй пункт меню
			cout << "=======================================================================" << endl; //Декоративная линия
			cout << "Enter the name of product: " << endl;
			cin >> tov; //Считывание переменной типа string, имени продукта
			cin.clear(); //Очистка поля ввода
			lst.Show(tov); //Вызов функции поиска самой дешевой цены

		}
		else if (x == 3) //Если выбран третий пункт меню
		{
			lst.ShowAll(); //Вызов функции вывода всех элементов списка на экран
		}
		else if (x == 4) //Если выбран четвертый пункт меню
		{
			int rko = lst.found(); //Объявление переменной типа integer, и присваивание ей значение вызова функции поиска элемента
			lst.Del(rko); //Вызов функции удаления элемента с полученным порядковым номером
		}
		else if (x == 5) //Если выбран пятый пункт меню
		{
			lst.change(); //Вызов функции изменения элемента списка
		}
		else if (x == 6) //Если выбран шестой пункт меню
		{
			break; //Выход из цикла и программы
		}
		else //Если введены неверные данные, пользователь оповещается и происходит выход в меню после нажатия любой клавиши
		{
			cout << "Sorry, you have entered a wrong number" << endl;
			system("pause");
		}
	}
	lst.~List(); //Удаление списка
	return 0;
}
