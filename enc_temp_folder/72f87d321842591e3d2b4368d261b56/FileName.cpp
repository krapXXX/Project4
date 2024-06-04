#include <iostream> 
#include <filesystem> 
using namespace std;
/*Створіть структуру Product(назва продукту, ціна, кількість, наявність на складі)
Запишіть у бінарний файл масив об'єктів структури типу Product.
Прочитайте їх з бінарного файлу.*/
struct Product
{
	char* name;
	double price;
	int amount;
	char* stock;
};
 void createProduct(Product& p)
 {
	 cout << "Name of the product: ";
	 cin >> p.name;
	 cout << "NWhat is the price: ";
	 cin >> p.price;
	 cout << "The amount: ";
	 cin >> p.amount;
	 cout << "In or Out of stock: ";
	 cin >> p.stock;
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
	FILE* file;
	for (int i = 0; i < N; ++i) 
	{
		createProduct(list[i]);
	}

	if (fopen_s(&file, PATH_TO_FILE, "wb+") == 0)
	{
		fwrite(list, sizeof(Product), N, file);
		Product* new_list = new Product[N];		
		fread(new_list, sizeof(Product), N, file);
		for (int i = 0; i < N; i++)
		{
			showProduct(new_list[i]);
		}
		fclose(file);
	}


	

}