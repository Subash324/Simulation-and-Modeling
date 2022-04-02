#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

class Customer
{
public:

  int arrivalTime;
  int processTime;

  Customer (int at = 0)
    : arrivalTime (at),
      processTime (1) {}


  bool done () {
    return --processTime < 0;
  }

  // order by arrival time
  bool operator< (const Customer& c) const {
    return arrivalTime < c.arrivalTime;
  }
};

class Teller
{
public:
  Teller (): free (true) { }

  bool isFree () {   // are we free to service new customer?
    if (free)
      return true;
    if (customer.done())
      free = true;
    return free;
  }

  // start serving new customer

  void addCustomer (const Customer &c) {
    customer = c;
    free = false;
  }

private:

  bool     free;
  Customer customer;
};

int main ()
{
  int numberOfTellers ;
  int numberOfMinutes;
  int custPerMin;
  double totalWait          = 0;
  int numberOfCustomers     = 0;
printf("Enter number of Tellers:\n");
scanf("%d",&numberOfTellers);

printf("Enter number of Minutes:\n");
scanf("%d",&numberOfMinutes);

printf("Enter number of Customers per Minute:\n");
scanf("%d",&custPerMin);


  vector<Teller> teller (numberOfTellers);
  queue<Customer> line;

  for (int t = 0; t < numberOfMinutes; t++)
{
    for (int j = 0; j < custPerMin; j++)
    {
        line.push (Customer (t));
        for (int i = 0; i < numberOfTellers; i++)
        {
            if (teller[i].isFree () && !line.empty ())
                {
                Customer& frontCustomer = line.front ();
                numberOfCustomers++;
                totalWait += t - frontCustomer.arrivalTime;
                teller[i].addCustomer (frontCustomer);
                line.pop ();
                }
        }
    }
  }

  cout << "average wait: " << (totalWait / numberOfCustomers) << endl;
}
