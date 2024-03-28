#include<iostream>

using namespace std;

struct Task{
    string task_description;
    bool completed;
};

Task tasks[100];
int numTasks = 0;

void addTask(string task_description){
    tasks[numTasks] = {task_description, false};
    cout<<"Task added with id "<< numTasks+1<<endl;
    numTasks++;
}

void viewTasks(){
    cout<<"To-Do List:\n "<<endl;
    for(int i=0; i<numTasks; i++){
        cout<<i+1<<". "<<tasks[i].task_description;
        if (tasks[i].completed){
            cout<<"[DONE]"<<endl;
        }
        else{
            cout<<"[PENDING]"<<endl;
        }
    }
}

void markascompleted(int taskId){
    if(taskId < numTasks){
        tasks[taskId].completed=true;
    }
    else{
        cout<<"Task not found!"<<endl;
    }
}
void removeTask(int taskId) {
    if (taskId <= numTasks) {
        for (int i = taskId-1; i <= numTasks ; i++) {
            tasks[i] = tasks[i + 1];
        }
        numTasks--;
    } 
   
    else {
        cout << "Task not found!" << endl;
    }
}

int main() {
    int choice;
    
    while (true) {
        cout << "1. Add task\n";
        cout << "2. View tasks\n";
        cout << "3. Mark as completed\n";
        cout << "4. Remove task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string description;
        int taskId;

        switch (choice) {
            case 1:
                cout << "Enter description: ";
                cin>>description;
                addTask(description);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                cout << "Enter task id: ";
                cin >> taskId;
                markascompleted(taskId);
                break;
            case 4:
                cout << "Enter task id: ";
                cin >> taskId;
                removeTask(taskId);
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice!\n";
                break;
        }
        cout << endl;
    }
    return 0;
}