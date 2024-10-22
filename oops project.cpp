#include<iostream>
#include<vector>
#include<string>
using namespace std;
class ApplicationException
{
public:
    int errNo;
    string errMsg;
    ApplicationException(int x,string y)
    {
        this->errNo=x;
        this->errMsg=y;
    }
    void showError()
    {
        cout<<"ERROR!!"<<endl;
        cout<<errNo<<":"<<errMsg<<endl;
    }
};
class User
{

public:
    int userId;
    string name;
    string email;
     string password;
     string location;
    User(int userId,string name,string email,string location,string password)
    {
        this->userId=userId;
        this->name=name;
        this->email=email;
        this->location=location;
        this->password=password;
    }
    virtual void printDetails()=0;
    virtual void updateProfile()=0;
    void notifyUpdates(string msg,int x)
    {
        cout<<"Hotel with hotelId "<<x<<msg<<endl;
    }
   void generateReciept(User* &userId)
    {
        cout<<"Name: "<<userId->name<<endl;
        cout<<"email:"<<userId->email<<endl;
        cout<<"location: "<<userId->location<<endl;
    }

};

class Customer:public User
{
    public:
    Customer(int userId,string name,string email,string location,string password):User(userId,name,email,location,password){}
    void printDetails()
    {
        cout<<userId<<":"<<name<<":"<<email<<":"<<location<<endl;
    }
    void updateProfile()
    {
        string p;
        int ch;
        cout<<"Would u like to change the Password if yes press 1"<<endl;
        cin>>ch;
        if(ch==1)
        {
            cout<<"Enter new password"<<endl;
            cin>>p;
            this->password=p;
            cout<<"password updated"<<endl;
        }
    }


};
class Admin:public User
{
    public:
    Admin(int userId,string name,string email,string location,string password):User(userId,name,email,location,password){}
    void printDetails()
    {
        cout<<userId<<":"<<name<<":"<<email<<":"<<location<<endl;
    }
    void updateProfile()
    {
        string p;
        int ch;
        cout<<"Would u like to change the Password if yes press 1"<<endl;
        cin>>ch;
        if(ch==1)
        {
            cout<<"Enter new password"<<endl;
            cin>>p;
            this->password=p;
            cout<<"Password updated"<<endl;
        }
    }
};
class Register
{
public:

       void signUp(vector<User*>&v,Customer &c,int x,string y)
        {
          string n,e,l;
          cout<<"Enter name, email and location"<<endl;
          cin>>n>>e>>l;
          c.userId=x;
          c.name=n;
          c.password=y;
          c.email=e;
          c.location=l;
          v.push_back(&c);
         cout<<"U are good to go"<<endl;
          /*for(int j=0;j<v.size();j++)
          {
              v[j]->printDetails();
          }*/

        }

        int login(vector<User*>&v,Customer &c)
        {
             int x;
            string y;
            int s=0;
            cout<<"Enter userId and password"<<endl;
            cin>>x>>y;
            for(int i=0;i<v.size();i++)
            {
                if(x==v[i]->userId && y==v[i]->password)
                {
                    cout<<"Login successfull"<<endl;
                    s=1;
                    break;

                }

            }
            if(s==0)
            {

               cout<<"U seem to signUp"<<endl;
               signUp(v,c,x,y);
               return x;

            }
            else
                return x;

        }

};
class Hotel
{
    public:
    int hotelId;
    string name;
    string location;
    int rating;
    double price;
    Hotel()
    {
        hotelId=0;
        name="";
        location="";
        rating=0;
        price=0;
    }
    Hotel(int h,string x,string l,int y,double z)
    {
        this->hotelId=h;
        this->name=x;
        this->location=l;
        this->rating=y;
        this->price=z;
    }

    void printHotel()
    {
cout<<hotelId<<":"<<name<<":"<<location<<":"<<rating<<":"<<price<<endl;
    }

    void updatePrice(vector<User*>&v,vector<Hotel>hotels,int x)
    {

int c=0;
        for(int i=0;i<v.size();i++)
        {

           if(v[i]->userId==x)
        {

            //int x;
            if(x<=1000)
            {
                throw ApplicationException(101,"User is not an admin");
            }
            cout<<v[i]->userId<<" is an admin"<<endl;

            int y,a;
                   cout<<"Enter the hotel id"<<endl;
                   cin>>a;
                    cout<<"Enter the updated price per room"<<endl;
                    cin>>y;
                    for(int j=0;j<hotels.size();j++)
                    {
                        if(hotels[j].hotelId==a)
                        {
                             hotels[j].price=y;

                    break;

                        }
                    }
                    cout<<"Hotel details after updating prices"<<endl;
                    for(int j=0;j<hotels.size();j++)
                    {
                        if(hotels[j].hotelId==a)
                        {
                             hotels[j].printHotel();



                        }
                    }



        }

        }


    }
};
class Vehicle
{
public:
    int vehicleId;
    string vehicleType;
    string franchiseName;
    int seatingCapacity;
    string from;
    string to;
    double price;
    Vehicle(int v,string x,string y,int z,string a,string b,double p)
    {
        this->vehicleId=v;
        this->vehicleType=x;
        this->franchiseName=y;
        this->seatingCapacity=z;
        this->from=a;
        this->to=b;
        this->price=p;
    }
    void printVehicleDetails()
    {
        cout<<vehicleId<<":"<<vehicleType<<":"<<franchiseName<<":"<<seatingCapacity<<":"<<from<<":"<<to<<":"<<price<<endl;
    }
};
class Transportation
{
public:
    string source;
    string destination;
    vector<Vehicle>vehicles;
     Transportation()
   {
       this->source="";
       this->destination="";
   }
   Transportation(string a,string b)
   {
       this->source=a;
       this->destination=b;
   }
   void updatePrice(vector<User*>&v,int x)
    {
         if(x<=1000)
         {
             throw ApplicationException(1002,"User is not an admin");
         }

        for(int i=0;i<vehicles.size();i++)
        {

           if(v[i]->userId>1000)
        {


             cout<<v[i]->userId<<" is an admin"<<endl;
             int a;
             cout<<"Enter vehicle Id"<<endl;
             cin>>a;

            for(int i=0;i<vehicles.size();i++)
            {
                if(vehicles[i].vehicleId==a)
                {
                    int y;
                    cout<<"Enter the updated price"<<endl;
                    cin>>y;
                    vehicles[i].price=y;
                    cout<<"Details after updation"<<endl;
                    vehicles[i].printVehicleDetails();

                    break;
                }
            }

        }

        }

    }

};


class Booking;

class BookingState {
public:
    virtual void confirmBooking(Booking& booking) = 0;
    virtual void cancelBooking(Booking& booking) = 0;

};



class PendingState : public BookingState {
public:
    void confirmBooking(Booking& booking) override;
    void cancelBooking(Booking& booking) override;

};

class ConfirmedState : public BookingState {
public:
    void confirmBooking(Booking& booking) override;
    void cancelBooking(Booking& booking) override;

};

class CancelledState : public BookingState {
public:
    void confirmBooking(Booking& booking) override;
    void cancelBooking(Booking& booking) override;

};
void PendingState::confirmBooking(Booking& booking) {
    cout << "Booking confirmed." << endl;

}

void PendingState::cancelBooking(Booking& booking) {
    cout << "Booking canceled." <<endl;



}


void ConfirmedState::confirmBooking(Booking& booking) {
 cout << "Booking is already confirmed." << endl;
}

void ConfirmedState::cancelBooking(Booking& booking) {
  cout << "Canceling booking." <<endl;

}



void CancelledState::confirmBooking(Booking& booking) {
 cout << "Cannot confirm a canceled booking." << std::endl;
}

void CancelledState::cancelBooking(Booking& booking) {
    cout << "Booking is already canceled." << std::endl;
}




class Booking
{
   public:
       int bookingId;
       vector<User*>users;
       vector<Hotel>rooms;
       vector<Transportation>t;
       vector<Hotel>booked;
       vector<Transportation>bookedT;
       BookingState* currentState;
       Booking(int x)
       {
        this->bookingId=x;
        currentState = new PendingState();
       }


void setState(BookingState* newState) {
        currentState = newState;
    }


     double BookHotel()
     {
         int y,x;
         double charge;
         cout<<"Enter the hotel id u want to book and no of rooms"<<endl;
         cin>>y>>x;
         for(int i=0;i<rooms.size();i++)
         {
             if(rooms[i].hotelId==y)
             {
                 charge=x*rooms[i].price;
                 rooms[i].price=charge;
                 booked.push_back(rooms[i]);
             }
         }
        currentState->confirmBooking(*this);

         return charge;
     }
     double BookTicket()
     {
        int x,y;
        double charge;
        cout<<"Enter the vehicleId and no of tickets"<<endl;
        cin>>x>>y;
         for(int i=0;i<t.size();i++)
         {
             if(t[i].vehicles[i].vehicleId==x)
             {

                 charge=y*t[i].vehicles[i].price;
                 t[i].vehicles[i].price=charge;
                 bookedT.push_back(t[i]);
             }
         }
          currentState->confirmBooking(*this);
         return charge;
     }

    void generateReciept(int x)
    {
        for(int i=0;i<users.size();i++)
        {
            if(users[i]->userId==x)
            {
                users[i]->printDetails();
            }
        }

    }
    double cancellation()
    {
        double sum=0,sum1=0;
        for(int i=0;i<booked.size();i++)
        {
            sum=sum+booked[i].price;
        }
        for(int i=0;i<bookedT.size();i++)
        {
            sum1=sum1+bookedT[i].vehicles[i].price;
        }
        double total=sum+sum1;

        currentState->cancelBooking(*this);
        return total;
    }

};
class Payment
{
public:
int paymentId;
string paymentMode;
double wallet;

Payment(int x,string y,double a)
{
    this->paymentId=x;
    this->paymentMode=y;
    this->wallet=a;
}
int makePayment(double x)
{
  cout<<"Bill: "<<x<<endl;
  cout<<"How would u like to pay??"<<endl;
  cout<<"[1]Wallet\n[2]UPI"<<endl;
  int y;
  cin>>y;
  if(y==1)
  {
      this->wallet-=x;
      cout<<"Payment Successfull"<<endl;
      cout<<"Remaining balance in your wallet: "<<wallet<<endl;
      return 1;
  }
return 0;
}
void refundPayment(double x)
{
    cout<<"Your wallet has been credited with refund amount "<<x<<endl;
    this->wallet+=x;
    cout<<"Remaining balance in the wallet "<<wallet<<endl;
}



};
int main()
{
    vector<User*>v;
    vector<Hotel>hotels;
    Register r;
    int x=0;
     Customer c1(101,"sachin","sac@gmail.com","Hubli","123al");
     Customer c2(102,"alwyn","sac@gmail.com","Hubli","123ay");
     Customer c3(103,"pavan","pav123@gmail.com","Gadag","pav123");
     Admin a1(1001,"ascii","as@gmail.com","Banglore","qqq");
     Admin a2(1002,"robert","rob@gmail","Belgaum","aaa");
     Customer c(0,"","","","");
     v.push_back(&c1);
     v.push_back(&c2);
     v.push_back(&a1);
     v.push_back(&c3);
     v.push_back(&a2);

     Hotel h1(1,"Denissons","Hubli",5,5000);
    Hotel h2(2,"TravelInn","Hubli",4,3000);
    Hotel h3(3,"Pavan'sHotel","Banglore",4,4000);
    Hotel h4(4,"Richid","Banglore",3,3800);
    hotels.push_back(h1);
    hotels.push_back(h2);
    hotels.push_back(h3);
    hotels.push_back(h4);
    vector<Vehicle>veh;
    Vehicle v1(1001,"Bus","SRS",100,"Hubli","Goa",700);
    Vehicle v2(2001,"Flight","Spicejet",500,"Hubli","Goa",5000);
    Vehicle v3(3001,"Train","RanichannamaExpress",2000,"Hubli","Banglore",800);
    veh.push_back(v1);
    veh.push_back(v2);
    veh.push_back(v3);
    vector<Transportation>transport;
    Transportation t1("Hubli","Goa");
    Transportation t2("Hubli","Goa");
    Transportation t3("Hubli","Banglore");
    t1.vehicles=veh;
    t2.vehicles=veh;
    t3.vehicles=veh;
     transport.push_back(t1);
    transport.push_back(t2);
    transport.push_back(t3);
    Booking b(101);
    b.users=v;
    b.rooms=hotels;
    b.t=transport;
   Payment p1(1,"Online",20000);
    cout<<"WELCOME!!!"<<endl<<endl;
    cout<<"MENU"<<endl;
    cout<<"[1].Login"<<endl;
    cout<<"[2].Visit Profile"<<endl;
    cout<<"[3].Update Profile"<<endl;
    cout<<"[4].Display available hotels"<<endl;
    cout<<"[5].Book Hotel rooms"<<endl;
    cout<<"[6].Display available Transportation services"<<endl;
    cout<<"[7].Book Tickets for travelling"<<endl;
    cout<<"[8].Make Payment"<<endl;
    cout<<"[9].Cancel Booking"<<endl;
    cout<<"[10].Update Hotel room prices"<<endl;
    cout<<"[11].Update Tickets prices"<<endl;
    cout<<"[12].Exit Application"<<endl;
    int ch;
string a;
string x1,y;
Hotel h;
Transportation t;
double p=0;
    while(1)
    {
        cout<<"Enter choice"<<endl;
    cin>>ch;
       switch(ch)
    {
        case 1:x=r.login(v,c);
         break;
        case 2:if(x>0){
            for(int i=0;i<v.size();i++)
       {
           if(v[i]->userId==x)
           {
               v[i]->printDetails();
           }
       }
        }
        else{
            cout<<"First Login"<<endl;
        }
       break;
       case 3:if(x>0){
           for(int i=0;i<v.size();i++)
       {
           if(v[i]->userId==x)
           {
               v[i]->updateProfile();
           }
       }
       }
       else{
            cout<<"First Login"<<endl;
        }
       break;
       case 4:
           if(x>0){
            cout<<"Enter your destination where u are planning to book hotel rooms"<<endl;
            cin>>a;
            for(int i=0;i<hotels.size();i++)
            {
                if(hotels[i].location==a)
                {
                    hotels[i].printHotel();
                }
            }
           }
           else{
            cout<<"First Login"<<endl;
        }
           break;
     case 5:if(x>0){
             b.setState(new PendingState());
            p=b.BookHotel();
            b.setState(new ConfirmedState());
     }
            else{
            cout<<"First Login"<<endl;
        }

            break;
    case 6:
            if(x>0){
            cout<<"Enter source and destination"<<endl;
            cin>>x1>>y;
            for(int i=0;i<transport.size();i++)
            {
                if(transport[i].vehicles[i].from==x1&&transport[i].vehicles[i].to==y)
                {
                    transport[i].vehicles[i].printVehicleDetails();
                }
            }
            }
            else{
            cout<<"First Login"<<endl;
        }

            break;
     case 7: if(x>0){
          b.setState(new PendingState());
           p=b.BookTicket();}
           else{
            cout<<"First Login"<<endl;
        }
            break;
     case 8:int z;
         if(p>0)
     {
        cout<<"Reciept Details:--"<<endl;
         b.generateReciept(x);
         z=p1.makePayment(p);
     }
     else
     {
         cout<<"First Book"<<endl;
     }

     break;
     case 9: double g;
     if(p>0){
            b.setState(new PendingState());
        g=b.cancellation();
        b.setState(new CancelledState());
        if(z==1){
        p1.refundPayment(g);
        }

     }
     else{
        cout<<"Without booking u cannot cancel"<<endl;
     }
        break;
    case 10: if(x>0){
        try{h.updatePrice(v,hotels,x);
    }
    catch(ApplicationException &e)
    {
        e.showError();
    }
    }
    else{
            cout<<"First Login"<<endl;
        }
    break;

   case 11:if(x>0){
       try{ t.updatePrice(v,x);}
   catch(ApplicationException &e)
   {
       e.showError();

   }
   }
   else{
            cout<<"First Login"<<endl;
        }
   break;
   case 12:exit(0);
   break;
        default:break;
    }

    }

    return 0;
}



















/*int main()
{
    vector<User*>v;
    vector<Hotel>hotels;
    Register r;
    int x;
     Customer c1(101,"sachin","sac@gmail.com","Hubli","123al");
     Customer c2(102,"alwyn","sac@gmail.com","Hubli","123ay");
     Admin a1(1001,"ascii","as@gmail.com","Banglore","qqq");
     Customer c(0,"","","","");
     v.push_back(&c1);
     v.push_back(&c2);
     v.push_back(&a1);
     Hotel h1(1,"Denissons","Hubli",5,5000);
    Hotel h2(2,"TravelInn","Hubli",4,3000);
    hotels.push_back(h1);
    hotels.push_back(h2);
    vector<Vehicle>veh;
    Vehicle v1(1001,"Bus","SRS",100,"Hubli","Goa",700);
    Vehicle v2(2001,"Flight","Spicejet",500,"Hubli","Goa",5000);
    veh.push_back(v1);
    veh.push_back(v2);

    vector<Transportation>transport;
    Transportation t1("Hubli","Goa");
    Transportation t2("Hubli","Goa");
    t1.vehicles=veh;
    t2.vehicles=veh;

    transport.push_back(t1);
    transport.push_back(t2);
     cout<<"WELCOME!!!"<<endl;
     cout<<"Login"<<endl;
    x=r.login(v,c);
    double p;
    Booking b(101);
    b.users=v;
    b.rooms=hotels;
    b.t=transport;
    Payment p1(1,"Online",20000);
     //b.notifyUpdates(x);
     cout<<"[0]Visit Profile"<<endl;
     cout<<"[1]Update Profile"<<endl;
     int a;
     cin>>a;
     if(a==0)
     {
       for(int i=0;i<v.size();i++)
       {
           if(v[i]->userId==x)
           {
               v[i]->printDetails();
           }
       }
     }
     if(a==1)
     {
         for(int i=0;i<v.size();i++)
       {
           if(v[i]->userId==x)
           {
               v[i]->updateProfile();
           }
       }
     }
    if(x>0&&x<=1000)
    {
        int y;
        cout<<"If u are looking for transportation booking press 0\nIf u are looking for hotel booking press 1 \n "<<endl;
        cout<<"[0]Transportation\n[1]Hotel"<<endl;
        cin>>y;
        if(y==1)
        {
            string a;
            cout<<"Enter your destination where u are planning to book hotel rooms"<<endl;
            cin>>a;
            for(int i=0;i<hotels.size();i++)
            {
                if(hotels[i].location==a)
                {
                    hotels[i].printHotel();
                }
            }
             p=b.BookHotel(b);
             cout<<"Your Reciept:--"<<endl;
             b.generateReciept(x);
            p1.makePayment(p);



        }
        if(y==0)
        {
            string x1,y;
            double p;
            cout<<"Enter source and destination"<<endl;
            cin>>x1>>y;
            for(int i=0;i<transport.size();i++)
            {
                if(transport[i].vehicles[i].from==x1&&transport[i].vehicles[i].to==y)
                {
                    transport[i].vehicles[i].printVehicleDetails();
                }
            }
            p=b.BookTicket();
            cout<<"Your Reciept:--"<<endl;
            cout<<"Booking Id: "<<b.bookingId<<endl;
            b.generateReciept(x);
            p1.makePayment(p);

        }
        int ch;
        double g;
        cout<<"\nIf u want to cancel your bookings press 1"<<endl;
        cin>>ch;
        if(ch==1)
        {
            g=b.cancellation(ch);
        }

    }







return 0;

}
*/
