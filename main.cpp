
#include <iostream>
#include <iomanip>
#include <map>

/// MARK: - Class Definitions
/// MARK: Class room
class room {
public:
  //  Default c'tor
  room(char rcode = ' ', float rate = 0.0F)
    : roomCode_(rcode), rate_(rate) {}
  //  copy c'tor
  room(room const &) = default;
  //  move c'tor
  room(room &&) = default;
  //  d'tor
  virtual ~room() = default;
  //  assignment copy operator
  room & operator=(room const &);
  //  assignment move operator
  room & operator=(room &&) = default; /*noexcept;*/

  // getters & setters
  float const rate(void) const;
  char roomCode(char roomCode);
  char roomCode(void) const;
  float roomTotal(float roomTotal);
  float roomTotal(void) const;
  float cost(float cost);
  float cost(void) const;
  float days_stay(float days_stay);
  float days_stay(void) const;
  int guests(int guests);
  int guests(void) const;
  float totalcost(float totalcost);
  float totalcost(void) const;

private:
  float const rate_;
  float roomTotal_;
  float cost_;
  float days_stay_;
  int guests_;
  char roomCode_;
  float totalcost_;
};

/// MARK: - Class room implementation.

/*
/// MARK: Class room copy c'tor
room::room(room const & that) : rate_(that.rate_) {
  roomTotal_ = that.roomTotal();
  cost_ = that.cost();
  days_stay_ = that.days_stay();
  guests_ = that.guests();
  roomCode_ = that.roomCode();
  totalcost_ = that.totalcost();
}
*/

/*
/// MARK: Class room move c'tor
room::room(room && that) : rate_(that.rate_) {
  roomTotal_ = std::move(that.roomTotal_);
  cost_ = std::move(that.cost_);
  days_stay_ = std::move(that.days_stay_);
  guests_ = std::move(that.guests_);
  roomCode_ = std::move(that.roomCode_);
  totalcost_ = std::move(that.totalcost_);
}
*/

/// MARK: room::operator=() <assignnment copy operator>
room & room::operator=(room const & that) {
  roomTotal_ = that.roomTotal();
  cost_ = that.cost();
  days_stay_ = that.days_stay();
  guests_ = that.guests();
  roomCode_ = that.roomCode();
  totalcost_ = that.totalcost();

  return *this;
}

/*
/// MARK: room::operator=() <assignnment move operator>
room & room::operator=(room && that) noexcept {
  roomTotal_ = std::move(that.roomTotal());
  cost_ = std::move(that.cost());
  days_stay_ = std::move(that.days_stay());
  guests_ = std::move(that.guests());
  roomCode_ = std::move(that.roomCode());
  totalcost_ = std::move(that.totalcost());

  return *this;
}
*/

/// MARK: room::rate() getter
float const room::rate(void) const {
  return rate_;
}
/// MARK: room::roomCode() setter
char room::roomCode(char roomCode) {
  roomCode_ = roomCode;
  return roomCode_;
}
/// MARK: room::roomCode() getter
char room::roomCode(void) const {
  return roomCode_;
}
/// MARK: room::roomTotal() setter
float room::roomTotal(float roomTotal) {
  roomTotal_ = roomTotal;
  return roomTotal_;
}
/// MARK: room::roomTotal() getter
float room::roomTotal(void) const {
  return roomTotal_;
}
/// MARK: room::cost() setter
float room::cost(float cost) {
  cost_ = cost;
  return cost_;
}
/// MARK: room::cost() getter
float room::cost(void) const {
  return cost_;
}
/// MARK: room::days_stay() setter
float room::days_stay(float days_stay) {
  days_stay_ = days_stay;
  return days_stay_;
}
/// MARK: room::days_stay() getter
float room::days_stay(void) const {
  return days_stay_;
}
/// MARK: room::guests() setter
int room::guests(int guests) {
  guests_ = guests;
  return guests_;
}
/// MARK: room::guests() getter
int room::guests(void) const {
  return guests_;
}
/// MARK: room::totalcost() setter
float room::totalcost(float totalcost) {
  totalcost_ = totalcost;
  return totalcost_;
}
/// MARK: room::totalcost() getter
float room::totalcost(void) const {
  return totalcost_;
}


/// MARK: - function prototypes
static
void menu(void);
static
room & collect(room & aroom);
static
void report(room const & aroom);

/// MARK: - Implementation.
/// MARK: main()
int main(int argc, char const * argv[]) {

//  std::map<char, room> rooms;
  /*
  room roomE('E',   684.00F);
  room roomP('P',   747.00F);
  room roomS('S',   684.00F);
  room roomR('R', 3'371.00F);
  room roomI('I', 4'010.00F);
  */
  std::map<char, room> rooms = {
    { 'E', { 'E',   684.00F, }, },
    { 'P', { 'P',   747.00F, }, },
    { 'S', { 'S',   684.00F, }, },
    { 'R', { 'R', 3'371.00F, }, },
    { 'I', { 'I', 4'010.00F, }, },
  };
    /*
    {'E', roomE},
    {'P', roomP},
    {'S', roomS},
    {'R', roomR},
    {'I', roomI},
    */

  char roomCode;
//  float cost, days_stay;
//  int guestNum;
//  int roomE, roomP, roomS,roomR,roomI;
  char answer;
//  float totalcostE, totalcostP, totalcostS, totalcostR, totalcostI;
//  totalcostE = totalcostP = totalcostS = totalcostR = totalcostI = 0;

  int average,
      totalGuest;
  float totalIncome;
  float percentageE,
        percentageP,
        percentageS,
        percentageR,
        percentageI;
  char popular, unpopular;

  menu();

  do {
    std::cout << "Please enter the room code ( E / P / S / R / I): ";
    std::cin >> roomCode;
    roomCode &= ~' '; // toupper
    if (roomCode == 'E') {
      room rm = rooms['E'];
      rooms['E'] = collect(rm);
    }
    else if (roomCode == 'P') {
      room rm = rooms['P'];
      rooms['P'] = collect(rm);
    }
    else if (roomCode == 'S') {
      room rm = rooms['S'];
      rooms['S'] = collect(rm);
    }
    else if(roomCode == 'R') {
      room rm = rooms['R'];
      rooms['R'] = collect(rm);
    }
    else if (roomCode == 'I') {
      room rm = rooms['I'];
      rooms['I'] = collect(rm);
    }

    std::cout << " Do you want to continue ( Y / N ) ";
    std::cin >> answer;
    std::cout << std::endl;
    answer &= ~' '; // toupper
  }
  while (answer != 'N');

  if (rooms['E'].roomTotal() >= rooms['P'].roomTotal()
  &&  rooms['E'].roomTotal() >= rooms['S'].roomTotal()
  &&  rooms['E'].roomTotal() >= rooms['R'].roomTotal()
  &&  rooms['E'].roomTotal() >= rooms['I'].roomTotal()) {
    popular = rooms['E'].roomCode();
  }
  else if (rooms['P'].roomTotal() >= rooms['E'].roomTotal()
       &&  rooms['P'].roomTotal() >= rooms['S'].roomTotal()
       &&  rooms['P'].roomTotal() >= rooms['R'].roomTotal()
       &&  rooms['P'].roomTotal() >= rooms['I'].roomTotal()) {
    popular = 'P';
  }
  else if (rooms['S'].roomTotal() >= rooms['P'].roomTotal()
       &&  rooms['S'].roomTotal() >= rooms['E'].roomTotal()
       &&  rooms['S'].roomTotal() >= rooms['R'].roomTotal()
       &&  rooms['S'].roomTotal() >= rooms['I'].roomTotal()) {
    popular = 'S';
  }
  else if (rooms['R'].roomTotal() >= rooms['P'].roomTotal()
       &&  rooms['R'].roomTotal() >= rooms['S'].roomTotal()
       &&  rooms['R'].roomTotal() >= rooms['E'].roomTotal()
       &&  rooms['R'].roomTotal() >= rooms['I'].roomTotal()) {
    popular = 'R';
  }
  else if (rooms['I'].roomTotal() >= rooms['P'].roomTotal()
       &&  rooms['I'].roomTotal() >= rooms['S'].roomTotal()
       &&  rooms['I'].roomTotal() >= rooms['R'].roomTotal()
       &&  rooms['I'].roomTotal() >= rooms['E'].roomTotal()) {
    popular = 'I';
  }

  if (rooms['E'].roomTotal() <= rooms['P'].roomTotal()
  &&  rooms['E'].roomTotal() <= rooms['S'].roomTotal()
  &&  rooms['E'].roomTotal() <= rooms['R'].roomTotal()
  &&  rooms['E'].roomTotal() <= rooms['I'].roomTotal()) {
    unpopular = 'E';
  }
  else if (rooms['P'].roomTotal() <= rooms['E'].roomTotal()
       &&  rooms['P'].roomTotal() <= rooms['S'].roomTotal()
       &&  rooms['P'].roomTotal() <= rooms['R'].roomTotal()
       &&  rooms['P'].roomTotal() <= rooms['I'].roomTotal()) {
    unpopular = 'P';
  }
  else if (rooms['S'].roomTotal() <= rooms['P'].roomTotal()
       &&  rooms['S'].roomTotal() <= rooms['E'].roomTotal()
       &&  rooms['S'].roomTotal() <= rooms['R'].roomTotal()
       &&  rooms['S'].roomTotal() <= rooms['I'].roomTotal()) {
    unpopular = 'S';
  }
  else if (rooms['R'].roomTotal() <= rooms['P'].roomTotal()
       &&  rooms['R'].roomTotal() <= rooms['S'].roomTotal()
       &&  rooms['R'].roomTotal() <= rooms['E'].roomTotal()
       &&  rooms['R'].roomTotal() <= rooms['I'].roomTotal()) {
    unpopular = 'R';
  }
  else if (rooms['I'].roomTotal() <= rooms['P'].roomTotal()
       &&  rooms['I'].roomTotal() <= rooms['S'].roomTotal()
       &&  rooms['I'].roomTotal() <= rooms['R'].roomTotal()
       &&  rooms['I'].roomTotal() <= rooms['E'].roomTotal()) {
      unpopular = 'I';
  }

  report(rooms['E']);
  report(rooms['P']);
  report(rooms['S']);
  report(rooms['R']);
  report(rooms['I']);

  totalGuest = rooms['E'].roomTotal()
             + rooms['P'].roomTotal()
             + rooms['S'].roomTotal()
             + rooms['R'].roomTotal()
             + rooms['I'].roomTotal()
             / rooms.size();
  totalIncome = rooms['E'].totalcost()
              + rooms['P'].totalcost()
              + rooms['S'].totalcost()
              + rooms['R'].totalcost()
              + rooms['I'].totalcost();
  percentageE = (rooms['E'].roomTotal() / totalGuest) * 100.00;
  percentageP = (rooms['P'].roomTotal() / totalGuest) * 100.00;
  percentageS = (rooms['S'].roomTotal() / totalGuest) * 100.00;
  percentageR = (rooms['R'].roomTotal() / totalGuest) * 100.00;
  percentageI = (rooms['I'].roomTotal() / totalGuest) * 100.00;

  std::cout << "The average guest for all room category is " << average << '\n';
  std::cout << "Percentage for each room category is as stated below: " << std::endl;
  std::cout << "Room E: " << percentageE << "%" << '\n';
  std::cout << "Room P: " << percentageP << "%" << '\n';
  std::cout << "Room S: " << percentageS << "%" << '\n';
  std::cout << "Room R: " << percentageR << "%" << '\n';
  std::cout << "Room I: " << percentageI << "%" << '\n';
  std::cout << "Total income for all room is : RM " << totalIncome << '\n';
  std::cout << "The most popular room is  : " << popular << '\n';
  std::cout << "The most unpopular room is: " << unpopular << '\n';
  std::cout << std::endl;

  return 0;
}

/// MARK: menu()
static
void menu(void) {
  std::cout << "--------------------------------------------------------------------------\n"; //title
  std::cout << "THIS PROGRAM IS TO TRACK UNKNOWN NUMBERS OF ROOMS FOR LEXIS HIBISCUS HOTEL\n";
  std::cout << "-------------------------------------------------------------------------\n";
  std::cout << "\t\t\t LEXIS HIBICUS HOTEL \t\t\t\n";
  std::cout << "_________________________________________________________________________\n";
  std::cout << "|Room & Suites Name   |   Room & Suites Code  |   Room & Suites Cost(RM)|\n";
  std::cout << "|~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
  std::cout << "|Executive Pool Villa |           E           |           684.00        |\n";
  std::cout << "|Premium Pool Villa   |           P           |           747.00        |\n";
  std::cout << "|Sky Pool Villa       |           S           |           684.00        |\n";
  std::cout << "|Royal Suite          |           R           |         3,371.00        |\n";
  std::cout << "|Imperial Suite       |           I           |         4,010.00        |\n";
  std::cout << "|_____________________|_______________________|_________________________|\n";
  std::cout << std::endl;
}

/// MARK: collect()
static
room & collect(room & aroom) {

  int guests;
  float room_total;
  float cost;
  float totalcost;
  float days_stay;

  std::cout << "Please enter the number of guests for room "
            << aroom.roomCode()
            << ' ';
  std::cin >> guests;

  std::cout << "how many days stay : ";
  std::cin >> days_stay;
  std::cout << std::endl;

  aroom.guests(guests);
  // all guests of this type
  room_total = aroom.roomTotal() + guests;
  aroom.roomTotal(room_total);
  cost = aroom.rate() * guests; // day cost of this stay
  aroom.cost(cost);

  aroom.days_stay(days_stay);
  // ruuning total for rooms
  totalcost = aroom.totalcost() + cost * days_stay;
  aroom.totalcost(totalcost);

  return aroom;
}

/// MARK: report()
static
void report(room const & aroom) {
  std::cout << "The total number of guests for Room "
            << aroom.roomCode()
            << " is: "
            << aroom.guests()
            << '\n';
  std::cout << "Total income for Room "
            << aroom.roomCode()
            << " is              : RM "
            << std::fixed << std::setprecision(2)
            << aroom.totalcost()
            << '\n'
            << "Total Night Stay                        : "
            << aroom.days_stay()
            << std::endl;
}
