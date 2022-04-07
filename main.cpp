#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::getline;

/*
 * Before running the program take a look at the following two pages:
 * --> getline:    http://cplusplus.com/reference/string/string/getline/
 * --> operator>>: http://cplusplus.com/reference/string/string/operator%3E%3E/
 *
 * 1. When does the getline function stop reading from the input stream?
 * Until a delimitation character is found or a newline character
 * 2. When does the operator>> stop reading from the input stream?
 * Until there is whitespace
 */

int main() {
    /*
     * When you run the program,
     * try the following names:
     * not-here.txt
     * --> The program should respond:
     *     Unable to open not-here.txt
     * --> 3. Any idea why the output is shown in a different color?
     * To show there was an error
     * data.txt
     * 4. Was it able to open it? Any idea why?
     * The file was not able to open and I think it is because we didn't include the data.txt file in our main
     * ../data.txt
     * This time the program must've been able to open the file
     * 5. Why do you think that is? A hint: where is the program running from?
     * I think the ../ has something to do with including the data.txt file in the main
     */

    string filename;
    cout << "Please input file name: ";
    cin >> filename;

    ifstream input;
    string string1, string2;

    input.open(filename);
    if (input.fail()){
        cerr << "Unable to open " << filename << endl;
        return 1;
    }
    /*
     * Notice in this part of the program that we are reading from the file
     * first by using the stream extraction operator >>
     * and then using the function getline
     * Notice the output. 
     * 6. Why do you think the output looks like that?
     * The >> operator only foes until it sees whitespace, so it stops after the new line
     */
    input >> string1;
    getline(input, string2);
    cout << "input << string1;   getline(input, string2);" << endl;
    cout << "string1 = " << string1 << endl;
    cout << "string2 = " << string2 << endl;

    input.close(); // to reset
    input.open(filename);
    // Just in case
    if (input.fail()){
        cerr << "Unable to open " << filename << endl;
        return 1;
    }
    /*
     * Now the program is reading from the file but this time
     * first by using getline and then by using the stream operator >>
     * Is it different from the output you saw from the previous code?
     * Yes, string 2 is now Amazing
     * 7. Why is that?
     * By looking at it we switched the getline and >> operator, I think it is so that the getline
     * takes everything from the first line and stops at the newline and the >> can take the second line
     */
    getline(input, string1);
    input >> string2;
    cout << "getline(input, string2);   input << string1;" << endl;
    cout << "string1 = " << string1 << endl;
    cout << "string2 = " << string2 << endl;

    input.close();

    return 0;
}
