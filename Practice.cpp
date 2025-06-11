# include <iostream>
using namespace std ;

const int m = 50;
class items
{
    int itemcode [m] ; float itemprice[m]; int count ;
    
    public : 
    void CNT()
    {
        count = 0;
    }
    void getitem()
    {
        cout<<"Enter item code : ";
        cin>>itemcode[count];
        cout<<"Enter item price : ";
        cin>>itemprice[count];
        count++;
    }
    void displaysum()
    {
        float sum =0;
        for (int i=0; i<count ; i++)
        {
            sum= sum + itemprice[i];
        }
        cout<<"\nTotal Value : "<<sum<<endl;
    }
    void remove ()
    {
        int a;
        cout<<"Enter itemcode : ";
        cin>>a;
        for(int i=0; i<count; i++)
        {
            if(itemcode[i]==a)
            {
                itemprice[i]=0;
            }
        }
    }
    void displayitems()
    {
        cout<<"\n Code Price \n";
        for (int i=0; i<count; i++)
        {
            cout<<"\n"<<itemcode[i];
            cout<<"\n"<<itemprice[i];
        }
        cout<<endl;
    }
};
int main()
{
    items order; order.CNT(); int x;
    do
    {
        cout<<"\nYou can do the following:\n\n";
        cout<<"Enter appropraite number\n";
        cout<<"1: Add an item\n";
        cout<<"2: Display total value\n";
        cout<<"3: Delete an item\n";
        cout<<"4: Display all item\n";
        cout<<"5: Quit\n";
        cout<<"\nWhat is your option?\n";
        cin>>x;
        switch (x)
        {
        case 1:
            order.getitem();
            break;
        case 2:
            order.displaysum();
            break;
        case 3:
            order.remove();
            break;
        case 4:
            order.displayitems();
            break;
        case 5:
            break;
        default: cout<<"**ERROR!!**\nTRY AGAIN\n";
            break;
        }
    }while (x!=5);

    return 0;
}