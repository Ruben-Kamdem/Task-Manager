#include <iostream>
#include <string.h>
using namespace std;

/*We want to create a sort of keep notes manager. We would have a parent class Board. From the parent class, we will 
derive a certain number of classes representing the main events on the board. In the derived classes, we will create
functions that inform of the status of those events: How far with their realisation*/

class Board
{
    public:
        void current_status (){
            string Title ="The current status of various events are pasted here.\nYou can infer them by typing the name of the event\n";
            cout<<Title<<endl;
            cout<<"\t1. Japanese_prefectures\n\t2. Names of animals\n\t3. Japanese_periods\n\t4. Programming and Physics\n\t5. Visiting Places\n";
        }
        void set_status (string stat){
            status=stat;
        }
        void set_performance (int perf){
            performance=perf;
        }
        
        void update_status (string new_stats, int perf){
            status=new_stats;
            performance=perf;
        }
    protected:
        string status;
        int performance;
};

// Here I'm trying to implement Polymorphism. Same function name but differnts behaviour.
class Japanese_prefectures : public Board{
    public:
        void current_status (){
            cout<<status<<" Performance : "<<performance<<"%"<<endl;
        }
};

class Names_of_animals : public Board{
    public:
        void current_status (){
            cout<<status<<" Performance : "<<performance<<"%"<<endl;
        }
};

class Japanese_periods : public Board{
    public:
        void current_status (){
            cout<<status<<" Performance : "<<performance<<"%"<<endl;
        }
};

class programming_physics : public Board{
    public:
        void current_status (){
            cout<<status<<" Performance : "<<performance<<"%"<<endl;
        }
};

class visiting_places : public Board{
    public:
        void current_status (){
            cout<<status<<" Performance : "<<performance<<"%"<<endl;
        }
};

int main ()
{
    int task=0, n=1, update=1, inter_perf=0;
    string inter_str;
    cout<<"******Welcome to the Keep Notes Status Board******"<<endl;
    Board board1;
    board1.current_status();
    // Creating an object of each derived class so as to be able to access the class fucntions.
    // Initialising the status of the tasks
    Japanese_prefectures prefectures;
    prefectures.set_status("You have studied the names of prefectures well. Reading the Kanji names is still difficult but you're on track. Keep up. ");
    prefectures.set_performance(80);
    Japanese_periods periods;
    periods.set_status("You know a bit about Japanese period, but more work is necessary.");
    periods.set_performance(40);
    Names_of_animals animals;
    animals.set_status("You have not yet started studying the names of Animals in Japanese. Get to work.");
    animals.set_performance(45);
    programming_physics academics;
    academics.set_status("You have been studying Physics, programming, and Japanese well. Good job. Keep Up.");
    academics.set_performance(75);
    visiting_places places;
    places.set_status("You have visited quite a good number of places tasted so many foods these holidays.");
    places.set_performance(80);
    do
    {
        cout<<"Which task's status do you want to check?? : ";
        cin>>task;
        switch (task)
        {
        case 1:
            prefectures.current_status(); break;
        case 2:
            animals.current_status();  break;
        case 3:
            periods.current_status();  break;
        case 4:
            academics.current_status();  break;
        case 5:
            places.current_status();  break;
        
        default:
            cout<<"Task unavailable. Please select from 1 to 5"<<endl;
            break;
        }
        cout<<"Do you want to see any other task's status??----Yes(1)----No(0) : ";
        cin>>n;
    } while (n);

    // Implementation of updates.
    cout<<"Do you have any updates for any of the tasks ??----Yes(1)----No(0) : ";
    cin>>update;
    if(update){
        cout<<"Which task do you want to update? Please insert the task number : ";
        cin>>task;
        cout<<"Please enter the new status: ";   cin>>inter_str;
        cout<<"New performance: ";  cin>>inter_perf;
        switch (task)
        {
        case 1:
            prefectures.update_status(inter_str,inter_perf);
            cout<<"****Prefectures Task updated****"<<endl;
            prefectures.current_status(); break;
        case 2:
            animals.update_status(inter_str,inter_perf); 
            cout<<"****Animals Task updated****"<<endl;
            animals.current_status(); break;
        case 3:
            periods.update_status(inter_str,inter_perf); 
            cout<<"****Japanese Periods Task updated****"<<endl;
            periods.current_status(); break;
        case 4:
            academics.update_status(inter_str,inter_perf);
            cout<<"****Academics Task updated****"<<endl;
            academics.current_status(); break;
        case 5:
            places.update_status(inter_str,inter_perf); 
            cout<<"****Places visited Task updated****"<<endl;
            places.current_status(); break;
        default:
            cout<<"Task unavailable. Please select from 1 to 5"<<endl;
            break;
        }
    }

    return 0;
    

}

