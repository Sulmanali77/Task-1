#include<iostream>
using namespace std;
struct item{
	string code;
	string description;
	double price;
};
main()
{
	//arrays store the item details
	item cases[] = {{"A1", "Compact", 75.00}, {"A2", "Tower", 150.00}};
    item ram[] = {{"B1", "8 GB", 79.99}, {"B2", "16 GB", 149.99}, {"B3", "32 GB", 299.99}};
    item hdd[] = {{"C1", "1 TB HDD", 49.99}, {"C2", "2 TB HDD", 89.99}, {"C3", "4 TB HDD", 129.99}};
    item additionalitem[] = {
        {"D1", "240 GB SSD", 59.99}, {"D2", "480 GB SSD", 119.99},
        {"E1", "1 TB HDD", 49.99}, {"E2", "2 TB HDD", 89.99}, {"E3", "4 TB HDD", 129.99},
        {"F1", "DVD/Blu-Ray Player", 50.00}, {"F2", "DVD/Blu-Ray Re-writer", 100.00},
        {"G1", "Standard Version", 100.00}, {"G2", "Professional Version", 175.00}
    };
    item selectedcomponent[3];
    cout <<"Select one case: "<<endl;
    for(int i=0;i<2;i++)
    	cout <<cases[i].code<<" . "<<cases[i].description<<" $ "<<cases[i].price<<endl;
	int casechoice;
    cin >> casechoice;
    
    selectedcomponent[0]=cases[casechoice-1];

	cout <<"Select one RAM: "<<endl;
    for (int i = 0; i < 3; i++) {
        cout << ram[i].code << ". " << ram[i].description << " - $" << ram[i].price << endl;
    }
    int ramchoice;
    cin >> ramchoice;
    selectedcomponent[1] = ram[ramchoice - 1];

    cout << "Select one Main Hard Disk Drive:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << hdd[i].code << ". " << hdd[i].description << " - $" << hdd[i].price << endl;
    }
    int hddchoice;
    cin >> hddchoice;
    selectedcomponent[2] = hdd[hddchoice - 1];
	
	// Calculate the price of the computer
    double totalPrice=selectedcomponent[0].price+selectedcomponent[1].price+selectedcomponent[2].price;
	// Selected additional items
    item selectedadditionalitem[6];  // Maximum 6 additional items

    char wadditionalitem;
    cout << "Do you want to purchase additional items (Yes/No)? ";
    cin >> wadditionalitem;
    
    int nadditionalitem = 0;  // Counter for selected additional items

    if (toupper(wadditionalitem) == 'Y') {
        cout << "Choose additional items (enter item codes, 0 to finish):" << endl;
        for (int i = 0; i < 9; i++) {
            cout << additionalitem[i].code << ". " << additionalitem[i].description << " - $" << additionalitem[i].price << endl;
        }

        while (true) {
            int itemchoice;
            cin >> itemchoice;

            if (itemchoice == 0) {
                break;  // Finish choosing additional items
            }

            selectedadditionalitem[nadditionalitem] = additionalitem[itemchoice - 1];
            totalPrice += additionalitem[itemchoice - 1].price;
            nadditionalitem++;
        }
    }
	// Calculate the discount based on the number of additional items
    double discount = 0.0;

    if (nadditionalitem == 1) {
        discount = 0.05 * totalPrice;  // 5% discount
    } else if (nadditionalitem >= 2) {
        discount = 0.10 * totalPrice;  // 10% discount
    }
    // Calculate the final price
    double finalPrice = totalPrice - discount;

    // Output the selected items, price, discount, and final price
    cout << "Selected components:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << selectedcomponent[i].description << endl;
    }

    cout << "Selected additional items:" << endl;
    for (int i = 0; i < nadditionalitem; i++) 
        cout << selectedadditionalitem[i].description << endl;
    
    cout << "Total Price: $" << totalPrice << endl;
    cout << "Discount: $" << discount << endl;
    cout << "Final Price: $" << finalPrice << endl;

    // Calculate the amount saved
    double amountSaved = totalPrice - finalPrice;

    cout << "Amount Saved: $" << amountSaved << endl;

    return 0;
}
