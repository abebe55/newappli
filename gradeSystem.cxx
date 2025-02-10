#include<fstream>
#include <iostream>
#include <string>
using namespace std;
struct Student {
 string name;
   int id;
   int age;
   string gender;
    string courses[6];
    double marksMid[6];
   double marksAsmnt[6];
    double marksFinal[6];
    double marks[6];
     double sum;
    double avg;
     string grade[6];
     string remark;
     Student* next;
};
Student*head=NULL;
Student*tail=NULL;
void addNewStudent();
void addCourses();
void sumAvgRemark();
void markFromHundred(Student*current);
void sumGrade(Student*current);
void calculateAverage(Student*current);
void displayRemark(Student*current);
void studentGrade(Student*current);
void displayStudentDetails(Student*current);
void displayAllStudentDetails();
void displayByRemark();
void searchStudent();

void updateStudentDetails();
void deleteStudent();
void deleteAllStudents();
void saveStudentDetailsToFile();
void loadStudentDetailsFromFile();
void sortStudentsByAvg();
void displayTopNStudents();
void percentage();
void percentageOfStudentsMark();
int main()
 {

int h;
string passWord,userName;
cout<<"============================================"<<endl;
cout<<"|     WELCOME TO STUDENT GRADING SYSTEM    |"<<endl;
cout<<"|==========================================|"<<endl;
cout<<"|       enter 1 to start as a registral    |"<<endl;
cout<<"|       enter 2 to start as a teacher      |"<<endl;
cout<<"|       enter 3 to start as a student      |"<<endl;
cout<<"============================================"<<endl;
cin>>h;
 if(h==1){
char x;
string user,pass;
cout<<"enter  a  to start"<<endl;
cin>>x;
while(x == 'a'){
cout<<"================================="<<endl;
cout<<"   enter user name :-";
cin>>user;
cout<<endl;
cout<<"   enter password  :-";
cin>>pass;
cout<<"================================="<<endl;
passWord=pass;
userName=user;
if(userName =="registral" && passWord == "wdu1234")
{
   int s1,c1;
cout<<"    enter 1 to start"<<endl;
cout<<"--------------------------"<<endl;
cin>>s1;
while(s1==1){
cout<<"======================================||==================================================================="<<endl;
cout<<"| enter  1  add a new student         ||   enter  7  delete all students                                  |" <<endl;
cout<<"| enter  2  display all student       ||   enter  8  save student details to a file                       |"<<endl;
cout<<"| enter  3  search  a student         ||   enter  9  load student details from a file                     |"<<endl;
cout<<"| enter  4  display students by Remark||   enter  10 display top n students                               |"<<endl;
cout<<"| enter  5  update Student details    ||   enter  11 sort the students by average mark                    |"<<endl;
cout<<"| enter  6  delete a student by id    ||   enter  12 display the percentage of passed and failed students |"<<endl;
cout<<"======================================||==================================================================="<<endl;
    cin>>c1;
switch(c1)
{
    case 1:
    addNewStudent();
        break;
    case 2:
    sumAvgRemark();
    displayAllStudentDetails();
       break;
    case 3:
    searchStudent();
       break;
    case 4:
    displayByRemark();
        break;
    case 5:
    updateStudentDetails();
         break;
     case 6:
    deleteStudent();
       break ;
    case 7:
    deleteAllStudents();
       break;
    case 8:
    saveStudentDetailsToFile();
       break;
    case 9:
    loadStudentDetailsFromFile();
       break;
    case 10:
    sortStudentsByAvg();
    displayTopNStudents();
       break;
    case 11:
    sortStudentsByAvg();
      break;
    case 12 :
    percentage();
    break;
    default :
    cout<<" wrong choice"<<endl;
      }
    cout <<"enter 1 to start with a new choice"<<endl;
    cout<<"------------------------------------------"<<endl;
    cin>>s1;
     }
 }

else{
cout<<"you entered wrong username or password "<<endl;
 }
cout<<"enter  a  to start"<<endl;
cin>>x;
}

}
else if(h==2 ){
string user,pass;
 char x;
 int s,k;
cout<<"enter  b  to start"<<endl;
cin>>x;
while(x == 'b'){
cout<<"================================="<<endl;
cout<<"   enter user name :-";
cin>>user;
cout<<endl;
cout<<"   enter password  :-";
cin>>pass;
cout<<"================================="<<endl;
passWord=pass;
userName=user;
if(userName =="teacher" && passWord == "wdu1234"){
cout<<" enter 1 to start"<<endl;
cout<<"------------------"<<endl;
cin>>s;
while(s==1){
cout<<" enter 1 to add students course and marks"<<endl;
cout<<"------------------------------------------"<<endl;
cin>>k;
if(k==1) {
addCourses();
}
cout <<"enter 1 to start with a new choice"<<endl;
cout<<"------------------------------------------"<<endl;
cin>>s;
    }
   }
 else{
cout<<"you entered wrongusername or password "<<endl;
 }
cout<<"enter  b  to start"<<endl;
cin>>x;
}
}
else if(h==3 ){
string user,pass;
 char x;
 int s,k;
cout<<"enter  c  to start"<<endl;
cin>>x;
while(x == 'c'){
cout<<"================================="<<endl;
cout<<"   enter user name :-";
cin>>user;
cout<<endl;
cout<<"   enter password  :-";
cin>>pass;
cout<<"================================="<<endl;
passWord=pass;
userName=user;
if(userName =="student" && passWord == "wdu1234"){
cout<<" enter 1 to start"<<endl;
cout<<"------------------"<<endl;
cin>>s;
while(s==1){
cout<<" enter 1 to search your grade information"<<endl;
cout<<"------------------------------------------"<<endl;
cin>>k;
if(k==1) {

searchStudent();
}
cout <<"enter 1 to start with a new choice"<<endl;
cout<<"------------------------------------------"<<endl;
cin>>s;
    }
   }
 else{
cout<<"you entered wrongusername or password "<<endl;
 }
cout<<"enter  c  to start"<<endl;
cin>>x;
}
}
return 0;
}




void addNewStudent(){
    Student*newStudent=new Student;
    cout<<"enter the name:"<<endl;
    getline(cin.ignore(), newStudent->name);
    cout<<"enter the id:"<<endl;
    cin>>newStudent->id;
    cout<<"enter the age:"<<endl;
    cin>>newStudent->age;
    cout<<"enter the gender:"<<endl;
   getline(cin.ignore(), newStudent->gender);
     newStudent->next=NULL;
        if (head == NULL) {
        head = newStudent;
        tail = newStudent;
} else {
        tail->next = newStudent;
        tail = newStudent;
    }
    cout << "  a new Student details added successfully." << endl;
  
}
void markFromHundred(Student*current){
  for ( int i= 0; i<6; i++){
     current->marks[i] = current->marksMid[i] + current->marksAsmnt[i] + current->marksFinal[i];
}
}
void sumAvgRemark(){
loadStudentDetailsFromFile();
 
if (head == NULL) {
        cout << "No students found." << endl;
        return;
        }
        Student*current = head;
    while(current != NULL) {
    sumGrade(current);
    calculateAverage(current);
    
     displayRemark(current);
    current=current->next;
}
saveStudentDetailsToFile();
}

void addCourses(){
loadStudentDetailsFromFile();
 if (head == NULL) {
        cout << "No students found." << endl;
        return;
    }int n;
    cout<<"enter course number 0-5:"<<endl;
    cin>>n;
    
    Student* current = head;
    while (current != NULL) {
   
    cout<<"enter student"<<current->id<<":"<<endl;
    cout<<"enter course name"<<endl;
    getline(cin.ignore(), current->courses[n]);
       cout<<"enter mid mark"<<endl;
    cin>>current->marksMid[n];
    cout<<"enter  asignment mark"<<endl;
    cin>>current->marksAsmnt[n];
    cout<<"enter final mark"<<endl;
    cin>>current->marksFinal[n];
    cout<<"course info add succsesfuly"<<endl;
    markFromHundred(current);
    studentGrade(current);
       
        
    current = current->next;
       
    }
saveStudentDetailsToFile();

}
void sumGrade(Student*current){
        double sum = 0;
        for (int i = 0; i < 6; i++)
         {
            sum += current->marks[i];
        }
        current->sum=sum;
    }
    void calculateAverage(Student*current)
{
current->avg = current->sum / 6;
         }
void displayRemark(Student*current)
{
if(current->avg >= 50){
    current->remark = "pass";
    }
    else
    {
    current->remark = "fail";
    }
}
void studentGrade(Student*current){
for(int i=0; i<6; i++){
double m = current->marks[i];
if( m <= 100 && m >= 90)
current->grade[i] ="A+";
else if(m < 90 &&  m >= 85)
current->grade[i] ="A";
else if(m <85 &&  m  >= 80)
current->grade[i] ="A-";
 if(  m <80 &&  m >= 75)
current->grade[i] ="B+";
else if(m <75 && m >= 70)
current->grade[i] ="B";
else if(m < 70 &&  m  >= 65 )
current->grade[i]="B-";
else if( m <65 && m >= 60)
current->grade[i] ="C+";
else if(m < 60 &&  m >= 50)
current->grade[i] ="C";
if(m <50 &&  m >= 45)
current->grade[i] ="C-";
else if( m <45 && m  >= 40)
current->grade[i] ="D";
else if( m < 40)
current->grade[i] ="F";
}
}
void displayStudentDetails(Student*current){
    cout  << "Student  name: " << current->name << endl;
    cout << "Student ID: " << current->id << endl;
    cout << "Student age: " << current->age << endl;
    cout << "Student gender: " << current->gender << endl;
    for(int i=0; i<6; i++){
    cout << "Student marks: " << current->courses[i]<<"  Mid =  " <<current->marksMid[i] <<" assignment =" <<current->marksAsmnt[i]<<" final mark =  " <<current->marksFinal[i] <<" mark from 100 % =   " <<current->marks[i]<<" grade =" <<current->grade[i]<< endl;
}
    cout << "Student  sum:" << current->sum << endl;
    cout << "Student  avg:" << current->avg << endl;
    cout<<" student remark:"<< current->remark<<endl;
    }
void displayAllStudentDetails() {
loadStudentDetailsFromFile();
   if (head == NULL) {
        cout << "No students found." << endl;
        return;
    }
    Student*current = head;
   while (current != NULL) {
    cout << "Student name:   " << current->name << endl;
    cout << "Student ID:   " << current->id << endl;
    cout << "Student age:   " << current->age << endl;
    cout << "Student gender: " << current->gender << endl;
    for(int i=0; i<6; i++){
    cout << "Student marks ofcourse:  " << current->courses[i] <<" Mid =  " <<current->marksMid[i] <<" assignment=  " <<current->marksAsmnt[i]<<" final mark =  " <<current->marksFinal[i] <<" mark from 100 % =   " <<current->marks[i]<<" grade =  "  <<current->grade[i]<< endl;
}
    cout << "Student sum:        " << current->sum << endl;
    cout << "Student avg:        " << current->avg << endl;
    cout<<" student remark:      "<< current->remark<<endl;
    current = current->next;
    cout << endl;
    }
}
void searchStudent(){
loadStudentDetailsFromFile();
      int id;
      cout << "Enter student ID to search student: "<<endl;
       cin >> id;
       if (head == NULL) {
        cout << "No students found." << endl;
        return;
}
    Student* current = head;
    while (current != NULL && current->id != id) {
        current = current->next;
}
    if (current == NULL  ) {
        cout << "Student not found." << endl;
        return;
}
    else {
    displayStudentDetails(current);
    current = current->next;
    cout << endl;
   }

}
void displayByRemark(){
loadStudentDetailsFromFile();
    string remark;
    cout << "Enter  pass if you want to display passed students or fail for failed students "<<endl;
    getline(cin.ignore(),remark);
    if (head == NULL) {
    cout << "No students found." << endl;
    return;
    }
    Student* current = head;
    while (current != NULL ) {
    if (current->remark == remark){
        displayStudentDetails(current);
    }
      current = current->next;
    cout << endl;
    }
    
   }
void updateStudentDetails() {
loadStudentDetailsFromFile();
    int id;
    cout << "Enter student ID to update: ";
    cin >> id;
    if (head == NULL  ) {
        cout << "No students found." << endl;
        return;
}
    Student* current = head;
    while (current != NULL && current->id != id) {
      current = current->next;
}
      if(id == current->id){
    cout << "Enter new student name (or press enter to keep existing value): "<<endl;
    string name;
    getline(cin.ignore(), name);
    if (name != "") {
        current->name = name;
}
    cout << "Enter new student age (or press 0 to keep existing value): "<<endl;
    int age;
    cin >> age;
    if (age != 0) {
        current->age = age;
    }
    cout << "Enter new student gender (or press enter to keep existing value): "<<endl;
    string gender;
    getline(cin.ignore(), gender);
    if (gender != "") {
        current->gender = gender;
    }
    for(int i=0; i<6; i++){
       string courses[i];   double marksFinal[i], marksMid[i], marksAsmnt[i];
    cout << "Enter new student courses (or press enter to keep existing value): "<<endl;
    getline(cin.ignore(), courses[i]);
    if (courses[i] != "") {
        current->courses[i] = courses[i];
}
     cout << "Enter new student mark  of mid (or press 0.0 to keep existing value): "<<endl;
    cin >> marksMid[i];
    if (marksMid[i] != 0.0) {
        current->marksMid[i] = marksMid[i];
}
    cout << "Enter new student mark  of assignment (or press 0.0 to keep existing value): "<<endl;
    cin >> marksAsmnt[i];
    if (marksAsmnt[i] != 0.0) {
        current->marksAsmnt[i] = marksAsmnt[i];
}
   cout << "Enter new student mark  of final (or press 0.0 to keep existing value): "<<endl;
    cin >> marksFinal[i];
    if (marksFinal[i] == 0.0) {
        current->marksFinal[i] =current->marksFinal[i];
    }
    else {
        current->marksFinal[i]=marksFinal[i];
    }
    }
    markFromHundred(current);
    sumGrade(current);
    calculateAverage(current);
     displayRemark(current);
     studentGrade(current);
saveStudentDetailsToFile();

}
       else {
        cout<<"student not found"<<endl;
}
cout << "Student details updated successfully." << endl;

}
void deleteStudent() {
loadStudentDetailsFromFile();
    int id;
    cout << "Enter student ID to delete: ";
    cin >> id;
    if (head == NULL) {
    cout << "No students found." << endl;
        return;
    }
    if (head->id == id) {
        Student* temp = head;
        head = head->next;
        delete temp;
        cout << "Student deleted successfully." << endl;
        return;
}
    Student* current = head;
    while (current->next != NULL && current->next->id != id) {
        current = current->next;
}
    if (current->next == NULL) {
        cout << "Student not found." << endl;
        return;
}
    Student* temp = current->next;
    current->next = current->next->next;
    if (tail == temp) {
        tail = current;
}
    delete temp;
    cout << "Student deleted successfully." << endl;
saveStudentDetailsToFile();
}
void deleteAllStudents() {
    /*
    loadStudentDetailsFromFile();
    if (head == NULL) {
        cout << "No students found." << endl;
        return;
    }
    Student* current = head;
    while (current != NULL) {
        Student* temp = current;
        current = current->next;
        delete temp;
    }
    head = NULL;
    tail = NULL;
    cout << "All students deleted successfully." << endl;
    
}
*/
string filename;
    cout << "Enter filename to  delete :"<<endl;
    getline(cin.ignore(), filename);
   ofstream outfile(filename, ios::trunc);
   
}

void saveStudentDetailsToFile() {
    /*string filename;
    cout << "Enter filename to save to: ";
    getline(cin.ignore(), filename);*/
   ofstream outfile("filename", ios::trunc);
    if (!outfile) {
        cout << "Error: Unable to open file." << endl;
        return;
}
    if (head == NULL) {
        outfile << "No students found." << endl;
        return;
}
    Student* current = head;
    while (current != NULL) {
        outfile << current->id << "," << current->name << "," << current->age << "," << current->gender << ",";
        for(int i=0; i<6; i++){
        outfile << current->courses[i] << "," <<current->marksMid[i] <<","<<current->marksAsmnt[i]<<"," <<current->marksFinal[i] <<","<<current->marks[i] <<","<< current->grade[i]<<",";
}
        outfile << current->remark<<","<<current->sum<<","<<current->avg<<endl;
        current = current->next;
    }
    outfile.close();
    cout << "Student details saved to file." << endl;
}
void loadStudentDetailsFromFile() {
    /* string filename;
     cout << "Enter filename to load from: ";
      getline(cin.ignore(), filename);*/
     ifstream infile("filename");
     if (!infile) {
        cout << "Error: Unable to open file." << endl;
        return;
}
      string line;
      while (getline(infile, line)) {
       Student* newStudent = new Student;
        int pos = line.find(",");
       newStudent->id = stoi(line.substr(0, pos));
        line = line.substr(pos + 1);
        pos = line.find(",");
        newStudent->name = line.substr(0, pos);
        line = line.substr(pos + 1);
        pos = line.find(",");
        newStudent->age = stoi(line.substr(0, pos));
        line = line.substr(pos + 1);
        pos = line.find(",");
        newStudent->gender = line.substr(0, pos);
        line = line.substr(pos + 1);
        for(int i=0; i<6; i++){
               pos = line.find(",");
                newStudent->courses[i] = line.substr(0, pos);
                line = line.substr(pos + 1);
                pos = line.find(",");
                 newStudent->marksMid[i] = stod(line);
                 line = line.substr(pos + 1);
                 pos = line.find(",");
                 newStudent->marksAsmnt[i] = stod(line);
                 line = line.substr(pos + 1);
                 pos = line.find(",");
                 newStudent->marksFinal[i] = stod(line);
                 line = line.substr(pos + 1);
                pos = line.find(",");
                 newStudent->marks[i] = stod(line);
                line = line.substr(pos + 1);
                pos = line.find(",");
                 newStudent->grade[i] = line.substr(0, pos);
                  line = line.substr(pos + 1);
                 }
        pos = line.find(",");
        newStudent-> remark = line.substr(0, pos);
        line = line.substr(pos + 1);
        pos = line.find(",");
        newStudent->sum= stoi(line.substr(0, pos));
        line = line.substr(pos + 1);
        pos = line.find(",");
        newStudent->avg= stoi(line.substr(0, pos));
        newStudent->next = NULL;
        if (head == NULL) {
            head = newStudent;
            tail = newStudent;
        } else {
            tail->next = newStudent;
            tail = newStudent;
        }
    }
    infile.close();
    cout << "Student details loaded from file." << endl;
 }
void sortStudentsByAvg(){
loadStudentDetailsFromFile();
	Student* current = head;
    Student* index = NULL;
    int temp;  double temp1;  string temp2;
    string tempName;
   if (head == NULL) {
        return;
    }
    else {
        while (current != NULL){
            index = current->next;
            while (index != NULL) {
                if (current->avg <index->avg){
     temp2= current->id;
     current->id = index->id;
     index->id= temp;
         temp= current->age;
         current->age = index->age;
          index->age= temp;
    temp2 = current->gender;
    current->gender= index->gender;
    index->gender= temp2;
 for (int i=0; i<6; i++){
 	       temp2= current->courses[i];
           current->courses[i] = index->courses[i];
           index->courses[i]= temp2;
    temp1 = current->marksMid[i];
    current->marksMid[i] = index->marksMid[i];
    index->marksMid[i]=temp1;
            temp1 = current->marksAsmnt[i];
            current->marksAsmnt[i] = index->marksAsmnt[i];
            index->marksAsmnt[i]=temp1;
      temp1 = current->marksFinal[i];
      current->marksFinal[i] = index->marksFinal[i];
      index->marksFinal[i]= temp1;
                    }
                }
                index = index->next;
            }
            markFromHundred(current);
     sumGrade(current);
     calculateAverage(current);
     displayRemark(current);
     studentGrade(current);
        current = current->next;
        }
  
     }
    saveStudentDetailsToFile();
}
void displayTopNStudents() {
loadStudentDetailsFromFile();
sortStudentsByAvg();
sortStudentsByAvg();
 int count = 0, n;
    cout<<"enter n"<<endl;
    cin>>n;
    Student*current = head;
    while (current != NULL && count < n) {
        cout<<"        Id   =   "<<current->id<<endl;
        cout<<"       name  =   "<<current->name << endl;
        cout<<"Average mark =   "<<current->avg<<endl;
        current = current->next;
        count++;
    }
}
  void percentage(){
loadStudentDetailsFromFile();
           int countPassed = 0, countFailed = 0;
           double count, sumPassed = 0, sumFailed = 0;
            Student*current = head;
      while (current != NULL) {
           if (current->avg >= 50) {
            countPassed++;
            sumPassed += current->avg;
} else {
            countFailed++;
            sumFailed += current->avg;
        }
        current = current->next;
    }
    count =countPassed + countFailed;
    cout << "Average number of passed students are"<<(countPassed/count)*100<<"%"<<endl;
    cout << "Average number of failed students are"<<(countFailed/count)*100<<"%"<<endl;
     if (countPassed > 0) {
        cout << "Average score of passed students: " << sumPassed/countPassed << endl;
    } else {
        cout << "No student passed." << endl;
    }
    if (countFailed > 0) {
        cout << "Average score of failed students: " << sumFailed/countFailed << endl;
    } else {
        cout << "No student failed." << endl;
    }
}


    