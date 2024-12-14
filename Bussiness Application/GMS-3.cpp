#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include<string>
#include<sstream>
#include <limits>
using namespace std;

// function to give loction of tecxt on cosole
void gotoxy(int x, int y);
// this function to for the animation of text
void animationText();
// this fuction is use to print the starting logo
void startingLogo();

// costant aarry size of the user information
const int userArrSize = 100;

// name array for user
string users[userArrSize];
// password array for user
string passwords[userArrSize];
// role array for the user
string roles[userArrSize];

// initial userCount
int usersCounter = 0;

// signIn Fuction of for the user
string signIn(string name, string password);
// bool type functio is use for the valiud user
bool signUp(string name, string password, string role);
// fuction to print the Top Header of the Programm
void topHeader();
// function to print the heading manu Before the main manu of the fuctionalities
void MenuHeaderBeforeMainMenu(string subMenu);
// function to print the subManu header
void subMenu(string subMenu);
// function for the login of the user
int loginMenu();
// function to clear the Before going to the next option
void clearScreen();

// function use to store the data of the user
void storeData(string name,string password,string role);
// function use to the record parsing to the storing function
string parseRecord(string record, int field);
// function use to load the data from the file and print it on the console
void loadData();
void addUserData(string name,string password,string role,int usersCounter);

// ADMIN MANU
// Function use to the admin mainManu
int adminMenu();
// print the all of the functionalities of the admin
void adminInterface();
// Function top priont all the Products Price,Stock and their Names
void viewProduct();
// function use to add new stocks
void addProduct();
void addNewProduct();
// function use to update the price of the Products
void updateProductPrice();
// function to delete the Stock from the Previous stock
int deleteProduct();
void removeProductsFomArray();
// Function to check the New Updated list of the Products
void updateListCheck();
// fuction use to see the most sold products from the last week
void mostSoldProduct();
// function use to Give discount on the Products
float discountOnProduct();
// funtion to change the password of the account
string changePassword1();
// function to see the customer feedBacks on the products
void viewCustomersfeedback();
// function use to see the history of all sales
void historyCheck();

int productCount=0;
// array of the all the products Name in Stock
string totalProductName[105];

// string productName[5];

// array of  total product price
int totalProductPrice[105];
// array of the stock of all the Products
int totalProductStock[105];

// array of the Product's quantity of evey product which is on that index
int quantityOfProduct[5];
// size of array Colours and Size of  Products
int sizeOfarray = 4;
// array for colours availabe in the stock
string colours[4] = {"black", "white", "blue", "red"};
// array for the size available in total stock
string sizeAvailable[4] = {"small", "medium", "large", "Xlarge"};


// CUSTOMER
// function for showing allthe functionality of the customer
int customerMenu();
// function for customer main body to call all the function related to their options
void customerInterface();
// function for view all the products with their NAME,PRICE & their Stock
void viewProduct1();
// function for view all the popular products
void viewPopularProduct();
// function to add the carts in your order
void addToCart();
// Function to slect colours and size availabe on Products and fianalize your order
void buyProduct();
// function to remove the carts in your order
int deleteProductFromCart();
// function to view all the dicount on the products....
float discount1();
// function to check the bill of all the carts
void billsCheck();
// funtion to change the password of the account
string changePassword();
// function to add the feedBacks on the products
void customerFeedback();
// function to check your order history
void checkHistory();

// variable declare to use in the feedback Function
string loginName;
// feedaback counts for the customer
int feedbackCounter = 0;
// array of Customers name who can add feedBacks
string feedbackNames[100];
// array for total number of feedBacks
string feedbacks[100];

// variable for the total bill of all carts
float totalBill = 0;

float discount;
bool flag = false;

// array total sales prices of product
float SalesPrice[5];
bool salesTf[5];
// boolien array for the discount on sold products
bool discountTf[5];

// variable for the size of the product
string sizeOfProduct;
// variable for the color of the product
string colour;

// for check validation of the password
bool checkPassword(string Password);

string parseRecord(string record, int field);
void storeData1();
void loadData1();
void storeData();
void storeData2();
void loadData2();
void loadData3();
void storeData3();

main()
{
  
    loadData();
    loadData1();
    loadData2();
    // loadData3();
    system("cls");
    system("Color 09");
    int loginOption = 0;
    startingLogo();
    gotoxy(12, 13);
    animationText();
    Sleep(1000);
    system("cls");
    while (loginOption != 3)
    {
        topHeader();
        MenuHeaderBeforeMainMenu("LogIn");

        loginOption = loginMenu();
        if (loginOption == 1)
        {
            system("cls");
            string name;
            string password;
            string role;
            MenuHeaderBeforeMainMenu("SignIn");

            cout << "ENTER YOUR NAME = ";
            cin >> name;
            cout << endl;
            bool flag1 = true;
            while (flag1==true)
            {
                for (int i = 0; i < name.length(); i++)
                {
                    if (!((name[i] >= 97 && name[i] <= 122) || (name[i] >= 65 && name[i] <= 90)))
                    {
                        cout << "Invalid!! Enter Again" << endl;
                        cin >>  name ;
                        break;
                    }
                    else
                    {
                        flag1 = false;
                    }
                }
            }
            cout << "ENTER YOUR PASSWORD = ";
            cin >> password;
            
            cout << endl;
            role = signIn(name, password);
            if (role == "Admin" || role == "admin")
            {
                clearScreen();
                adminInterface();
            }
            else if (role == "Customer" || role == "customer")
            {
                clearScreen();
                customerInterface();
            }
            else if (role == "undefined")
            {
                cout << "YOU HAVE ENTERED WRONG USER! " << endl;
            }
            
        }

        else if (loginOption == 2)
        {
            system("cls");
            string name;
            string password;
            string role;
            topHeader();
            MenuHeaderBeforeMainMenu("SignUp");
            cout << "ENTER YOUR NAME = ";
            cin >> name;
            bool flag = true;
            while (flag)
            {
                for (int i = 0; i < name.length(); i++)
                {
                    if (!((name[i] >= 97 && name[i] <= 122) || (name[i] >= 65 && name[i] <= 90)))
                    {
                        cout << "Invalid!! Enter Again" << endl;
                        cin >>  name ;
                        break;
                    }
                    else
                    {
                        flag = false;
                    }
                }
            }

            cout << endl;
            cout << "ENTER YOUR PASSWORD = ";
            cin >> password;

            cout << endl;
            bool check=checkPassword(password);
            if(check==true)
            {
            cout << "ENTER YOUR ROLE = ";
            cin >> role;
            cout << endl;
            bool roleCheck = true;
            while (roleCheck==true)
            {
                for (int i = 0; i < role.length(); i++)
                {
                    if (!((role[i] >= 97 && role[i] <= 122) || (role[i] >= 65 && role[i] <= 90)))
                    {
                        cout << "Invalid!! Enter Again" << endl;
                        cout<<"ENTER ROLE : ";
                        cin >>  role ;
                        break;
                    }
                    else
                    {
                        roleCheck = false;
                    }
                }
            }

            bool isValidUser = signUp(name, password, role);
            if (isValidUser)
            {
                cout << "CONGRATULATIONS! SignedUp Successfully" << endl;
            }
            if (!isValidUser)
            {
                cout << " SIGNED UP FAILED! " << endl;
            }
            }
             else
            {
                cout << "YOU HAVE ENTERED WRONG INPUT....."<<endl;
            }
            
        }

       
        clearScreen();
    }
    
    
    storeData3();
}
int loginMenu()
{
    int i=0;
    int option;
    cout << "1. SignIn with your USER " << endl;
    cout << "2. SignUp to get your USER " << endl;
    cout << "3. Exit the Application" << endl;
    cout << endl;
    cout << "Enter Option ..... ";
    cin >> option;
    while(!(option>=1 && option<=3) && (i<=3))
    {
        cin >> option;
        if (option>=1 && option<=3)
        {
            break;
        }
        else
        {
            cout<<"Option is not Valid! "<<endl;
            break;
        }
        i++;
    }
    return option;
    
}
string signIn(string name, string password)
{
    for (int idx = 0; idx < usersCounter; idx++)
    {
        if (users[idx] == name && passwords[idx] == password)
        {
            return roles[idx];
        }
    }
    return "undefined";
}

bool signUp(string name, string password, string role)
{
    if (usersCounter < userArrSize)
    {
        
        if (role == "customer" || role == "Customer")
        {
            loginName = name;
        }
        storeData(name,password,role);
        addUserData(name,password,role,usersCounter);
        usersCounter++;
        return true;
    }

    else
    {
        return false;
    }
}

void addUserData(string name,string password,string role,int usersCounter)
{
    users[usersCounter] = name;
    passwords[usersCounter] = password;
    roles[usersCounter] = role;
}
void addNewProduct()
{
    string productName="";
    int productPrice=0;
    int productStock=0;
    bool flag1=true;
    cout<<"ENTER THE NAME OF PRODUCT TO ADD : ";
    cin>>productName;
    while (flag1)
            {
                for (int i = 0; i < productName.length(); i++)
                {
                    if (!((productName[i] >= 97 && productName[i] <= 122) || (productName[i] >= 65 && productName[i] <= 90)))
                    {
                        cout << "Invalid!! Enter Again" << endl;
                        cout<<"ENTER THE NAME OF PRODUCT TO ADD :";
                        cin >>  productName ;
                        break;
                    }
                    else
                    {
                        flag1 = false;
                    }
                }
            }
    cout<<"ENTER THE PRICE OF THE PRODUCT : ";
    cin>>productPrice;
    
    cout<<"ENTER THE STOCK OF THE PRODUCT : ";
    cin>>productStock;
    totalProductName[productCount]=productName;
    totalProductPrice[productCount]=productPrice;
    totalProductStock[productCount]=productStock;
    productCount++;
    storeData1();
    
}



void removeProductsFromArray()
{
    
    string product;
    cout << "ENTER THE NAME OF PRODUCT YOU WANT TO REMOVE : ";
    cin >> product;
    for (int i = 0; i < productCount; i++)
    {
        if (totalProductName[i] == product)
        {
            for (int j = i; j <productCount; j++)
            {

                totalProductName[j] = totalProductName[j + 1];
                totalProductPrice[j] = totalProductPrice[j + 1];
                totalProductStock[j]=totalProductStock[j+1];
            }
            cout << "------>>>PRODUCT REMOVED SUCCESSFULLY<<<------ " << endl;
            productCount--;
        }
        storeData3();
    }
  
}




void topHeader()
{
    cout << "" << endl;
    cout << "       " << endl;
    cout << "               " << endl;
    cout << "        GGGGGGGGGGGGGMMMMMMMM               MMMMMMMM   SSSSSSSSSSSSSSS         PPPPPPPPPPPPPPPPP   KKKKKKKKK    KKKKKKK" << endl;
    cout << "     GGG::::::::::::GM:::::::M             M:::::::M SS:::::::::::::::S        P::::::::::::::::P  K:::::::K    K:::::K" << endl;
    cout << "   GG:::::::::::::::GM::::::::M           M::::::::MS:::::SSSSSS::::::S        P::::::PPPPPP:::::P K:::::::K    K:::::K" << endl;
    cout << "  G:::::GGGGGGGG::::GM:::::::::M         M:::::::::MS:::::S     SSSSSSS        PP:::::P     P:::::PK:::::::K   K::::::K" << endl;
    cout << " G:::::G       GGGGGGM::::::::::M       M::::::::::MS:::::S                      P::::P     P:::::PKK::::::K  K:::::KKK" << endl;
    cout << "G:::::G              M:::::::::::M     M:::::::::::MS:::::S                      P::::P     P:::::P  K:::::K K:::::K   " << endl;
    cout << "G:::::G              M:::::::M::::M   M::::M:::::::M S::::SSSS                   P::::PPPPPP:::::P   K::::::K:::::K    " << endl;
    cout << "G:::::G    GGGGGGGGGGM::::::M M::::M M::::M M::::::M  SS::::::SSSSS              P:::::::::::::PP    K:::::::::::K     " << endl;
    cout << "G:::::G    G::::::::GM::::::M  M::::M::::M  M::::::M    SSS::::::::SS            P::::PPPPPPPPP      K:::::::::::K     " << endl;
    cout << "G:::::G    GGGGG::::GM::::::M   M:::::::M   M::::::M       SSSSSS::::S           P::::P              K::::::K:::::K    " << endl;
    cout << "G:::::G        G::::GM::::::M    M:::::M    M::::::M            S:::::S          P::::P              K:::::K K:::::K   " << endl;
    cout << " G:::::G       G::::GM::::::M     MMMMM     M::::::M            S:::::S          P::::P            KK::::::K  K:::::KKK" << endl;
    cout << "  G:::::GGGGGGGG::::GM::::::M               M::::::MSSSSSSS     S:::::S        PP::::::PP          K:::::::K   K::::::K" << endl;
    cout << "   GG:::::::::::::::GM::::::M               M::::::MS::::::SSSSSS:::::S  ....  P::::::::P          K:::::::K    K:::::K" << endl;
    cout << "     GGG::::::GGG:::GM::::::M               M::::::MS:::::::::::::::SS  ...... P::::::::P          K:::::::K    K:::::K" << endl;
    cout << "        GGGGGG   GGGGMMMMMMMM               MMMMMMMM SSSSSSSSSSSSSSS     ....  PPPPPPPPPP          KKKKKKKKK    KKKKKKK" << endl;
}



void MenuHeaderBeforeMainMenu(string submenu)
{
    string message = submenu + " Menu";
    cout << message << endl;
    cout << "--------->>>>" << endl;
}

void subMenu(string submenu)
{
    string message = "Main Menu > " + submenu;
    cout << message << endl;
    cout << "--------->>>>" << endl;
}

void clearScreen()
{
    cout << "Press Any Key to Continue.." << endl;
    getch();
    system("cls");
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void animationText()
{
    string text = "<<<<<GARMENTS MANAGEMENT SYSTEM>>>>>";
    string text1 = "<<<<<WELCOME  TO MALIK'S GARMENTS MANAGEMENT SYSTEM>>>>";
    int idx = 0;
    int index = 0;
    while (text[idx] != '\0')
    {
        cout << text[idx];
        Sleep(50);
        idx++;
    }
    gotoxy(4, 15);
    while (text1[index] != '\0')
    {
        cout << text1[index];
        Sleep(50);
        index++;
    }
    cout << endl
         << endl
         << endl;
}

void startingLogo()
{

    cout << " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ " << endl;
    cout << " @                                                          @ " << endl;
    cout << " @         @@@@@@@       MMM     MMM       $$$$$$           @ " << endl;
    cout << " @        @@              M M   M M       $$                @ " << endl;
    cout << " @        @@    @@@       M  M M  M        $$$$$$           @ " << endl;
    cout << " @        @@     @@  @@@  M   M   M   MMM       $$          @ " << endl;
    cout << " @         @@@@@@@   @@@ MMM     MMM  MMM  $$$$$$           @ " << endl;
    cout << " @                                                          @ " << endl;
    cout << " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ " << endl;
}

int adminMenu()
{
    int i=0;
    int option;
    cout << " SLECT ONE OF THE FOLLOWING OPTIONS--------- " << endl;
    cout << "1.Add Product	" << endl;
    cout << "2.View Product	 " << endl;
    cout << "3.Update Price of Product	 " << endl;
    cout << "4.Delete Product	 " << endl;
    cout << "5.Check list of Products	 " << endl;
    // cout << "6.Most Sold Products	 " << endl;
    cout << "6.Discount	 " << endl;
    cout << "7.Change Password " << endl;
    cout << "8.Feedback " << endl;
    cout << "9.History " << endl;
    cout << "10.Exit " << endl;
    cout << "Your Option.....";

    while(!(option>=1 && option<=11) && (i<=3))
    {
        cin >> option;
        if (option>=1 && option<=11)
        {
            break;
        }
        else
        {
            cout<<"Option is not Valid! "<<endl;
            break;
        }
        i++;
    }
    return option;

}

void adminInterface()
{
    int adminOption = 0;
    while (true)
    {
        topHeader();
        subMenu("");
        adminOption = adminMenu();
        if (adminOption == 1)
        {
            system("cls");
            topHeader();
            subMenu("Add Product");
            string opt2="";
            cout<<"1.ADD NEW PRODUCT"<<endl;
            cout<<"2.UPDATE STOCK"<<endl;
            cout<<"ENTER OPTION---->>>";

            cin>>opt2;
            if(opt2=="1"){
                addNewProduct();
            }
            else if(opt2=="2"){
                addProduct();
            }
            else{
                cout<<"Wrong Input!";
            }
        }

        if (adminOption == 2)
        {
            system("cls");
            topHeader();
            subMenu("View Product");
            viewProduct();
        }

        if (adminOption == 3)
        {
            system("cls");
            topHeader();
            subMenu("Update Price of Product");
            updateProductPrice();
        }

        if (adminOption == 4)
        {
            system("cls");
            topHeader();
            subMenu("Delete Product");
            string opt3="";
            cout<<"1.REMOVE PRODUCT"<<endl;
            cout<<"2.REMOVE STOCK"<<endl;
            cout<<"ENTER OPTION---->>>";
            cin>>opt3;
            if(opt3=="1"){
                removeProductsFromArray();
            }
            else if(opt3=="2"){
                deleteProduct();
            }
            else{
                cout<<"Wrong Input!";
            }
        }

        if (adminOption == 5)
        {
            system("cls");
            topHeader();
            subMenu("Check list of Products");
            updateListCheck();
        }

        if (adminOption == 6)
        {
            system("cls");
            topHeader();
            subMenu("Discount");
            discountOnProduct();
        }

        if (adminOption == 7)
        {
            system("cls");
            topHeader();
            subMenu("Change Password");
            changePassword1();
        }

        if (adminOption == 8)
        {
            system("cls");
            topHeader();
            subMenu("Feedback");
            viewCustomersfeedback();
        }

        if (adminOption == 9)
        {
            system("cls");
            topHeader();
            subMenu("History");
            historyCheck();
        }

        if (adminOption == 10)
        {
            break;
        }

        clearScreen();
    }
}

void addProduct()
{
    cout << "NAME OF THE PRODUCTS ARE ...... " << endl;
    for (int idx = 0; idx < productCount; idx++)
    {
        cout << idx + 1 << ". " << totalProductName[idx] << endl;
    }
    string press;
    string name1;
    int stockToAdd;
    int idx = 0;
    int temp = 0;

    while (idx != productCount)
    {
        cout << "ENTER THE NAME OF PRODUCT .. ";
        cin >> name1;
        
        for (int idx = 0; idx < productCount; idx++)
        {
            if (totalProductName[idx] == name1)
            {
                temp = idx;
                cout << "TOTAL STOCK OF " << name1 << " IS : " << totalProductStock[idx] << endl;
                break;
            }
            // else
            // {
            //     cout<<"YOU HAVE ENTER WRONG INPUT!TRY AGAIN...."<<endl;
            //     break;
            // }
        }

        cout << "Do you want to add more stock in it(yes/no): ";
        cin >> press;
        if (press == "yes" || press == "Yes")
        {
            cout << "ENTER NEW STOCK TO ADD : ";
            cin >> stockToAdd;
            totalProductStock[temp] = totalProductStock[temp] + stockToAdd;
            cout << totalProductStock[idx] << endl;
        }

        if (press == "no" || press == "No")
        {
            break;
        }

        else
        {
            cout<<"YOU HAVE ENTER WRONG INPUT!TRY AGAIN...."<<endl;
            break;
        }

        idx++;
    }
}


void viewProduct()
{
    cout << "\t\t\t"
         << "Product NAME"
         << "\t"
         << "Price"
         << "\t\t"
         << "Stock" << endl;
    for (int idx = 0; idx < productCount; idx++)
    {
        cout<< "\t\t\t" << totalProductName[idx] << "\t\t: " << totalProductPrice[idx] << "\t\t: " << totalProductStock[idx] << endl;
    }
}



void updateProductPrice()
{
    bool flag = false;
    int price;

    cout << "NAME OF THE PRODUCTS ARE ...... " << endl;

    for (int idx = 0; idx < productCount; idx++)
    {
        cout << idx + 1 << ". " << totalProductName[idx] << endl;
    }
    string name2;
    cout << "ENTER THE NAME OF PRODUCT TO UPDATE : ";
    cin>>name2;
    bool flag4 = true;
            while (flag4==true)
            {
                for (int i = 0; i < name2.length(); i++)
                {
                    if (!((name2[i] >= 97 && name2[i] <= 122) || (name2[i] >= 65 && name2[i] <= 90)))
                    {
                        cout << "Invalid!! Enter Again" << endl;
                        cout<<"ENTER THE NAME OF PRODUCT TO UPDATE ";
                        cin >>  name2 ;
                        break;
                    }
                    else
                    {
                        flag4 = false;
                    }
                }
            }
    int i = 0;
    for (int idx1 = 0; idx1 < productCount; idx1++)
    {
        if (totalProductName[idx1] == name2)
        {
            i = idx1;
            flag = true;
            break;
        }
    }

    if (flag)
    {
        cout << "PRICE OF THIS ITEM IS : " << totalProductPrice[i] << endl;
        cout << "ENTER THE NEW PRICE OF THE PRODUCT : ";
        cin >> price;
        
        totalProductPrice[i] = price;
        cout << "YOUR NEW PRICE IS : " << totalProductPrice[i] << endl;
    }
    else if (!flag)
    {

        cout << "YOU HAVE ENTER WRONG INPUT! TRY AGAIN...." << endl;
    }
}

void updateListCheck()
{
    cout << "\t\t\t"
         << "Product NAME"
         << "\t"
         << "Price"
         << "\t\t"
         << "Stock" << endl;
    for (int idx = 0; idx < productCount; idx++)
    {
        cout << "\t\t\t" << totalProductName[idx] << "\t\t: " << totalProductPrice[idx] << "\t\t: " << totalProductStock[idx] << endl;
    }
}

string changePassword1()
{
    bool flag = false;
    string username;
    cout << "ENTER THE USER NAME = ";
    cin >> username;
    cout << endl;
    string oldPassword;
    cout << "ENTER THE OLD PASSWORD = ";

    cin >> oldPassword;
    cout << endl;
    string newPassword;
    int index = 0;


    for (int idx = 0; idx < userArrSize; idx++)
    {
        if ((users[idx] == username) && (roles[idx] == "Admin" || roles[idx] == "admin") && (passwords[idx] == oldPassword))
        {
            index = idx;
            flag = true;
        }
    }
    if (flag)
    {
        cout << "ENTER YOUR NEW PASSWORD : ";
        cin >> newPassword;
        passwords[index] = newPassword;
        cout << "YOU HAVE CHANGED THE PASSWORD SUCCESSFULLY!" << endl;
    }
    else if (!flag)
    {
        cout << "SORRY!YOU HAVE ENTERED WRONG PASSWORD...." << endl;
    }
}



float discountOnProduct()
{
    bool flag = false;
    bool found1=true;
    int date;
    string month;
    cout << "ENTER THE DISCOUNT DATE ..... ";
    cin >> date;
    cout << "ENTER THE MONTH ...... ";
    cin>>month;
    while (!found1)
            {
                for (int i = 0; i < month.length(); i++)
                {
                    if (!((month[i] >= 97 && month[i] <= 122) || (month[i] >= 65 && month[i] <= 90)))
                    {
                        cout << "Invalid!! Enter Again" << endl;
                        cin >>  month ;
                        break;
                    }
                    else
                    {
                        found1 = false;
                    }
                }
            }

    for (int idx = 0; idx < productCount; idx++)
    {

        if ((month == "November" || month == "August" || month == "December") && (date >= 0 || date <= 9))
        {
            discount = totalProductPrice[idx] * 0.10;
            cout << "<<<YOUR DISCOUNTED PRICE OF FROM THE ORIGINAL PRICE.... :" << totalProductName[idx] << " IS : " << discount << endl;
            flag = true;
        }

        else if ((month == "April" || month == "March" || month == "May") && (date >= 11 || date <= 22))
        {
            discount = totalProductPrice[idx] * 0.50;
            cout << "<<<YOUR DISCOUNTED PRICE OF FROM THE ORIGINAL PRICE.... :" << totalProductName[idx] << " IS : Rs." << discount << endl;
            flag = true;
        }
        else
        {
            discount = 0;
            cout << " SORRY!THERE IS NO DISCOUNT DURING THESE DAYS!!! ";
            break;
        }
    }
}



int deleteProduct()
{
    cout << "NAME OF THE PRODUCTS ARE ...... " << endl;
    for (int idx = 0; idx < productCount; idx++)
    {
        cout << idx + 1 << ". " << totalProductName[idx] << endl;
    }
    string press;
    string name3;
    int stockToDelete;
    int index = 0;
    int tempVar = 0;

    while (index != productCount)
    {
        cout << "ENTER THE NAME OF PRODUCT .. ";
        cin >> name3;
        for (int index = 0; index < productCount; index++)
        {
            if (totalProductName[index] == name3)
            {
                tempVar = index;
                cout << "TOTAL STOCK OF " << name3 << " IS : " << totalProductStock[index] << endl;
                break;
            }
            else
            {
                cout << "YOU HAVE ENTER WRONG INPUT!TRY AGAIN...." << endl;
                break;
            }
        }
        cout << "Do you want to DELETE  stock in it(yes/no): ";
        cin >> press;
        if (press == "yes" || press == "Yes")
        {
            cout << "ENTER NEW STOCK TO Delete : ";
            cin >> stockToDelete;
            totalProductStock[tempVar] = totalProductStock[tempVar] - stockToDelete;
            cout << totalProductStock[index] << endl;
            break;
        }
        else if (press == "no" || press == "No")
        {
            break;
        }

        else
        {
            cout << "SORRY...YOU HAVE ENTER WRONG NUMBER !";
        }

        index++;
    }
}

void viewCustomersfeedback()
{
    cout << "FOLLOWING ARE THE FEEDBACKS OF YOUR CLINTS ......" << endl;
    cout << loginName << " : " << endl;
    cout << feedbacks[feedbackCounter] << endl;
}


void historyCheck()
{
    
    cout << "WELCOME TO HISTORY OF YOUR ALL ORDERS....." << endl;
    cout << endl;
    cout << "\t\t"
         << " ________________" << endl;
    cout << "\t\t"
         << "| REMAINING STOCK|" << endl;
    cout << "\t\t"
         << "|________________|" << endl;
    for (int idx = 0; idx < productCount; idx++)
    {

        cout << idx + 1 << ". "
             << "REMAINING STOCK OF :" << totalProductName[idx] << " Is : " << totalProductStock[idx] << " WITH PRICE OF : " << totalProductPrice[idx] << endl;
    }
    cout << endl
         << endl;
    cout << "\t\t"
         << " ________________" << endl;
    cout << "\t\t"
         << "| <<CARTS SOLD>> |" << endl;
    cout << "\t\t"
         << "|________________|" << endl;
    for (int idx = 0; idx < productCount; idx++)
    {
        if (SalesPrice[idx] > 0)
        {
            cout << idx + 1 << ". "
                 << "<<<FINAL ORDERD PRICE OF.... :" << totalProductName[idx] << " IS : " << SalesPrice[idx] << " WITH THE COLOUR " << colour << " WITH THE SIZE "
                 << "<<<" << sizeOfProduct << ">>>" << endl;
        }
    }
    
    cout << "THE FINAL PRICE OF THE Client IS .... " << totalBill << endl;
    
}


int customerMenu()
{
    int i=0;
    int option;
    cout << " SLECT ONE OF THE FOLLOWING OPTION' --------- " << endl;
    cout << " 1.View Product" << endl;
    // cout << " 2.View Popular Products" << endl;
    cout << " 2.Add to cart" << endl;
    cout << " 3.buy Product" << endl;
    cout << " 4.Remove Product from the cart" << endl;
    cout << " 5.Discount" << endl;
    cout << " 6.Bills" << endl;
    cout << " 7.Change Password" << endl;
    cout << " 8.Feedback" << endl;
    cout << " 9.History" << endl; 
    cout   << " 10.Exit" << endl;
    cout << "Your Option..";
    // while (!(cin >> option))
    // {
    //      cin.clear();
    //      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //      cout << "Invalid! Enter again:";
    // }
    while(!(option>=1 && option<=10) && (i<=3))
    {
        cin >> option;
        if (option>=1 && option<=11)
        {
            break;
        }
        else
        {
            cout<<"Option is not Valid! "<<endl;
        }
        i++;
    }
    return option;
}

void customerInterface()
{
    int userOption = 0;

    while (true)
    {
        topHeader();
        subMenu("");
        userOption = customerMenu();
        if (userOption == 1)
        {
            system("cls");
            topHeader();
            subMenu("View Product");
            viewProduct1();
        }

        if (userOption == 2)
        {
            system("cls");
            topHeader();
            subMenu("Add to cart");
            addToCart();
        }

        if (userOption == 3)
        {
            system("cls");
            topHeader();
            subMenu("buy Product");
            buyProduct();
        }

        if (userOption == 4)
        {
            system("cls");
            topHeader();
            subMenu("Remove Product from the cart");
            deleteProductFromCart();
        }

        if (userOption == 5)
        {
            system("cls");
            topHeader();
            subMenu("Discount");
            discount1();
        }

        if (userOption == 6)
        {
            system("cls");
            topHeader();
            subMenu("Bills");
            billsCheck();
        }

        if (userOption == 7)
        {
            system("cls");
            topHeader();
            subMenu("Change Password");
            changePassword();
        }

        if (userOption == 8)
        {
            system("cls");
            topHeader();
            subMenu("Feedback");
            customerFeedback();
        }

        if (userOption == 9)
        {
            system("cls");
            topHeader();
            subMenu("History");
            checkHistory();
        }

        if (userOption == 10)
        {
            break;
        }

        clearScreen();
    }
}

void viewProduct1()
{
    cout << "\t\t\t"
         << "Product NAME"
         << "\t"
         << "Price"
         << "\t\t"
         << "Stock" << endl;
    for (int idx = 0; idx < productCount; idx++)
    {
        cout << "\t\t\t" << totalProductName[idx] << "\t\t: " << totalProductPrice[idx] << "\t\t: " << totalProductStock[idx] << endl;
    }
}

string changePassword()
{
    bool flag = false;
    string username;
    cout << "ENTER THE USER NAME = ";
    cin >> username;
    cout << endl;
    string oldPassword;
    cout << "ENTER THE OLD PASSWORD = ";
    cin >> oldPassword;
    cout << endl;
    string newPassword;
    int index = 0;

    for (int idx = 0; idx < userArrSize; idx++)
    {
        if ((users[idx] == username) && (roles[idx] == "Customer" || roles[idx] == "customer") && (passwords[idx] == oldPassword))
        {
            index = idx;
            flag = true;
        }
    }
    if (flag)
    {
        cout << "ENTER YOUR NEW PASSWORD : ";
        cin >> newPassword;
        passwords[index] = newPassword;
        cout << "YOU HAVE CHANGED THE PASSWORD SUCCESSFULLY!" << endl;
    }
    else if (!flag)
    {
        cout << "SORRY!YOU HAVE ENTERED WRONG PASSWORD...." << endl;
    }
}

float discount1()
{
    bool flag1=true;
    int date;
    string month;

    cout << "ENTER THE DISCOUNT DATE ..... ";
    while (!(cin >> date))
    {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "Invalid! Enter again:";
    }
    cout << "ENTER THE MONTH ...... ";
    cin>>month;
    while (flag1)
            {
                for (int i = 0; i < month.length(); i++)
                {
                    if (!((month[i] >= 97 && month[i] <= 122) || (month[i] >= 65 && month[i] <= 90)))
                    {
                        cout << "Invalid!! Enter Again" << endl;
                        cout << "ENTER THE MONTH ...... ";
                        cin >>  month ;
                        break;
                    }
                    else
                    {
                        flag1 = false;
                    }
                }
            }


    if ((month == "November" || month == "August" || month == "December") && (date >= 0 || date <= 9))
    {
        cout << "<<<YOUR DISCOUNTED PRICE OF PRODUCT IN THESE DAYS IS 10%..... " << endl;
    }

    else if ((month == "April" || month == "March" || month == "May") && (date >= 11 || date <= 22))
    {
        cout << "<<<YOUR DISCOUNTED PRICE OF PRODUCT IN THESE DAYS IS 50%..... " << endl;
    }
    else
    {
        cout << " SORRY!THERE IS NO DISCOUNT DURING THESE DAYS!!! ";
    }
}

void addToCart()
{
    int index = 0;
    string press;
    int stockToAddCart;

    string name;
    while (index != productCount)
    {
        cout << "NAME OF THE PRODUCTS ARE ...... " << endl;

        cout << "\t\t\t"
             << "Product NAME"
             << "\t"
             << " Price"
             << "\t\t"
             << " Stock" << endl;
        for (int idx = 0; idx < productCount; idx++)
        {
            cout << "\t\t\t" << totalProductName[idx] << "\t\t: " << totalProductPrice[idx] << "\t\t: " << totalProductStock[idx] << endl;
        }

        cout << "Do you want to add product in cart (yes/no): ";
        cin >> press;

        if (press == "yes" || press == "Yes")
        {
            cout << "ENTER THE NAME OF THE PRODUCT : ";
            cin >> name;
            bool checkShirts;
    while (checkShirts)
    {
      for (int i = 0; i < name.length(); i++)
                {
                    if (!((name[i] >= 97 && name[i] <= 122) || (name[i] >= 65 && name[i] <= 90)))
                    {
                        cout << "Invalid!! Enter Again" << endl;
                        cin >>  name ;
                        break;
                    }
                    else
                    {
                        checkShirts = false;
                    }
                }  
    }
            cout << "ENTER  THE QUANTITY OF PRODUCT TO ADD IN YOUR CART : ";
            cin >> stockToAddCart;

            for (int i = 0; i < productCount; i++)
            {
                if (name == totalProductName[i])
                {
                    quantityOfProduct[i] = stockToAddCart;
                    totalProductStock[i] = totalProductStock[i] - quantityOfProduct[i];
                    discountTf[i] = true;
                    salesTf[i] = true;
                    // sales[idx]=true;
                    // break;
                }
                cout << totalProductName[i] << " : " << quantityOfProduct[i] << endl;
            }
        }

        else if (press == "no" || press == "No")
        {
            break;
        }

        else
        {
            cout << "YOU HAVE ENTER WRONG INPUT!TRY AGAIN...." << endl;
        }
        clearScreen();

        index++;
    }
}

void buyProduct()
{
    string press;
    // string colour;
    cout << "ENTER THE COLOUR OF PRODUCT : ";
    cin >> colour;

    for (int idx = 0; idx < 4; idx++)
    {
        if (colour == colours[idx])
        {
            cout << "YOUR SLECTED colour OF PRODUCT IS : " << colour << endl;
            break;
        }
    }

    // string sizeOfProduct;
    cout << "ENTER THE SIZE OF THE PRODUCT : ";
    cin >> sizeOfProduct;

    for (int idx = 0; idx < 4; idx++)
    {
        if (sizeOfProduct == sizeAvailable[idx])
        {
            cout << "YOUR SLECTED SIZE OF PRODUCT IS : " << sizeOfProduct << endl;
            break;
        }
    }

    cout << "PLEASE Confirm YOUR ORDER  IF YOU WANT (yes): ";
    cin >> press;
    bool pressboolien;
    while (pressboolien)
    {
      for (int i = 0; i < press.length(); i++)
                {
                    if (!((press[i] >= 97 && press[i] <= 122) || (press[i] >= 65 && press[i] <= 90)))
                    {
                        cout << "Invalid!! Enter Again" << endl;
                        cin >>  press ;
                        break;
                    }
                    else
                    {
                        pressboolien = false;
                    }
                }  
    }
    if (press == "yes" || press == "Yes")
    {
        cout << "Thanks For Placing Your Order ...NOW CHECK ORDER DETAIL FROM ORDER HISTORY.... " << endl;
    }
    else
    {
        cout<<"wrong input!"<<endl;
    }
}

int deleteProductFromCart()
{
    int index = 0;
    string press;
    int stockToRemoveCart;
    int reAdd;
    bool flag=true;
    string name;
    while (index != productCount)
    {
        cout << "NAME OF THE PRODUCTS ARE ...... " << endl;

        cout << "\t\t"
             << "No."
             << "\t\t"
             << "Product NAME"
             << "\t"
             << "Price"
             << "\t\t"
             << "Stock" << endl;
        for (int idx = 0; idx < productCount; idx++)
        {
            cout << "\t\t" << idx + 1 << ". "
                 << "\t\t" << totalProductName[idx] << "\t\t: " << totalProductPrice[idx] << "\t\t: " << totalProductStock[idx] << endl;
        }

        cout << "SLECT ONE OF THE ABOVE PRODUCT...." << endl;

        cout << "Do you want to remove product in cart (yes/no): ";
        cin >> press;
        if (press == "yes" || press == "Yes")
        {
            cout << "ENTER THE NAME OF THE PRODUCT : ";
            //   while (flag)
            // {
            //     for (int i = 0; i < name.length(); i++)
            //     {
            //         if (!((name[i] >= 97 && name[i] <= 122) || (name[i] >= 65 && name[i] <= 90)))
            //         {
            //             cout << "Invalid!! Enter Again" << endl;
            //             cin >>  name ;
            //             break;
            //         }
            //         else
            //         {
            //             flag = false;
            //         }
            //     }
            }
            cout << "ENTER  THE QUANTITY OF PRODUCT TO REMOVE IN YOUR CART : ";
            cin >> stockToRemoveCart;

            for (int i = 0; i < productCount; i++)
            {
                reAdd = totalProductStock[i] + stockToRemoveCart;
                if (reAdd > totalProductStock[i])
                {
                    cout << "SORRY! YOUR INPUT IS EXCEEDED TO THE ORIGINAL STOCK ....   " << endl;
                    break;
                }
                else if (reAdd < totalProductStock[i])
                {

                    quantityOfProduct[i] = stockToRemoveCart;
                    if (totalProductName[i] == name)
                    {
                        totalProductStock[i] = totalProductStock[i] + quantityOfProduct[i];
                        cout << totalProductName[i] << " : " << quantityOfProduct[i] << endl;
                        break;
                    }
                }
            }
        
        if (press == "no" || press == "No")
        {
            break;
        }

        else
        {
            cout << "YOU HAVE ENTER WRONG INPUT!TRY AGAIN...." << endl;
            break;
        }

    index++;
        clearScreen();

    }
}
   


void billsCheck()
{

    // addToCart();

    cout << " ENTER ANY KEY TO CHECK YOUR CARTS ..... " << endl;
    cout << "\t\t"
         << "Product NAME"
         << "\t"
         << " Quantity"
         << "\t"
         << " Price" << endl;
    for (int i = 0; i < productCount; i++)
    {
        cout << "\t\t" << totalProductName[i] << "\t\t: " << quantityOfProduct[i] << "\t\t: " << totalProductPrice[i] << endl;
    }
    bool flag1=true;
    int price;
    float discount;
    int date;
    float Bill = 0;
    string month;
    cout << "ENTER THE Today DATE ..... ";
    cin >> date;

    cout << "ENTER THE MONTH ...... ";
    cin>>month;
    while (flag1)
            {
                for (int i = 0; i < month.length(); i++)
                {
                    if (!((month[i] >= 97 && month[i] <= 122) || (month[i] >= 65 && month[i] <= 90)))
                    {
                        cout << "Invalid!! Enter Again" << endl;
                        cout << "ENTER THE MONTH ...... ";
                        cin >>  month ;
                        break;
                    }
                    else
                    {
                        flag1 = false;
                    }
                }
            }

    getch();

    for (int idx = 0; idx < productCount; idx++)
    {
        if (((month == "November" || month == "August" || month == "December") && (date >= 0 && date <= 9)) && discountTf[idx] == true && salesTf[idx] == true)
        {

            discount = quantityOfProduct[idx] * totalProductPrice[idx] * 0.10;
            price = totalProductPrice[idx] * quantityOfProduct[idx];
            Bill = price - discount;
            cout << "<<<YOUR TOTAL PRICE OF.... :" << totalProductName[idx] << " IS : " << Bill << endl;
            flag = true;
            SalesPrice[idx] = Bill;
        }

        else if (((month == "April" || month == "March" || month == "May") && (date >= 11 && date <= 22)) && discountTf[idx] == true && salesTf[idx] == true)
        {
            discount = quantityOfProduct[idx] * totalProductPrice[idx] * 0.50;
            price = totalProductPrice[idx] * quantityOfProduct[idx];
            Bill = price - discount;
            cout << "<<<YOUR TOTAL PRICE OF.... :" << totalProductName[idx] << " IS : " << Bill << endl;
            flag = true;
            SalesPrice[idx] = Bill;
        }

        if (flag == false)
        {
            discount = 0;
            Bill = totalProductPrice[idx] * quantityOfProduct[idx];
            cout << "<<<YOUR TOTAL PRICE OF.... :" << totalProductName[idx] << " IS : " << Bill << endl;
            SalesPrice[idx] = Bill;
        }

        discountTf[idx] = false;
        salesTf[idx] = false;
        flag = false;
        totalBill = totalBill + Bill;
    }
    cout << "YOUR TOTAL BILL IS : " << totalBill << endl;
    storeData2();
}


void customerFeedback()
{

    cout << "Enter YOU FEEDBACK ON PRODUCT : " << endl;
    cin.clear();
    cin.ignore();
    getline(cin, feedbacks[feedbackCounter]);
    cout << "THANKS FOR LEAVING YOUR REVIEW ON OUR PRODUCTS....!" << endl;
    getch();
}

void checkHistory()
{
    cout << "LET'S CHECK YOUR ORDER HISTORY....." << endl;
    cout << " DEAR " << loginName << " : " << endl;
    cout << "THANKS FOR PLACING YOUR ORDER..... " << endl;
    cout << "\t\t\t"
         << "FOLLOWINGS ARE YOUR ORDER DETAILS....." << endl;
    int index = 0;

    cout << "YOUR HAVE SELECTED THE FOLLOWING PRODUCTS>>>>>" << endl;
    for (int idx = 0; idx < productCount; idx++)
    {
        if (SalesPrice[idx] > 0)
        {
            cout << "<<<YOUR ORDERD PRICE OF.... :" << totalProductName[idx] << " IS : " << SalesPrice[idx] << " WITH THE COLOUR " << colour << " WITH THE SIZE "
                 << "<<<" << sizeOfProduct << ">>>" << endl;
        }
    }

    cout << "YOUR FINAL PRICE OF THE BILL IS : " << totalBill << endl;
   
}

void storeData(string name,string password,string role)
{
    
    fstream myfile;
    myfile.open("loginData1.txt", ios::app);
        myfile << name <<endl;
        myfile << password << endl;
        myfile << role<<endl;
        // // myfile << feedbackNames[x] << ",";
        // myfile << feedbacks[x] << ",";
        // myfile << colours[x] << ",";
        // myfile << sizeAvailable[x] << endl;
    myfile.close();
}

string parseRecord(string record, int field)
{
    int commaCount = 1;
    string item="";
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
   
    return item;
}

void loadData()
{
    string name;
    string password;
    string role;
    fstream myfile;
    myfile.open("loginData1.txt", ios::in);
    while ( getline(myfile,name) && getline (myfile , password) && getline (myfile,role))
    {

        users[usersCounter] = name;
        passwords[usersCounter] = password;
        roles[usersCounter] = role;
       
        usersCounter++;
    }


    myfile.close();
}

bool checkPassword(string Password)
{
    bool flag=false;
    int length =Password.length();
    int index=0;
    if (length>4)
    {
        for(int idx=0; idx<usersCounter;idx++)
        {
            if(Password==passwords[idx])
        {
            return flag;
        }
        }
    

    while(index<length)
    {
        if((Password[index]>63 && Password[index]<91) || (Password[index]>96 && Password[index]<123) || (Password[index]>47 && Password[index]<58))
        {
            index++;
        }
        else
        {
            return flag;
        }
    }
}
        flag=true;
    }


void storeData1()
{
    int x=0;
    fstream myfile;
    myfile.open("data.txt", ios::out);
    getch();
    while(x<productCount)
    {
        myfile << totalProductName[x] << ",";
        myfile << totalProductPrice[x] << ",";
        myfile << totalProductStock[x]<< "," << endl;
        // myfile << quantityOfProduct[x] <<endl;
        x++;
    }
    myfile.close();
}

void loadData1()
{
    
    string record;
    fstream myfile;
    myfile.open("data.txt", ios::in);
    while(getline(myfile,record))
    {
        totalProductName[productCount] = parseRecord(record, 1);
        totalProductPrice[productCount] = stoi(parseRecord(record, 2));
        totalProductStock[productCount] = stoi(parseRecord(record, 3));
        // quantityOfProduct[x] = stoi(parseRecord(record, 4));
        productCount++;
    }
    myfile.close();
}



void storeData2()
{
    fstream myfile;
    myfile.open("History.txt", ios::out);
    int x=0;
    while(x<1)
    {
        myfile << loginName<< ",";
        myfile <<quantityOfProduct[x]<< ",";
        myfile << SalesPrice[x]<< ",";
        myfile<<totalBill<<endl;
        x++;
    }
    myfile.close();
}


void loadData2()
{
    string record;
    fstream myfile;
    myfile.open("History.txt", ios::in);
    while(getline(myfile,record))
    {
        loginName=parseRecord(record, 1);
        quantityOfProduct[productCount]=stoi(parseRecord(record,2));
        SalesPrice[productCount]=stoi(parseRecord(record, 3));
        totalBill=stoi(parseRecord(record, 4));
        productCount++;
    }
}


void storeData3()
{
    fstream myfile;
    myfile.open("data.txt", ios::out);
    for (int i = 0; i < productCount; i++)
    {
        myfile << totalProductName[i] << ',' << totalProductPrice[i] << ',' << totalProductStock[i] << endl;
    }
    myfile.close();
}



void loadData3()
{
    string record;
    fstream myfile;
    myfile.open("data.txt", ios::in);
    while(getline(myfile,record))
    {
        totalProductName[productCount]=parseRecord(record, 1);
        totalProductPrice[productCount]=stoi(parseRecord(record, 2));
        totalProductStock[productCount]=stoi(parseRecord(record, 3));
     
    }
}
