#include "Emploeers.h"

Emploeers::Emploeers(string id)
{
    string tmp_id, tmp_name, tmp_firstname, tmp_age;
    fstream read_db("Emploeers.txt");
    while (!read_db.eof())
    {
        read_db >> tmp_id >> tmp_name >> tmp_firstname >> tmp_age;
        if (tmp_id == id) {
            name = tmp_name;
            firstname = tmp_firstname;
            age = tmp_age;
        }
    }

}

void Emploeers::show()
{
    cout << "\nСотрудник! " << endl;
    cout << "Name : " << name << endl;
    cout << "Firstame : " << firstname << endl;
    cout << "Age : " << age << endl;

}
