#include <iostream> 
#include <filesystem> 
#include <cstring> 
using namespace std;
/*Створіть структуру Product(назва продукту, ціна, кількість, наявність на складі)
Запишіть у бінарний файл масив об'єктів структури типу Product.
Прочитайте їх з бінарного файлу.*/
struct Product 
{
	char name[50];
	double price;
	int amount;
	char stock[20];
};
 void createProduct(Product& p)
 {
	 cout << "Name of the product: ";
	 cin >> p.name;
	 cout << "NWhat is the price: ";
	 cin.getline(p.name, 50);	 
	 cout << "The amount: ";
	 cin >> p.amount;
	 cout << "In or Out of stock: ";
	 cin.getline(p.stock, 20);
 }
void showProduct(Product& p)
{
	cout << "Name: "<<p.name;
	cout << "Price: " << p.price;
	cout << "Amount: "<<p.amount;
	cout << "In/Out: "<<p.stock;
}

int main()
{
	int N;
	const char* PATH_TO_FILE = "product.txt";
	cout << "How many products do you wanr to add: ";
	cin >> N;
	Product* list = new Product[N];
	for (int i = 0; i < N; i++) 
	{
		createProduct(list[i]);
	}

	FILE* file;
	Product* new_list = new Product[N];	

	if (fopen_s(&file, PATH_TO_FILE, "wb") == 0) 
	{
		fwrite(list, sizeof(Product), N, file);
		fclose(file);
	}

	if (fopen_s(&file, PATH_TO_FILE, "rb") == 0) 
	{
		fread(new_list, sizeof(Product), N, file);
		fclose(file);
	}

	for (int i = 0; i < N; ++i) 
	{
		showProduct(new_list[i]);
	}

	delete[] list;
	delete[] new_list;
	

}