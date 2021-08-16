#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
#include<conio.h>
#include<windows.h>

using namespace std;

int defaultInputValue, log;              // This is Global Variable for getting Selection Input From User
string accessLable;
int englishMarks = 999, mathsMarks = 999, cssMarks = 999, htmlMarks = 999, pythonMarks = 999;

class Logs
{
public:
    void logs();
    void logs(string passValue);
    void logs(string passValue,int Value);
};

void Logs::logs()
{
    fstream logFile;
    logFile.open("logs.txt",ios::app);
    if (logFile.is_open()){
        time_t now = time(0);
        char* dt = ctime(&now);
        logFile<<"\n\n[<END>]";
    }
    logFile.close();
}

void Logs::logs(string passValue)
{
    fstream logFile;
    logFile.open("logs.txt",ios::app);
    if (logFile.is_open()){
        time_t now = time(0);
        char* dt = ctime(&now);
        logFile<<"["<<dt<<"\t <"<<passValue<<"> ]";
    }
    logFile.close();
}

void Logs::logs(string passValue,int Value)
{
    fstream logFile;
    logFile.open("logs.txt",ios::app);
    if (logFile.is_open()){
        time_t now = time(0);
        char* dt = ctime(&now);
        logFile<<"["<<dt<<"\t <"<<passValue<<" | "<<Value<<"> | ";
    }
    logFile.close();
}

class User
{
protected:
    string UserUsername, UserPassword;
public:
    //User();
    void login();
};

void User::login()
{
    system("color 71");
    char ch;
    cout<<"\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t           #    ###  ###  ###  #    #"<<endl;
    cout<<"\t\t\t\t\t           #    # #  # #   #   ##   #"<<endl;
    cout<<"\t\t\t\t\t           #    # #  ###   #   #  # #"<<endl;
    cout<<"\t\t\t\t\t           #    # #    #   #   #   ##"<<endl;
    cout<<"\t\t\t\t\t           ###  ###  ###  ###  #    #"<<endl;
    //cout<<"\t\t\t\t\t              USER LOGIN"<<endl;
    cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
    cout<<"\t\t\t\t\t|           | "<<endl;
    cout<<"\t\t\t\t\t| Username: | ";
    cin>>UserUsername;
    cout<<"\t\t\t\t\t __________________________________________"<<endl;
    cout<<"\t\t\t\t\t|           | "<<endl;
    cout<<"\t\t\t\t\t| Password: | ";
    ch = _getch();
   while(ch != 13){//character 13 is enter
      UserPassword.push_back(ch);
      cout << '*';
      ch = _getch();
   }

   //-----------------------------
   fstream usernamePasswords;
    usernamePasswords.open("userLoginDetails.txt",ios::in);
    string filename;
    if (usernamePasswords.is_open()){
        int c = 0;
        string unpassacc;
        while(getline(usernamePasswords,unpassacc)){
            if (UserUsername + UserPassword + "lec" == unpassacc ){
                accessLable = "ALLOWlect";
                break;
            }else if (UserUsername + UserPassword + "stu" == unpassacc){
                accessLable = "ALLOWstu";
                break;
            }else{
                accessLable = "DENY";
            }
        }
    }else{
        cout<<"Error While Opening File... ";
    }
    usernamePasswords.close();
}

void menuHeader()
{
    cout<<"====================================================================================================================="<<endl;
    cout<<"                                                 MAIN MENUE"<<endl;
    cout<<"====================================================================================================================="<<endl;
}

class Instructions
{
public:
    Instructions();
    ~Instructions();
};

Instructions::Instructions()
{
    if (accessLable == "ALLOWstu"){
        cout<<"====================================================================================================="<<endl;
        cout<<"                                        STUDENT INSTRUCTIONS"<<endl;
        cout<<"====================================================================================================="<<endl;
        cout<<"\n\n\n";
        cout<<"\t -> Quizzes \n Student must go to the Attempt to QUIZ option in Main Menu and after You can see Exam Menu, from this menu You can select exam after select you can attempt to Quiz | In the Quiz You will be display Question and Answers You must select Answer number in this one "<<endl<<endl;
        cout<<"\t -> Check Answers \n Student must go to the Check the Answers option in Main Menu and after You can see Exam Menu, from this menu You can select exam after select you can see the Answers and Questions "<<endl<<endl;
        cout<<"\t -> Resaults \n Student must go to the Resaults option in Main Menu and after You can see Exam Menu, from this menu You can select exam after select you can see the results of you attempted Exam's "<<endl<<endl;
        cout<<"\t -> View Profiles \n Student must go to the View Profiles option in Main Menu and after You can see Enter Username Message, from this one You can enter the username and After this you can see the user Profile of username owner's "<<endl<<endl;
        cout<<"\t -> Log Out \n  Simply You can exit from the system."<<endl<<endl;
        cout<<"\t -> ABOUT ERROR MESSAGES \n  "<<endl<<endl;
    }else{
        cout<<"====================================================================================================="<<endl;
        cout<<"                                        LECTURER INSTRUCTIONS"<<endl;
        cout<<"====================================================================================================="<<endl;
        cout<<"\n\n\n";
        cout<<"\t -> Edit Exam \n You must go to the Edit Exam option in Main Menu and after You can see Exam Menu, from this menu You can select exam after select you can Edit exam BUT REMEMBER OLDER DATA WILL LOSS| In the Quiz You will be display first add Question Message then you can enter Question and after Answers can add You must select Answer number in this one also "<<endl<<endl;
        cout<<"\t -> Add Student \n You can simply Add students by adding details "<<endl<<endl;
        cout<<"\t -> Add Lecturer\n You can simply Add Lecturer by adding details "<<endl<<endl;
        cout<<"\t -> View Profiles \n You must go to the View Profiles option in Main Menu and after You can see Enter Username Message, from this one You can enter the username and After this you can see the user Profile of username owner's "<<endl;
        cout<<"\t -> Log Out \n  Simply You can exit from the system."<<endl<<endl;
        cout<<"\t -> ABOUT ERROR MESSAGES \n  "<<endl<<endl;
    }
}

Instructions::~Instructions()
{

}


class Student : public User
{
public:
    Student();
    void menu();
    void profile();
};

Student::Student()
{

}

void Student::menu()
{
    cout<<"\n\n";
    cout<<"\t\t\t\t________________________________________"<<endl<<endl;
    cout<<"\t\t\t\t\t01. Read the Instructions"<<endl;
    cout<<"\t\t\t\t\t02. Attempt to QUIZ"<<endl;
    cout<<"\t\t\t\t\t03. Check the Answers"<<endl;
    cout<<"\t\t\t\t\t04. Results"<<endl;
    cout<<"\t\t\t\t\t05. View Profiles"<<endl;
    cout<<"\t\t\t\t\t00. Log Out"<<endl;
    cout<<"\t\t\t\t________________________________________"<<endl<<endl;
}

void Student::profile()
{
        fstream profile;
        string fileName;
        cout<<"Enter Username \n -> ";
        cin>>fileName;
        profile.open(fileName + ".txt",ios::in);
        if (profile.is_open()){
            string data; int c = 1;
            while(getline(profile,data)){
                switch (c)
                {
                case 1:
                    cout<<" _________________________________________________________________________________"<<endl;
                    cout<<"|            |"<<endl;
                    cout<<"| NAME       | "<<data<<endl;
                    cout<<"|____________|____________________________________________________________________"<<endl;
                    break;
                case 2:
                    cout<<" _________________________________________________________________________________"<<endl;
                    cout<<"|            |"<<endl;
                    cout<<"| Address    | "<<data<<endl;
                    cout<<"|____________|____________________________________________________________________"<<endl;
                    break;
                case 3:
                    cout<<" _________________________________________________________________________________"<<endl;
                    cout<<"|            |"<<endl;
                    cout<<"| Tel:       | "<<data<<endl;
                    cout<<"|____________|____________________________________________________________________"<<endl;
                    break;
                case 4:
                    cout<<" _________________________________________________________________________________"<<endl;
                    cout<<"|            |"<<endl;
                    cout<<"| e-mail     | "<<data<<endl;
                    cout<<"|____________|____________________________________________________________________"<<endl;
                    break;
                case 5:
                    cout<<" _________________________________________________________________________________"<<endl;
                    cout<<"|            |"<<endl;
                    cout<<"| User Type: | "<<data<<endl;
                    cout<<"|____________|____________________________________________________________________"<<endl;
                    break;
                case 6:
                    cout<<" _________________________________________________________________________________"<<endl;
                    cout<<"|                 |"<<endl;
                    cout<<"| Specialization: | "<<data<<endl;
                    cout<<"|_________________|________________________________________________________________"<<endl;
                    break;
                case 7:
                    cout<<" _________________________________________________________________________________"<<endl;
                    cout<<"|                    |"<<endl;
                    cout<<"| Working Branches:  | "<<data<<endl;
                    cout<<"|____________________|_____________________________________________________________"<<endl;
                    break;
                }
                c = c + 1;
            }
        }else{
            system("color 47");
            cout<<"There are no Users from this Username... "<<endl;
        }
        profile.close();
}


class Lecturer
{
    string username, password;
public:
    Lecturer ();
    void menu();
    void profiles();
    void addNewStudent();
    void addNewLecturer();
    void addStudentUserNamePassword();
    void addLecturerUsernamePassword();
};

Lecturer::Lecturer()
{

}

void Lecturer::menu()
{
    cout<<"\n\n";
    cout<<"\t\t\t\t________________________________________"<<endl<<endl;
    cout<<"\t\t\t\t\t01. Read the Instructions"<<endl;
    cout<<"\t\t\t\t\t02. Edit Exam"<<endl;
    cout<<"\t\t\t\t\t03. Add Student"<<endl;
    cout<<"\t\t\t\t\t04. Add Lecturer"<<endl;
    cout<<"\t\t\t\t\t05. View Profiles"<<endl;
    cout<<"\t\t\t\t\t00. Log Out"<<endl;
    cout<<"\t\t\t\t________________________________________"<<endl<<endl;
}

void Lecturer::profiles()
{
    fstream profile;
    string fileName;
    cout<<"Enter Username \n -> ";
    cin>>fileName;
    profile.open(fileName + ".txt",ios::in);
    if (profile.is_open()){
        string data; int c = 1;
        while(getline(profile,data)){
            switch (c)
            {
                case 1:
                    cout<<" _________________________________________________________________________________"<<endl;
                    cout<<"|            |"<<endl;
                    cout<<"| NAME       | "<<data<<endl;
                    cout<<"|____________|____________________________________________________________________"<<endl;
                    break;
                case 2:
                    cout<<" _________________________________________________________________________________"<<endl;
                    cout<<"|            |"<<endl;
                    cout<<"| Address    | "<<data<<endl;
                    cout<<"|____________|____________________________________________________________________"<<endl;
                    break;
                case 3:
                    cout<<" _________________________________________________________________________________"<<endl;
                    cout<<"|            |"<<endl;
                    cout<<"| Tel:       | "<<data<<endl;
                    cout<<"|____________|____________________________________________________________________"<<endl;
                    break;
                case 4:
                    cout<<" _________________________________________________________________________________"<<endl;
                    cout<<"|            |"<<endl;
                    cout<<"| e-mail     | "<<data<<endl;
                    cout<<"|____________|____________________________________________________________________"<<endl;
                    break;
                case 5:
                    cout<<" _________________________________________________________________________________"<<endl;
                    cout<<"|            |"<<endl;
                    cout<<"| User Type: | "<<data<<endl;
                    cout<<"|____________|____________________________________________________________________"<<endl;
                    break;
                case 6:
                    cout<<" _________________________________________________________________________________"<<endl;
                    cout<<"|                 |"<<endl;
                    cout<<"| Specialization: | "<<data<<endl;
                    cout<<"|_________________|________________________________________________________________"<<endl;
                    break;
                case 7:
                    cout<<" _________________________________________________________________________________"<<endl;
                    cout<<"|                    |"<<endl;
                    cout<<"| Working Branches:  | "<<data<<endl;
                    cout<<"|____________________|_____________________________________________________________"<<endl;
                    break;
            }
            c = c + 1;
        }
    }else{
        system("color 47");
        cout<<"There are no Users from this Username... "<<endl;
    }
    profile.close();

}

void Lecturer::addLecturerUsernamePassword()
{
    fstream lecturerUsernamePassword;
    lecturerUsernamePassword.open("userLoginDetails.txt",ios::app);
    if (lecturerUsernamePassword.is_open()){
        cout<<"Enter Username \n -> ";
        cin>>username;
        cout<<"Enter Password \n -> ";
        cin>>password;
        lecturerUsernamePassword<<"\n"<<username+password+"lec";
    }else{
        system("color 47");
        cout<<"Error While Opening File... ";
    }
    lecturerUsernamePassword.close();
}

void Lecturer::addNewLecturer()
{
    fstream addLecturerDetails;
    string filename;
    filename = username + ".txt";
    addLecturerDetails.open(filename,ios::out);
    if (addLecturerDetails.is_open()){

        string Name, address, tel, mail,userType = "Lecturer", special, branch;
        cout<<"Enter Full Name \n -> ";
        cin>>Name;
        cout<<"\n\nEnter Home Address \n -> ";
        cin>>address;
        cout<<"\n\nEnter Telephone Number \n -> +94 ";
        cin>>tel;
        cout<<"\n\nEnter email Address \n -> ";
        cin>>mail;
        cout<<"\n\nEnter Specializations \n -> ";
        cin>>special;
        cout<<"\n\nEnter Working Branchs \n -> ";
        cin>>branch;

        addLecturerDetails<<Name<<"\n"<<address<<"\n"<<tel<<"\n"<<mail<<"\n"<<userType<<"\n"<<special<<"\n"<<branch;

        system("CLS");

        system("Color 27");
        cout<<"\n\n";
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
        cout<<"\n\n\t\t\t\t\t         User Added Sucessfully..."<<endl;
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;

    }else{
        system("color 47");
        cout<<"Error While Opening File... ";
    }
    addLecturerDetails.close();
}

void Lecturer::addStudentUserNamePassword()
{
    fstream studentUsernamePassword;
    studentUsernamePassword.open("userLoginDetails.txt",ios::app);
    if (studentUsernamePassword.is_open()){
        cout<<"Enter Username \n -> ";
        cin>>username;
        cout<<"Enter Password \n -> ";
        cin>>password;
        studentUsernamePassword<<"\n"<<username+password+"stu";
    }else{
        system("color 47");
        cout<<"Error While Opening File... ";
    }
    studentUsernamePassword.close();
}

void Lecturer::addNewStudent()
{
    fstream addStudtntDetails;
    string filename;
    filename = username + ".txt";
    addStudtntDetails.open(filename,ios::out);
    if (addStudtntDetails.is_open()){
        string Name, address, tel, mail,userType = "Student";
        cout<<"Enter Full Name \n -> ";
        cin>>Name;
        cout<<"\n\nEnter Home Address \n -> ";
        cin>>address;
        cout<<"\n\nEnter Telephone Number \n -> +94 ";
        cin>>tel;
        cout<<"\n\nEnter email Address \n -> ";
        cin>>mail;

        addStudtntDetails<<Name<<"\n"<<address<<"\n"<<tel<<"\n"<<mail<<"\n"<<userType;

        system("CLS");

        system("Color 27");
        cout<<"\n\n";
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
        cout<<"\n\n\t\t\t\t\t         User Added Sucessfully..."<<endl;
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
    }else{
        cout<<"Error While Opening File... ";
    }
    addStudtntDetails.close();
}


class Exam
{
public:
    //Exam();
    string answer[20], userAnswer[20];

    void englishQUIZ();
    void mathsQuiz();
    void cssQUIZ();
    void htmlQUIZ();
    void pythonQUIZ();
    void checkAnswers();
    void resaults();
    void editExam();
};


void Exam::englishQUIZ()
{
    fstream englishExam;
    englishExam.open("examEnglish.txt",ios::in);
    if (englishExam.is_open()){
        string QA;
        int c = 1, countValue = 0;
        while(getline(englishExam,QA)){
            if (c%6 == 1){
                for (int i = 0; i<1; i++){
                    cout<<"\t"<<QA<<endl;
                    cout<<"_____________________________________ "<<endl<<endl;
                }
            }else if(c%6 == 2 ||c%6 == 3 || c%6 == 4 || c%6 == 5 ){
                cout<<(c%6) - 1<<" - "<<QA<<endl;

            }else{
                answer[countValue] = QA;
                cout<<"\n________________________________"<<endl;
                cout<<"|              |"<<endl;
                cout<<"| Enter Answer |";
                cin>>userAnswer[countValue];
                countValue = countValue + 1;
                cout<<"\n\n\n";
            }
            c = c + 1;
        }
    }else{
        cout<<"Error While Opening File...";
    }
    englishExam.close();
    englishMarks = 0;
    for (int chAs = 0; chAs <= 20; chAs++){
        if (userAnswer[chAs] == answer[chAs]){
            englishMarks = englishMarks + 1;
        }
    }
    system("CLS");
    if (englishMarks > 10){
        system("Color 27");
        cout<<"\n\n";
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
        cout<<"\n\n\t\t\t\t\t                   PASS"<<endl;
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
        cout<<"\t\t\t"<<englishMarks<<"/20"<<endl;
    }else{
        system("Color 47");
        cout<<"\n\n";
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
        cout<<"\n\n\t\t\t\t\t                   FAIL"<<endl;
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
        cout<<"\t\t\t"<<englishMarks<<"/20"<<endl;
    }
    system("pause");
}

void Exam::mathsQuiz()
{
    fstream mathsExam;
    mathsExam.open("examMaths.txt",ios::in);
    if (mathsExam.is_open()){
        string QA;
        int c = 1, countValue = 0;
        while(getline(mathsExam,QA)){
            if (c%6 == 1){
                for (int i = 0; i<1; i++){
                    cout<<"\t"<<QA<<endl;
                    cout<<"_____________________________________ "<<endl<<endl;
                }
            }else if(c%6 == 2 ||c%6 == 3 || c%6 == 4 || c%6 == 5 ){
                cout<<(c%6) - 1<<" - "<<QA<<endl;

            }else{
                answer[countValue] = QA;
                cout<<"\n________________________________"<<endl;
                cout<<"|              |"<<endl;
                cout<<"| Enter Answer |";
                cin>>userAnswer[countValue];
                countValue = countValue + 1;
                cout<<"\n\n\n";
            }
            c = c + 1;
        }
    }else{
        cout<<"Error While Opening File...";
    }
    mathsExam.close();
    mathsMarks = 0;
    for (int chAs = 0; chAs <= 20; chAs++){
        if (userAnswer[chAs] == answer[chAs]){
            mathsMarks = mathsMarks + 1;
        }
    }
    system("CLS");
    if (mathsMarks > 10){
        system("Color 27");
        cout<<"\n\n";
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
        cout<<"\n\n\t\t\t\t\t                   PASS"<<endl;
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
        cout<<"\t\t\t"<<mathsMarks<<"/20"<<endl;
    }else{
        system("Color 47");
        cout<<"\n\n";
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
        cout<<"\n\n\t\t\t\t\t                   FAIL"<<endl;
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
        cout<<"\t\t\t"<<mathsMarks<<"/20"<<endl;
    }
    system("pause");
}

void Exam::cssQUIZ()
{
    fstream cssExam;
    cssExam.open("examCSS.txt",ios::in);
    if (cssExam.is_open()){
        string QA;
        int c = 1, countValue = 0;
        while(getline(cssExam,QA)){
            if (c%6 == 1){
                for (int i = 0; i<1; i++){
                    cout<<"\t"<<QA<<endl;
                    cout<<"_____________________________________ "<<endl<<endl;
                }
            }else if(c%6 == 2 ||c%6 == 3 || c%6 == 4 || c%6 == 5 ){
                cout<<(c%6) - 1<<" - "<<QA<<endl;

            }else{
                answer[countValue] = QA;
                cout<<"\n________________________________"<<endl;
                cout<<"|              |"<<endl;
                cout<<"| Enter Answer |";
                cin>>userAnswer[countValue];
                countValue = countValue + 1;
                cout<<"\n\n\n";
            }
            c = c + 1;
        }
    }else{
        cout<<"Error While Opening File...";
    }
    cssExam.close();

    cssMarks = 0;
    for (int chAs = 0; chAs <= 20; chAs++){
        if (userAnswer[chAs] == answer[chAs]){
            cssMarks = cssMarks + 1;
        }
    }
    system("CLS");
    if (cssMarks > 10){
        system("Color 27");
        cout<<"\n\n";
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
        cout<<"\n\n\t\t\t\t\t                   PASS"<<endl;
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
        cout<<"\t\t\t"<<cssMarks<<"/20"<<endl;
    }else{
        system("Color 47");
        cout<<"\n\n";
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
        cout<<"\n\n\t\t\t\t\t                   FAIL"<<endl;
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
        cout<<"\t\t\t"<<cssMarks<<"/20"<<endl;
    }
    system("pause");
}

void Exam::htmlQUIZ()
{
    fstream htmlExam;
    htmlExam.open("examHTML.txt",ios::in);
    if (htmlExam.is_open()){
        string QA;
        int c = 1, countValue = 0;
        while(getline(htmlExam,QA)){
            if (c%6 == 1){
                for (int i = 0; i<1; i++){
                    cout<<"\t"<<QA<<endl;
                    cout<<"_____________________________________ "<<endl<<endl;
                }
            }else if(c%6 == 2 ||c%6 == 3 || c%6 == 4 || c%6 == 5 ){
                cout<<(c%6) - 1<<" - "<<QA<<endl;

            }else{
                answer[countValue] = QA;
                cout<<"\n________________________________"<<endl;
                cout<<"|              |"<<endl;
                cout<<"| Enter Answer |";
                cin>>userAnswer[countValue];
                countValue = countValue + 1;
                cout<<"\n\n\n";
            }
            c = c + 1;
        }
    }else{
        cout<<"Error While Opening File...";
    }
    htmlExam.close();

    htmlMarks = 0;
    for (int chAs = 0; chAs <= 20; chAs++){
        if (userAnswer[chAs] == answer[chAs]){
            htmlMarks = htmlMarks + 1;
        }
    }
    system("CLS");
    if (htmlMarks > 10){
        system("Color 27");
        cout<<"\n\n";
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
        cout<<"\n\n\t\t\t\t\t                   PASS"<<endl;
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
        cout<<"\t\t\t"<<htmlMarks<<"/20"<<endl;
    }else{
        system("Color 47");
        cout<<"\n\n";
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
        cout<<"\n\n\t\t\t\t\t                   FAIL"<<endl;
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
        cout<<"\t\t\t"<<htmlMarks<<"/20"<<endl;
    }
    system("pause");
}

void Exam::pythonQUIZ()
{
    fstream pythonExam;
    pythonExam.open("examPython.txt",ios::in);
    if (pythonExam.is_open()){
        string QA;
        int c = 1, countValue = 0;
        while(getline(pythonExam,QA)){
            if (c%6 == 1){
                for (int i = 0; i<1; i++){
                    cout<<"\t"<<QA<<endl;
                    cout<<"_____________________________________ "<<endl<<endl;
                }
            }else if(c%6 == 2 ||c%6 == 3 || c%6 == 4 || c%6 == 5 ){
                cout<<(c%6) - 1<<" - "<<QA<<endl;

            }else{
                answer[countValue] = QA;
                cout<<"\n________________________________"<<endl;
                cout<<"|              |"<<endl;
                cout<<"| Enter Answer |";
                cin>>userAnswer[countValue];
                countValue = countValue + 1;
                cout<<"\n\n\n";
            }
            c = c + 1;
        }
    }else{
        cout<<"Error While Opening File...";
    }
    pythonExam.close();

    pythonMarks = 0;
    for (int chAs = 0; chAs <= 20; chAs++){
        if (userAnswer[chAs] == answer[chAs]){
            pythonMarks = pythonMarks + 1;
        }
    }
    system("CLS");
    if (pythonMarks > 10){
        system("Color 27");
        cout<<"\n\n";
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
        cout<<"\n\n\t\t\t\t\t                   PASS"<<endl;
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
        cout<<"\t\t\t"<<pythonMarks<<"/20"<<endl;
    }else{
        system("Color 47");
        cout<<"\n\n";
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
        cout<<"\n\n\t\t\t\t\t                   FAIL"<<endl;
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
        cout<<"\t\t\t"<<pythonMarks<<"/20"<<endl;
    }
    system("pause");

}

void Exam::checkAnswers()
{
    if (defaultInputValue == 1){
        fstream englishAnswers;
        englishAnswers.open("examEnglish.txt",ios::in);
        if (englishAnswers.is_open()){
            string QA, correctAnswer[4];
            int c = 1, countValue = 0;
            while(getline(englishAnswers,QA)){
                if (c%6 == 1){
                    for (int i = 0; i<1; i++){
                        cout<<"\t"<<QA<<endl;
                        cout<<"_____________________________________ "<<endl<<endl;
                    }
                }else if(c%6 == 2 ||c%6 == 3 || c%6 == 4 || c%6 == 5 ){
                    cout<<(c%6) - 1<<" - "<<QA<<endl;

                }else{
                    cout<<"\n\n";
                    cout<<"Correct Answer : "<<QA;
                    cout<<"\n\n\n";
                    system("pause");
                    system("CLS");
                }
                c = c + 1;
            }
        }else{
            cout<<"Error While Opening File...";
        }
        englishAnswers.close();

    }else if (defaultInputValue == 2){
        fstream mathsAnswers;
        mathsAnswers.open("examMaths.txt",ios::in);
        if (mathsAnswers.is_open()){
            string QA, correctAnswer[4];
            int c = 1, countValue = 0;
            while(getline(mathsAnswers,QA)){
                if (c%6 == 1){
                    for (int i = 0; i<1; i++){
                        cout<<"\t"<<QA<<endl;
                        cout<<"_____________________________________ "<<endl<<endl;
                    }
                }else if(c%6 == 2 ||c%6 == 3 || c%6 == 4 || c%6 == 5 ){
                    cout<<(c%6) - 1<<" - "<<QA<<endl;

                }else{
                    cout<<"\n\n";
                    cout<<"Correct Answer : "<<QA;
                    cout<<"\n\n\n";
                    system("pause");
                    system("CLS");
                }
                c = c + 1;
            }
        }else{
            cout<<"Error While Opening File...";
        }
        mathsAnswers.close();

    }else if (defaultInputValue == 3){
        fstream cssAnswers;
        cssAnswers.open("examCSS.txt",ios::in);
        if (cssAnswers.is_open()){
            string QA, correctAnswer[4];
            int c = 1, countValue = 0;
            while(getline(cssAnswers,QA)){
                if (c%6 == 1){
                    for (int i = 0; i<1; i++){
                        cout<<"\t"<<QA<<endl;
                        cout<<"_____________________________________ "<<endl<<endl;
                    }
                }else if(c%6 == 2 ||c%6 == 3 || c%6 == 4 || c%6 == 5 ){
                    cout<<(c%6) - 1<<" - "<<QA<<endl;

                }else{
                    cout<<"\n\n";
                    cout<<"Correct Answer : "<<QA;
                    cout<<"\n\n\n";
                    system("pause");
                    system("CLS");
                }
                c = c + 1;
            }
        }else{
            cout<<"Error While Opening File...";
        }
        cssAnswers.close();

    }else if (defaultInputValue == 4){
        fstream htmlAnswers;
        htmlAnswers.open("examHTML.txt",ios::in);
        if (htmlAnswers.is_open()){
            string QA, correctAnswer[4];
            int c = 1, countValue = 0;
            while(getline(htmlAnswers,QA)){
                if (c%6 == 1){
                    for (int i = 0; i<1; i++){
                        cout<<"\t"<<QA<<endl;
                        cout<<"_____________________________________ "<<endl<<endl;
                    }
                }else if(c%6 == 2 ||c%6 == 3 || c%6 == 4 || c%6 == 5 ){
                    cout<<(c%6) - 1<<" - "<<QA<<endl;

                }else{
                    cout<<"\n\n";
                    cout<<"Correct Answer : "<<QA;
                    cout<<"\n\n\n";
                    system("pause");
                    system("CLS");
                }
                c = c + 1;
            }
        }else{
            cout<<"Error While Opening File...";
        }
        htmlAnswers.close();

    }else if (defaultInputValue == 5){
        fstream pythonAnswers;
        pythonAnswers.open("examPython.txt",ios::in);
        if (pythonAnswers.is_open()){
            string QA, correctAnswer[4];
            int c = 1, countValue = 0;
            while(getline(pythonAnswers,QA)){
                if (c%6 == 1){
                    for (int i = 0; i<1; i++){
                        cout<<"\t"<<QA<<endl;
                        cout<<"_____________________________________ "<<endl<<endl;
                    }
                }else if(c%6 == 2 ||c%6 == 3 || c%6 == 4 || c%6 == 5 ){
                    cout<<(c%6) - 1<<" - "<<QA<<endl;

                }else{
                    cout<<"\n\n";
                    cout<<"Correct Answer : "<<QA;
                    cout<<"\n\n\n";
                    system("pause");
                    system("CLS");
                }
                c = c + 1;
            }
        }else{
            cout<<"Error While Opening File...";
        }
        pythonAnswers.close();

    }
}

void Exam::resaults()
{
    if (defaultInputValue == 1){
        if (englishMarks == 999){
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
            cout<<"\n\n\t\t\t\t\t  You Are not Attempt to English Quiz...."<<endl;
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
            system("pause");
        }else{
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
            cout<<"\n\n\t\t\t\t\t                 "<<englishMarks<<"/20"<<endl;
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
            system("pause");
        }

    }else if (defaultInputValue == 2){
        if (englishMarks == 999){
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
            cout<<"\n\n\t\t\t\t\t You Are not Attempt to Maths Quiz...."<<endl;
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
            system("pause");
        }else{
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
            cout<<"\n\n\t\t\t\t\t                  "<<mathsMarks<<"/20"<<endl;
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
            system("pause");
        }
    }else if (defaultInputValue == 3){
        if (englishMarks == 999){
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
            cout<<"\n\n\t\t\t\t\t You Are not Attempt to CSS Quiz...."<<endl;
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
            system("pause");
        }else{
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
            cout<<"\n\n\t\t\t\t\t                 "<<cssMarks<<"/20"<<endl;
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
            system("pause");
        }
    }else if (defaultInputValue == 4){
        if (englishMarks == 999){
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
            cout<<"\n\n\t\t\t\t\t You Are not Attempt to HTML Quiz...."<<endl;
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
            system("pause");
        }else{
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
            cout<<"\n\n\t\t\t\t\t                 "<<htmlMarks<<"/20"<<endl;
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
            system("pause");
        }
    }else if (defaultInputValue == 5){
        if (englishMarks == 999){
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
            cout<<"\n\n\t\t\t\t\t You Are not Attempt to Python Quiz...."<<endl;
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
            system("pause");
        }else{
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
            cout<<"\n\n\t\t\t\t\t                 "<<pythonMarks<<"/20"<<endl;
            cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl;
            system("pause");
        }
    }

}

void Exam::editExam()
{
    if (defaultInputValue == 1){
        fstream editEglishExam;
        editEglishExam.open("examEnglish.txt");
        if (editEglishExam.is_open()){
            int c = 1;
            string data;
            while (c <= 20){
                cout<<"Enter Question \n -> ";
                cin>>data;
                editEglishExam<<data;
                cout<<"\n Question "<<c<<" added Successfully... "<<endl;
                for (int i = 1; i<=4; i++){
                    cout<<"Enter answer "<<i<<" \n -> ";
                    cin>>data;
                    editEglishExam<<"\n"<<data;
                }
                cout<<"\n___________________________________________________"<<endl;
                cout<<"|    Answer     |";
                cin>>data;
                editEglishExam<<"\n"<<data<<"\n";
                cout<<"\n\n\n Question "<<c<<"'s answers added Successfully... "<<endl;
                c = c + 1;
                system("pause");
                system("CLS");
            }
        }else{
            cout<<"Error While Opening File...";
        }
        editEglishExam.close();
    }else if (defaultInputValue == 2){
        fstream editMathsExam;
        editMathsExam.open("examMaths.txt");
        if (editMathsExam.is_open()){
            int c = 1;
            string data;
            while (c <= 20){
                cout<<"Enter Question \n -> ";
                cin>>data;
                editMathsExam<<data;
                cout<<"\n Question "<<c<<" added Successfully... "<<endl;
                for (int i = 1; i<=4; i++){
                    cout<<"Enter answer "<<i<<" \n -> ";
                    cin>>data;
                    editMathsExam<<"\n"<<data;
                }
                cout<<"\n___________________________________________________"<<endl;
                cout<<"|    Answer     |";
                cin>>data;
                editMathsExam<<"\n"<<data<<"\n";
                cout<<"\n\n\n Question "<<c<<"'s answers added Successfully... "<<endl;
                c = c + 1;
                system("pause");
                system("CLS");
            }
        }else{
            cout<<"Error While Opening File...";
        }
        editMathsExam.close();
    }else if (defaultInputValue == 3){
        fstream editCSSExam;
        editCSSExam.open("examCSS.txt");
        if (editCSSExam.is_open()){
            int c = 1;
            string data;
            while (c <= 20){
                cout<<"Enter Question \n -> ";
                cin>>data;
                editCSSExam<<data;
                cout<<"\n Question "<<c<<" added Successfully... "<<endl;
                for (int i = 1; i<=4; i++){
                    cout<<"Enter answer "<<i<<" \n -> ";
                    cin>>data;
                    editCSSExam<<"\n"<<data;
                }
                cout<<"\n___________________________________________________"<<endl;
                cout<<"|    Answer     |";
                cin>>data;
                editCSSExam<<"\n"<<data<<"\n";
                cout<<"\n\n\n Question "<<c<<"'s answers added Successfully... "<<endl;
                c = c + 1;
                system("pause");
                system("CLS");
            }
        }else{
            cout<<"Error While Opening File...";
        }
        editCSSExam.close();
    }else if (defaultInputValue == 4){
        fstream editHTMLExam;
        editHTMLExam.open("examHTML.txt");
        if (editHTMLExam.is_open()){
            int c = 1;
            string data;
            while (c <= 20){
                cout<<"Enter Question \n -> ";
                cin>>data;
                editHTMLExam<<data;
                cout<<"\n Question "<<c<<" added Successfully... "<<endl;
                for (int i = 1; i<=4; i++){
                    cout<<"Enter answer "<<i<<" \n -> ";
                    cin>>data;
                    editHTMLExam<<"\n"<<data;
                }
                cout<<"\n___________________________________________________"<<endl;
                cout<<"|    Answer     |";
                cin>>data;
                editHTMLExam<<"\n"<<data<<"\n";
                cout<<"\n\n\n Question "<<c<<"'s answers added Successfully... "<<endl;
                c = c + 1;
                system("pause");
                system("CLS");
            }
        }else{
            cout<<"Error While Opening File...";
        }
        editHTMLExam.close();
    }else if (defaultInputValue == 5){
        fstream editPythonExam;
        editPythonExam.open("examPython.txt");
        if (editPythonExam.is_open()){
            int c = 1;
            string data;
            while (c <= 20){
                cout<<"Enter Question \n -> ";
                cin>>data;
                editPythonExam<<data;
                cout<<"\n Question "<<c<<" added Successfully... "<<endl;
                for (int i = 1; i<=4; i++){
                    cout<<"Enter answer "<<i<<" \n -> ";
                    cin>>data;
                    editPythonExam<<"\n"<<data;
                }
                cout<<"\n___________________________________________________"<<endl;
                cout<<"|    Answer     |";
                cin>>data;
                editPythonExam<<"\n"<<data<<"\n";
                cout<<"\n\n\n Question "<<c<<"'s answers added Successfully... "<<endl;
                c = c + 1;
                system("pause");
                system("CLS");
            }
        }else{
            cout<<"Error While Opening File...";
        }
        editPythonExam.close();
    }
}

// =========================================================================================================
void examMenu()
{
    cout<<"====================================================================================================================="<<endl;
    cout<<"                                                   EXAMS"<<endl;
    cout<<"====================================================================================================================="<<endl;
    cout<<"\n\n"<<endl;
    cout<<"\t\t\t\t\t________________________________________"<<endl;
    cout<<"\t\t\t\t\t|             ONGOING EXAMS             |"<<endl;
    cout<<"\t\t\t\t\t________________________________________"<<endl;
    cout<<"\t\t\t\t\t|    01. English                        |"<<endl;
    cout<<"\t\t\t\t\t|    02. Maths                          |"<<endl;
    cout<<"\t\t\t\t\t|    03. HTML                           |"<<endl;
    cout<<"\t\t\t\t\t|    04. CSS                            |"<<endl;
    cout<<"\t\t\t\t\t|    05. Python                         |"<<endl;
    cout<<"\t\t\t\t\t________________________________________"<<endl;
    cout<<"\t\t\t\t\t|    00. Back to Menu                   |"<<endl;
    cout<<"\t\t\t\t\t________________________________________"<<endl;

}


void getUserSelection()
{
    cout<<"\n\n";
    cout<<" ______________________________________"<<endl;
    cout<<"|                 |"<<endl;
    cout<<"| Enter Selection | ";
    cin>>defaultInputValue;
    log = defaultInputValue;
}

void clearScreen()
{
    system("CLS");
}

void loadingBar(int delay)
{
    clearScreen();
	system("color 71");

	char a = 177, b = 219;  	// Initialize char for printing

	cout<<"\n\n\n\n\n\n\n";
	cout<<"\n\n\n\n\t\t\t\t\t\tLoading...\n\n";
	cout<<"\t\t\t\t\t\t";

	for (int i = 0; i < 26; i++){       // Print initial loading bar
		cout<<a;
	}

	cout<<"\r";	                        // Set the cursor again starting | point of loading bar
	cout<<"\t\t\t\t\t\t";

	for (int i = 0; i < 26; i++) {  	// Print loading bar progress
		cout<< b;
		Sleep(delay); //Delay command
	}
	clearScreen();
}

void invalidInputMessage()
{
    system("color 47");
    cout<<"\n\n";
    cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
    cout<<"\n\n\t\t\t\t\t              INVALID INPUT..."<<endl;
    cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl<<endl;
}

// ===================================================================================================================
int main()
{
    User x;
    Logs session;
    session.logs("User-try-to-log");
    x.login();
    loadingBar(40);
    // Student Side
    if (accessLable == "ALLOWstu"){
        session.logs("student-log");
        menuHeader();
        Student student;
        student.menu();
        getUserSelection();
        session.logs("menu-input", log);
        while (defaultInputValue != 0){
            loadingBar(20);
            switch(defaultInputValue)
            {
            case 1:
                Instructions ();
                system("pause");
                clearScreen();
                break;
            case 2:
                examMenu();
                getUserSelection();
                loadingBar(5);
                session.logs("quiz-menu-input", log);
                while (defaultInputValue != 0){
                    if (defaultInputValue == 1){
                        Exam QUIZ;
                        clearScreen();
                        QUIZ.englishQUIZ();
                    }else if (defaultInputValue == 2){
                        Exam QUIZ;
                        clearScreen();
                        QUIZ.mathsQuiz();
                    }else if (defaultInputValue == 3){
                        Exam QUIZ;
                        clearScreen();
                        QUIZ.cssQUIZ();
                    }else if (defaultInputValue == 4){
                        Exam QUIZ;
                        clearScreen();
                        QUIZ.htmlQUIZ();
                    }else if (defaultInputValue == 5){
                        Exam QUIZ;
                        clearScreen();
                        QUIZ.pythonQUIZ();
                    }else{
                        invalidInputMessage();
                        system("pause");
                    }
                    loadingBar(15);
                    examMenu();
                    getUserSelection();
                    session.logs("quiz-menu-input", log);
                    clearScreen();
                }
                break;
            case 3:
                examMenu();
                getUserSelection();
                session.logs("checkA-menu-input", log);
                while (defaultInputValue != 0){
                    if (defaultInputValue <= 5){
                        Exam check;
                        clearScreen();
                        check.checkAnswers();
                        //system("pause");
                    }else{
                        invalidInputMessage();
                        system("pause");
                    }
                    loadingBar(15);
                    examMenu();
                    getUserSelection();
                    clearScreen();
                }

                break;
            case 4:
                examMenu();
                getUserSelection();
                session.logs("resaults-menu-input", log);
                while (defaultInputValue != 0){
                    if (defaultInputValue <= 5){
                        Exam view;
                        clearScreen();
                        view.resaults();
                    }else{
                        invalidInputMessage();
                        system("pause");
                    }
                    loadingBar(15);
                    examMenu();
                    getUserSelection();
                    clearScreen();
                }
                break;
            case 5:
                session.logs("viewP-menu-input");
                student.profile();
                system("pause");
                break;
            default:
                session.logs("INVALID-menu-input");
                invalidInputMessage();
                break;
            }
            loadingBar(2);
            menuHeader();
            student.menu();
            getUserSelection();
            session.logs("menu-input", log);
        }

    // Lecturer Side
    }else if (accessLable == "ALLOWlect"){
        session.logs("lecturer-log");
        menuHeader();
        Lecturer lecturer;
        lecturer.menu();
        getUserSelection();
        session.logs("menu-input", log);
        while (defaultInputValue != 0){
            loadingBar(20);
            switch(defaultInputValue)
            {
            case 1:
                Instructions ();
                system("pause");
                clearScreen();

                break;
            case 2:
                examMenu();
                getUserSelection();
                session.logs("edit-exam-input", log);
                while (defaultInputValue != 0){
                    if (defaultInputValue <=5 ){
                        Exam edit;
                        system("CLS");
                        edit.editExam();
                    }else{
                        invalidInputMessage();
                    }
                    loadingBar(5);
                    examMenu();
                    getUserSelection();
                    session.logs("edit-exam-input", log);
                    clearScreen();
                }
                break;
            case 3:
                session.logs("add-student");
                lecturer.addStudentUserNamePassword();
                clearScreen();
                lecturer.addNewStudent();
                system("pause");

                break;
            case 4:
                session.logs("add-lecturer");
                lecturer.addLecturerUsernamePassword();
                clearScreen();
                lecturer.addNewLecturer();
                system("pause");

                break;
            case 5:
                session.logs("view-profile");
                lecturer.profiles();
                system("pause");
                break;
            default:
                session.logs("INVALID-menu-input");
                invalidInputMessage();
            }
            loadingBar(20);
            menuHeader();
            lecturer.menu();
            getUserSelection();
            session.logs("menu-input", log);
        }
    }else{
        system("color 47");
        session.logs("Invalid-Login");
        cout<<"\n\n\n\n\n\n\n";
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl;
        cout<<"\n\n\t\t\t\t\t              INVALID LOGIN..."<<endl;
        cout<<"\n\t\t\t\t\t __________________________________________"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    }
    session.logs();
    return 0;
}
