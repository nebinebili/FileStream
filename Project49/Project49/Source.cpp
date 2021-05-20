#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
using namespace std;

class Contact {
public:
	string name;
	string surname;
	string number;

	Contact() = default;
	Contact(const string& name, const string& surname,
		const string& number)
	{
		this->name = name;
		this->surname = surname;
		this->number = number;
	}
};


void file_txt_write_object() {
	Contact contact("Nicat", "nicatli", "29");

	ofstream fout("contact.txt", ios::app);
	fout.setf(ios::left);

	if (!fout) {
		throw "File is not found";
	}
	if (!fout.is_open()) {
		throw "File can not open";
	}

	fout << setw(20) << contact.name << " "
		<< setw(20) << contact.surname << " "
		<< setw(20) << contact.number << endl;
	fout.close();
}

void file_txt_read_object() {
	Contact contact;

	ifstream fin("contact.txt",ios_base::in);

	if (!fin) {
		throw "File is not found";
	}

	if (!fin.is_open()) {
		throw "File can not open";
	}

	while (!fin.eof())
	{
		fin >> contact.name;
		fin >> contact.surname;
		fin >> contact.number;

	 cout << contact.name << " " << contact.surname << " " << contact.number << endl;
	}

	fin.close();
}

void find(const string& name) {
	Contact contact;

	ifstream fin("contact.txt");

	if (fin.is_open()) {
		bool isFind = false;
		while (!fin.eof())
		{
			fin >> contact.name;
			fin >> contact.surname;
			fin >> contact.number;

			if (contact.name == name) {
				cout << contact.name << endl;
				cout << contact.surname << endl;
				cout << contact.number << endl;
				isFind = true;
				break;
			}
		}

		if (!isFind) cout << "Not found" << endl;

	}

	fin.close();
}

bool findd(const string& name) {
	Contact contact;

	ifstream fin("contact.txt");

	if (fin.is_open()) {
		bool isFind = false;
		while (!fin.eof())
		{
			fin >> contact.name;
			fin >> contact.surname;
			fin >> contact.number;

			if (contact.name == name) {
				cout << contact.name << endl;
				cout << contact.surname << endl;
				cout << contact.number << endl;
				isFind = true;
				return true;
				break;
			}
		}

		if (!isFind) cout << "Not found" << endl;
		return false;
	}

	fin.close();
}

void deletecontact(const string& name) {
	
	Contact contact;

	ifstream fin("contact.txt");
	if (findd(name) == 0) {
		cout << "Person is not found" << endl;
		return;
	}
	
		if (fin.is_open()) {
			while (!fin.eof())
			{
				fin >> contact.name;
				fin >> contact.surname;
				fin >> contact.number;

				if (contact.name == name) continue;

				ofstream fout("newtext.txt", ios::app);
				fout.setf(ios::left);

				if (!fout) {
					throw "File is not found";
				}
				if (!fout.is_open()) {
					throw "File can not open";
				}

				if (contact.name != "")fout << setw(20) << contact.name << " "
					<< setw(20) << contact.surname << " "
					<< setw(20) << contact.number << endl;
				contact.name = "";
				fout.close();


			}
		}

		fin.close();
		remove("contact.txt");
		if (rename("contact.txt", " newtext.txt") == 0) cout << "File renamed" << endl;
	
}

int main() {
	


	try
	{
	  //file_txt_write_object();
	  //file_txt_read_object();
	  //find("Nicat");
	  //deletecontact("Nicat");
	}
	catch (const char*ex)
	{
		cout<<ex;
	}
	return 0;
}