#include "core.hpp"
int Core::tasks = 0;
std::queue <TaskType> Core::globalTasks;
Core::Core(TaskType t){
    this->type = t;
}
void Core::RemoveTask(){
    this->assignedTasks.pop();
}
TaskType Core::GetTaskType(){
    return this->type;
}
void Core::SetTaskQuantity(int n){
    Core::tasks = n;
}
int Core::GetGlobalTaskCount(){
    return Core::tasks;
}
bool Core::Empty(){
    return this->assignedTasks.empty();
}

void Core::Core::Assign(TaskType t){
    this->assignedTasks.push(t);
}
std::queue <TaskType> Core::GetGlobalTasks(){
    return Core::globalTasks;
}
int Core::Init(std::string path){
    
    std::ifstream file(path);
    if(!file.is_open()){
        return 1;
    }

    std::string line;
    std::getline(file, line);
    Core::SetTaskQuantity(stoi(line));

    while(std::getline(file, line)){
        std::istringstream stringStream(line);
        std::string a;
        std::getline(stringStream, a, '\n');
        if(a == "H"){
            Core::globalTasks.push(H);
        }else if(a ==  "M"){
            Core::globalTasks.push(M);
        }else if(a ==  "L"){
            Core::globalTasks.push(L);
        }
        

    }
    file.close();
    return 0;
}
int Core::GetTaskCount(){
    return this->assignedTasks.size();
}
int Core::BeginSolvingAll(Core X2, Core A710, Core A510){
    int count = 0;
    while(!X2.Empty() || !A710.Empty() || !A510.Empty()){
        if(!X2.Empty()){
            X2.RemoveTask();
        }
        if(!A710.Empty()){
            A710.RemoveTask();
        }
        if(!A510.Empty()){
            A510.RemoveTask();
        }
        count++;
    }
    return count;
}
TaskType Core::GetLastTask(){
    return this->assignedTasks.back();
}
int Core::ComputeRR(Core X2, Core A710, Core A510){
    std::queue<TaskType> temp;
    temp = Core::globalTasks;
    while(!Core::globalTasks.empty()){
        if(Core::globalTasks.front() != X2.GetTaskType() && Core::globalTasks.size() > 0){
            X2.Assign(Core::globalTasks.front());
            X2.Assign(Core::globalTasks.front());
            
            Core::globalTasks.pop();
        } 
        else if (Core::globalTasks.front() == X2.GetTaskType() && Core::globalTasks.size() > 0){
            X2.Assign(Core::globalTasks.front());
            
            Core::globalTasks.pop();
        }

        if(Core::globalTasks.front() != A710.GetTaskType() && Core::globalTasks.size() > 0){
            A710.Assign(Core::globalTasks.front());
            A710.Assign(Core::globalTasks.front());
            
            Core::globalTasks.pop();
        } 
        else if (Core::globalTasks.front() == A710.GetTaskType() && Core::globalTasks.size() > 0){
            A710.Assign(Core::globalTasks.front());
            
            Core::globalTasks.pop();
        }
    
        if(Core::globalTasks.front() != A510.GetTaskType() && Core::globalTasks.size() > 0){
            A510.Assign(Core::globalTasks.front());
            A510.Assign(Core::globalTasks.front());
            
            Core::globalTasks.pop();
        } 
        else if (Core::globalTasks.front() == A510.GetTaskType() && Core::globalTasks.size() > 0){
            A510.Assign(Core::globalTasks.front());
            
            Core::globalTasks.pop();
        }
    }
    Core::globalTasks = temp;
  
    
 
    return BeginSolvingAll(X2, A710, A510);
}

int Core::ComputeBM(Core X2, Core A710, Core A510){
    std::queue<TaskType> temp;
    temp = Core::globalTasks;
    while(!globalTasks.empty()){
        if(X2.GetTaskType() == Core::globalTasks.front()){
           X2.Assign(Core::globalTasks.front());
           
           Core::globalTasks.pop();
        }
        if(A710.GetTaskType() == Core::globalTasks.front()){
           A710.Assign(Core::globalTasks.front());
           
           Core::globalTasks.pop();
        }
        if(A510.GetTaskType() == Core::globalTasks.front()){ 
                                                                            
                                                                    
           A510.Assign(Core::globalTasks.front());
           
           Core::globalTasks.pop();
        }
        if(X2.GetTaskCount() == A710.GetTaskCount() + 3){
            A710.Assign(X2.GetLastTask());
            A710.Assign(X2.GetLastTask());
            X2.RemoveTask();
        } else if(X2.GetTaskCount() + 3 == A710.GetTaskCount()){
            X2.Assign(A710.GetLastTask());
            X2.Assign(A710.GetLastTask());
            A710.RemoveTask();
        }
    
        if(X2.GetTaskCount() == A510.GetTaskCount() + 3){
            A510.Assign(X2.GetLastTask());
            A510.Assign(X2.GetLastTask());
            X2.RemoveTask();

        } else if(X2.GetTaskCount() + 3 == A510.GetTaskCount()){
            X2.Assign(A510.GetLastTask());
            X2.Assign(A510.GetLastTask());
            A510.RemoveTask();
        }

        if(A710.GetTaskCount() == A510.GetTaskCount() + 3){
            A510.Assign(A710.GetLastTask());
            A510.Assign(A710.GetLastTask());
            A710.RemoveTask();
        
        } else if(A710.GetTaskCount() + 3 == A510.GetTaskCount()){
            A710.Assign(A510.GetLastTask());
            A710.Assign(A510.GetLastTask());
            A510.RemoveTask();
        }
    }
    Core::globalTasks = temp;
    return Core::BeginSolvingAll(X2, A710, A510);
}