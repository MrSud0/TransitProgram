/**
 * @author 	Eleftherios Kosmas <ekosmas@staff.teicrete.gr>
 * @version 2.0
 * 
 * @updates (from version 1.0)
 *
 * Addition of function student_main_function(), in line 22.
 *
 * @section PROJECT
 *
 * Additional files for the project of the course "Programming Languages", 
 * TEI of Crete, Fall Semester, 2017
 *
 * @section DESCRIPTION
 * 
 * This file contains the functions' prototypes (declarations) used to
 * implement the project's events.
 */

#include "C:\Users\Jason\CLionProjects\TransitProgram\TransitProgram\std_lib_facilities.h"

void student_main_function();

void initialize_from_file();
void program_termination();

void add_user( char, 
	string username, 
	string password, 
	string name, 
	string surname, 
	string city, 
	string street_name, 
	int street_num, 
	int postal_code, 
	string phone_number);
void login_user(string username, string password);
void logout_user();
void chage_user_category(string username, char new_category);

void add_meeting_point(string description);

void add_vehicle_category(string category);
void add_preferred_vehicle_category(string category);
void remove_preferred_vehicle_category(string category);
void add_non_preferred_vehicle_category(string category);
void remove_non_preferred_vehicle_category(string category);

void define_walking_time(string meeting_point_1, string meeting_point_2, int walking_time);

void add_preferred_route(string meeting_point_1, string meeting_point_2, int cost);
void add_preferred_moving(string meeting_point_1, string meeting_point_2, int date, int cost);

void vehicle_purchase(string id, string category, int num_seats);
void add_moving_service(string meeting_point_1, string meeting_point_2, int date, int cost, int duration, string id);
void search_for_passengers();
void notify_passenger(string username, string meeting_point_1, string meeting_point_2, int date);

void buy_ticket(string meeting_point_1, string meeting_point_2, int date, string id);
void cancel_ticket(string meeting_point_1, string meeting_point_2, int date);

void increment_date(int num_days);

void rate_and_comment(string meeting_point_1, string meeting_point_2, int date, int rate, string comments);

void group_meeting_points(string meeting_point_1, string meeting_point_2);

void show_users();
void show_meeting_points();
void show_routes_with_no_walking_time();
void show_preferred_vehicle_categories();
void show_non_preferred_vehicle_categories();
void show_preferred_routes();
void show_movings();
void show_ticket(string meeting_point_1, string meeting_point_2, int date);
void show_passengers_list_for_moving(string meeting_point_1, string meeting_point_2, int date);
void show_passengers_list_scheduled();
void show_passengers_list_completed();
void show_big_rate_drivers(int num);
void show_small_rate_drivers(int num);
void show_more_happy_passengers(int num);
void show_less_happy_passengers(int num);
void show_all_vehicles();
