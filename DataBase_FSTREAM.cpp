#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>

using namespace std;

int _StateMenu;
////////FUNCTIONS////////
void Menu() {
	cout << "Выберите действие : " << endl
		<< "(0) выход из програмы." << endl
		<< "(1) Ввод данных" << endl
		<< "(2) Вывод данных." << endl
		<< "(3) Изменение данных." << endl
		<< "(4) Удаление данных." << endl
		<< "(5) Добавление данных." << endl
		<< "(6) Сохранение данных." << endl
		<< "Ваш выбор : ";
	cin >> _StateMenu;

}
//CORRECT
void copy() {
	//копирование в новый файл 

	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);

	if (reading) {
		if (record) {
			//временные переменные 
			string phone_name;
			int phone_id;
			string brand_name;
			int n;

			//считываем из буферного файла в новый 
			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> phone_name;
				record << phone_name << endl;

				reading >> phone_id;
				record << phone_id << endl;

				reading >> brand_name;
				if (i < n - 1) {
					record << brand_name << endl;

				}
				else {
					record << brand_name;
				}
			}
		}
		else {
			cout << "Ошибка открытия файла" << endl;
		}

	}
	else {
		cout << "ошибка открытия буферного файла" << endl;
	}
	record.close();
	reading.close();
}
//CORRECT
void datainitialization() {

	//создаем временный файл в котором будет храниться актуальная информация. Т.е создадим буфер 

	ofstream _buf("Bufer.txt");//создает нам текстовый файл (Возможность библиотеки fstream)

	if (!_buf) {
		cout << "Ошибка создания буферного файла ";
	}

	_buf.close();//закрывает созданый файл 
}
//CORRECT
void dataentry() {
	//ввод данных в ручную

	//временнные переменные 
	string phone_name;
	int phone_id;
	string brand_name;
	int n;

	cout << "введите количество данных";
	cin >> n;

	//открываем буферный файл и записываем в него данные
	ofstream record("Buffer.txt", ios::app);//ios::app добавляет запись в конец

	if (record) {
		//record << endl;
		record << n << endl;

		for (int i = 0; i < n; i++) {
			cout << "Введите данные №1 (имя телефона): ";
			cin >> phone_name;

			cout << "Введите данные №2 (айди телефона) : ";
			cin >> phone_id;

			cout << "Введите данные №3 (имя бренда): ";
			cin >> brand_name;

			record << phone_name<<endl;
			record << phone_id<<endl;
			if (i < n - 1) {
				record << brand_name << endl;
			}
			else {
				record << brand_name << endl;

				cout << "_______________________________";
			}
		}
	}
	else {
		cout << "error Xo ";

		record.close();
	}

}	
// CORRECT
void datareading(string filename) {

	ifstream reading(filename);//поток который читает из файла который нам нужен
	ofstream record("Bufer.txt", ios::out);//ios::out удаляет все содержимое в файле

	if (reading) {
		if (record) {

			//временные переменные
			string phone_name;
			int phone_id;
			string brand_name;
			int n;

			//считываем данные из файла

			reading >> n;
			record << n << endl;

			for (int i=0; i < n; i++) {

				reading >> phone_name;

				reading >> phone_id;

				reading >> brand_name;

				record << phone_name << endl;
				record << phone_id << endl;
				if (i < n - 1) {
					record << brand_name << endl;
				}
				else {
					record << brand_name;
				}

			}
			cout << "данные считаны !";
		}
		else {
			cout << "ошибка файл не найден !!!" << endl;
		}
	}
	else {
		cout << "ошибка файл не найден !!!" << endl;
	}

	//закрытие файла 
	record.close();
	reading.close();
}
//??????????
void print() {
	ifstream reading("Buffer.txt");

	if (reading) {
		string phone_name;
		int phone_id;
		string brand_name;
		int n;

		reading >> n;
		cout << "количество данных: " << n << endl;

		for (int i = 0; i < n; i++) {
			cout << "данные об № " << i + 1 << endl;

			reading >> phone_name;
			cout << "Данные номер 1 (Имя телефона ): " << phone_name << endl;

			reading >> phone_id;
			cout << "Данные номер 2 (id телефона ):" << phone_id << endl;

			reading >> brand_name;
			cout << "Данные номер 3 (бренд телефона ): " << brand_name << endl;

			cout << "_____________________________________" << endl;
		}
	}
	else {
		cout << "ошибка открытия файла!!! " << endl;

		reading.close();
	}
}
// CORRECT
void datachange() {

	//изменение данных

	//сохраним еще раз данные
	//очистим буфер и снова начнем записывать данные в него 
	//дойдем до необходимого и изменим данные в нем

	copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			//временные переменные
			string phone_name;
			int phone_id;
			string brand_name;
			int n, _n;

			//считываем из буферного файла в новый
			reading >> n;

			cout << "выберите номер изменяемого элемента (от 1 до " << n << ") : ";
			cin >> _n;
			_n--;

			system("cls");

			record << n << endl;

			if (_n >= 0 && _n < n) {

				for (int i = 0; i < n; i++) {
					if (i != _n) {
						reading >> phone_name;
						record << phone_name << endl;

						reading >> phone_id;
						record << phone_id << endl;

						reading >> brand_name;
						if (i < n - 1) {
							record << brand_name << endl;
						}
						else {
							record << brand_name;
						}
					}
					else {
						cout << "Введите данные №1 (phone_name): " << endl;
						cin >> phone_name;

						cout << "Введите данные №2 (phone_id): " << endl;
						cin >> phone_id;

						cout << "Введите данные №3 (brand_name): " << endl;
						cin >> brand_name;

						record << phone_name << endl;
						record << phone_id << endl;
						if (i < n - 1) {
							record << brand_name << endl;
						}
						else {
							record << brand_name;

							reading >> phone_name;
							reading >> phone_id;
							reading >> brand_name;
						}
					}
				}
				cout << "данные изменены!" << endl;
			}
			else {
				cout << "Номер введен не верно!" << endl;
			}
		}
		else {
			cout << "ошибка открытия файла!" << endl;
		}
	}
	else {
		cout << "ошибка открытия буферного файла!" << endl;
	}
	record.close();
	reading.close();

	remove("Buffer_.txt");

}
//CORRECT
void deletedata()
{
	//удaление данных

	//запоминаем данные 
	//перезаписываем в исходный буфер
	//кроме удаляемого 

	copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			//временные переменные 
			string phone_name;
			int phone_id;
			string brand_name;
			int n, _n;

			//считываем  из буферного файла в новый 

			reading >> n;
			int b = n - 1;

			cout << "выберите номер изменяемого элемента (от 1 до " << n << "): " << endl;
			cin >> _n;
			_n--;

			system("cls");

			record << b << endl;

			if (_n >= 0 && _n < n) {

				for (int i{}; i < n; i++) {
					if (i != _n) {
						reading >> phone_name;
						record << phone_name << endl;

						reading >> phone_id;
						record << phone_id << endl;

						reading >> brand_name;
						if (i < n - 1) {
							record << brand_name << endl;
						}
						else {
							record << brand_name;
						}

					}
					else {
						reading >> phone_name;
						reading >> phone_id;
						reading >> brand_name;
					}
				}
				cout << "Данные удалены!" << endl;
			}
			else {
				cout << "номер введен не верно!" << endl;
			}
		}
		else {
			cout << "ошибка открытия файла!" << endl;
		}
	}
	else {
		cout << "ошибка открытия буферного файла!" << endl;
	}

	record.close();
	reading.close();
	remove("Buffer_.txt");
}
//CORRECT
int amountdata() {
	//выводит количество данных из файла
	ifstream _buf("Buffer.txt");
	int n;

	if (_buf) {
		_buf >> n;
	}
	else {
		cout << "Ошибка открытия буферного файла!!!" << endl;
	}
	_buf.close();

	return n;
}
void adddata() {
	//добавление данных

	//временные переменные
	string phone_name;
	int phone_id;
	string brand_name;
	int n = amountdata() + 1;

	//открываем буферный файл 
	ofstream record("Buffer.txt", ios::app);
	ofstream record_("Buffer.txt", ios::out | ios::in);

	if (record_) {
		record_ << n << endl;
	}
	else {
		cout << "ошибка открытия буферного файла!!!" << endl;
	}
	if (record) {
		record << endl;

		cout << "Введите данные №1(Phone_name): ";
		cin >> phone_name;

		cout << "Введите данные №2(Phone_id): ";
		cin >> phone_id;

		cout << "Введите данные №3(Brand_name): ";
		cin >> brand_name;

		record << phone_name << endl;
		record << phone_id << endl;
		record << brand_name;
	}
	else {
		cout << "ошибка открытия файла!!!!" << endl;

	}
	record.close();
	record_.close();
}

void savedata(string filename) {
	//сохранение данных

	ifstream reading("Buffer.txt");
	ofstream record(filename, ios::out);

	if (reading) {
		if (record) {

			//временные переменные 
			string phone_name;
			int phone_id;
			string brand_name;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> phone_name;
				record << phone_name << endl;

				reading >> phone_id;
				record << phone_id<<endl;

				reading >> brand_name;
				if (i < n - 1) {
					record << brand_name << endl;
				}
				else {
					record << brand_name;
				}
				cout << "Данные сохранены в файле " << filename << endl;
			}
		}
		else {
			cout << "Ошибка открытия буферного файла!!!" << endl;
		}
	}
	else {
		cout << "Ошибка открытия файла!!!" << endl;
	}
	record.close();
	reading.close();
}
bool datacleaning() {
	//очистка буфера

	bool clear = 0;

	//открываем файл
	fstream _buf("Buffer.txt", ios::out);
	if (!_buf) {
		cout << "Ошибка буферного файла!" << endl;
	}
	//очищаем
	_buf.clear();

	//проверка что файл чист
	if (_buf.peek() == EOF) {
		clear = true;
	}
	else {
		clear = false;
	}
	_buf.close();

	return clear;
}
/////////////////////

//MAIN
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	datainitialization();

	Menu();

	int _actions;
	string filename;

	while (_StateMenu != 0)
	{
		switch (_StateMenu)
		{
		case 1:
			system("cls");

			cout << "Ввод вручную или из файла (1 = вручную)?: ";
			cin >> _actions;

			system("cls");

			if (_actions == 1) {
				//ввод в ручную
				dataentry();
			}
			else
			{
				//чтение из файла
				cout << "Введите название файла: ";
				cin >> filename;

				datareading(filename);

			}
			system("pause");//задержка консоли 
			system("cls");
			Menu();
			break;
			/////////////////////
		case 2:
			system("cls");

			print();

			system("pause");
			system("cls");
			Menu();
			break;
			////////////////////
		case 3:
			system("cls");

			datachange();

			system("pause");
			system("cls");
			Menu();
			break;
			////////////////////
		case 4:
			system("cls");

			deletedata();

			system("pause");
			system("cls");
			Menu();
			break;
		case 5:
			system("cls");

			adddata();

			system("pause");
			system("cls");
			Menu();
			break;
		case 6:
			system("cls");

			//zapis v file
			cout << "Введите название файла: ";
			cin >> filename;

			system("cls");

			savedata(filename);

			system("pause");
			system("cls");
			Menu();
			break;
		default:
			cout << "error" << endl;
			break;
		}
	}

	system("cls");
	if (datacleaning()) {
		cout << "Cleaned"<<endl;
	}
	else {
		cout << "UnCleaned!" << endl;

	}
	cout << "раьота завершена!" << endl;
	system("pause");
}