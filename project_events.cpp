/**
 * @author 	Eleftherios Kosmas <ekosmas@staff.teicrete.gr>
 * @version 2.0
 * 
 * @updates (from version 1.0)
 *
 * Addition of function student_main_function(), in lines 23-29.
 *
 * @section PROJECT
 *
 * Additional files for the project of the course "Programming Languages", 
 * TEI of Crete, Fall Semester, 2017
 *
 * @section DESCRIPTION
 * 
 * This file contains the functions' implementations (definitions) used to
 * implement the project's events.
 */


#include "C:\Users\Jason\CLionProjects\TransitProgram\TransitProgram\project_events.h"

/**
 * Definition of event: Initialize from File
 */
void student_main_function()
{
	// add your code here ...
}

/**
 * Definition of event: Initialize from File
 */
void initialize_from_file()
{
	// add your code here ...
}

/**
 * Definition of event: Program Termination
 */
void program_termination()
{
	// add your code here ...
}

/**
 * User Addition
 *
 * @param category is one of: 
 *        + 'A': administrator
 *        + 'D': driver
 *        + 'P': passenger
 */
void add_user(
	char category, 
	string username, 
	string password, 
	string name, 
	string surname, 
	string city, 
	string street_name, 
	int street_num, 
	int postal_code, 
	string phone_number)
{
	// add your code here ...
}

/**
 * Definition of event: User Login
 */
void login_user(string username, string password)
{
	// add your code here ...
}

/**
 * Definition of event: User Logout
 */
void logout_user()
{
	// add your code here ...
}

/**
 * Change User Category
 *
 * @param new_category is one of: 
 *        + 'A': administrator
 *        + 'D': driver
 *        + 'P': passenger
 */
void chage_user_category(string username, char new_category)
{
	// add your code here ...
}

/**
 * Definition of event: Add Meeting Point
 */
void add_meeting_point(string description)
{
	// add your code here ...
}

/**
 * Definition of event: Add Vehicle Category
 */
void add_vehicle_category(string description)
{
	// add your code here ...
}

/**
 * Definition of event: Add Preferred Vehicle Category
 */
void add_preferred_vehicle_category(string category)
{
	// add your code here ...
}

/**
 * Definition of event: Remove Preferred Vehicle Category
 */
void remove_preferred_vehicle_category(string category)
{
	// add your code here ...
}

/**
 * Definition of event: Add Non-Preferred Vehicle Category
 */
void add_non_preferred_vehicle_category(string category)
{
	// add your code here ...
}

/**
 * Definition of event: Remove Non-Preferred Vehicle Category
 */
void remove_non_preferred_vehicle_category(string category)
{
	// add your code here ...
}

/**
 * Definition of event: Define Walkint Time
 * 
 * @param walking_time is a positive integer representing minutes
 */
void define_walking_time(string meeting_point_1, string meeting_point_2, int walking_time)
{
	// add your code here ...
}

/**
 * Definition of event: Add Preferred Route
 *
 * @param cost is one of the following:
 *        + 0  --> free of charge 
 *        + -1 --> indifferent
 *        + a positive integer --> cost in �
 */
void add_preferred_route(string meeting_point_1, string meeting_point_2, int cost)
{
	// add your code here ...
}

/**
 * Definition of event: Add Preferred Moving
 *
 * @param date is an integer from the set [1..365]
 * @param cost is one of the following:
 *        + -2 --> no selection (the cost is the same with the correspoding route's cost)
 *        + 0  --> free of charge 
 *        + -1 --> indifferent
 *        + a positive integer --> cost in �
 */
void add_preferred_moving(string meeting_point_1, string meeting_point_2, int date, int cost)
{
	// add your code here ...
}

/**
 * Definition of event: Vehicle Purchase
 *
 * @param num_seats is a positive integer
 */
void vehicle_purchase(string id, string category, int num_seats)
{
	// add your code here ...
}

/**
 * Definition of event: Add Moving Service
 *
 * @param date is an integer from the set [1..365]
 * @param cost is one of the following:
 *        + -2 --> no selection (the cost is the same with the correspoding route's cost)
 *        + 0  --> free of charge 
 *        + -1 --> indifferent
 *        + a positive integer --> cost in �
 * @param duration is a positive integer representing minutes
 */
void add_moving_service(string meeting_point_1, string meeting_point_2, int date, int cost, int duration, string id)
{
	// add your code here ...
}

/**
 * Definition of event: Search For Passengers
 */
void search_for_passengers()
{
	// add your code here ...
}

/**
 * Definition of event: Notify Passenger
 *
 * @param date is an integer from the set [1..365]
 */
void notify_passenger(string username, string meeting_point_1, string meeting_point_2, int date)
{
	// add your code here ...
}

/**
 * Definition of event: Buy Ticket
 *
 * @param date is an integer from the set [1..365]
 */
void buy_ticket(string meeting_point_1, string meeting_point_2, int date, string id)
{
	// add your code here ...
}

/**
 * Definition of event: Cancel Ticket
 *
 * @param date is an integer from the set [1..365]
 */
void cancel_ticket(string meeting_point_1, string meeting_point_2, int date)
{
	// add your code here ...
}

/**
 * Definition of event: Increment Date
 *
 * @param num_days is a positive integer
 */
void increment_date(int num_days)
{
	// add your code here ...
}

/**
 * Definition of event: Cancel Ticket
 *
 * @param date is an integer from the set [1..365]
 * @param rate is an integer from the set [1..100]
 */
void rate_and_comment(string meeting_point_1, string meeting_point_2, int date, int rate, string comments)
{
	// add your code here ...
}

/**
 * Definition of event: Group Meeting Points
 *
 */
void group_meeting_points(string meeting_point_1, string meeting_point_2)
{
	// add your code here ...
}

/**
 * Definition of event: Show Users
 */
void show_users()
{
	// add your code here ...
}

/**
 * Definition of event: Show Meeting Points
 */
void show_meeting_points()
{
	// add your code here ...
}

/**
 * Definition of event: Show Routes with no Walking Time Assigned
 */
void show_routes_with_no_walking_time()
{
	// add your code here ...
}

/**
 * Definition of event: Show Preferred Vehicle Categories
 */
void show_preferred_vehicle_categories()
{
	// add your code here ...
}

/**
 * Definition of event: Show Non-Preferred Vehicle Categories
 */
void show_non_preferred_vehicle_categories()
{
	// add your code here ...
}

/**
 * Definition of event: Show Preferred Routes
 */
void show_preferred_routes()
{
	// add your code here ...
}

/**
 * Definition of event: Show Movings
 */
void show_movings()
{
	// add your code here ...
}

/**
 * Definition of event: Show Ticket
 *
 * @param date is an integer from the set [1..365]
 */
void show_ticket(string meeting_point_1, string meeting_point_2, int date)
{
	// add your code here ...
}

/**
 * Definition of event: Show Passengers List
 *
 * @param date is an integer from the set [1..365]
 */
void show_passengers_list_for_moving(string meeting_point_1, string meeting_point_2, int date)
{
	// add your code here ...
}

/**
 * Definition of event: Show Passengers List for Each Scheduled Moving
 */
void show_passengers_list_scheduled()
{
	// add your code here ...
}

/**
 * Definition of event: Show Passengers List for Each Completed Moving
 */
void show_passengers_list_completed()
{
	// add your code here ...
}

/**
 * Definition of event: Show the First num Drivers With Bigger Rate
 *
 * @param num is a positive integer
 */
void show_big_rate_drivers(int num)
{
	// add your code here ...
}

/**
 * Definition of event: Show the First num Drivers With Smaller Rate
 *
 * @param num is a positive integer
 */
void show_small_rate_drivers(int num)
{
	// add your code here ...
}

/**
 * Definition of event: Show the First num More Happy Passengers
 *
 * @param num is a positive integer
 */
void show_more_happy_passengers(int num)
{
	// add your code here ...
}

/**
 * Definition of event: Show the First num Less Happy Passengers
 *
 * @param num is a positive integer
 */
void show_less_happy_passengers(int num)
{
	// add your code here ...
}

/**
 * Definition of event: Show the First num Less Happy Passengers
 */
void show_all_vehicles()
{
	// add your code here ...
}
