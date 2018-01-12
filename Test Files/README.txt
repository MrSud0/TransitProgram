==============================================================
A. TEST FILES DESCRIPTION
=========================
This package includes 14 test files, labeled as test1.txt,
test2.txt, ..., test11.txt, test12a.txt, test12b.txt,
test12c.txt. These test files correspond to 12 tests. 
More specifically the 12th test is splitted into three test 
files (test12a.txt, test12b.txt and test12c.txt) since it 
additionally (to test11.txt) tests system shutdown (to 
system files) and initialization from (these) files.

Each test file describes the events it contains. Each of these 
events is identical and complies with the description of the 
corresponding project's event. It should not be hard for you 
to match them.

Each test file incrementaly introduces new categories of 
events. For this reason, you should implement the events for 
all the previous test files, before you consider working with 
the next test file.

This is NOT a COMPLETE set of tests. These test are only 
provided for your convenience. Your final program should run 
for ANY test, including these events. If you prefer it, you 
can use these events in order to describe (and execute) your 
scenarios, by developing your test files.
==============================================================

==============================================================
B. PROGRAM FILES DESCRIPTION
============================
1. read_events.cpp
-------------------
Contains the code for parsing the events from the test files. 
There is no need to change this code.

2. project_events.h
-------------------
Contains the functions' prototypes (declarations) used to 
implement the project's events. There is no need to change 
this code.

3. project_events.cpp
---------------------
Contains the functions' implementations (definitions) used to 
implement the project's events. YOU SHOULD CHANGE THIS CODE, 
in order to implement each event, according to your symstem's 
implementation.
==============================================================

==============================================================
C. HOW TO USE
=============
This highly depends on the C++ IDE you use. However, the 
general steps are the following:
1. Import all files into your project.
2. Make project_events.cpp the main project file.
3. Add extra header files required for the event's code to be
   linked with your system. e.g. include required header files
   in "project_events.cpp".
4. To run the test files, add the required parameters to your 
   project, e.g. i) "test1.txt", ii) "text12b.txt" and "INIT".
5. To run your program (not any test file), just do not add
   any parameter.
==============================================================