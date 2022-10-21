#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>

using namespace std;

int _StateMenu;
////////FUNCTIONS////////
void Menu() {
	cout << "Choose the action : " << endl
		<< "(0) Ending a session." << endl
		<< "(1) Data Entery" << endl
		<< "(2) Data output." << endl
		<< "(3) Data Change." << endl
		<< "(4) Delete Data." << endl
		<< "(5) Add Data." << endl
		<< "(6) Save Data." << endl
		<< "Your choise : ";
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
			cout << "Error Open File" << endl;
		}

	}
	else {
		cout << "Error Buf file" << endl;
	}
	record.close();
	reading.close();
}
//CORRECT
void datainitialization() {

	//создаем временный файл в котором будет храниться актуальная информация. Т.е создадим буфер 

	ofstream _buf("Bufer.txt");//создает нам текстовый файл (Возможность библиотеки fstream)

	if (!_buf) {
		cout << "Error creating buff file ";
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

	cout << "Enter data amount: ";
	cin >> n;

	//открываем буферный файл и записываем в него данные
	ofstream record("Buffer.txt", ios::app);//ios::app добавляет запись в конец

	if (record) {
		//record << endl;
		record << n << endl;

		for (int i = 0; i < n; i++) {
			cout << "Enter Data №1 (Phone Name): ";
			cin >> phone_name;

			cout << "Enter Data №2 (Phone ID) : ";
			cin >> phone_id;

			cout << "Enter Data №3 (Brand Name): ";
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
			cout << "Data read !";
		}
		else {
			cout << "ERROR. File not found !!!" << endl;
		}
	}
	else {
		cout << "ERROR. File not found" << endl;
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
		cout << "Amount data: " << n << endl;

		for (int i = 0; i < n; i++) {
			cout << "Data  № " << i + 1 << endl;

			reading >> phone_name;
			cout << "Data number 1 (Phone Name ): " << phone_name << endl;

			reading >> phone_id;
			cout << "Data number 2 (Phone ID ):" << phone_id << endl;

			reading >> brand_name;
			cout << "Data number 3 (Brand Name ): " << brand_name << endl;

			cout << "_____________________________________" << endl;
		}
	}
	else {
		cout << "Open File Issue!!! " << endl;

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

			cout << "Choose a number of changing element (Betwen 1 to " << n << ") : ";
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
						cout << "Enter Data №1 (phone_name): " << endl;
						cin >> phone_name;

						cout << "Enter Data №2 (phone_id): " << endl;
						cin >> phone_id;

						cout << "Enter Data №3 (brand_name): " << endl;
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
				cout << "Data Changed!!!" << endl;
			}
			else {
				cout << "Incorrect Number!" << endl;
			}
		}
		else {
			cout << "Open file issue!!!" << endl;
		}
	}
	else {
		cout << "Open buf fule issue!!!" << endl;
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
		cout << "Open buff file issue!!!" << endl;
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
				cout << "Data saved with file name : " << filename << endl;
			}
		}
		else {
			cout << "Open buff file issue!!!" << endl;
		}
	}
	else {
		cout << "Open file issue!!!" << endl;
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

			cout << "Enter data?: ";
			cin >> _actions;

			system("cls");

			if (_actions == 1) {
				//ввод в ручную
				dataentry();
			}
			else
			{
				//чтение из файла
				cout << "Enter file name: ";
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
			cout << "Enter file name: ";
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
	cout << "shuted down!" << endl;
	system("pause");
}