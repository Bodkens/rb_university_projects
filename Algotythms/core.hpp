#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <stack>
#include <string>
#include <fstream>
#include <sstream>
enum TaskType{
    H,
    M,
    L
};
class Core{
    private:
    TaskType type;
    std::queue <TaskType> assignedTasks;
    static std::queue <TaskType> globalTasks;
    static int tasks;
    static void SetTaskQuantity(int q);
    static int BeginSolvingAll(Core X2, Core A710, Core A510); 
    public:
    

    //! Compute tasks via Round-Robin
    static int ComputeRR(Core X2, Core A710, Core A510);
    

    //! Compute tasks via Best-Merge
    static int ComputeBM(Core X2, Core A710, Core A510);


    //! Returning last assigned task to core
    TaskType GetLastTask();  


    //! Constructor, where 't' is the type of core
    Core(TaskType t); 


    //! Returns type of core task
    TaskType GetTaskType();


    //! Returning current amount of tasks in global tasks
    static int GetGlobalTaskCount();


    //! Removing last assigned core task
    void RemoveTask();


    //! Assigning task to core
    void Assign(TaskType t); 


    //! Returning true if there is no tasks in core
    bool Empty();


    //! Returning current amount of tasks in Core
    int GetTaskCount();  


    //! Returning queue of global tasks
    static std::queue <TaskType> GetGlobalTasks(); 


    //! Loading tasks from .txt file 
    static int Init(std::string path);
};

