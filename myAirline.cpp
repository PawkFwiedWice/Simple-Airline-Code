//Timothy Ng
//Feb 14 2018
//Code takes several user inputs to calculate simple airfare
//Practice using switch statements

#include <iostream>
using namespace std;

int main()
{
   //init
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   //Constant Variables
   //Miami flight fares
   const double mWeekdayFareDay   = 150.00;
   const double mWeekdayFareNight = 100.00;
   const double mWeekendFareDay   = 180.00;
   const double mWeekendFareNight = 120.00;

   //Chicago flight fares  (1/2 Miami Fares)
   const double cWeekdayFareDay   = 75.00;
   const double cWeekdayFareNight = 50.00;
   const double cWeekendFareDay   = 90.00;
   const double cWeekendFareNight = 60.00;

   //Portland Flight Fares (2 x Miami fares)
   const double pWeekdayFareDay   = 300.00;
   const double pWeekdayFareNight = 200.00;
   const double pWeekendFareDay   = 360.00;
   const double pWeekendFareNight = 240.00;

   //Time Limits
   const int    beginDayLimit     = 0;    //travelTime cannot be lower than 0     (12AM)
   const int    endOfDayLimit     = 2359; //travelTime cannot be higher than 2359 (11:59 pm)
   const int    daytimeLimit      = 500;  //daytime lower bound
   const int    eveningLimit      = 1900; //daytime upper bound (all values outside bound assumed 'evening)
   
   //input vars
   int          travelTime;               //time of departure
   int          numTickets;               //number of tickets
   char         cityCode;                 //destination city
   char         dayOrWeekend;             //Day type (weekday or weekend)
   double       customerPayment;          //Customer payment

   //output vars
   double       change;                   //change = customerPayment - totalFare
   double       fareType;                 //Holds fare value determined from switch statement
   double       totalFare;                //numTickets * fareType

   //Data validation variables
   bool         cityErrFlag       = 1;    //Data validation for cityCode
   bool         dayErrFlag        = 1;    //Data Validatuib for dayOrWeekend
   const int    numTicketLow      = 0;    //Number of tickets cannot be less than 0
   
   //inputs
   cout << "Welcome to Fordham Airlines" << endl;

   //cityCode input data validation
   do
   {
      cout << "What is your destination? ([C]hicago, [M]iami or [P]ortland): ";
      cin  >> cityCode;

      switch (cityCode)
      {
         case 'c':
         case 'C':
         case 'm':
         case 'M':
         case 'p':
         case 'P':
            cityErrFlag = 0;
         break;

         default:
            cout << "\nInput Error! Try Again: " << endl;
      }
   } while (cityErrFlag == 1);

   cout << "What time will you travel? (Enter time between 0-2359) ";
   cin  >> travelTime;
   
   //travelTime data validation
   if (travelTime < beginDayLimit || travelTime > endOfDayLimit)
      do
      {
         cout << "Error! Please enter a valid time: ";
         cin  >> travelTime;
      } while (travelTime < beginDayLimit || travelTime > endOfDayLimit);

   //Day type with data validation
   do
   {
      cout << "What type of day are you traveling? (week[E]nd or week[D]ay) ";
      cin  >> dayOrWeekend;

      switch (dayOrWeekend)
      {
         case 'e':
         case 'E':
         case 'd':
         case 'D':
            dayErrFlag = 0;
         break;

         default:
            cout << "\nInput Error! Try again: " << endl;
      }
   } while (dayErrFlag == 1);

   //processing
   switch (cityCode)
   { //Miami
      case 'M':
      case 'm':
         switch (dayOrWeekend)
         {
            case 'E':
            case 'e':
               if (travelTime > daytimeLimit && travelTime < eveningLimit)
               {
                  fareType = mWeekendFareDay;
               }
               else
               {
                  fareType = mWeekendFareNight;
               }
            break;

            case 'D':
            case 'd':
               if (travelTime > daytimeLimit && travelTime < eveningLimit)
               {
                  fareType = mWeekdayFareDay;
               }
               else
               {
                  fareType = mWeekdayFareNight;
               }
            break;
         }

         //outputs
         cout << "Each ticket will cost $" << fareType << endl;

         //Additional inputs
         cout << "How many tickets do you want? ";
         cin  >> numTickets;
         
         //numTickets data validation
         if (numTickets <= numTicketLow)
         {
            do
            {
               cout << "Input Error! Number of tickets cannot be negative!\n"
                    << "Please try again: How many tickets do you want? ";
               cin  >> numTickets;
            } while (numTickets < numTicketLow);

            if (numTickets == numTicketLow)
            {
               cout << "0 tickets entered. No tickets were ordered." << endl;
               break;
            }
         }
      
         //more processing
         totalFare = fareType * numTickets;

         //outputs continued
         cout << "You owe $" << totalFare << endl;

         cout << "How much will you pay? $";
         cin  >> customerPayment;

         if (customerPayment < totalFare)
         {
            cout << "That is too little! No tickets were ordered." << endl;
         }
         else
         {
            change = customerPayment - totalFare;

            cout << "You will receive $" << change << " in change." << endl;
            cout << "Your tickets have been ordered!" << endl;
         }
      break;

      //Chicago
      case 'C':
      case 'c':
         switch (dayOrWeekend)
         {
            case 'e':
            case 'E':
               if (travelTime > daytimeLimit && travelTime < eveningLimit)
               {
                  fareType = cWeekendFareDay;
               }
               else
               {
                  fareType = cWeekendFareNight;
               }
            break;

            case 'd':
            case 'D':
               if (travelTime > daytimeLimit && travelTime < eveningLimit)
               {
                  fareType = cWeekdayFareDay;
               }
               else
               {
                  fareType = cWeekdayFareNight;
               }
            break;
         }
         //outputs
         cout << "Each ticket will cost $" << fareType << endl;

         //Additional inputs
         cout << "How many tickets do you want? ";
         cin  >> numTickets;

         //numTickets data validation
         if (numTickets <= numTicketLow)
         {
            do
            {
               cout << "Input Error! Number of tickets cannot be negative!\n"
                    << "Please try again: How many tickets do you want? ";
               cin  >> numTickets;
            } while (numTickets < numTicketLow);
         
            if (numTickets == numTicketLow)
            {
               cout << "0 tickets entered. No tickets were ordered." << endl;
               break;
            }
         }

         //more processing
         totalFare = fareType * numTickets;

         //outputs continued
         cout << "You owe $" << totalFare << endl;

         cout << "How much will you pay? $";
         cin  >> customerPayment;

         if (customerPayment < totalFare)
         {
            cout << "That is too little! No tickets were ordered." << endl;
         }
         else
         {
            change = customerPayment - totalFare;

            cout << "You will receive $" << change << " in change." << endl;
            cout << "Your tickets have been ordered!" << endl;
         }

         break;

      //Portland
      case 'P':
      case 'p':
         switch (dayOrWeekend)
         {
            case 'e':
            case 'E':
               if (travelTime > daytimeLimit && travelTime < eveningLimit)
               {
                  fareType = pWeekendFareDay;
               }
               else
               {
                  fareType = pWeekendFareNight;
               }
            break;

            case 'd':
            case 'D':
               if (travelTime > daytimeLimit && travelTime < eveningLimit)
               {
                  fareType = pWeekdayFareDay;
               }
               else
               {
                  fareType = pWeekdayFareNight;
               }
            break;
         }

         //outputs
         cout << "Each ticket will cost $" << fareType << endl;

         //Additional inputs
         cout << "How many tickets do you want? ";
         cin  >> numTickets;

         //numTicket data validation
         if (numTickets < numTicketLow)
         {
            do
            {
               cout << "Input Error! Number of tickets cannot be negative!\n"
                    << "Please try again: How many tickets do you want? ";
               cin  >> numTickets;
            } while (numTickets < numTicketLow);
            
            if (numTickets == numTicketLow)
            {
               cout << "0 tickets entered. No tickets were ordered" << endl;
               break;
            }
         }
      
         //more processing
         totalFare = fareType * numTickets;

         //outputs continued
         cout << "You owe $" << totalFare << endl;

         cout << "How much will you pay? $";
         cin  >> customerPayment;

         if (customerPayment < totalFare)
         {
            cout << "That is too little! No tickets were ordered." << endl;
         }
         else
         {
            change = customerPayment - totalFare;

            cout << "You will receive $" << change << " in change." << endl;
            cout << "Your tickets have been ordered!" << endl;
         }
         break;

      //bad input handle
      default:
         cout << "Error! Bad Input: Please try again" << endl;
      break;
   }

   return 0;
}

