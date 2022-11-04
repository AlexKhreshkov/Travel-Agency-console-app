#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Client
{
    string full_name;        
    string telephone_number; 
    string passport_number; 
public:
    Client();                                                                          
    Client(string full_name, string telephone_number, string passport_number);        
    void SetValues(string full_name, string telephone_number, string passport_number); 
    void Print();                                                                      
    string Get_Full_name();                                                            
    string Get_telephone_number();                                                     
    string Get_passport_number();                                                      
    void Add_to_File(string name);                                                     
};
Client::Client(string full_name, string telephone_number, string passport_number)
{
    this->full_name = full_name;
    this->telephone_number = telephone_number;
    this->passport_number = passport_number;
}

Client::Client()
{
    full_name = "";
    telephone_number = "";
    passport_number = "";
}
void Client::SetValues(string full_name, string telephone_number, string passport_number)
{
    this->full_name = full_name;
    this->telephone_number = telephone_number;
    this->passport_number = passport_number;
}
void Client::Print()
{
    cout << "ФИО: " << full_name << endl
         << "Номер телефона: " << telephone_number << endl
         << "Номер паспорта: " << passport_number << endl
         << "_________________________________" << endl;
}
string Client::Get_Full_name() { return full_name; };
string Client::Get_passport_number() { return passport_number; };
string Client::Get_telephone_number() { return telephone_number; };
void Client::Add_to_File(string name) 
{
    ofstream fout(name, ios::app); 
    if (fout.is_open())
    {
        fout << endl
             << full_name << endl;
        fout << telephone_number << endl;
        fout << passport_number;
    }
    else
        cout << "Ошибка открытия файла,такого файла для записи клиента нету" << endl;
}
class Trip
{
    string name_of_trip;
    int start_date;      
    int end_date;       
    string place;        
    float price;         
    int nowadays = 10;  
public:
    Trip();                                                                                      
    Trip(string name_of_trip, int start_date, int end_date, string place, float price);           
    void Print();                                                                                 
    void SetValues(string name_of_trip, int start_date, int end_date, string place, float price); 
    void Add_to_File(string name);                                                                
    string Get_name_of_trip() { return name_of_trip; }                                            
    int Get_Start_date() { return start_date; }                                                  
    int Get_End_date() { return end_date; }                                                       
    float Get_Price() { return price; }                                                           
    int Get_Nowadays() { return nowadays; }                                                       
    friend ostream &operator<<(ostream &s, Trip &t);                                              
};
Trip::Trip()
{
    name_of_trip = "";
    start_date = 0;
    end_date = 0;
    place = "";
    price = -1;
    nowadays = 5;
}
Trip::Trip(string name_of_trip, int start_date, int end_date, string place, float price)
{
    this->name_of_trip = name_of_trip;
    this->start_date = start_date;
    this->end_date = end_date;
    this->place = place;
    this->price = price;
    nowadays = 10;
}
void Trip::SetValues(string name_of_trip, int start_date, int end_date, string place, float price)
{
    this->name_of_trip = name_of_trip;
    this->start_date = start_date;
    this->end_date = end_date;
    this->place = place;
    this->price = price;
}
void Trip::Print()
{
    cout << "Название поездки: " << name_of_trip << endl
         << "Начальная дата: " << start_date << endl
         << "Конечная дата: " << end_date << endl
         << "Куда: " << place << endl
         << "Цена: " << price << endl
         << "_________________________________" << endl;
}
void Trip::Add_to_File(string name)
{
    ofstream fout(name, ios::app); 
    if (fout.is_open())
    {
        fout << endl
             << name_of_trip << endl;
        fout << start_date << endl;
        fout << end_date << endl;
        fout << place << endl;
        fout << price;
    }
    else
        cout << "Ошибка открытия файла,такого файла для записи поездок нету" << endl;
}
ostream &operator<<(ostream &s, Trip &t)
{
    s << "Название поездки: " << t.name_of_trip << endl
      << "Начальная дата: " << t.start_date << endl
      << "Конечная дата: " << t.end_date << endl
      << "Куда: " << t.place << endl
      << "Цена: " << t.price << endl
      << "_________________________________" << endl;
    return s;
}
class Sales
{
    string name_of_trip;   //назва поїздки
    string name_of_client; //ім'я користувача
public:
    Sales(string name_of_trip, string name_of_client);          
    Sales();                                                    
    void Print();                                               
    void SetValues(string name_of_client, string name_of_trip); 
    string GetName_of_client() { return name_of_client; }      
    string GetName_of_trip() { return name_of_trip; }           
};
Sales::Sales()
{
    name_of_client = "";
    name_of_trip = "";
}
Sales::Sales(string name_of_client, string name_of_trip)
{
    this->name_of_client = name_of_client;
    this->name_of_trip = name_of_trip;
}
void Sales::SetValues(string name_of_client, string name_of_trip)
{
    this->name_of_client = name_of_client;
    this->name_of_trip = name_of_trip;
}
void Sales::Print()
{
    cout << "ФИО:" << name_of_client << endl;
    cout << "Поездка: " << name_of_trip << endl
         << "_________________________________" << endl;
}
int Num_of_El_FromFile(string filename) 
{
    ifstream fin(filename);
    int count = 0;
    string str;
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            fin >> str;
            count++;
        }
    }
    else
        cout << "Файл для чтения не открыт" << endl;
    fin.close();
    return count;
}
void Read_FromFile_Cleint(Client *C, string filename) 
{
    ifstream fin(filename);
    int count = Num_of_El_FromFile(filename);
    string full_name_, telephone_number_, passport_number_;
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            for (int i = 0; i < count / 3; i++)
            {
                fin >> full_name_ >> telephone_number_ >> passport_number_;
                C[i].SetValues(full_name_, telephone_number_, passport_number_);
            }
        }
    }
    else
        cout << "Ошибка открытия файла InputClient.txt";
}
void Read_FromFile_Trip(Trip *T, string filename) 
{
    ifstream fin(filename);
    int count = Num_of_El_FromFile(filename);
    string name_of_trip, place;
    int start_date, end_date;
    float price;
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            for (int i = 0; i < count / 5; i++)
            {
                fin >> name_of_trip >> start_date >> end_date >> place >> price;
                T[i].SetValues(name_of_trip, start_date, end_date, place, price);
            }
        }
    }
    else
        cout << "Ошибка открытия файла InputTripes.txt";
}
void Read_FromFile_Sales(Sales *S, string filename) 
{
    ifstream fin(filename);
    int count = Num_of_El_FromFile(filename);
    string name_of_client, name_of_trip;
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            for (int i = 0; i < count / 2; i++)
            {
                fin >> name_of_client >> name_of_trip;
                S[i].SetValues(name_of_client, name_of_trip);
            }
        }
    }
    else
        cout << "Ошибка открытия файла InputSales.txt";
}
int condition;  
void MainMenu() 
{
    cout << " ......._TravelAgency_MENU/V.1.0...............\n"
         << "(0) Выход из программы.\n"
         << "(1) Добавить клиентов. \n"
         << "(2) Ведомость про клиентов\n"
         << "(3) Добавить путевку.\n"
         << "(4) Ведомости о продаже путевок.\n"
         << "(5) Проверить, есть ли путёвка с задаными датами начала и конца.\n"
         << "(6) Вывести самую дорогую путёвку.\n"
         << "(7) Горящие путёвки: \n"
         << "(8) Добавить продажу. \n"
         << "(9) Список продаж: \n"
         << "(10) Какую путёвку купил клиент: \n"
         << "Ваш выбор: ";
    cin >> condition;
};
int main()
{
    setlocale(LC_ALL, "ru");                                  
    string InputClient = {"InputClient.txt"};                 
    int count_for_clients = Num_of_El_FromFile(InputClient); 
    int Num_of_Clients = Num_of_El_FromFile(InputClient) / 3; 
    string full_name;                                         
    string telephone_number;                                 
    string passport_number;                                   
    string InputTripes = {"InputTripes.txt"};                
    int count_for_Tripes = Num_of_El_FromFile(InputTripes);  
    int Num_of_Tripes = Num_of_El_FromFile(InputTripes) / 5; 
    string name_of_trip, place;                             
    int start_date, end_date;                                
    float price;                                             
    /////////////////////////////////////////////////////////
    string InputSales = {"InputSales.txt"};                
    int count_for_Sales = Num_of_El_FromFile(InputSales);  
    int Num_of_Sales = Num_of_El_FromFile(InputSales) / 2; 
    MainMenu();                                            
    while (condition != 0)                                
    {
        if (condition > 10 || condition < 0) 
        {
            cout << "Команда не распознана.Введите от 0-10." << endl;
            system("pause"); 
            system("cls");   
            MainMenu();      
        }
        if (condition == 1) 
        {
            if ((count_for_clients % 3) != 0) 
            {
                if (count_for_clients == 1) 
                {
                    cout << "Клиентов не обнаружено.Добавлеям 1-ого: " << endl;
                    cout << "Введите ФИО: ";
                    cin >> full_name;
                    cout << "Введите номер телефона: ";
                    cin >> telephone_number;
                    cout << "Введите номер паспорта: ";
                    cin >> passport_number;
                    ofstream fout(InputClient, ios::app); 
                    if (fout.is_open())                  
                    {
                        fout << endl
                             << full_name << endl;
                        fout << telephone_number << endl;
                        fout << passport_number;
                    }
                    else
                        cout << "Ошибка открытия файла,такого файла для записи клиентов нету" << endl;
                }
                else
                {
                    cout << "Ошибка при подсчете клиентов!Проверьте файл InputClient.txt ";
                    return -1;
                }
            }
            else
            { 
                cout << "Клиенты обнаружены. Добавляем нового клиента." << endl
                     << "Введите ФИО: ";
                cin >> full_name;
                cout << "Введите номер телефона: ";
                cin >> telephone_number;
                cout << "Введите номер паспорта: ";
                cin >> passport_number;
                ofstream fout(InputClient, ios::app); 
                if (fout.is_open())                   
                {
                    fout << endl
                         << full_name << endl;
                    fout << telephone_number << endl;
                    fout << passport_number;
                }
                else
                    cout << "Ошибка открытия файла,такого файла для записи клиентов нету" << endl;
            }
            cout << "Клиент успешно добален. ";
            return 0;
        }
        if (condition == 2)                 
        {                                     
            if ((count_for_clients % 3) != 0) 
            {
                if (count_for_Tripes == 1)
                {
                    cout << "Клиентов не обнаружено.Добавтье их через 1 пункт меню  или в файл InputClient.txt";
                }
                cout << "Ошибка при подсчете клиентов! Проверьте файл InputClient.txt ";
                return -1;
            }
            Client *С = new Client[Num_of_Clients];
            Read_FromFile_Cleint(С, InputClient);   
            for (int i = 0; i < Num_of_Clients; i++)
            { 
                cout << "Клиент номер: " << i + 1 << endl;
                С[i].Print();
            }
            delete[] С;
            system("pause"); 
            system("cls");   
            MainMenu();      
        }
        if (condition == 3) 
        {
            if ((count_for_Tripes % 5) != 0) 
            {
                if (count_for_Tripes == 1) 
                {
                    cout << "Путёвок не обнаружено.Добавляем 1-ую. " << endl;
                    cout << "Введите название путёвки: ";
                    cin >> name_of_trip;
                    cout << "Введите дату начала: ";
                    cin >> start_date;
                    cout << "Введите дату конца: ";
                    cin >> end_date;
                    cout << "Введите место: ";
                    if (start_date > end_date || start_date < 0 || start_date > 31 || end_date < 0 || end_date > 32) 
                    {
                        cout << "Даты заданы некоректно.";
                        return 0;
                    }
                    cin >> place;
                    cout << "Введите стоимость: ";
                    cin >> price;
                    if (price <= 0) 
                    {
                        cout << "Цена указана некоректная.";
                        return 0;
                    }
                    ofstream fout(InputTripes, ios::app); 
                    if (fout.is_open())
                    {
                        fout << endl
                             << name_of_trip << endl;
                        fout << start_date << endl;
                        fout << end_date << endl;
                        fout << place << endl;
                        fout << price;
                    }
                    else
                        cout << "Ошибка открытия файла,такого файла для записи поездок нету" << endl;
                }
                else
                {
                    cout << "Ошибка при подсчете поездок!Проверьте файл InputTripes.txt ";
                    return -1;
                }
                cout << "Путёвка была успешно добавлена.";
                return 0;
                system("pause"); 
                system("cls");   
                MainMenu();      
            }
            else
            {
                cout << "Путёвки обнаружены. Добавляем новую:" << endl;
                cout << "Введите название путёвки: ";
                cin >> name_of_trip;
                cout << "Введите дату начала: ";
                cin >> start_date;
                cout << "Введите дату конца: ";
                cin >> end_date;
                if (start_date > end_date || start_date < 0 || start_date > 31 || end_date < 0 || end_date > 32) 
                {
                    cout << "Даты заданы некоректно.";
                    return 0;
                }
                cout << "Введите место: ";
                cin >> place;
                cout << "Введите стоимость: ";
                cin >> price;
                if (price <= 0)
                {
                    cout << "Цена указана некоректно.Путёвка не записана.";
                    return 0;
                }
                ofstream fout(InputTripes, ios::app); 
                if (fout.is_open())
                {
                    fout << endl
                         << name_of_trip << endl;
                    fout << start_date << endl;
                    fout << end_date << endl;
                    fout << place << endl;
                    fout << price;
                }
                else
                    cout << "Ошибка открытия файла,такого файла для записи клиентов нету" << endl;
                cout << "Путевка успешно добавлена. ";
                return 0;
            }
        }
        if (condition == 4) 
        {
            if ((count_for_Tripes % 5) != 0) 
            {
                if (count_for_Tripes == 1) 
                {
                    cout << "Путёвок не обнаружено.Добавтье их через 3 пункт или в файл InputTripes.txt";
                    return 0;
                }
                cout << "Ошибка при подсчете путёвок! Проверьте файл InputTripes.txt ";
                return -1;
            }                                   
            Trip *T = new Trip[Num_of_Tripes];  
            Read_FromFile_Trip(T, InputTripes); 
            for (int i = 0; i < Num_of_Tripes; i++)
            {
                cout << "Пуёвка номер: " << i + 1 << endl;
                T[i].Print();
            }
            delete[] T;
            system("pause"); 
            system("cls");   
            MainMenu();      
        }
        if (condition == 5) 
        {                   
            if (count_for_Tripes < 2)
            {
                cout << "Путёвок не обнаружено.";
                return 0;
            }
            cout << "Дата начала: ";
            cin >> start_date;
            cout << "Дата конца: ";
            cin >> end_date;
            if (start_date >= end_date && start_date < 0 && start_date > 32 && end_date < 0 && end_date > 32)
            {
                cout << "Даты заданы некоректно.";
                return 0;
            }
            Trip *T = new Trip[Num_of_Tripes];  
            Read_FromFile_Trip(T, InputTripes); 
            bool is = false;                    
            for (int i = 0; i < Num_of_Tripes; i++)
            { 
                if ((T[i].Get_Start_date() == start_date) && T[i].Get_End_date() == end_date)
                {
                    is = true;
                    cout << "Путевка обнаружена." << endl
                         << T[i] << endl;
                }
            }
            if (is == false) 
                cout << "Путёвки с задаными датами нету." << endl;
            delete[] T;
            system("pause");
            system("cls");   
            MainMenu();      
        }
        if (condition == 6) 
        {
            if (count_for_Tripes < 2) 
            {
                cout << "Путёвок не обнаружено.";
                return 0;
            }
            Trip *T = new Trip[Num_of_Tripes];  
            Read_FromFile_Trip(T, InputTripes); 
            float tmp = 0;
            for (int i = 0; i < Num_of_Tripes; i++)
            { 
                if (T[i].Get_Price() > tmp)
                    tmp = T[i].Get_Price();
            }
            for (int i = 0; i < Num_of_Tripes; i++)
            { 
                if (T[i].Get_Price() == tmp)
                    cout << "Самая дорогая путёвка: " << endl
                         << T[i];
            }
            delete[] T;
            system("pause"); 
            system("cls");   
            MainMenu();      
        }
        if (condition == 7) 
        {
            if (count_for_Tripes < 2) 
            {
                cout << "Путёвок не обнаружено.";
                return 0;
            }
            Trip *T = new Trip[Num_of_Tripes];  
            Read_FromFile_Trip(T, InputTripes); 
            bool key = false;                   
            for (int i = 0; i < Num_of_Tripes; i++)
            {
                if ((T[i].Get_Start_date() - T[i].Get_Nowadays()) < 5 && (T[i].Get_Start_date() - T[i].Get_Nowadays()) >= 0)
                { 
                    key = true;
                    cout << "Горящие путёвки:" << endl
                         << T[i];
                }
            }
            if (key == false) 
                cout << "Горящих путёвок нету.";
            delete[] T;
            system("pause"); 
            system("cls");   
            MainMenu();
        }
        if (condition == 8) 
        {
            cout << "Перед вводом продаж необходимo что бы клиент и путёвки были в базе!" << endl;
            string name_of_client, name_of_trip;
            cout << "Введите ФИО клиента:" << endl;
            cin >> name_of_client;
            cout << "Введите название путвёвки:" << endl;
            cin >> name_of_trip;
            Trip *T2 = new Trip[Num_of_Tripes];  
            Read_FromFile_Trip(T2, InputTripes); 
            bool key_1 = false, key_2 = false;
            for (int i = 0; i < Num_of_Tripes; i++)
            {
                if ((T2[i].Get_name_of_trip()) == name_of_trip)
                    key_1 = true;
            }
            Client *C2 = new Client[Num_of_Clients]; 
            Read_FromFile_Cleint(C2, InputClient);   
            for (int i = 0; i < Num_of_Clients; i++)
            {
                if ((C2[i].Get_Full_name()) == name_of_client)
                    key_2 = true;
            }
            if (key_1 && key_2) 
            {
                ofstream fout("InputSales.txt", ios::app);
                fout << endl
                     << name_of_client << endl
                     << name_of_trip;
                cout << "Продажа успешно добавлена!";
                system("pause");
                return 0;
            }
            else 
                cout << "Ошибка.Такого клиента или путёвки нету в базе " << endl;
            delete[] C2;
            delete[] T2;
            system("pause");
            system("cls");   
            MainMenu();      
        }
        if (condition == 9) 
        {
            string InputSales = {"InputSales.txt"};
            if (count_for_Sales == 1) 
            {
                cout << "Продаж не обнаружено.Добавтье их через 8 пункт меню или в файл InputSales.txt";
                return 0;
            }
            Sales *S = new Sales[Num_of_Sales]; 
            Read_FromFile_Sales(S, InputSales); 
            for (int i = 0; i < Num_of_Sales; i++)
            { 
                cout << "Продажа номер: " << i + 1 << endl;
                S[i].Print();
            }
            delete[] S;
            system("pause"); 
            system("cls");  
            MainMenu();      
        }
        if (condition == 10) 
        {
            if (count_for_Sales == 1) 
            {
                cout << "Продаж не обнаружено.";
                return 0;
            }
            string client_name_;
            cout << "Введите ФИО клиента:";
            cin >> client_name_;
            bool key = false;
            Sales *S_ = new Sales[Num_of_Sales]; 
            Read_FromFile_Sales(S_, InputSales);
            for (int i = 0; i < Num_of_Sales; i++)
            { 
                if (S_[i].GetName_of_client() == client_name_)
                {
                    key = true;
                    cout << "Название путёвки, которую купил клиент: " << S_[i].GetName_of_trip() << endl;
                }
            }
            if (key == false) 
                cout << "У заданого клиента нету покупок.";
            delete[] S_;
            system("pause");
            system("cls");
            MainMenu();
        }
    }
}