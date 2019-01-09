#include<iostream>
using namespace std;

class Buyer;

class Item
{
public:

    string itemname,originName;
    int quantity;
    double price;
    Item() {}

    Item(string a,string b,double c,int d)
    {
        itemname = a;
        originName = b;
        price = c;
        quantity = d;
    }

    void showItem()
    {
        cout<<"Item Title : "<<itemname<<endl;
        cout<<"Origin Name : "<<originName<<endl;
        cout<<"Price : "<<price<<endl;
        cout<<"Quantity : "<<quantity<<endl;
    }
};

class ItemCategory : public Item
{
private:
    string category;

public:
    ItemCategory() {}

    ItemCategory(string ct,string a,string b,double c,int d):Item(a,b,c,d)
    {
        category = ct;

    }

    void showDetail()
    {
        cout<<"Item Description : "<<endl<<endl;
        cout<<"Item Category : "<<category<<endl;
        showItem();

        cout<<endl;
    }
};

class Buyer
{


public:
    string name,type, gender;
    Buyer() {}

    Buyer(string a,string b, string c)
    {
        name = a;
        type=b;
        gender=c;
    }


    friend void buyItems( ItemCategory a, Buyer b);
};

void buyItems( ItemCategory a, Buyer b)
{
    double discount;
    if((b.type.compare("Regular")) == 0)
    {
            discount=(a.price*10)/100;
            a.price=a.price-discount;
            if (b.gender.compare("C")==0)
            cout<<" Child "<<b.name<<" is a "<<b.type<<" Buyer, will get 10% discount,so Discount price:"<<a.price<<" taka."<<endl<<endl;

            if (b.gender.compare("M")==0)
            cout<<" Mr. "<<b.name<<" is a "<<b.type<<" Buyer, will get 10% discount,so Discount price:"<<a.price<<" taka."<<endl<<endl;

            if (b.gender.compare("F")==0)
            cout<<" Mrs. "<<b.name<<" is a "<<b.type<<" Buyer, will get 10% discount,so Discount price:"<<a.price<<" taka."<<endl<<endl;


    }
    else{
            if (b.gender.compare("C")==0)
            cout<<" Child "<<b.name<<" is a "<<b.type<<" Buyer, will  not get 10% discount,so price:"<<a.price<<" taka."<<endl<<endl;

            if (b.gender.compare("M")==0)
            cout<<" Mr. "<<b.name<<" is a "<<b.type<<" Buyer, will  not get 10% discount,so price:"<<a.price<<" taka."<<endl<<endl;

            if (b.gender.compare("F")==0)
            cout<<" Mrs. "<<b.name<<" is a "<<b.type<<" Buyer, will  not get 10% discount,so price:"<<a.price<<" taka."<<endl<<endl;


    }
}

int main()
{
    ItemCategory A("Cosmatic","Perfume","Canada",500,20);
    Buyer cs("ASHIS","Regular","M");
    A.showDetail();
    buyItems(A,cs);

    ItemCategory B("Stationary","Hair Band","Australia",20,2500);
    Buyer ds("Mrs.Anna","Non_Regular","F");
    B.showDetail();
    buyItems(B,ds);

    ItemCategory C("Garments","Shirt","France",400,18);
    Buyer ks("Pokemon","Regular", "C");
    C.showDetail();
    buyItems(C,ks);

}
