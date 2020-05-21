#include<iostream>
using namespace std;
//how we descrip every seat
struct seat
{
	int id;
	bool reservation = false;
};
//how we descrip every car
struct car
{
	int id;
	int numofseats;
	seat seats[30];
};
// function to reserve a seat in train
void reservation(car train[], int size, int cn, int sn)
{
	if (train[cn - 1].seats[sn - 1].reservation == false) {
		train[cn - 1].seats[sn - 1].reservation = true;
		cout << "reserved\n";
	}
	else
		cout << "can't reserve\n";
}
//function to  cancel reserviton of a seat in train
void cancelreserve(car train[], int size, int cn, int sn)
{
	if (train[cn - 1].seats[sn - 1].reservation == true) {
		train[cn - 1].seats[sn - 1].reservation = false;
		cout << "cancel done\n";
	}
	else
		cout << "cancel not done\n";
}
//function to check avaliablity of seats in a car
void avaiseats(car train[], int size, int cn)
{
	int count = 0;
	for (int i = 0; i < 30; i++)
	{
		if (train[cn - 1].seats[i].reservation == false)
			count++;
	}
	if (count == 0)
		cout << "there is not available seats";

	else
		cout << "there is available seats";
}
//function to show status of speceific seat 
void specseats(car train[], int size, int cn, int sn) {
	if (train[cn - 1].seats[sn - 1].reservation == false)
		cout << "is available";
	else
		cout << "is not available";
}
//function to calculate the number of aviable seats in a car
int count(car train[], int size, int cn)
{
	int count = 0;
	for (int i = 0; i < 30; i++)
	{
		if (train[cn - 1].seats[i].reservation == false)
			count++;
	}
	return count;
}
//function to show status of seats in a car 
void seatstatus(car train[], int size, int cn)
{
	for (int i = 0; i < 30; i++) {
		if (train[cn - 1].seats[i].reservation == false)
			cout << i + 1 << "is available\n";
		else
			cout << i + 1 << "is not available\n";
	}
}
//main function to call all other functions at the start 
int main()
{
	car train[10];
	
	int ans;
	//if 7 breaks the loop
	do
	{
		cout << "1 to reserve\n";
		cout << "2 to cancel\n";
		cout << "3 to check specific car\n";
		cout << "4 to check specific seat\n";
		cout << "5 to get num of avail seats\n";
		cout << "6 to show all seats\n";
		cout << "7 to exit\n";
		cin >> ans;
		switch (ans)
		{
		case 1:
			int cn, sn;
			cout << "please enter car number " << endl;
			cin >> cn;
			cout << "please enter seat number " << endl;
			cin >> sn;
			reservation(train, 10, cn, sn);
			break;
		case 2:

			cout << "please enter car number " << endl;
			cin >> cn;
			cout << "please enter seat number " << endl;
			cin >> sn;
			cancelreserve(train, 10, cn, sn);
			break;
		case 3:

			cout << "please enter car number " << endl;
			cin >> cn;
			avaiseats(train, 10, cn);
			break;
		case 4:

			cout << "please enter car number " << endl;
			cin >> cn;
			cout << "please enter seat number " << endl;
			cin >> sn;
			specseats(train, 10, cn, sn);
			break;
		case 5:
			int x;
			cout << "please enter car number " << endl;
			cin >> cn;
			x = count(train, 10, cn);
			cout << "the number of avilable seats is " << x << endl;
			break;
		case 6:

			cout << "please enter car number " << endl;
			cin >> cn;
			seatstatus(train, 10, cn);
			break;
		}
	} while (ans != 7);
}