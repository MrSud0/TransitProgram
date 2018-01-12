/**
 * @author 	Eleftherios Kosmas <ekosmas@staff.teicrete.gr>
 * @version 2.0
 *
 * @updates (from version 1.0)
 *
 * Addition of function student_main_function(), in lines 115-118.
 * 
 * @section PROJECT
 *
 * Additional files for the project of the course "Programming Languages", 
 * TEI of Crete, Fall Semester, 2017
 *
 * @section DESCRIPTION
 * 
 * This file: 
 * 1. parses a file containing events for the project and
 * 2. for each event calls the corresponding function, providing
 *    the required parameters.
 *
 * Usage: "<executable_code_name> <filename> (INIT)", where 
 * INIT is optional; if it is set, the system is initialized from file. 
 * e.g.1. "./a.out test1.txt"
 * e.g.2. "./a.out test12b.txt INIT"
 * 
 * Note: INIT is required only for test files: "test12b.txt" and "test12c.txt".
 */

#include "project_events.h"

/**
 * Finds and replaces some text of a string.
 */
void find_and_replace(string& source, string const& find, string const& replace);

/**
 * Validates that category is one of {'A', 'D', 'P'}
 * 
 * @throws exception in case validation fails
 */
void check_category_validity(char);

/**
 * Validates that the cost is >= min.
 * 
 * @throws exception in vase validation fails
 */
void check_cost_validity(int , int min);

/**
 * Validates that date is in [0..365]
 * 
 * @throws exception in vase validation fails
 */
void check_date_validity(int date);

/**
 * Validates that the number of seats is a positive number
 * 
 * @throws exception in vase validation fails
 */
void check_positive_integer_validity(int num_seats);

/**
 * Validates that rate is in [0..100]
 * 
 * @throws exception in case validation fails
 */
void check_rate_validity(int rate);

/**
 * A user-defined type representing full name of a user.
 */
struct FullName {
	string name, surname;
};

istream& operator>>(istream& ist, FullName& fn) {
	return ist >> fn.name >> fn.surname;
}

ostream& operator<<(ostream& ost, FullName& fn) {
	return ost << fn.name << "] [" << fn.surname;
}

/**
 * A user-defined type representing address of a user.
 */
struct UserAddress {
	string city, street_name;
	int street_num, postal_code;
};

istream& operator>>(istream& ist, UserAddress& ua) {
	return ist >> ua.city >> ua.street_name >> ua.street_num >> ua.postal_code;
}

ostream& operator<<(ostream& ost, UserAddress& ua) {
	return ost << ua.city << "] [" << ua.street_name << "] [" << ua.street_num << "] [" << ua.postal_code;
}


/**
 * The main function parsing file input.
 *
 * @param argc number of command line parameters
 * @param argv array containg command line parameters as strings
 *             e.g., argv[0] = <executable_code_name>
 *
 */
int main (int argc, char *argv[]){
	int event_num = 0;
	
	// check the number of parameters
	if (argc == 1) {
		student_main_function();
		return 0;
	}
	else if (argc != 2 && argc !=3) {
		cerr << "Usage: " << argv[0] << " <filename> (INIT), where INIT is optional; if it is set, the system is initialized from file\n" << endl;
		return 1;
	}
	else if (argc == 3 && strcmp(argv[2],"INIT")!=0){
		cerr << "Usage: " << argv[0] << " <filename> (INIT), where INIT is optional; if it is set, the system is initialized from file\n" << endl;
		return 1;
	}
	else if (argc == 3) {
		cout << ++event_num << ". INITIALIZATION FROM FILE" << endl;
		initialize_from_file();
	}
		
	ifstream ist(argv[1]);
	if (!ist) error("Error: can not open input filename: ", argv[1]);
	
	string line;
	char event = '0';
	while (event != 'Z' && getline(ist,line)) {		// when event == 'Z' program terminates
		stringstream ss(line);

		event = '0';
		ss >> event;
		
		switch (event) {
			case 'Z':
				cout << ++event_num << ". PROGRAM TERIMATION" << endl;
				program_termination();
				break;
			case 'U': {
				char category;
				string username, password, phone_number;
				FullName full_name;
				UserAddress address;
				ss >> category >> username >> password >> full_name >> address >> phone_number; 
				check_category_validity(category);
				cout << ++event_num << ". ADD USER: ["  << category << "] [" << username << "] [" << password << "] [" << full_name << "] [" << address << "] [" << phone_number << "]" << endl;
				add_user(category, username, password, full_name.name, full_name.surname, address.city, address.street_name, address.street_num, address.postal_code, phone_number);
				break;
			}
			case 'L': {
				string username, password;
				ss >> username >> password;
				cout << ++event_num << ". LOGIN USER: [" << username << "] [" << password << "]" << endl;
				login_user(username,password);
				break;
			}
			case 'O': {
				cout << ++event_num << ". USER LOGOUT" << endl;
				logout_user();
				break;
			}
			case 'Y': {
				char new_category;
				string username;
				ss >> username >> new_category;
				check_category_validity(new_category);
				cout << ++event_num << ". CHANGE USER's ["  << username << "] CATEGORY TO [" << new_category << "]" << endl;
				chage_user_category(username, new_category);
				break;
			}
			case 'M': {
				string description = line;
				description.erase(0,2);
				cout << ++event_num << ". ADD MEETING POINT: [" << description << "]" << endl;
				add_meeting_point(description);
				break;
			}
			case 'V': {
				string category = line;
				category.erase(0,2);
				cout << ++event_num << ". ADD VEHICLE CATEGORY: [" << category << "]" << endl;
				add_vehicle_category(category);
				break;
			}
			case 'P': {
				char op;
				ss >> op;
				string category = line;
				category.erase(0,4);
				switch (op) {
					case '+':
						cout << ++event_num << ". ADD PREFERRED VEHICLE CATEGORY: [" << category << "]" << endl;
						add_preferred_vehicle_category(category);
						break;
					case '-':
						cout << ++event_num << ". REMOVE PREFERRED VEHICLE CATEGORY: [" << category << "]" << endl;
						remove_preferred_vehicle_category(category);
						break;
					default:
						error ("Error: wrong operation for user's vehicle category");
						break;
				}
				break;
			}
			case 'N': {
				char op;
				ss >> op;
				string category = line;
				category.erase(0,4);
				switch (op) {
					case '+':
						cout << ++event_num << ". ADD NON-PREFERRED VEHICLE CATEGORY: [" << category << "]" << endl;
						add_non_preferred_vehicle_category(category);
						break;
					case '-':
						cout << ++event_num << ". REMOVE NON-PREFERRED VEHICLE CATEGORY: [" << category << "]" << endl;
						remove_non_preferred_vehicle_category(category);
						break;
					default:
						error ("Error: wrong operation for user's preferred vehicle category");
						break;
				}
				break;
			}
			case 'W': {
				string meeting_point_1, meeting_point_2;
				int walking_time;
				ss >> meeting_point_1 >> meeting_point_2 >> walking_time;
				find_and_replace(meeting_point_1, "_", " ");
				find_and_replace(meeting_point_2, "_", " ");
				check_positive_integer_validity(walking_time);
				cout << ++event_num << ". DEFINE WALKING TIME: FROM [" << meeting_point_1 << "] TO [" << meeting_point_2 << "] IN [" << walking_time << "] MINUTES" << endl;
				define_walking_time(meeting_point_1, meeting_point_2, walking_time);
				break;
			}
			case 'R': {
				string meeting_point_1, meeting_point_2;
				int cost;
				ss >> meeting_point_1 >> meeting_point_2 >> cost;
				find_and_replace(meeting_point_1, "_", " ");
				find_and_replace(meeting_point_2, "_", " ");
				check_cost_validity(cost, -1);
				cout << ++event_num << ". ADD PREFERRED ROUTE: FROM [" << meeting_point_1 << "] TO [" << meeting_point_2 << "] WITH COST [" << cost << "]" << endl;
				add_preferred_route(meeting_point_1, meeting_point_2, cost);
				break;
			}
			case 'I': {
				string meeting_point_1, meeting_point_2;
				int date, cost;
				ss >> meeting_point_1 >> meeting_point_2 >> date >> cost;
				find_and_replace(meeting_point_1, "_", " ");
				find_and_replace(meeting_point_2, "_", " ");
				check_date_validity(date);
				check_cost_validity(cost, -2);
				cout << ++event_num << ". ADD PREFERRED MOVING: FROM [" << meeting_point_1 << "] TO [" << meeting_point_2 << "] AT DATE [" << date << "] WITH COST [" << cost << "]" << endl;
				add_preferred_moving(meeting_point_1, meeting_point_2, date, cost);
				break;
			}
			case 'C':{
				string id, category; 
				int num_seats;
				ss >> id >> category >> num_seats;
				check_positive_integer_validity(num_seats);
				cout << ++event_num << ". VEHICLE PURCHASE: WITH ID [" << id << "], CATEGORY [" << category << "], AND NUMBER OF SEATS [" << num_seats << "]" << endl;
				vehicle_purchase(id, category, num_seats);
				break;
			}
			case 'E': {
				string meeting_point_1, meeting_point_2, id;
				int date, cost, duration;
				ss >> meeting_point_1 >> meeting_point_2 >> date >> cost >> duration >> id ;
				find_and_replace(meeting_point_1, "_", " ");
				find_and_replace(meeting_point_2, "_", " ");
				check_date_validity(date);
				check_cost_validity(cost, -2);
				check_positive_integer_validity(duration);
				cout << ++event_num << ". ADD MOVING SERVICE: FROM [" << meeting_point_1 << "] TO [" << meeting_point_2 << "] AT DATE [" << date << "] WITH COST [" << cost << "] IN [" << duration << "] MINUTES USING VEHICLE [" << id << "]" << endl;
				add_moving_service(meeting_point_1, meeting_point_2, date, cost, duration, id);
				break;
			}
			case 'G':
				cout << ++event_num << ". SEARCH FOR PASSENGERS" << endl;
				search_for_passengers();
				break;
			case 'T': {
				string username, meeting_point_1, meeting_point_2;
				int date;
				ss >> username >> meeting_point_1 >> meeting_point_2 >> date;
				find_and_replace(meeting_point_1, "_", " ");
				find_and_replace(meeting_point_2, "_", " ");
				check_date_validity(date);
				cout << ++event_num << ". NOTIFY PASSENGER: [" << username << "] FOR MOVING FROM [" << meeting_point_1 << "] TO [" << meeting_point_2 << "] AT DATE [" << date << "]" << endl;
				notify_passenger(username, meeting_point_1, meeting_point_2, date);
				break;
			}
			case 'B': {
				string meeting_point_1, meeting_point_2, id;
				int date;
				ss >> meeting_point_1 >> meeting_point_2 >> date >> id;
				find_and_replace(meeting_point_1, "_", " ");
				find_and_replace(meeting_point_2, "_", " ");
				check_date_validity(date);
				cout << ++event_num << ". BUY TICKET: MOVING FROM [" << meeting_point_1 << "] TO [" << meeting_point_2 << "] AT DATE [" << date << "] WITH VEHICLE [" << id << "]" << endl;
				buy_ticket(meeting_point_1, meeting_point_2, date, id);
				break;
			}
			case 'K': {
				string meeting_point_1, meeting_point_2;
				int date;
				ss >> meeting_point_1 >> meeting_point_2 >> date;
				find_and_replace(meeting_point_1, "_", " ");
				find_and_replace(meeting_point_2, "_", " ");
				check_date_validity(date);
				cout << ++event_num << ". CANCEL TICKET: MOVING FROM [" << meeting_point_1 << "] TO [" << meeting_point_2 << "] AT DATE [" << date << "]" << endl;
				cancel_ticket(meeting_point_1, meeting_point_2, date);
				break;
			}
			case 'D': {
				int num_days;
				ss >> num_days;
				check_positive_integer_validity(num_days);
				cout << ++event_num << ". INCREMENT DATE: BY [" << num_days << "] DAYS" << endl;
				increment_date(num_days);
				break;
			}
			case 'F': {
				string meeting_point_1, meeting_point_2, comments;
				int date, rate;
				ss >> meeting_point_1 >> meeting_point_2 >> date >> rate;
				getline(ss, comments);
				comments.erase(0,1);
				find_and_replace(meeting_point_1, "_", " ");
				find_and_replace(meeting_point_2, "_", " ");
				check_date_validity(date);
				check_rate_validity(rate);
				cout << ++event_num << ". RATE AND COMMENT FINIHED MOVIND: FROM [" << meeting_point_1 << "] TO [" << meeting_point_2 << "] AT DATE [" << date << "] WITH RATE [" << rate << "] AND COMMENTS [" << comments << "]" << endl;
				rate_and_comment(meeting_point_1, meeting_point_2, date, rate, comments);
				break;
			}
			case 'Q': {
				string meeting_point_1, meeting_point_2;
				ss >> meeting_point_1 >> meeting_point_2;
				find_and_replace(meeting_point_1, "_", " ");
				find_and_replace(meeting_point_2, "_", " ");
				cout << ++event_num << ". GROUP MEETING POINTS: [" << meeting_point_1 << "] AND [" << meeting_point_2 << "]" << endl;
				group_meeting_points(meeting_point_1, meeting_point_2);
				break;
			}
			case 'S': {
				char type;
				ss >> type;
				switch (type) {
					case 'U': {
						cout << ++event_num << ". SHOW LIST OF USERS" << endl;
						show_users();
						break;
					}
					case 'M': {
						cout << ++event_num << ". SHOW MEETING POINTS" << endl;
						show_meeting_points();
						break;
					}
					case 'W': {
						cout << ++event_num << ". SHOW ROUTES WITH NO WALKING TIME ASSIGNED" << endl;
						show_routes_with_no_walking_time();
						break;
					}
					case 'P': {
						cout << ++event_num << ". SHOW PREFERRED VEHICLE CATEGORIES" << endl;
						show_preferred_vehicle_categories();
						break;
					}
					case 'N': {
						cout << ++event_num << ". SHOW NON-PREFERRED VEHICLE CATEGORIES" << endl;
						show_non_preferred_vehicle_categories();
						break;
					}
					case 'R': {
						cout << ++event_num << ". SHOW PREFERRED ROUTES" << endl;
						show_preferred_routes();
						break;
					}
					case 'S': {
						cout << ++event_num << ". SHOW MOVINGS" << endl;
						show_movings();
						break;
					}
					case 'T': {
						string meeting_point_1, meeting_point_2;
						int date;
						ss >> meeting_point_1 >> meeting_point_2 >> date;
						find_and_replace(meeting_point_1, "_", " ");
						find_and_replace(meeting_point_2, "_", " ");
						check_date_validity(date);
						cout << ++event_num << ". SHOW TICKET: MOVING FROM [" << meeting_point_1 << "] TO [" << meeting_point_2 << "] AT DATE [" << date << "]" << endl;
						show_ticket(meeting_point_1, meeting_point_2, date);
						break;
					}
					case 'L': {
						string meeting_point_1, meeting_point_2;
						int date;
						ss >> meeting_point_1 >> meeting_point_2 >> date;
						find_and_replace(meeting_point_1, "_", " ");
						find_and_replace(meeting_point_2, "_", " ");
						check_date_validity(date);
						cout << ++event_num << ". SHOW PASSENGER LIST: FOR MOVING FROM [" << meeting_point_1 << "] TO [" << meeting_point_2 << "] AT DATE [" << date << "]" << endl;
						show_passengers_list_for_moving(meeting_point_1, meeting_point_2, date);
						break;
					}
					case 'C': {
						cout << ++event_num << ". SHOW PASSENGERS LIST FOR EACH SCHEDULED MOVING" << endl;
						show_passengers_list_scheduled();
						break;
					}
					case 'E': {
						cout << ++event_num << ". SHOW PASSENGERS LIST FOR EACH COMPLETED MOVING" << endl;
						show_passengers_list_completed();
						break;
					}
					case 'B': {
						int num;
						ss >> num;
						check_positive_integer_validity(num);
						cout << ++event_num << ". SHOW DRIVERS WITH BIGGER RATE" << endl;
						show_big_rate_drivers(num);
						break;
					}
					case 'V': {
						int num;
						ss >> num;
						check_positive_integer_validity(num);
						cout << ++event_num << ". SHOW DRIVERS WITH SMALLER RATE" << endl;
						show_small_rate_drivers(num);
						break;
					}
					case 'H': {
						int num;
						ss >> num;
						check_positive_integer_validity(num);
						cout << ++event_num << ". SHOW MORE HAPPY PASSENGERS" << endl;
						show_more_happy_passengers(num);
						break;
					}
					case 'Y': {
						int num;
						ss >> num;
						check_positive_integer_validity(num);
						cout << ++event_num << ". SHOW LESS HAPPY PASSENGERS" << endl;
						show_less_happy_passengers(num);
						break;
					}
					case 'J': {
						cout << ++event_num << ". SHOW ALL VEHICLES" << endl;
						show_all_vehicles();
						break;
					}
					default: 
						//cout << "----- No S event: " << line << endl;
						break;
				}
				break;
			}
			default: 
				//cout << "----- No event: " << line << endl;
				break;
		}
	}
	
	return 0;
}

/**
 * A function used to find and replace a text into a string.
 */
void find_and_replace(string& source, string const& find, string const& replace)
{
    for(string::size_type i = 0; (i = source.find(find, i)) != string::npos;)
    {
        source.replace(i, find.length(), replace);
        i += replace.length();
    }
}


/**
 * Validates that category is one of {'A', 'D', 'P'}
 * 
 * @throws exception in case validation fails
 */
void check_category_validity(char category) 
{
	if (category!='A' && category!='D' && category!='P')  error("Error: this is not a valid user category.");
}


/**
 * Validates that the cost is >= min.
 * 
 * @throws exception in case validation fails
 */
void check_cost_validity(int cost, int min)
{
	if (cost < min) error("Error: cost value is not valid.");
}

/**
 * Validates that date is in [0..365]
 * 
 * @throws exception in case validation fails
 */
void check_date_validity(int date)
{
	if (date < 0 || date > 365) error("Error: date value is not valid.");
}

/**
 * Validates that the number of seats is a positive number
 * 
 * @throws exception in case validation fails
 */
void check_positive_integer_validity(int num_seats)
{
	if (num_seats < 1) error("Error: this is not a positive number.");
}

/**
 * Validates that rate is in [0..100]
 * 
 * @throws exception in case validation fails
 */
void check_rate_validity(int rate)
{
	if (rate < 0 || rate > 100) error("Error: date value is not valid.");
}
