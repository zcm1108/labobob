#include <iostream>
#include <vector>
using namespace std;

class product {
    int price;
    string name;
public:
    product(int price,string name): price(price),name(name){}
    void pritnProduct()const {
        cout << "Product's name" << name << "\n";
        cout << "Price: " << price<<"\n";
    }
    int getPrice()const {
        return price;
    }
    string getName()const {
        return name;
    }
};

class store {
    string name;
    vector<product>products;
public:
    store(string name,vector<product>products):name(name),products(products){}
    void printStore()const {
        cout << "Name: " << name << "\n";
        for (auto el : products) {
            el.pritnProduct();
            cout << "\n";
        }
    }

    string getName() const {
        return name;
    }

    const vector<product>& getProducts() const {
        return products;
    }
};

template <typename T>
class network {
    vector<T>stores;
public:
    network(vector<T>stores): store(stores){}

    void addStore(const T& store) {
        stores.push_back(store);
    }

    void cheapGood(string nameG) {
        store tmp = stores[0];

        for (int i = 0; i < stores.size(); i++) {
            for (int j = 0; j < stores[i].goods.size(); j++)
            {
                if (nameG == stores[i].goods[j].nameGood) {
                    if (tmp.goods[j].price < stores[i].goods[j].price)
                        tmp = stores[i];
                }
            }
        }

        cout << "The cheaper good :\n";
        tmp.printStore();
    }

    void printNetwork() {
        for (auto el : stores) {
            el.printStore();
        }
    }
};

ostream& operator <<(ostream& os, const store& s1) {
    s1.printStore();
    return os;

};

int main()
{


}

