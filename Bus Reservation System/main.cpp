#include <iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;

struct name
{
    int seat_no;
    string first_name;
    string last_name ;
    string phone_no ;
    name(){}
    name(string s)
    {
        stringstream ss(s);
        ss>>seat_no>>first_name>>last_name>>phone_no;
    }
    string get_string()
    {
        return (to_string(seat_no)+" "+first_name+" "+last_name+" "+phone_no);
    }
};

int main()
{
    vector<struct name>  vec ;
    ifstream ifile("file.txt");
    while(ifile)
    {
        string s;
        getline(ifile,s);
        if(s.length()==0)
            break;
        vec.emplace(vec.end(),s);
    }
    ifile.close();

    cout<<" \n\n        Bus No : HR12AB7777\n\n" ;
    cout<<"Starting Location : DTU (IIT Bawana )\n";
    cout<<"Destination : Hyderabad\n\n\n";
    char arr [52][2];
    for (int i =1; i <=52 ; ++i)
    {
        arr[i-1][1] = i %10 + '0';
        arr[i-1][0] = i /10 + '0';
    }
    for(auto it:vec)
    {
        int sno=it.seat_no;
        arr[sno-1][0]='N';
        arr[sno-1][1]='A';
    }

    cout<<"*************************************************\n                                                |";

    cout<<"\n<<<<<<<<< THIS IS THE FRONT ENTRY GATE          |\n                                                |\n";
    cout<<"**********************            ***************\n";
    for (int i = 00; i <=46 ; i+=05)
    {
        if(i<=6)
        {
            cout<<"|      |      |      |            |      |      |\n";
            cout<<"|  "<<arr[i][0]<<arr[i][1]<<"  |  "<<arr[i+1][0]<<arr[i+1][1]<<"  |  "<<arr[i+2][0]<<arr[i+2][1]<<"  |            |  "<<arr[i+3][0]<<arr[i+3][1]<<"  |  "<<arr[i+4][0]<<arr[i+4][1]<<"  |"<<endl ; //,arr[i][0] , arr[i][1],arr[i+1][0] , arr[i+1][1],arr[i+2][0] , arr[i+2][1],arr[i+3][0] , arr[i+3][1],arr[i+4][0] , arr[i+4][1] ;
            cout<<"|      |      |      |            |      |      |\n";
            cout<<"**********************            ***************\n";
        }
        else if (i<=41)
        {
            cout<<"|      |      |      |            |      |      |\n";
            cout<<"|  "<<arr[i][0]<<arr[i][1]<<"  |  "<<arr[i+1][0]<<arr[i+1][1]<<"  |  "<<arr[i+2][0]<<arr[i+2][1]<<"  |            |  "<<arr[i+3][0]<<arr[i+3][1]<<"  |  "<<arr[i+4][0]<<arr[i+4][1]<<"  |"<<endl ;  //printf("|  %c%c  |  %c%c  |  %c%c  |            |  %c%c  |  %c%c  |\n",arr[i][0] , arr[i][1],arr[i+1][0] , arr[i+1][1],arr[i+2][0] , arr[i+2][1],arr[i+3][0] , arr[i+3][1],arr[i+4][0] , arr[i+4][1]) ;
            cout<<"|      |      |      |            |      |      |\n";
            cout<<"**********************            ***************\n";
        }
        else
        {
            cout<<"                                                |\n<<<<<THIS IS THE BACK ENTRY GATE"
                  "                |\n                                                |\n";
            cout<<"|      |      |      |      |      |      |     |\n";
            cout<<"|  "<<arr[i][0]<<arr[i][1]<<"  |  "<<arr[i+1][0]<<arr[i+1][1]<<"  |  "<<arr[i+2][0]<<arr[i+2][1]<<"  |  "<<arr[i+3][0]<<arr[i+3][1]<<"  |  "<<arr[i+4][0]<<arr[i+4][1]<<"  |  "<<arr[i+5][0]<<arr[i+5][1]<<"  |  "<<arr[i+6][0]<<arr[i+6][1]<<" |"<<endl ; // \n",arr[i][0] , arr[i][1],arr[i+1][0] , arr[i+1][1],arr[i+2][0] , arr[i+2][1],arr[i+3][0] , arr[i+3][1],arr[i+4][0] , arr[i+4][1],arr[i+5][0], arr[i+5][1] ,arr[i+6][0] ,arr[i+6][1]) ;
            cout<<"|      |      |      |      |      |      |     |\n";
            cout<<"*************************************************\n";
            cout<<"         BREAK GLASS IN CASE OF EMERGENCY        \n\n";
        }
    }


    int no_of_seats_you_want_to_reserve ;
    cout<<"    Price of each ticket is 699 only !!!!" << endl;
    cout<<"Enter the no of seats you want to reserve :";
    cin >> no_of_seats_you_want_to_reserve ;
    if (no_of_seats_you_want_to_reserve>=53)
    {
        int other_no_of_seats_you_want_to_reserve;
        cout<<"The amount of seat you have entered are more than the total no of seats in the bus \n" ;
        cout<<"Select any other no of seats you want to reserve : ";
        cin>> other_no_of_seats_you_want_to_reserve ;
        no_of_seats_you_want_to_reserve = other_no_of_seats_you_want_to_reserve;
    }
    for (int i = 1; i <=no_of_seats_you_want_to_reserve ; i++)
    {
        struct name a ;
        cout<<"Enter the seat no you want to reserve between 1 and 52 : ";
        cin>>a.seat_no;
        for (int j =1 ; j <= vec.size() ; j++)
        {
            if(a.seat_no == vec.at(j-1).seat_no)
            {
                cout << "!!!!  Oops !!!  The seat is not vacant now   !!!!!!" << endl;
                int another_seat_no;
                cout << "Enter any other seat no :";
                cin >> another_seat_no;
                a.seat_no = another_seat_no;
            }
        }

        cout<<"Enter the First Name Of the passenger:";
        string first_name ;
        cin>>a.first_name;

        cout<<"Enter the Last Name Of the passenger :";

        cin>>a.last_name;

        cout<<"Enter your mobile no :";
        cin>>a.phone_no;


        int j = a.seat_no ;
        arr[j-1][1] = 'A';
        arr[j-1][0] = 'N';
        vec.push_back(a);

    }
    system("cls");

    remove("file.txt");
    ofstream ofile("file.txt");
    for(auto &it:vec)
    {
        ofile<<it.get_string()<<"\n";
    }
    ofile.close();


    cout<<" \n\n        Bus No : HR12AB7777\n\n" ;
    cout<<"Starting Location : DTU (IIT Bawana )\n";
    cout<<"Destination : Hyderabad\n\n\n";
    cout<<"*************************************************\n                                                |";

    cout<<"\n<<<<<<<<< THIS IS THE FRONT ENTRY GATE          |\n                                                |\n";
    cout<<"**********************            ***************\n";

//    cout<<"*************************************************|\n                                              |";
//    cout<<"                                              |\n<<<<<<<<< THIS IS THE FRONT ENTRY GATE               |\n\n";
//    cout<<"**********************            ***************\n";
    for (int i = 00; i <=46 ; i+=05)
    {
        if(i<=6)
        {
            cout<<"|      |      |      |            |      |      |\n";
            cout<<"|  "<<arr[i][0]<<arr[i][1]<<"  |  "<<arr[i+1][0]<<arr[i+1][1]<<"  |  "<<arr[i+2][0]<<arr[i+2][1]<<"  |            |  "<<arr[i+3][0]<<arr[i+3][1]<<"  |  "<<arr[i+4][0]<<arr[i+4][1]<<"  |"<<endl ; //,arr[i][0] , arr[i][1],arr[i+1][0] , arr[i+1][1],arr[i+2][0] , arr[i+2][1],arr[i+3][0] , arr[i+3][1],arr[i+4][0] , arr[i+4][1] ;
            cout<<"|      |      |      |            |      |      |\n";
            cout<<"**********************            ***************\n";
        }
        else if (i<=41)
        {
            cout<<"|      |      |      |            |      |      |\n";
            cout<<"|  "<<arr[i][0]<<arr[i][1]<<"  |  "<<arr[i+1][0]<<arr[i+1][1]<<"  |  "<<arr[i+2][0]<<arr[i+2][1]<<"  |            |  "<<arr[i+3][0]<<arr[i+3][1]<<"  |  "<<arr[i+4][0]<<arr[i+4][1]<<"  |"<<endl ;  //printf("|  %c%c  |  %c%c  |  %c%c  |            |  %c%c  |  %c%c  |\n",arr[i][0] , arr[i][1],arr[i+1][0] , arr[i+1][1],arr[i+2][0] , arr[i+2][1],arr[i+3][0] , arr[i+3][1],arr[i+4][0] , arr[i+4][1]) ;
            cout<<"|      |      |      |            |      |      |\n";
            cout<<"**********************            ***************\n";
        }
        else
        {
            cout<<"                                                |\n<<<<<THIS IS THE BACK ENTRY GATE"
                  "                |\n                                                |\n";
            cout<<"|      |      |      |      |      |      |     |\n";
            cout<<"|  "<<arr[i][0]<<arr[i][1]<<"  |  "<<arr[i+1][0]<<arr[i+1][1]<<"  |  "<<arr[i+2][0]<<arr[i+2][1]<<"  |  "<<arr[i+3][0]<<arr[i+3][1]<<"  |  "<<arr[i+4][0]<<arr[i+4][1]<<"  |  "<<arr[i+5][0]<<arr[i+5][1]<<"  |  "<<arr[i+6][0]<<arr[i+6][1]<<" |"<<endl ; // \n",arr[i][0] , arr[i][1],arr[i+1][0] , arr[i+1][1],arr[i+2][0] , arr[i+2][1],arr[i+3][0] , arr[i+3][1],arr[i+4][0] , arr[i+4][1],arr[i+5][0], arr[i+5][1] ,arr[i+6][0] ,arr[i+6][1]) ;
            cout<<"|      |      |      |      |      |      |     |\n";
            cout<<"*************************************************\n";
            cout<<"         BREAK GLASS IN CASE OF EMERGENCY        \n";
        }
    }

    cout<<"\n\nThe total amount to be paid is equal to :"<<no_of_seats_you_want_to_reserve*699 <<endl ;
    cout<<"\nmake payment through upi 9416305609@paytm   \n or bank account with \n Account no - 5252xxxxxxxx5252 \n ifsc code - hdfc0001732\n name - Druv Gera"<<endl;
    cout<<"\ncongratulations you have passed the step 1 for booking your tickets and now complete the payment on the above mentioned upi id or transfer to bank\n\n  "<<endl;
    cout << "you will recieve confirmation through sms on the given mobile no within 4 hrs of succesfull payment "<< endl;


}
