
#include <iostream>
#include <iomanip>

//using namespace std;

int main(int argc, char const * argv[]) {
  char roomCode;
  float cost, days_stay;
  int guestNum;
  int roomE, roomP, roomS,roomR,roomI;
  char answer;
  float roomEtotal = 0, roomPtotal = 0,roomStotal = 0,roomRtotal = 0,roomItotal = 0;
  float totalcostE = 0, totalcostP = 0, totalcostS = 0, totalcostR = 0, totalcostI = 0;
  int average, totalGuest;
  float totalIncome;
  float percentageE, percentageP, percentageS, percentageR, percentageI;
  char popular, unpopular;

  std::cout << "--------------------------------------------------------------------------" << std::endl; //title
  std::cout << "THIS PROGRAM IS TO TRACK UNKNOWN NUMBERS OF ROOMS FOR LEXIS HIBISCUS HOTEL" << std::endl;
  std::cout << "--------------------------------------------------------------------------" << std::endl;
  std::cout << "\t\t\t LEXIS HIBICUS HOTEL \t\t\t" << std::endl;
  std::cout << "_________________________________________________________________________" << std::endl;
  std::cout << "|Room & Suites Name   |   Room & Suites Code  |   Room & Suites Cost(RM)|" << std::endl;
  std::cout << "|~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~~~|" << std::endl;
  std::cout << "|Executive Pool Villa |           E           |           684.00        |" << std::endl;
  std::cout << "|Premium Pool Villa   |           P           |           747.00        |" << std::endl;
  std::cout << "|Sky Pool Villa       |           S           |           684.00        |" << std::endl;
  std::cout << "|Royal Suite          |           R           |           3371.00       |" << std::endl;
  std::cout << "|Imperial Suite       |           I           |           4010.00       |" << std::endl;
  std::cout << "|_____________________|_______________________|_________________________|" << std::endl;
  std::cout << std::endl;

  do {
    std::cout << "PLEASE ENTER THE ROOM CODE ( E / P / S / R /I): ";
    std::cin >> roomCode;
    if (roomCode == 'E')
    {
      cost = 684.00;
      std::cout << "PLEASE ENTER THE NUMBER OF GUEST FOR ROOM E ";
      std::cin >> roomE;
      roomEtotal += roomE;
      cost *= roomE;
      totalcostE += cost;
      std::cout << "HOW MANY DAYS STAY : ";
      std::cin >> days_stay;
      std::cout << std::endl;
    }
    else if (roomCode == 'P')
    {
      cost = 747.00;
      std::cout << "PLEASE ENTER THE NUMBER OF GUEST FOR ROOM E ";
      std::cin >> roomP;
      roomPtotal += roomP;
      cost *= roomP;
      totalcostP += cost;
      std::cout << "HOW MANY DAYS STAY : ";
      std::cin >> days_stay;
      std::cout << std::endl;
    }
    else if (roomCode == 'S')
    {
      cost = 684.00;
      std::cout << "PLEASE ENTER THE NUMBER OF GUEST FOR ROOM S ";
      std::cin >> roomS;
      roomStotal += roomS;
      cost *= roomS;
      totalcostS += cost;
      std::cout << "HOW MANY DAYS STAY : ";
      std::cin >> days_stay;
      std::cout << std::endl;
    }
    else if(roomCode == 'R')
    {
      cost = 3371.00;
      std::cout << "PLEASE ENTER THE NUMBER OF GUEST FOR ROOM R ";
      std::cin >> roomR;
      roomRtotal += roomR;
      cost *= roomR;
      totalcostR += cost;
      std::cout << "HOW MANY DAYS STAY : ";
      std::cin >> days_stay;
      std::cout << std::endl;
    }
    else if (roomCode == 'I')
    {
      cost = 4010.00;
      std::cout << "PLEASE ENTER THE NUMBER OF GUEST FOR ROOM I ";
      std::cin >> roomI;
      roomItotal += roomI;
      cost *= roomI;
      totalcostI += cost;
      std::cout << "HOW MANY DAYS STAY : ";
      std::cin >> days_stay;
      std::cout << std::endl;
    }
    std::cout << " Do you want to continue ( Y / N ) ";
    std::cin >> answer;
    std::cout << std::endl;
  }
  while (answer != 'N');

  if (roomEtotal >= roomPtotal && roomEtotal >= roomStotal && roomEtotal >= roomRtotal && roomEtotal >= roomItotal)
  {
    popular = 'E';
  }
  else if (roomPtotal >= roomEtotal && roomPtotal >= roomStotal && roomPtotal >= roomRtotal && roomPtotal >= roomItotal)
  {
    popular = 'P';
  }
  else if (roomStotal >= roomPtotal && roomStotal >= roomEtotal && roomStotal >= roomRtotal && roomStotal >= roomItotal)
  {
    popular = 'S';
  }
  else if (roomRtotal >= roomPtotal && roomRtotal >= roomStotal && roomRtotal >= roomEtotal && roomRtotal >= roomItotal)
  {
    popular = 'R';
  }
  else if (roomItotal >= roomPtotal && roomItotal >= roomStotal && roomItotal >= roomRtotal && roomItotal >= roomEtotal)
  {
    popular = 'I';
  }
  if (roomEtotal <= roomPtotal && roomEtotal <= roomStotal && roomEtotal <= roomRtotal && roomEtotal <= roomItotal)
  {
    unpopular = 'E';
  }
  else if (roomPtotal <= roomEtotal && roomPtotal <= roomStotal && roomPtotal <= roomRtotal && roomPtotal <= roomItotal)
  {
    unpopular = 'P';
  }
  else if (roomStotal <= roomPtotal && roomStotal <= roomEtotal && roomStotal <= roomRtotal && roomStotal <= roomItotal)
  {
    unpopular = 'S';
  }
  else if (roomRtotal <= roomPtotal && roomRtotal <= roomStotal && roomRtotal <= roomEtotal && roomRtotal <= roomItotal)
  {
    unpopular = 'R';
  }
  else if (roomItotal <= roomPtotal && roomItotal <= roomStotal && roomItotal <= roomRtotal && roomItotal <= roomEtotal)
  {
      unpopular = 'I';
  }

  std::cout << "The total number of guests for Room E is: " << roomEtotal << std::endl;
  std::cout << "Total income for Room E is              : RM " << std::fixed << std::setprecision(2) << totalcostE << std::endl;
  std::cout << "Total Night Stay                       : " << days_stay;
  std::cout << std::endl;
  std::cout << "The total number of guests for Room P is: " << roomPtotal << std::endl;
  std::cout << "Total income for Room P is              : RM" << std::fixed << std::setprecision(2) << totalcostP << std::endl;
  std::cout << "Total Night Stay                       : " << days_stay;
  std::cout << std::endl;
  std::cout << "The total number of guests for Room S is: " << roomStotal << std::endl;
  std::cout << "Total income for Room S is              : RM " << std::fixed << std::setprecision(2) << totalcostS << std::endl;
  std::cout << "Total Night Stay                       : " << days_stay;
  std::cout << std::endl;
  std::cout << "The total number of guests for Room R is: " << roomRtotal << std::endl;
  std::cout << "Total income for Room R is              : RM " << std::fixed << std::setprecision(2) << totalcostR << std::endl;
  std::cout << "Total Night Stay                       : " << days_stay;
  std::cout << std::endl;
  std::cout << "The total number of guests for Room I is: " << roomItotal << std::endl;
  std::cout << "Total income for Room I is              : RM " << totalcostI << std::endl;
  std::cout << "Total Night Stay                       : " << days_stay;
  std::cout << std::endl;

  totalGuest = roomEtotal + roomPtotal + roomStotal + roomRtotal + roomItotal;
  average = totalGuest / 5;
  totalIncome = totalcostE + totalcostI + totalcostP + totalcostR + totalcostS;
  percentageE = (roomEtotal / totalGuest) * 100.00;
  percentageP = (roomPtotal / totalGuest) * 100.00;
  percentageS = (roomStotal / totalGuest) * 100.00;
  percentageR = (roomRtotal / totalGuest) * 100.00;
  percentageI = (roomItotal / totalGuest) * 100.00;

  std::cout << "The average guest for all room category is " << average << std::endl;
  std::cout << "Percentage for each room category is as stated below: " << std::endl;
  std::cout << "Room E: " << percentageE << "%" << std::endl;
  std::cout << "Room P: " << percentageP << "%" << std::endl;
  std::cout << "Room S: " << percentageS << "%" << std::endl;
  std::cout << "Room R: " << percentageR << "%" << std::endl;
  std::cout << "Room I: " << percentageI << "%" << std::endl;
  std::cout << "Total income for all room is : RM " << totalIncome << std::endl;
  std::cout << "The most popular room is  : " << popular << std::endl;
  std::cout << "The most unpopular room is: " << unpopular << std::endl;
}
